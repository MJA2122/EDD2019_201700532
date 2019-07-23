package diasemana;
import java.util.Scanner;
public class DiaSemana {
    public static void main(String[] args) {
        //DECLARACION DE SCANNER
        Scanner sc = new Scanner(System.in);
        //DECLARACION DE VARIABLES
        int year = 0;
        int mes = 20;
        int dia = 90;
        int limite = 0;
        int res = 0;
        boolean p = false;
        String a = "";
        //INGRESO DE AÑO
        while (year<1700){
            System.out.println("Ingrese el año en numero, mayor o igual a 1700");
            year = sc.nextInt();
        }
        //INGRESO DE MES
        while (mes>12){
            System.out.println("Ingrese mes en numero");
            mes = sc.nextInt();
        }
        //ESTABLECE LIMITE
        if (mes == 1 | mes == 3 | mes == 5 | mes == 7 | mes == 8 | mes == 10 | mes == 12){
            limite = 31;
        }else if (mes == 4 | mes == 6 | mes == 9 | mes == 11){
            limite = 30;
        }else{
            if (year%4==0){
                limite = 29;
                p = true;
            }else{
                limite = 28;
                p = false;
            }
        }
        //INGRESO DIA
        while (dia>limite){
            System.out.println("Ingrese dia en numero");
            dia = sc.nextInt();
        }
        //OPERACION
        if (p=true){
            switch (mes){
                case 1:
                    mes = 0;
                    break;
                case 2:
                    mes = 3;
                    break;
                case 3:
                    mes = 3;
                    break;
                case 4:
                    mes = 6;
                    break;
                case 5:
                    mes = 1;
                    break;
                case 6:
                    mes = 4;
                    break;
                case 7:
                    mes = 6;
                    break;
                case 8:
                    mes = 2;
                    break;
                case 9:
                    mes = 5;
                    break;
                case 10:
                    mes = 0;
                    break;
                case 11:
                    mes = 3;
                    break;
                case 12:
                    mes = 5;
                    break;
            }
        }else{
            switch (mes){
                case 1:
                    mes = 0;
                    break;
                case 2:
                    mes = 3;
                    break;
                case 3:
                    mes = 4;
                    break;
                case 4:
                    mes = 0;
                    break;
                case 5:
                    mes = 2;
                    break;
                case 6:
                    mes = 5;
                    break;
                case 7:
                    mes = 0;
                    break;
                case 8:
                    mes = 3;
                    break;
                case 9:
                    mes = 6;
                    break;
                case 10:
                    mes = 1;
                    break;
                case 11:
                    mes = 4;
                    break;
                case 12:
                    mes = 6;
                    break;
            }
        }
        res = ((year - 1)%7 + ((year - 1)/4 - (3*((year - 1)/100 + 1)/4))%7 + mes + dia%7)%7;
        switch (res){
            case 0:
                a = "Domingo";
                break;
            case 1:
                a = "Lunes";
                break;
            case 2:
                a = "Martes";
                break;
            case 3:
                a = "Miercoles";
                break;
            case 4:
                a = "Jueves";
                break;
            case 5:
                a = "Viernes";
                break;
            case 6:
                a = "Sabado";
                break;
        }
        System.out.println("El dia de la semana es: "+a);
    }
}