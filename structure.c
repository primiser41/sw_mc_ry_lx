struct donnee_paragraphe{
  char charactere;
  struct donnee_paragraphe* suivant;
  struct donnee_paragraphe* precedent;
};
typedef struct donnee_paragraphe * charlist;
struct donnee_text{
  int identifiant;
  string date_hour;
  string author;
  struct donnee_paragraphe* first_letter;  
  struct donnee_text* suivant;
  struct donnee_text* precedent;
};
typedef struct donnee_text * paralist;
