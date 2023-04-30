#define MAX_ITERACOES 6

#define WIDTH 400

#define HEIGHT 250
#include <stdio.h>
#include <stdlib.h>

struct ponto {

double x,y;

} a,b,r,m,s,t;

 

struct segmento {

double x1,y1,x2,y2;

struct segmento *prox;

}*p_ini,*p_ini_aux,*p_new,*p_act,*p_act_aux,*p_aux;

 

double fator;

 

struct segmento *aloca( void ) {

struct segmento *ptr;

if((ptr=(struct segmento *) malloc(sizeof(struct segmento))) == NULL) {

printf("Erro 4: Nao consigo alocar memoria suficiente p/ a lista.\n");

exit(1);

}

return ptr;

}

 

struct segmento *atribui(struct segmento *p_aux,double x1,double y1,double x2,double y2,struct segmento *p_prox){

p_aux->x1=x1;

p_aux->y1=y1;

p_aux->x2=x2;

p_aux->y2=y2;

p_aux->prox=p_prox;

return p_aux;

}

 

void limpa(struct segmento *p_ini) {

struct segmento *p_act, *p_aux;

p_act = p_ini;

while( p_aux->prox != NULL ) {

p_aux = p_act;

p_act = p_act->prox;

free(p_aux);

}

}

 

void tela_inicial(double x_ini,double x_fim,double y_ini,double y_fim,double x_aux,double y_aux) {

setfillstyle(1,16);

bar((x_ini-x_ini)/x_aux,

(y_ini-y_ini)/y_aux,

(x_fim-x_ini)/x_aux,

(y_fim-y_ini)/y_aux);

setcolor(1);

}

 

void main() {

double deltax,deltay;

double x_ini,x_fim,y_ini,y_fim,x_aux,y_aux;

int i;

 

/* ABRINDO O MODO GRAFICO */

int gdriver = DETECT, gmode, errorcode;

 

initgraph(&gdriver, &gmode, "");

 

errorcode = graphresult();

 

if (errorcode != grOk) {

printf("Erro 02: Impossivel abrir o modo grafico.\n");

exit(1);

}

// LIMITES DO GRAFICO

x_ini = 0;

x_fim = 6;

y_ini = 0;

y_fim = 6;

 

// VARIAVEIS AUXILIARES PARA ECONOMIZAR TEMPO

x_aux = (x_fim - x_ini) / WIDTH;

y_aux = (y_fim - y_ini) / HEIGHT;

 

//GRAFICO

tela_inicial(x_ini,x_fim,y_ini,y_fim,x_aux,y_aux);

 

/* Inicio koch */

fator = sqrt(3) / 6;

 

p_act = p_ini = atribui(aloca(),1,3,5,3,NULL);

 

i=0;

while(i<MAX_ITERACOES) {

 

/* Lista auxiliar */

p_ini_aux = NULL;

 

/* desenho do fractal */

p_act=p_ini;

while(p_act != NULL) {

if((((p_act->x1 - x_ini) != 0) &&

((p_act->y1 - y_ini) != 0) &&

((p_act->x2 - x_ini) != 0) &&

((p_act->y2 - y_ini) != 0))) {

line((p_act->x1-x_ini)/x_aux,(p_act->y1-y_ini)/y_aux,(p_act->x2-x_ini)/x_aux,(p_act->y2-y_ini)/y_aux);

}

p_act = p_act->prox;

}

 

getch();

 

tela_inicial(x_ini,x_fim,y_ini,y_fim,x_aux,y_aux);

 

p_act = p_ini;

/* fim desenho do fractal */

while( p_act != NULL ) {

 

a.x=p_act->x1;

a.y=p_act->y1;

b.x=p_act->x2;

b.y=p_act->y2;

r.x = ( 2.0 * a.x + b.x ) / 3.0;

r.y = ( 2.0 * a.y + b.y ) / 3.0;

 

t.x = ( a.x + 2.0 * b.x ) / 3.0;

t.y = ( a.y + 2.0 * b.y ) / 3.0;

 

m.x = ( a.x + b.x ) / 2.0;

m.y = ( a.y + b.y ) / 2.0;

 

deltax = b.x - a.x;

deltay = b.y - a.y;

 

s.x = m.x + (fator * deltay);

s.y = m.y - (fator * deltax);

 

p_new=atribui(aloca(),a.x,a.y,r.x,r.y,NULL);

 

if(p_ini_aux == NULL)

p_ini_aux = p_new;

else

p_act_aux->prox = p_new;

p_act_aux = p_new;

 

p_new=atribui(aloca(),r.x,r.y,s.x,s.y,NULL);

p_act_aux->prox = p_new;

p_act_aux = p_new;

 

p_new=atribui(aloca(),s.x,s.y,t.x,t.y,NULL);

p_act_aux->prox = p_new;

p_act_aux = p_new;

 

p_new=atribui(aloca(),t.x,t.y,b.x,b.y,NULL);

p_act_aux->prox = p_new;

p_act_aux = p_new;

 

p_aux = p_act;

p_act = p_act->prox;

free(p_aux);

p_ini = p_act;

}

 

/* transferindo lista auxiliar p/ lista original */

p_act_aux = p_ini_aux;

p_ini = NULL;

while(p_act_aux != NULL) {

 

p_new = aloca();

if (p_ini == NULL)

p_ini = p_new;

else

p_act->prox = p_new;

p_act = p_new;

 

atribui(p_act,p_act_aux->x1,p_act_aux->y1,p_act_aux->x2,p_act_aux->y2,NULL);

p_aux = p_act_aux;

p_act_aux = p_act_aux->prox;

p_ini_aux = p_act_aux;

free(p_aux);

}

p_act = p_ini;

 

i++;

} /* fim kock */

limpa(p_ini); // limpando lista original

closegraph();

}