#include <cstdlib>
#include<cstdio>
#include<cstring>
#include "Chaine.hpp"

//on doit implémenter forcément la fonction getLength.
//on doit jouer sur le constructeur pour vérifier les tailles (par défaut sur
//la pile c'est zéro)

/*
Chaine::Chaine():_taille(0), _donnees(NULL) {};
//retenir la syntaxe: Chaine::Chaine(): data1(value1), data2(value2) {};(optionnel).
//car à l'intèrieur, on va préciser ce que fera le constructeur.
*/

Chaine::Chaine():_taille(0),_donnees(NULL){
  printf("%s(%d): %s\n",__FILE__,__LINE__,__func__);
}
//c'est normal à la classe, de même que le destructeur qu'on implémentera maintenant.

//pas besoin de mettre en commentaire l'autre constructeur, on peut avoir deux!
//voir le fichier principal: Chaine.hpp.
//question: comment construire un string ? en poo c++ sachat la fonction dst src de strcpy?(const char* src)
//new char soit new char[10] pour une chaine de 9 caractères ASCII.

Chaine::Chaine(const char* data):_taille(strlen(data)),_donnees(strcpy(new char[_taille+1],data)) {}//en profondeur, c'est détruit à l'appel du destructeur
//cette allocation de chaine.

Chaine::~Chaine(){
  //typederetour puis _:_ mais pour ces deux-là direct| _:_{}
  printf("Destructeur appelé à cet instant.\n");
  //ATTENTION: on a alloué indirectement le tableau _donnees il faut le désallouer suivant la valeur NULL ou non.
    delete[] _donnees;
  //dans le cas du constructeur par défaut, _donnees=NULL, on appelle le destructeur, cela peut poser certains problèmes ; avec gdb, on a su que quelque chose clochait au niveau de _donnees et de la libération des ressources avant le return 0 du main() de Programme.cpp. 
}


//a la fin d'une fonction, on met pas de point virgule ! comme ci-dessus:

unsigned int Chaine::getLength(){//de même.(en entrant dans la classe)
  return _taille;
}
//l'exo4 est deja fait dès le début, c'est les zéros qui séaffichent comme longueur.

char Chaine::get(unsigned int i){
  if((i<=_taille) && (_donnees != NULL) && (i!=0))
    return _donnees[i-1];
  return '\0';
}
//il faut que i soit positif (c'est primordial)+i<=_taille
//il faut qu'il dépasse la taille ('\0'non compris)+le fait que _donnees!=NULL
//pour que le tableau soit alloué sur char de nombre: _taille sinon return '\0'.





  
//c'est un getter.
