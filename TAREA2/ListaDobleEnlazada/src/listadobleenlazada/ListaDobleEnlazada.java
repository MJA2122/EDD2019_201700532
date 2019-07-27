package listadobleenlazada;
import java.util.Scanner;
public class ListaDobleEnlazada {
    public static void main(String[] args) {
        Lista lista1 = new Lista();
        int menu = 0;
        String cadena;
        int n1,n2;
        Scanner sc = new Scanner(System.in);
        while (menu!=6){
            System.out.println("-----------------Lista Doblemente Enlazada-----------------");
            System.out.println("1. Ingresar Nodo");
            System.out.println("2. Mostrar Lista");
            System.out.println("3. Estado de la lista");
            System.out.println("4. Mostrar inicio");
            System.out.println("5. Mostrar tamaño");
            System.out.println("6. Salir");
            cadena=sc.nextLine();
            try{
                menu = Integer.parseInt(cadena);
            }catch(Exception e){
                
            }
            switch (menu){
                case 1:
                    lista1.limpiar();
                    try{
                        System.out.println("Ingrese numero 1:");
                        cadena=sc.nextLine();
                        n1 = Integer.parseInt(cadena);
                        System.out.println("Ingrese numero 2:");
                        cadena=sc.nextLine();
                        n2 = Integer.parseInt(cadena);
                        lista1.addNodo(n1, n2);
                        lista1.limpiar();
                        System.out.println("Valores ingresados");
                    }catch(Exception e){    
                        System.out.println("Error al ingresar numero!");
                    }
                    break;
                case 2:
                    lista1.limpiar();
                    lista1.imprimirLista();
                    break;
                case 3:
                    lista1.limpiar();
                    if (lista1.Estado()==true) {
                        System.out.println("La lista esta vacia");
                    }else{
                        System.out.println("La lista esta llena");
                    }
                    break;
                case 4:
                    lista1.limpiar();
                    if (lista1.getIni()==null) {
                        System.out.println("La lista esta vacia");
                    }else{
                        System.out.println("Primer elemento: "+lista1.getIni().x+" , "+lista1.getIni().y);
                    }
                    break;
                case 5:
                    lista1.limpiar();
                    System.out.println("El tamaño de la lista es: "+lista1.getSize());
                    break;
            }
        }
    }
}