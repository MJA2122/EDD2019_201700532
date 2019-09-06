#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <conio.h>
using namespace std;

class Producto{
	public:
		int codigo;
		int stock;
		int stock_min;
		int cod_proveedor;
		Producto* sig;
		Producto(int codigo,int stock,int stock_min,int cod_proveedor){
			this->codigo=codigo;
			this->stock=stock;
			this->stock_min=stock_min;
			this->cod_proveedor=cod_proveedor;
			sig=NULL;
		}
};
class Lista
{
	public:
		Producto* ini;
		Producto* fin;
		int size;
		Lista(){
			ini=NULL;
			fin=NULL;
			size=0;
		}
		void addProducto(int codigo,int stock,int stock_min,int cod_proveedor){
			Producto* nuevo=new Producto(codigo,stock,stock_min,cod_proveedor);
			if(ini==NULL){
				ini=nuevo;
				fin=nuevo;
			}else{
				fin->sig=nuevo;
				fin=nuevo;
			}
			size += 1;
		}
		void add(Producto* prod){
			Producto* nuevo=new Producto(prod->codigo,prod->stock,prod->stock_min,prod->cod_proveedor);
			if (this->ini == NULL){ //Primero
		        this->ini=nuevo;
		        this->fin=nuevo;
		    }else{ //Ya existe 1 en la lista
				bool encontrado=false;
				Producto* ant=NULL;
				Producto* act=ini;
				//Ordenamiento
				while((encontrado==false) && (act!=NULL)){
					if (nuevo->codigo<act->codigo){//Encuentra indice menor
						encontrado=true;
					}else{
						ant=act;
						act=act->sig;
					}
				}
				if (ant==NULL){//Ocupa primero
					nuevo->sig=act;
					ini=nuevo;
				}else{
					if (act==NULL){//Ocupa ultimo
						ant->sig=nuevo;
						fin=nuevo;
					}else{//Ocupa desupues de primero
						ant->sig=nuevo;
						nuevo->sig=act;
					}
				}
		    }
			this->size = this->size + 1;
		}
		Lista* OrdenarLista(Lista* Original){
			Lista* ListaOrdenada=new Lista();
			Producto* temp=Original->ini;
			while(temp){
				if(temp->stock<temp->stock_min){
					ListaOrdenada->add(temp);
				}
				temp=temp->sig;
			}
			return ListaOrdenada;
		}
		void Elimiar(){
			Producto* ant=NULL;
			Producto* act=ini;
			while(act){
				if(act->codigo>100){
					if(ant==NULL){//Primero
						ini=act->sig;
						act=ini;//Inicia otra vez
						ant=NULL;
					}else{//Despies de primero
						Producto* aux=act->sig;
						ant->sig=aux;
						act=ini;//Inicia otra vez
						ant=NULL;
					}
				}
				ant=act;
				act=act->sig;
			}
		}
		void imprimir(){
			Producto* temp=ini;
			if(temp!=NULL){
				cout<<"Lista de productos:"<<endl;
				cout<<"Codigo \tStock \tMinimo \tProveedor"<<endl;
				while(temp){
					cout<<temp->codigo<<"\t"<<temp->stock<<"\t"<<temp->stock_min<<"\t"<<temp->cod_proveedor<<endl;
					temp=temp->sig;
				}
			}else{
				cout<<"Lista vacia!"<<endl;
			}
		}
	protected:
};

#endif
