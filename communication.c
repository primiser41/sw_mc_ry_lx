#include "structure.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/*@ensures : ecris le texte contenu dans text dans le fichier au chemin absolu path 
et cree ce fichier s'il n'existe pas. En cas de succes on retourne 0 sinon 1*/
int localsave(char* path,paralist text){
  paralist paragraphe;
  charlist charactere;
  char letter;
  int ret;
  paragraphe = text;

  if((ret=open(path,O_WRONLY | O_CREAT,00777))<0){
    return(1);
  }

  while(paragraphe!=NULL){/*pour chaque paragraphe du texte*/
    charactere = first_letter(paragraphe);

    while(charactere!=NULL){/*pour chaque charactere du paragraphe*/
      letter = letter(charactere);
      write(ret,letter,1);
      charactere = charsuivant(charactere);
    }

    paragraphe = parasuivant(paragraphe);
  }
  write(ret,"\0",1);

  return(0);

}


int versionsave(char* path,char* serveur,paralist text,char* filename){
  paralist paragraphe;
  charlist charactere;
  char letter;
  int ret;
  char* donnee_paragraphe;
  int statut;
  char* sshcommande;
  paragraphe = text;

  if((ret=open("./tmpversionsave",O_WRONLY | O_CREAT,00777))<0){
    return(1);
  }

  while(paragraphe!=NULL){/*pour chaque paragraphe du texte*/
    charactere = first_letter(paragraphe);
    sprintf(donnee_paragraphe,"##id=%d author=%s date_heure=%d##\n",idpara(paragraphe),author(paragraphe),date_heurepara(paragraphe));
    write(ret,donnee_paragraphe,strlen(donnee_paragraphe));

    while(charactere!=NULL){/*pour chaque charactere du paragraphe*/
      letter = letter(charactere);
      write(ret,letter,1);
      charactere = charsuivant(charactere);
    }

    paragraphe = parasuivant(paragraphe);
  }
  write(ret,"\0",1);

  switch(pid=fork){
  case -1: 
    return(1);
    break;
  case 0: 
    sprintf(scpcommande,"scp ./tmpversionsave %s:/depot_projet/%s",serveur,filename);
    execlp(scpcommande,scpcommande,NULL);
    break;
  default: 
    wait(&statut);
    execlp("rm./tmpversionsave ","rm ./tmpversionsave",NULL);
    break;
  }

  return(0);

}


/*charsuivant renvoie l'element suivant d'une charlist*/
/*parasuivant renvoie l'element suivant d'une paralist*/
/*first_letter renvoie la premiere lettre d'un paragraphe*/
