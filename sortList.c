//Write Code to Sort a List
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//--------------------------- LISTES---------------------------------------

/// declaration of type of liste
typedef struct liste liste;
struct liste {
    char ch[1000];
    struct liste*  svt;
};
///----- function using lifo----
liste *creelifo(int n)
{
    liste *p;

    /// ------creation of liste lifo-----

    p=(liste*)malloc(sizeof(liste));
    if (p==NULL) {
        return NULL;
    }

    // traitement de la tete

    printf("\n give first word: ");
    scanf("%s",p->ch);
    p->svt=NULL;
    return p;
}
/// ---fonction that creats the rest of the liste----
void add_element(liste* tete, int n){

    int i;
    for (i=2; i<=n+1; i++){
        liste* e=(liste*)malloc(sizeof(liste));
        if (e==NULL) {
            return ;
        }

        printf("\n give word %d of your list: ",i);
        scanf("%s",e->ch);
        tete->svt = e;
        e->svt=NULL;
        tete=e;

    }



}
/// Fonction that prints the list----------------------------------
void affiche_liste(liste *tetel){
    liste *p ;// p is a pointeur 
   for (p=tetel; p!= NULL; p=p->svt){

        puts(p->ch);

    }
}
///----------------
void viderBuffer() {
    int c = 0;
    while(c != '\n' && c != EOF) {
        c = getchar();
    }
}
///------FUNCTION OF SORT BY bubble sort methode------------------------------------
liste *tri_liste_bulle(liste*tetel,int or)
{    int k=1,nbPerm=0,nbComp=0;
    liste *mot,*r,*q;
   if(or==1)
   {
       mot=(liste*)malloc(sizeof(liste));
       q=tetel;
       r=q->svt;
       while (q->svt!=NULL)
       {
           while ((r!=NULL))


        {     nbComp++;
               if ((strcmp(q->ch, r->ch)>0)) {

                   // permutation
                   nbPerm++;

                   strcpy(mot->ch, r->ch);
                   strcpy(r->ch,q->ch);
                   strcpy(q->ch, mot->ch);
                   r=r->svt;

                    printf("\n the state of %d after treatment : \n",k);
                    affiche_liste(tetel);
                    printf("\n ------------------------------------------------------------ \n ");
                    k++;

               }
               q=q->svt;
           }
       }
   }

    int main(){


//DECLARATIONS---------------------------------------------------------
  int type,z,y , n , i ,j,or;


    char chaine1[100];
    char chaine2[100];
  liste *tetel,*q,*r, *mot ;


    printf("\n give number of words:  ");
    scanf("  %d",&n);
    tetel=creelifo(n);
    add_element(tetel,n-1);
    printf(" -------list before sort-----\n\n");
    affiche_liste(tetel);
    printf("\n");

    tri_liste_bulle(tetel,or);

    printf("  -------list after sort------\n\n");
    affiche_liste(tetel);


    return 0;


    }