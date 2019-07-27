package listadobleenlazada;
public class Lista {
    Nodo ini,fin;
    int size;
    public Lista(){
        ini=fin=null;
        size=0;
    }
    public void addNodo(int x,int y){
        if (ini==null) {
            Nodo temp = new Nodo(x,y);
            ini = fin = temp;
            ini.sig=fin;
            fin.sig=ini;
            ini.ant=fin;
            fin.ant=ini;
        }else{
            Nodo temp = new Nodo(x,y);
            fin.sig=temp;
            temp.ant=fin;
            temp.sig=ini;
            ini.ant=temp;
            fin=temp;
        }
        size ++;
    }
    public void imprimirLista(){
        try{
            Nodo aux=ini;
            int contador = 1;
            System.out.println("Numeros ingresados:");
            do{
                System.out.println(contador+". Valor: "+aux.x+" , "+aux.y);
                aux = aux.sig;
            }while (aux!=ini);
        }catch(Exception e){
            System.out.println("La lista esta vacia");
        }
    }
    public boolean Estado(){
        if (ini==null) {
            return true;
        }else{
            return false;
        }
    }
    public Nodo getIni(){
        Nodo aux = ini;
        return aux;
    }
    public int getSize(){
        return size;
    }
    public void limpiar(){
        for (int i = 0; i < 15; i++) {
            System.out.println(" ");
        }
    }
}