#include <iostream>
#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include "Matriz.h"
using namespace std;
void leerArchivo(){    
	Matriz* nuevo = new Matriz();
	string nombreArchivo,contenido,layer,fileName,celda;
    cout<<"Ingrese el nombre del archivo"<<endl;
    cin>>nombreArchivo;
	int y=1;
	fstream archivo;
	archivo.open(nombreArchivo.c_str(),ios::in);
    if(archivo.is_open()){
		while (!archivo.eof()){
			for (int i=1;i<=6;i++){
				getline(archivo,celda,';');
				if(celda.compare("X")!=0 && celda.compare("x")!=0 && celda.compare("")!=0){
					nuevo->insertar(celda,i,y);
				}
			}
			getline(archivo,celda,'\n');
			if(celda.compare("X")!=0 && celda.compare("x")!=0 && celda.compare("")!=0){
				nuevo->insertar(celda,7,y);
			}
			y+=1;
		}
		cout<<"Archivo cargado!"<<endl;
	}else{
		cout<<"Error al intentar abrir el archivo!"<<endl;
	}
	archivo.close();
	nuevo->getGraphic();
}
int main(int argc, char** argv) {
	leerArchivo();
	return 0;
}
