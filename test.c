#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


/*@ensure  if((ret=open(path,O_WRONLY | O_CREAT))<0){
    return(1);
  }s : ecris le texte contenu dans text dans le fichier au chemin absolu path 
et cree ce fichier s'il n'existe pas. En cas de succes on retourne 0 sinon 1*/
int main(int argc, char ** argv){
  int ret;
  if((ret=open(argv[1],O_WRONLY | O_CREAT,00777))<0){
    printf("pb open\n");
    exit(1);
  }
  write(ret,"a",1);
  write(ret,"\n",1);
  write(ret,"a",1);
  write(ret,"\n",1);
  write(ret,"# test1 #\n",11);
  ret=write(ret,"\0",1);
  printf("%d\n",ret);
  /*write(ret,"\0",1);*/

  return 0;
}

/*charsuivant renvoie l'element suivant d'une charlist*/
/*parasuivant renvoie l'element suivant d'une paralist*/
/*first_letter renvoie la premiere lettre d'un paragraphe*/
