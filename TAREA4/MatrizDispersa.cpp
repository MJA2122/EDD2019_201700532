#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;

//HORAS
class Nodo{
    public:
     	//Atributos
		int hora;
    	Nodo *sig;
    	//Constructor
		Nodo(int hora){
		    this->hora = hora;
		    sig = NULL
		;}
};

class lista{
    public:
		//Atributos
		Nodo *ini;
	    Nodo *fin;
	    int size;
	    //Constructor
		lista(){
		    this->ini=NULL;
		    this->fin=NULL;
		    this->size=0;
		;}
		//Metodos
	    void addNodo(int hora){
			Nodo *nuevo = new Nodo(hora); //*nuevo: obtiene la direccion de memoria del nuevo nodo
		    if (this->ini == NULL){
		        this->ini=nuevo;
		        this->fin=nuevo;
		    }else{
		        this->fin->sig=nuevo;
		        this->fin=nuevo;
		    }
		    this->size = this->size + 1
		;}
		bool existe(int hora){
			Nodo *temp=this->ini;
			while (temp){
				if (temp->hora==hora){
					return true;
				}
				temp=temp->sig;
			}
			return false;
		}
};
//ACTIVIDADES DE DIA
class NodoActividad{
    public:
     	//Atributos
		string actividad;
		int pos_x;
		int pos_y;
    	NodoActividad *sig; //Mismo dia
		NodoActividad *ant; //Mismo dia
    	//Constructor
		NodoActividad(string actividad,int dia,int hora){
			this->actividad = actividad;
		    this->sig = NULL;
		    this->ant = NULL;
		    this->pos_x = dia;
		    this->pos_y = hora;
		}
};
class listaActividad{
    public:
		//Atributos
		NodoActividad *ini;
	    NodoActividad *fin;
	    int size;
	    //Constructor
		listaActividad(){
		    this->ini=NULL;
		    this->fin=NULL;
		    this->size=0;
		}
		bool existe(int hora){
			NodoActividad *temp=this->ini;
			while (temp){
				if (temp->pos_y==hora){
					return true;
				}
				temp=temp->sig;
			}
			return false;
		}
		//Metodos de insercion
		void addActividad(string actividad,int dia,int hora){
			NodoActividad *nuevo = new NodoActividad(actividad,dia,hora); //*nuevo: obtiene la direccion de memoria del nuevo nodo
			if (existe(hora)==false){
				if (this->ini == NULL){ //Primero
			        this->ini=nuevo;
			        this->fin=nuevo;
			    }else{ //Ya existe 1 en la lista
					bool encontrado=false;
					NodoActividad *ant=NULL;
					NodoActividad *act=this->ini;
					//Ordenamiento
					while((encontrado==false) && (act!=NULL)){
						if (nuevo->pos_y<act->pos_y){//Encuentra indice menor
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
						if (act==NULL){
							ant->sig=nuevo;
							nuevo->ant=ant;
						}else{//Ocupa desupues de primero
							NodoActividad *aux = ant->sig;
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
		void imprimir(){
			NodoActividad *temp=this->ini; //*nuevo: obtiene la direccion de memoria del primer nodo
		    while (temp){
		    	cout<<"\t"<<temp->pos_y<<": "<<temp->actividad<<endl;
		        temp=temp->sig;
			}
	    }
	    void imprimirHora(int hora){
			NodoActividad *temp=this->ini; //*nuevo: obtiene la direccion de memoria del primer nodo
		    while (temp){
		    	if (temp->pos_y==hora){
		    		cout<<"\t\t"<<temp->actividad<<endl;
				}
		        temp=temp->sig;
			}
	    }
};

//DIA DE LA SEMANA
class NodoDia{
    public:
     	//Atributos
		string nombre;
    	NodoDia *sig;
    	int pos_x;
    	listaActividad actividades;
    	//Constructor
		NodoDia(string valor){
		    this->nombre = valor;
		    this->sig = NULL;
		    this->actividades = listaActividad();
		    //Asignacion de indice por dia
			if (nombre.compare("Lunes")==0){
		    	pos_x=1;
			}
			if (nombre.compare("Martes")==0){
		    	pos_x=2;
			}
			if (nombre.compare("Miercoles")==0){
		    	pos_x=3;
			}
			if (nombre.compare("Jueves")==0){
		    	pos_x=4;
			}
			if (nombre.compare("Viernes")==0){
		    	pos_x=5;
			}
			if (nombre.compare("Sabado")==0){
		    	pos_x=6;
			}
			if (nombre.compare("Domingo")==0){
		    	pos_x=7;
			}
		}
};
class listaDia{
    public:
		//Atributos
		NodoDia *ini;
		NodoDia *fin;
	    int size;
	    //Constructor
		listaDia(){
		    this->ini=NULL;
		    this->fin=NULL;
		    this->size=0;
		}
		//Metodos
	    bool buscar(string nombre){
	    	NodoDia *temp = this->ini;
	    	while (temp){
	    		if (temp->nombre.compare(nombre)==0){
	    			return true;
				}
				temp=temp->sig;
			}
			return false;
		}
		//this->semana.find_add(actividad,dia,indexdia,hora);
		void find_add(string actividad, string nombre, int dia, int hora){
	    	NodoDia *temp = this->ini;
	    	while (temp){
	    		if (temp->nombre.compare(nombre)==0){
					temp->actividades.addActividad(actividad,dia,hora);
				}
				temp=temp->sig;
			}
		}
		//INSERTAR ORDENADO
		void addDia(string nombre){
			if (buscar(nombre) == false){	//DIA NUEVO
				NodoDia *nuevo = new NodoDia(nombre); //*nuevo: obtiene la direccion de memoria del nuevo nodo
				if (this->ini == NULL){ //Primero
			        this->ini=nuevo;
			        this->fin=nuevo;
			    }else{ //Ya existe 1 en la lista
			        bool encontrado=false;
					NodoDia *ant=NULL;
					NodoDia *act=this->ini;
					//Ordenamiento
					while((encontrado==false) && (act!=NULL)){
						if (nuevo->pos_x<act->pos_x){//Encuentra indice menor
							encontrado=true;
						}else{
							ant=act;
							act=act->sig;
						}
					}
					if (ant==NULL){//Ocupa primero
						nuevo->sig=act;
						this->ini=nuevo;
					}else{//Ocupa desupues de primero
						ant->sig=nuevo;
						nuevo->sig=act;
					}
			    }
				this->size = this->size + 1;
			}
		}
	    void imprimir(){
		    NodoDia *temp=this->ini; //*nuevo: obtiene la direccion de memoria del primer nodo
		    cout<<"Dias de la semana:"<<endl;
			while (temp){
		    	cout<<temp->nombre<<": "<<endl;
		        temp->actividades.imprimir();
				temp=temp->sig;
			}
	    }
	    void imprimirDia(string nombre){
		    NodoDia *temp = this->ini;
	    	while (temp){
	    		if (temp->nombre.compare(nombre)==0){
	    			break;
				}
				temp=temp->sig;
			}
		    cout<<"Actividades del dia "<<temp->nombre<<":"<<endl;
		  	temp->actividades.imprimir();
	    }
	    void imprimirHora(int hora){
		    cout<<"Actividades de la hora "<<hora<<":"<<endl;
			NodoDia *temp = this->ini;
	    	while (temp){
	    		cout<<"\t Dia: "<<temp->nombre<<endl;
				temp->actividades.imprimirHora(hora);
				temp=temp->sig;
			}
	    }
};

class Semana{
	public:
		int Nsemana;
		listaDia semana;
		lista horas;
		Semana(int Nsemana){
			this->semana = listaDia();
			this->Nsemana = Nsemana;
			this->horas = lista();
		}
		void insertar(string dia, string actividad, int hora){
			this->semana.addDia(dia);
			int indexDia=0;
			if (dia.compare("Lunes")==0){
		    	indexDia=1;
			}
			if (dia.compare("Martes")==0){
		    	indexDia=2;
			}
			if (dia.compare("Miercoles")==0){
		    	indexDia=3;
			}
			if (dia.compare("Jueves")==0){
		    	indexDia=4;
			}
			if (dia.compare("Viernes")==0){
		    	indexDia=5;
			}
			if (dia.compare("Sabado")==0){
		    	indexDia=6;
			}
			if (dia.compare("Domingo")==0){
		    	indexDia=7;
			}
			//Agregar a listas de actividades
			this->semana.find_add(actividad,dia,indexDia,hora);
			this->horas.addNodo(hora);
		}
};
void limpiar(){
	for (int i;i<30;i++){
		cout<<endl;
	}
}
//Main
int main(){
    Semana week = Semana(1);
    week.insertar("Domingo","Cenar",22);
	week.insertar("Lunes","Almorzar",12);
    week.insertar("Viernes","Desayunar",5);
    week.insertar("Miercoles","Desayunar",5);
    week.insertar("Jueves","Desayunar",5);
    week.insertar("Sabado","Cenar",22);
    week.insertar("Martes","Desayunar",5);
    week.insertar("Lunes","Desayunar",5);
    week.insertar("Lunes","Cenar",20);
    week.insertar("Lunes","Estudiar",14);
    string menu="0";
    string actividad,dia,Shora;
    int hora;
    bool p;
	while (menu.compare("5")!=0){
		actividad="";
		dia="";
		hora=-1;
		p=false;
		cout<<"---Actividades de la semana---"<<endl;
	    cout<<"1. Agregar actividad"<<endl;
	    cout<<"2. Mostrar actividades por dia"<<endl;
	    cout<<"3. Mostrar actividades por hora"<<endl;
	    cout<<"4. Mostrar semana"<<endl;
	    cout<<"5. Salir"<<endl;
	    cin>>menu;
	    limpiar();
	    if(menu.compare("1")==0){
	    	cout<<"Ingrese el dia de la semana"<<endl;
	    	cin>>dia;
	    	cout<<"Ingrese hora del dia"<<endl;
	    	cin>>Shora;
	    	cout<<"Ingrese actividad"<<endl;
	    	cin>>actividad;
	    	hora=atoi(Shora.c_str());
	    	cout<<hora<<endl;
	    	if (hora>=0 && hora<=23){
				if (dia.compare("Lunes")==0){
			    	p=true;
				}if (dia.compare("Martes")==0){
			    	p=true;
				}if (dia.compare("Miercoles")==0){
			    	p=true;
				}if (dia.compare("Jueves")==0){
			    	p=true;
				}if (dia.compare("Viernes")==0){
			    	p=true;
				}if (dia.compare("Sabado")==0){
			    	p=true;
				}if (dia.compare("Domingo")==0){
			    	p=true;
				}if (p==true){
					week.insertar(dia,actividad,hora);
				}
			}
		}if(menu.compare("2")==0){
			if (week.semana.size>0){
				cout<<"Ingrese un dia"<<endl;
				cin>>dia;
				if (dia.compare("Lunes")==0){
			    	p=true;
				}if (dia.compare("Martes")==0){
			    	p=true;
				}if (dia.compare("Miercoles")==0){
			    	p=true;
				}if (dia.compare("Jueves")==0){
			    	p=true;
				}if (dia.compare("Viernes")==0){
			    	p=true;
				}if (dia.compare("Sabado")==0){
			    	p=true;
				}if (dia.compare("Domingo")==0){
			    	p=true;
				}
				if(p==true){
					limpiar();
					week.semana.imprimirDia(dia);
					cin>>dia;
				}
			}else{
				cout<<"No hay actividades"<<endl;
				cin>>dia;
			}
		}if(menu.compare("3")==0){
	    	if (week.semana.size>0){
				cout<<"Ingrese una hora"<<endl;
		    	cin>>Shora;
		    	hora=atoi(Shora.c_str());
		    	limpiar();
		    	if (week.horas.existe(hora)==true){
		    		week.semana.imprimirHora(hora);
		    		cin>>dia;
				}
			}else{
				cout<<"No hay actividades"<<endl;
				cin>>dia;
			}
		}if(menu.compare("4")==0){
			if (week.semana.size>0){
				week.semana.imprimir();
			}else{
				cout<<"No hay actividades"<<endl;
			}
			cin>>dia;
		}
		limpiar();
	}
	cout<<"---Aplicacion Terminada!---"<<endl;
    week.semana.imprimir();
    cout<<"----------------------La aplicacion terminara----------------------"<<endl;
    string n;
    cin>>n;
    return 0;
}
