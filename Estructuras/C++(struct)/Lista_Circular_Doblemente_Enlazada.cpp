// LISTA CIRCULAR
#include<iostream>
using namespace std;

struct nodo *Push_front(struct nodo *Lista, int dato);      		// Inserta elemento al inicio
struct nodo *Pop_front(struct nodo *Lista);                 		// Elimina el primer elemento
struct nodo *Push_back(struct nodo *Lista, int dato);       		// Inserta elemento al final
struct nodo *Pop_back(struct nodo *Lista);                  		// Elimina el ultimo elemento
struct nodo *Insert(struct nodo *Lista, int pos, int dato); 		// Imserta un elemento en la posicion 
struct nodo *Erase(struct nodo *Lista, int pos);            		// Borra el elemento de la posicion
struct nodo *Reverse(struct nodo *Lista);                   		// Invierte el orden de los elementos de la lista
struct nodo *Clear(struct nodo *Lista);                     		// Elimina todos los elementos de la lista
void Print_lista(struct nodo *Lista);                       		// Imprime la lista

struct nodo{
	int info;
	struct nodo *ant;
	struct nodo *sig;
};

int main(){
	struct nodo *Lista;
	Lista= (struct nodo*)malloc(sizeof(struct nodo));
	Lista= NULL;
	Lista= Push_front(Lista,7); 			// 7
	Lista= Push_front(Lista,4); 			// 4 7
	Lista= Clear(Lista);        			// 
	Lista= Push_front(Lista,9); 			// 9
	Lista= Push_front(Lista,6); 			// 6 9
	Lista= Push_back(Lista,1);  			// 6 9 1
	Lista= Push_back(Lista,15); 			// 6 9 1 15
	Lista= Pop_front(Lista);    			// 9 1 15
	Lista= Pop_back(Lista);     			// 9 1
	Lista= Insert(Lista,1,21);  			// 21 9 1
	Lista= Insert(Lista,4,8);   			// 21 9 1 8
	Lista= Insert(Lista,4,7);   			// 21 9 1 7 8
	Lista= Erase(Lista,2);      			// 21 1 7 8
	
	Print_lista(Lista);         			// imprime
	Lista= Reverse(Lista);      			// 8 7 1 21
	Print_lista(Lista);         			// imprime
}

struct nodo *Push_front(struct nodo *Lista, int dato){
	struct nodo *p;
	p= (struct nodo*)malloc(sizeof(struct nodo));
	p->info= dato;
	if(Lista==NULL){
		p->ant= p;
		p->sig= p;
		Lista= p;
	}
	else{
		Lista->sig->ant= p;
		p->sig= Lista->sig;
		p->ant= Lista;
		Lista->sig= p;
	}
	return(Lista);
}

struct nodo *Pop_front(struct nodo *Lista){
	if(Lista!=NULL){
		struct nodo *temp;
		if(Lista==Lista->sig){
			temp= Lista;
			Lista= NULL;
			free(temp);
		}
		else{
			temp= Lista->sig;
			Lista->sig->sig->ant= Lista;
			Lista->sig= Lista->sig->sig;
			free(temp);
		}
	}
	return(Lista);
}

struct nodo *Push_back(struct nodo *Lista, int dato){
	struct nodo *p;
	p= (struct nodo*)malloc(sizeof(struct nodo));
	p->info= dato;
	if(Lista==NULL){
		p->ant= p;
		p->sig= p;
		Lista= p;
	}
	else{
		Lista->sig->ant= p;
		p->sig= Lista->sig;
		p->ant= Lista;
		Lista->sig= p;
	}
	Lista= Lista->sig;
	return(Lista);
}

struct nodo *Pop_back(struct nodo *Lista){
	if(Lista!=NULL){
		struct nodo *temp,*p,*q;
		temp= Lista;
		if(Lista==Lista->sig)
			Lista= NULL;
		else{
			p= Lista->ant;
			q= Lista->sig;
			q->ant= p;
			p->sig= q;
			Lista= p;
		}
		free(temp);
	}
	return(Lista);
}

struct nodo *Insert(struct nodo *Lista, int pos, int dato){
	int i;
	struct nodo *p,*q,*r;
	p= (struct nodo*)malloc(sizeof(struct nodo));
	p->info= dato;
	if(Lista==NULL){
		if(pos==1){
			p->ant= p;
			p->sig= p;
			Lista= p;
		}
	}
	else{
		q= Lista;
		for(i=1; i<pos && (q!=Lista || i==1); i++){
			q= q->sig;
		}
		if(i==pos){
			q->sig->ant= p;
			p->sig= q->sig;
			p->ant= q;
			q->sig= p;
			if(q==Lista && i!=1)
			Lista= p;
		}
	}	
	return(Lista);
}

struct nodo *Erase(struct nodo *Lista, int pos){
	if(Lista!=NULL){
		int i;
		struct nodo *q,*r;
		q= Lista;
		r= Lista->sig;
		for(i=1; i<pos && r!=Lista; i++){
			q= r;
			r= r->sig;
		}
		if(i==pos){
			if(i==1 && r==Lista)
				Lista= NULL;
			else if(r==Lista){
				r->sig->ant= q;
				q->sig= r->sig;
				Lista= q;
			}
			else{
				r->sig->ant= q;
				q->sig= r->sig;
			}
			free(r);
		}
	}
	return(Lista);
}

struct nodo *Reverse(struct nodo *Lista){
	if(Lista!=NULL){
		struct nodo *p,*q,*temp;
		p= Lista->sig;
		q= Lista;
		Lista= NULL;
		while(p!=q){
			Lista= Push_front(Lista, p->info);
			temp= p;
			p= p->sig;
			free(temp);
		}
		Lista= Push_front(Lista, p->info);
		free(p);
	}
	return(Lista);
}

struct nodo *Clear(struct nodo *Lista){
	if(Lista!=NULL){
		struct nodo *p,*temp;
		p= Lista->sig;
		while(p!=Lista){
			temp= p;
			p= p->sig;
			free(temp);
		}
		free(Lista);
	}
	Lista= NULL;
	return(Lista);
}

void Print_lista(struct nodo *Lista){
	if(Lista!=NULL){
		struct nodo *p;
		p= Lista->sig;
		cout<< p->info;
		while(p!=Lista){
			p= p->sig;
			cout<<" "<< p->info;
		}
	}
	cout<<endl;
}
