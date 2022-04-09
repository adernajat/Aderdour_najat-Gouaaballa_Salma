#include <stdio.h>
#include <stdlib.h>
typedef struct proces{
    int identifiant;

    int temps_restant;
     int date_arrive;
     int priorit;
    struct proces * suivant;
}process;
//q2//
process * create_pro(process pr){
    process *pro=(process *)malloc(sizeof(process));
    pro->identifiant=pr.identifiant;
    pro->temps_restant=pr.temps_restant;
    pro->date_arrive=pr.date_arrive;
    pro->priorit=pr.priorit;
    return pro;
}
typedef struct {
    process *tete;
   process *queue;
	int tail;
}file;
//q4//
  file *ini_file(){
   file *f;
   f=(file *)malloc(sizeof(file));
    f->tete=NULL;
    f->queue=NULL;
    return f;
}
//test si la file est vide //
int test_vide(file *f){
    if(f->tete==f->queue) return 1;
    else return 0;
}
//q5//
process *pop_process(file *f){
process *x;
if (test_vide(f)==1){
printf("la file est vide ");
exit(1);
}
else
x= f->tete;
f->tail--;
f->tete=f->tete->suivant;
return x;
}
//Q6//
process *read (file *f){
process *x;
if (test_vide(f)==1){
printf("la file est vide ");
exit(1);
}
else
x=f->tete;
f->tete=f->tete->suivant;
return x;
}
//fifo
void FIFO (file *f,process *x){
    if(f->queue==NULL)
        f->tete=f->queue=x ;
    else{
        f->queue->suivant = x;
        f->queue = x ;
    }
    f->tail++;
}


void creer_file(file *f,int a){
    int i;
    process prc;
    process *x = NULL;
    for(i=1;i<=a;i++){
       printf("Proc prc'%d\n",i);
       printf("L'identifiant : ");
       scanf("%d",&prc.identifiant);
       printf("Date d'arriver: ");
       scanf("%d",&prc.date_arrive);
       printf("Temps restant: ");
       scanf("%d",&prc.temps_restant);
       printf("La prioriter: ");
       scanf("%d",&prc.priorit);
       x=create_pro(prc);
       FIFO(f,x);
    }
}
//tourniquet
void push_tourniquet(file *f){
	process *x;
	int q;
	printf("donner le quanta :");
	scanf("%d",&q);
	while(f->tete!=NULL){
		if(f->tete->temps_restant > q){
			printf("P'%d\t%d",f->tete->identifiant,q);
			f->tete->temps_restant -= q;
        }
		else printf("P'%d\t%d",f->tete->identifiant,f->tete->temps_restant);
	}
}
void affiche(file *f,int n){
    int i;
    process *p = NULL;
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\n",f->tete->identifiant,f->tete->date_arrive,f->tete->temps_restant,f->tete->priorit);
        p = pop_process(f);
    }
}
int main()
{
	int n;
	file *f = ini_file();
	printf("Donner le nombre de process: ");
	scanf("%d",&n);
	creer_file(f,n);
    affiche(f,n);
    push_tourniquet(f);
    return 0;
}
