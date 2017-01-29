// LISTA SIMPLE
#include<iostream>
using namespace std;

struct nodo *Push_front(struct nodo *Lista, int dato);				// Inserta elemento al inicio
struct nodo *Pop_front(struct nodo *Lista);							// Elimina el primer elemento
struct nodo *Push_back(struct nodo *Lista, int dato);				// Inserta elemento al final
struct nodo *Pop_back(struct nodo *Lista);							// Elimina el ultimo elemento
struct nodo *Insert(struct nodo *Lista, int pos, int dato);			// Imserta un elemento en la posicion 
struct nodo *Erase(struct nodo *Lista, int pos);					// Borra el elemento de la posicion
struct nodo *Reverse(struct nodo *Lista);							// Invierte el orden de los elementos de la lista
struct nodo *Clear(struct nodo *Lista);								// Elimina todos los elementos de la lista
void Print_lista(struct nodo *Lista);								// Imprime la lista

struct nodo{
	int info;
	struct nodo *sig;
};

int main(){
	struct nodo *Lista;
	Lista= (struct nodo*)malloc(sizeof(struct nodo));
	Lista= NULL;
	Lista= Push_front(Lista,7);					// 7
	Lista= Push_front(Lista,4);					// 4 7
	Lista= Clear(Lista);						// 
	Lista= Push_front(Lista,9);					// 9
	Lista= Push_front(Lista,6);					// 6 9
	Lista= Push_back(Lista,1);					// 6 9 1
	Lista= Push_back(Lista,15);					// 6 9 1 15
	Lista= Pop_front(Lista);					// 9 1 15
	Lista= Pop_back(Lista);						// 9 1
	Lista= Insert(Lista,1,21);					// 21 9 1
	Lista= Insert(Lista,4,8);					// 21 9 1 8
	Lista= Insert(Lista,4,7);					// 21 9 1 7 8
	Lista= Erase(Lista,2);						// 21 1 7 8
	
	Print_lista(Lista);							// imprime
	Lista= Reverse(Lista);						// 8 7 1 21
	Print_lista(Lista);							// imprime
}

struct nodo *Push_front(struct nodo *Lista, int dato){
	struct nodo *p;
	p= (struct nodo*)malloc(sizeof(struct nodo));
	p->info= dato;
	p->sig= Lista;
	Lista= p;
	return(Lista);
}

struct nodo *Pop_front(struct nodo *Lista){
	if(Lista!=NULL){
		struct nodo *p;
		p= Lista;
		Lista= Lista->sig;
		free(p);
	}
	return(Lista);
}

struct nodo *Push_back(struct nodo *Lista, int dato){
	struct nodo *p,*q,*r;
	p= (struct nodo*)malloc(sizeof(struct nodo));
	p->info= dato;
	p->sig= NULL;
	
	q= NULL;
	r= Lista;
	while(r!=NULL){
		q= r;
		r= r->sig;
	}
	if(q==NULL)
	Lista= p;
	else
	q->sig= p;
	
	return(Lista);
}

struct nodo *Pop_back(struct nodo *Lista){
	if(Lista!=NULL){
		struct nodo *q,*r;
		q= NULL;
		r= Lista;
		while(r->sig!=NULL){
			q= r;
			r= r->sig;
		}
		if(q==NULL){
			free(r);
			Lista= NULL;
		}
		else{
			q->sig= NULL;
			free(r);
		}
	}
	return(Lista);
}

struct nodo *Insert(struct nodo *Lista, int pos, int dato){
	int i;
	struct nodo *p,*q,*r;
	p= (struct nodo*)malloc(sizeof(struct nodo));
	p->info= dato;
	q= NULL;
	r= Lista;
	for(i=1; i<pos && r!=NULL; i++){
		q= r;
		r= r->sig;
	}
	if(i==pos){
		if(r==Lista){
			p->sig= r;
			Lista= p;
		}
		else{
			p->sig= r;
			q->sig= p;
		}
	}
	return(Lista);
}

struct nodo *Erase(struct nodo *Lista, int pos){
	int i;
	struct nodo *q,*r;
	q= NULL;
	r= Lista;
	for(i=1; i<pos && r!=NULL; i++){
		q= r;
		r= r->sig;
	}
	if(i==pos && r!=NULL){
		if(r==Lista){
			Lista= Lista->sig;
			free(r);
		}
		else{
			q->sig= r->sig;
			free(r);
		}
	}
	return(Lista);
}

struct nodo *Reverse(struct nodo *Lista){
	if(Lista!=NULL){
		struct nodo *p,*temp;
		p= Lista;
		Lista= NULL;
		while(p!=NULL){
			Lista= Push_front(Lista, p->info);
			temp= p;
			p= p->sig;
			free(temp);
		}
	}
	return(Lista);
}

struct nodo *Clear(struct nodo *Lista){
	struct nodo *p;
	while(Lista!=NULL){
		p= Lista;
		Lista= Lista->sig;
		free(p);
	}
	return(Lista);
}

void Print_lista(struct nodo *Lista){
	if(Lista!=NULL){
		cout<<Lista->info;
		Lista= Lista->sig;
	}
	while(Lista!=NULL){
		cout<<" "<<Lista->info;
		Lista= Lista->sig;
	}
	cout<<endl;
}
