#ifndef MATRIZ_H
#define MATRIZ_H
#include<iostream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<sstream>
using namespace std;
class NodoCelda{
    public:
		string actividad;
		int pos_x;
		int pos_y;
    	NodoCelda* sig_x;
		NodoCelda* ant_x;
		NodoCelda* sig_y;
		NodoCelda* ant_y;
		NodoCelda(string actividad,int x,int y){
			this->actividad=actividad;
			this->pos_x = x;
		    this->pos_y = y;
		    sig_x = NULL;
		    ant_x = NULL;
		    sig_y = NULL;
		    ant_y = NULL;
		}
};
class listaCelda{
    public:
		NodoCelda* ini;
	    NodoCelda* fin;
	    int size;
		listaActividad(){
		    ini=NULL;
		    fin=NULL;
		    size=0;
		}
		bool existe(int y){
			NodoCelda* temp=this->ini;
			while (temp){
				if (temp->pos_y==y){
					return true;
				}
				temp=temp->sig_y;
			}
			return false;
		}
		void addCeldaX(NodoCelda* nuevo){
			if (this->ini == NULL){ //Primero
		        this->ini=nuevo;
		        this->fin=nuevo;
		    }else{ //Ya existe 1 en la lista
				bool encontrado=false;
				NodoCelda* ant=NULL;
				NodoCelda* act=this->ini;
				//Ordenamiento
				while((encontrado==false) && (act!=NULL)){
					if (nuevo->pos_y<act->pos_y){//Encuentra indice menor
						encontrado=true;
					}else{
						ant=act;
						act=act->sig_y;
					}
				}
				if (ant==NULL){//Ocupa primero
					nuevo->sig_y=act;
					act->ant_y=nuevo;
					this->ini=nuevo;
				}else{
					if (act==NULL){
						ant->sig_y=nuevo;
						nuevo->ant_y=ant;
					}else{//Ocupa desupues de primero
						NodoCelda* aux = ant->sig_y;
						ant->sig_y=nuevo;
						nuevo->sig_y=aux;
						aux->ant_y=nuevo;
						nuevo->ant_y=ant;
					}
				}
		    }
			this->size = this->size + 1;
		}
		void addCeldaY(NodoCelda* nuevo){
			if (this->ini == NULL){ //Primero
		        this->ini=nuevo;
		        this->fin=nuevo;
		    }else{ //Ya existe 1 en la lista
				bool encontrado=false;
				NodoCelda* ant=NULL;
				NodoCelda* act=this->ini;
				//Ordenamiento
				while((encontrado==false) && (act!=NULL)){
					if (nuevo->pos_x<act->pos_x){//Encuentra indice menor
						encontrado=true;
					}else{
						ant=act;
						act=act->sig_x;
					}
				}
				if (ant==NULL){//Ocupa primero
					nuevo->sig_x=act;
					act->ant_x=nuevo;
					this->ini=nuevo;
				}else{
					if (act==NULL){
						ant->sig_x=nuevo;
						nuevo->ant_x=ant;
					}else{//Ocupa desupues de primero
						NodoCelda* aux = ant->sig_x;
						ant->sig_x=nuevo;
						nuevo->sig_x=aux;
						aux->ant_x=nuevo;
						nuevo->ant_x=ant;
					}
				}
		    }
			this->size = this->size + 1;
		}
		NodoCelda* getCelda(int y){
			NodoCelda* temp=ini;
			while(temp){
				if(temp->pos_y==y){
					return temp;
				}
				temp=temp->sig_y;
			}
		}
};
class NodoY{
    public:
		int y;
    	NodoY* sig;
    	NodoY* ant;
    	listaCelda* celdas;
		NodoY(int y){
		    this->y = y;
		    sig = NULL;
		    ant = NULL;
		    celdas = new listaCelda();
		;}
};
class listaY{
    public:
		NodoY* ini;
	    NodoY* fin;
	    int size;
		listaY(){
		    this->ini=NULL;
		    this->fin=NULL;
		    this->size=0;
		}
		bool existe(int y){
			NodoY* temp=this->ini;
			while (temp){
				if (temp->y==y){
					return true;
				}
				temp=temp->sig;
			}
			return false;
		}
	    void addY(int y){
		    if (existe(y)==false){
				NodoY* nuevo = new NodoY(y);
				if (this->ini == NULL){ //Primero
			        this->ini=nuevo;
			        this->fin=nuevo;
			    }else{ //Ya existe 1 en la lista
					bool encontrado=false;
					NodoY* ant=NULL;
					NodoY* act=this->ini;
					//Ordenamiento
					while((encontrado==false) && (act!=NULL)){
						if (nuevo->y<act->y){//Encuentra indice menor
							encontrado=true;
						}else{
							ant=act;
							act=act->sig;
						}
					}
					if (ant==NULL){//Ocupa primero
						nuevo->sig=act;
						act->ant=nuevo;
						this->ini=nuevo;
					}else{
						if (act==NULL){//Ocupa final
							ant->sig=nuevo;
							nuevo->ant=ant;
							this->fin=nuevo;
						}else{//Ocupa desupues de primero
							NodoY* aux = ant->sig;
							ant->sig=nuevo;
							nuevo->sig=aux;
							aux->ant=nuevo;
							nuevo->ant=ant;
						}
					}
			    }
				this->size = this->size + 1;
			}
		}
		NodoY* getNodoY(int y){
			NodoY* tempY=ini;
			while (tempY){
				if (tempY->y==y){
					return tempY;
				}
				tempY=tempY->sig;
			}
		}
};
class NodoX{
    public:
		int x;
    	NodoX* sig;
    	NodoX* ant;
    	int pos_x;
    	listaCelda* celdas;
		NodoX(int x){
		    this->x = x;
		    sig = NULL;
		    ant = NULL;
		    celdas = new listaCelda();
		}
};
class listaX{
    public:
		NodoX* ini;
		NodoX* fin;
	    int size;
		listaX(){
		    this->ini=NULL;
		    this->fin=NULL;
		    this->size=0;
		}
	    bool existe(int x){
			NodoX* temp=this->ini;
			while (temp){
				if (temp->x==x){
					return true;
				}
				temp=temp->sig;
			}
			return false;
		}
	    void addX(int x){
		    if ((existe(x))==false){
				NodoX* nuevo = new NodoX(x);
				if (this->ini == NULL){ //Primero
			        this->ini=nuevo;
			        this->fin=nuevo;
			    }else{ //Ya existe 1 en la lista
					bool encontrado=false;
					NodoX* ant=NULL;
					NodoX* act=this->ini;
					//Ordenamiento
					while((encontrado==false) && (act!=NULL)){
						if (nuevo->x<act->x){//Encuentra indice menor
							encontrado=true;
						}else{
							ant=act;
							act=act->sig;
						}
					}
					if (ant==NULL){//Ocupa primero
						nuevo->sig=act;
						act->ant=nuevo;
						this->ini=nuevo;
					}else{
						if (act==NULL){//Ocupa final
							ant->sig=nuevo;
							nuevo->ant=ant;
							this->fin=nuevo;
						}else{//Ocupa desupues de primero
							NodoX* aux = ant->sig;
							ant->sig=nuevo;
							nuevo->sig=aux;
							aux->ant=nuevo;
							nuevo->ant=ant;
						}
					}
			    }
				this->size = this->size + 1;
			}
		}
		NodoX* getNodoX(int x){
			NodoX* tempX=ini;
			while (tempX){
				if (tempX->x==x){
					return tempX;
				}
				tempX=tempX->sig;
			}
		}
};
class Matriz
{
	public:
		int Num;
		listaX* ejeX;
		listaY* ejeY;
		Matriz* ant;
		Matriz* sig;
		Matriz(){
			ejeX = new listaX();
			ejeY = new listaY();
			Num=1;
			ant = NULL;
			sig = NULL;
		}
		void insertar(string actividad, int x, int y){
			NodoCelda* nuevo = new NodoCelda(actividad,x,y);
			ejeX->addX(x);
			ejeY->addY(y);
			NodoX* NX = ejeX->getNodoX(x);
			NodoY* NY = ejeY->getNodoY(y);
			NX->celdas->addCeldaX(nuevo);
			NY->celdas->addCeldaY(nuevo);
		}
		void getGraphic(){
			string grafico,ranksame,auxgrafico,fileName,fileName2,comando;
			fileName="Semana.dot";
			fileName2="Semana.jpg";
			NodoY* auxY;
			NodoX* auxX;
			NodoCelda* C;
			NodoCelda* auxC;
			grafico += "digraph G { \n";
			grafico += "node [shape = square]; \n";
			auxgrafico += "P [label=\"Semana\"]; \n";
			NodoY* NY = ejeY->ini;			
			while (NY){ //Creacion de nodos Y
				ranksame+="{rank=same Y_"+to_string(NY->y)+" ";
				C=NY->celdas->ini;
				auxgrafico += "Y_"+to_string(NY->y)+" [label=\" Hora "+to_string(NY->y)+"\"]; ";
				while(C){ //Creacion de nodos Celda
					auxgrafico += "N_"+to_string(C->pos_x)+"_"+to_string(C->pos_y)+" [label=\""+C->actividad+"\"]; ";
					ranksame+="N_"+to_string(C->pos_x)+"_"+to_string(C->pos_y)+" ";
					C=C->sig_x;
				}
				ranksame+="} \n";
				auxgrafico+="\n";
				NY = NY->sig;
			}
			NodoX* NX = ejeX->ini;
			ranksame += "{rank=same P ";
			while (NX){ //Creacion de nodos X
				ranksame += " X_"+to_string(NX->x)+" ";
				auxgrafico += "X_"+to_string(NX->x)+" [label=\" Dia "+to_string(NX->x)+"\"]; ";
				NX = NX->sig;
			}
			auxgrafico+="\n";
			ranksame+="} \n";
			NY = ejeY->ini;
			for (int i=0;i<ejeY->size;i++){ //Enlaces en Y
				C=NY->celdas->ini;
				if(i==0){
					auxgrafico += "P -> Y_"+to_string(NY->y)+" [constaint=false,dir=both]; \n";
				}else{
					auxY = NY->ant;
					auxgrafico += "Y_"+to_string(auxY->y)+" -> Y_"+to_string(NY->y)+" [constaint=false,dir=both]; \n";
				}
				auxgrafico += "Y_"+to_string(NY->y)+" -> N_"+to_string(C->pos_x)+"_"+to_string(C->pos_y)+" [constaint=false,dir=both]; \n";
				auxC = C;
				C=C->sig_x;
				while(C){
					auxgrafico += "N_"+to_string(auxC->pos_x)+"_"+to_string(auxC->pos_y)+"-> N_"+to_string(C->pos_x)+"_"+to_string(C->pos_y)+" [constaint=false,dir=both]; \n";
					auxC = C;
					auxC=C;
					C=C->sig_x;
				}
				NY = NY->sig;
			}
			NX = ejeX->ini;
			for (int i=0;i<ejeX->size;i++){ //Enlaces en X
				C=NX->celdas->ini;
				if(i==0){
					auxgrafico += "P -> X_"+to_string(NX->x)+" [constaint=false,dir=both]; \n";
				}else{
					if(i==(ejeX->size-1)){
						auxX = NX->ant;
						auxgrafico += "X_"+to_string(auxX->x)+" -> X_"+to_string(NX->x)+" [constaint=false,dir=both]; \n";
					}else{
						auxX = NX->ant;
						auxgrafico += "X_"+to_string(auxX->x)+" -> X_"+to_string(NX->x)+" [constaint=false,dir=both]; \n";
					}
				}
				auxgrafico += "X_"+to_string(NX->x)+" -> N_"+to_string(C->pos_x)+"_"+to_string(C->pos_y)+" [constaint=false,dir=both]; \n";
				auxC = C;
				C=C->sig_y;
				while(C){
					auxgrafico += "N_"+to_string(auxC->pos_x)+"_"+to_string(auxC->pos_y)+"-> N_"+to_string(C->pos_x)+"_"+to_string(C->pos_y)+" [constaint=false,dir=both]; \n";
					auxC=C;
					C=C->sig_y;
				}
				NX = NX->sig;
			}
			grafico += ranksame;
			grafico += auxgrafico;
			grafico += "}";
			fstream archivo;
			archivo.open(fileName.c_str(),ios::out);
			if(archivo.fail()){
				cout<<"Error al generar archivo"<<endl;
				getch();
			}else{
				archivo<<grafico;
				comando = "dot -Tjpg "+fileName+" -o "+fileName2;
				system(comando.c_str());
				system(fileName2.c_str());
			}
			archivo.close();
		}		
	protected:
};

#endif
