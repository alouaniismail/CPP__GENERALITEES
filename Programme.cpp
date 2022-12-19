#include<cstdlib>
#include<cstdio>
#include "Chaine.hpp"

void annexe(Chaine& s){}//de même pour la syntaxe du ;.


int main(){
  Chaine chaine1("Salut");//déclaration d'une variable de type Chaine(pile)
  Chaine* chaine2;//pointeur sur un objet de type Chaine(allocation dynamique)
  chaine2=new Chaine("Coucou");//sur le tas, syntaxe =new Chaine();
  printf("%d\n",chaine1.getLength());
  printf("%d\n",chaine2->getLength());

  //on peut le faire directement en pile:
  //Chaine chaine1("Salut") donner la valeur dédiée au constructeur
  //directement.

  //les annexe appels-- POSENT un léger problème...(toutes les valeurs, les traces d'appels sont cohérents).
  
  annexe(chaine1);//avec chaine1 no  comment   aucun problème après la mise
  //a jour du destructeur. 
  annexe(*chaine2);//problème avant même du valgrind!!!
  //on a alloué sur le tas la donnée de l'objet instancié chaine2
  //il faut désallouer cette ressource.

  //il faut lire le cours parfois, cela sert énormément, une fonction qui prendra une instance de classe comme paramètre ne posera plus de problème(instances M2MOIRE) si on passe l'instance par référence du coup même adresse du coup même traitement comme un objet unique !



  
  
  delete chaine2;
  //comme int* i=new int; puis delete(i); on fait de la même manière.
  //pas de ressources allouées sur le tas maintenant, la pile se vide toute seule, pas de données ambigues, valgrind est content. 
  return 0;
}

//le destructeur est appelé avant la libération des ressources lors de la destruction d'objet.(cumuler indirectement un delete chaine2 puis un appel comme on adit implicite a Chaine::~Chaine() ne fait un gros problème pour valgrind qui sait comme ça se gère ce genre de trucs.



//remarque: dès qu'on alloue des ressources prenant la place dans la pile le tas prenant son exemple on entre dans la fonction on le ré-empile dans la pile on quitte la fonction avec un code retour qui signale l'instanciation pour passage de parametres a la fonction donc les frees ne sont plus pas compliques comme on y avait pense avant (NULL c'est géré automatiquement par le systeme) le annexe l'appel via une instance de Chaine cree de nouvelles cases memoires dont on sert pas et sont perdues a la fin du programme vue la structure objet du c++, d'où le problème, on applique une fonction sauf elle est bien définie, c'est une méthode public/protected si on parle d'une classe fille ou bien via un constructeur de copie par passage de référence si on veut manipuler en argument seul une instance d'une classe prédéfinie avant. 


//il faut retenir que passer une instance à une fonction externe permet de visualiser d'autres cases mémoires et donc de rendre difficile la gestion de la pile et surtout du tas en cas de constructeur stricte un passager par référence ce qui en lui-même un constructeur par recopie en fin pre sque résoud ce problème à 100%.
