#include<iostream>
#include<string>
using namespace std;
//ACTIVIDADES DE DIA
class NodoActividad{
    public:
     	//Atributos
		string actividad;
    	NodoActividad *sig;
    	NodoActividad *ant;
    	//Constructor
		NodoActividad(string valor){
		    this->actividad = valor;
		    this->sig = NULL;
		    this->ant = NULL;
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
		//Metodos
	    void addActividad(string valor){
			NodoActividad *nuevo = new NodoActividad(valor); //*nuevo: obtiene la direccion de memoria del nuevo nodo
		    if (this->ini == NULL){
		        this->ini=nuevo;
		        this->fin=nuevo;
		    }else{
		        this->fin->sig=nuevo;
		        this->fin=nuevo;
		    }
		    this->size = this->size + 1;
		}
	    void imprimir(){
		    NodoActividad *temp=this->ini; //*nuevo: obtiene la direccion de memoria del primer nodo
		    while (temp){
		    	cout<<"\t"<<temp->actividad<<endl;
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
    	int id;
    	listaActividad actividades;
    	//Constructor
		NodoDia(string valor){
		    this->nombre = valor;
		    this->sig = NULL;
		    this->actividades = listaActividad();
		    //Asignacion de indice por dia
			if (nombre.compare("Lunes")==0){
		    	id=1;
			}
			if (nombre.compare("Martes")==0){
		    	id=2;
			}
			if (nombre.compare("Miercoles")==0){
		    	id=3;
			}
			if (nombre.compare("Jueves")==0){
		    	id=4;
			}
			if (nombre.compare("Viernes")==0){
		    	id=5;
			}
			if (nombre.compare("Sabado")==0){
		    	id=6;
			}
			if (nombre.compare("Domingo")==0){
		    	id=7;
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
		void addDia(string nombre,string actividad){
			if (buscar(nombre) == false){
				NodoDia *nuevo = new NodoDia(nombre); //*nuevo: obtiene la direccion de memoria del nuevo nodo
				if (this->ini == NULL){
			        this->ini=nuevo;
			        this->fin=nuevo;
			    }else{
			        bool encontrado=false;
					NodoDia *ant=NULL;
					NodoDia *act=this->ini;
					//Ordenamiento
					while((encontrado==false) && (act!=NULL)){
						if (nuevo->id<act->id){//Encuentra indice menor
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
			    nuevo->actividades.addActividad(actividad);
				this->size = this->size + 1;
			}else{
				NodoDia *temp = this->ini;
		    	while (temp){
		    		if (temp->nombre.compare(nombre)==0){
		    			temp->actividades.addActividad(actividad);
		    			break;
					}
					temp=temp->sig;
				}
			}
		}
	    void imprimir(){
		    NodoDia *temp=this->ini; //*nuevo: obtiene la direccion de memoria del primer nodo
		    cout<<"Dias de la semana:"<<endl;
			while (temp){
		    	cout<<temp->nombre<<":"<<endl;
		    	temp->actividades.imprimir();
		        temp=temp->sig;
			}
	    }
};
//Main
int main(){
    listaDia Semana = listaDia();
	Semana.addDia("Viernes","dormir");
	Semana.addDia("Lunes","comer");
    Semana.addDia("Miercoles","estudiar");
    Semana.addDia("Viernes","correr");
    Semana.addDia("Lunes","estudiar");
    Semana.addDia("Viernes","cocinar");
    Semana.addDia("Martes","Salir");
    Semana.addDia("Domingo","Salir");
    Semana.addDia("Sabado","Estudiar");
    Semana.addDia("Domingo","Dormir");
    Semana.imprimir();
    cout<<"----------------------La aplicacion terminara----------------------"<<endl;
    string n;
    cin>>n;
    return 0;
}
