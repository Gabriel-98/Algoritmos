#include<iostream>
#define infinito 2147483647
using namespace std;

void mergesort(int V[], int p, int r);      	// Se ingresan la posicion inicial y final
void merge(int V[], int p, int q, int r); 		// Mezcla las dos sublistas en una sola lista ordenada

int main(){
	int n=6, i;
	int V[n]= {7,21,13,4,8,2};  				// 7 21 13 4 8 2
	mergesort(V,0,n-1);         				// 2 4 7 8 13 21
	for(int i=0; i<n; i++){
		cout<<V[i]<<" ";
	}
	cout<<endl;
}

void mergesort(int V[], int p, int r){
		if(p<r){
			int q;
			q= (p+r)/2;
			mergesort(V,p,q);
			mergesort(V,q+1,r);
			merge(V,p,q,r);
		}
}

void merge(int V[], int p, int q, int r){
	int n1, n2, i, j, k;
	n1= q-p+1;
	n2= r-q;
	int L[n1+2];
	int R[n2+2];
	
	for(i=1; i<=n1; i++){
		L[i]= V[p+i-1];
	}
	for(j=1; j<=n2; j++){
		R[j]= V[q+j];
	}
	
	L[n1+1]= infinito;
	R[n2+1]= infinito;
	
	i=1;
	j=1;
	
	for(k=p; k<=r; k++){
		if(L[i] <= R[j]){
			V[k]= L[i];
			i++;
		}
		else{
			V[k]= R[j];
			j++;
		}
	}
}
