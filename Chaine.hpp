#ifndef CHAINE_HPP
#define CHAINE_HPP

class Chaine{
private://données privées.
  unsigned int _taille;
  char* _donnees;
public://méthodes publiques.
  Chaine();//le constructeur par défaut.
  Chaine(const char* data);//overloading.(reecriture)
  ~Chaine();
  unsigned int getLength();
  char get(unsigned int);//comme un header --déclaration.
  /*  void annexe(Chaine s){}//syntaxe possible(pas d'implémentation;c'est tout).*/
  //MAIS ce n'est pas la cible, c'est écrit dans le programme principal!
};//attention au point de virgule.


#endif
