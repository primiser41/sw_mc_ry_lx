
typedef struct donnee_paragraphe * charlist;
typedef struct donnee_text * paralist;
/*@ensures : get a char from a charlist*/
char charactere(charlist l);
/*@ensures : insert a char in a charlist*/
charlist insert_char(charlist l, char c);
/*@ensures : insert a word in a charlist*/
charlist insert_word(charlist l, word c);
/*@ensures : delete a word in a charlist*/
charlist delete_word(charlist l, word c);
/*@ensures : delete a char in a charlist*/
charlist delete_char(charlist l, char c);
/*@ensures : get the next element of a charlist*/
charlist char_next(charlist l);
/*@ensures : get the previous element of a charlist*/
charlist char_previous(charlist l);


/*@ensures : get a charlist from a paralist*/
charlist first_letter(paralist l);
/*@ensures : get a string informing the date and the hour of the last save for this element of a paralist*/
string save_date(paralist l);
/*@ensures : get the last author of the element of a paralist*/
string author(paralist l);
/*@ensures : get the id of the element of a paralist*/
int id_para(paralist l);
/*@ensures : insere un paragraphe dans une paralist*/
paralist insert_para(paralist l,int id,string hour,string author);
/*@ensures : supprime un paragraphe dans une paralist*/
paralist delete_para(paralist l,int id,string hour,string author);
/*@ensures : get the next element of a charlist*/
paralist para_next(charlist l);
/*@ensures : get the previous element of a charlist*/
paralist para_previous(charlist l);
/*@ensures : change the string informing the date and the hour of the last save for this element of a paralist*/
string save_date(paralist l,string save_date);
/*@ensures : change the last author of the element of a paralist*/
string author(paralist l,string author);
/*@ensures : change the id of the element of a paralist*/
int id_para(paralist l,int id);
