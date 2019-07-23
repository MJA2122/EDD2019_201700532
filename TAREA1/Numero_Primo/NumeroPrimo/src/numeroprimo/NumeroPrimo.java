package numeroprimo;
import java.util.Scanner;
public class NumeroPrimo {
    public static void main(String[] args) {
        //DECLARACION DE SCANNER
        Scanner sc = new Scanner(System.in);
        //DECLARACION DE VARIABLES
        int n = 0;
        //INGRESO DE NUMERO
        while (n<=1){
            System.out.println("Ingrese un numero (>1): ");
            n = sc.nextInt();
        }
        //SE LLENA EL ARREGLO
        int[] ns = new int[n];
        for (int i = 0; i < n; i++) {
            ns[i]=i+1;
        }
        //OPERACIONES
        for (int i = 1; i < n; i++) {
            if (ns[i]!=0) {
                for (int j = i+1; j < n; j++) {
                    if(ns[j]!=0){
                        if ((ns[j]%ns[i])==0){
                            ns[j]=0;
                        }
                    }
                }
            }
        }
        //IMPRIMIR LISTA
        System.out.print("Lista de numeros primos: ");
        for (int i = 1; i < n; i++) {
            if (ns[i]!=0) {
                System.out.print(ns[i]+" ");
            }
        }
    }
}