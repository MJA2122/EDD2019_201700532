#include <iostream>
#include "Lista.h"
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	string menu,cod,stock,stockm,codP;
	Lista* L1=new Lista();
	L1->addProducto(190,35,100,1006);//
	L1->addProducto(21,50,100,1001);//
	L1->addProducto(150,20,100,1002);//
	L1->addProducto(77,10,30,1003);//
	L1->addProducto(27,30,12,1004);
	L1->addProducto(105,10,30,1005);//
	L1->addProducto(17,30,50,1005);//
	while(true){
		for(int i=0;i<30;i++){
			cout<<endl;
		}
		cout<<"-----------------Lista De Productos-----------------"<<endl;
		cout<<"1. Agregar"<<endl;
		cout<<"2. Ordenar"<<endl;
		cout<<"3. Eliminar"<<endl;
		cout<<"4. Imprimir"<<endl;
		cout<<"5. Salir"<<endl;
		cin>>menu;
		if(menu.compare("1")==0){
			cout<<"Codigo:"<<endl;
			cin>>cod;
			cout<<"Stock:"<<endl;
			cin>>stock;
			cout<<"Stock minimo:"<<endl;
			cin>>stockm;
			cout<<"Codigo Proveedor:"<<endl;
			cin>>codP;
			L1->addProducto(atoi(cod.c_str()),atoi(stock.c_str()),atoi(stockm.c_str()),atoi(codP.c_str()));
		}
		if(menu.compare("2")==0){
			L1=L1->OrdenarLista(L1);
		}
		if(menu.compare("3")==0){
			L1->Elimiar();
		}
		if(menu.compare("4")==0){
			L1->imprimir();
			getch();
		}
		if(menu.compare("5")==0){
			break;
		}
	}
	return 0;
}
