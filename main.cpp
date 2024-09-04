#include <iostream>
#include <conio.h>
#include <math.h>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    cout<<"Bienvenido, este programa convierte un numero dado en sistema binario, a decimal o hexadecimal\nPorfavor digite el numero binario a convertir: ";
    string binario;
    int decimal = 0;
    int iterador=0;
    cin>>binario;
    map<int, string> mapHexa = {{10,"A"},{11,"B"},{12,"C"},{13,"D"},{14,"E"},{15,"F"}}; //Definimos un diccionario para los valores hexadecimales
    system("CLS");
    getchar();
    cout<<"Seleccione una de las siguientes opciones para convertir el valor " << binario
        <<"\n1. Convertir a decimal\n2. Convertir a hexadecimal\nEsperando opcion:";
    int opcion;
    cin>>opcion;
    while (opcion != 1 && opcion != 2)
    {
        system("cls");
        cout<<"Opcion no valida, intentelo de nuevo.\n";
        cout<<"Seleccione una de las siguientes opciones para convertir el valor " << binario
        <<"\n1. Convertir a decimal\n2. Convertir a hexadecimal\nEsperando opcion: ";
        cin>>opcion;
    }
    if(opcion==1){
        for (int i = binario.length()-1; i >= 0; i--)
        {
            int bit = stoi(binario.substr(i,1)); //Convertir el valor en la posicion i que es de tipo char a tipo int
            decimal += bit*pow(2,iterador);
            iterador++;
        }
        cout <<"\nEl valor decimal es: "<<decimal;
    }else{
        int tamano = binario.length();
        int conteo = 0;

        while(tamano % 4 != 0){ //Calcular el tamaño, para los hexadecimales cada 4 bits son un valor en hexadecimal, por lo que buscamos tener un multiplo de 4 si es el caso rellenando con ceros
            tamano++;
            conteo++;
        }
        //Una vez se tiene el tamaño correcto, se calcula la cantidad de valores hexadecimales que tendra el numero
        int tamanoHexa = tamano/4;
        string hexadecimal[tamanoHexa];

        char binarioAux[tamano];
        for (int i = 0; i < tamano; i++) //Teniendo en cuenta el tamaño y el conteo de ceros extras se le suman a la izquierda de los valores ya digitados
        {
            if (i < conteo)
            {
                binarioAux[i]='0';
            }else{
                binarioAux[i]=binario[i-conteo];
            }
        }
        int subActual=0;
        for (int i = 0; i < tamanoHexa; i++)
        {
            iterador = 0;
            decimal = 0;
            string subBinario[4];
            for (size_t j = 0; j <= 3 ; j++)
            {
                subBinario[j]=binarioAux[4*subActual+j];
            }
            subActual++;
            
            for (int k = 3; k >= 0; k--){ //Conversor de numeros de 4 bits a decimal
                int bit = stoi(subBinario[k]); //Convertir el valor en la posicion i que es de tipo char a tipo int
                decimal += bit*pow(2,iterador);
                iterador++;
            }
            
            //Una vez tenemos el valor decimal, comparamos si es menor o mayor a 9, si es mayor a 9 se le asigna el valor correspondiente hexadecimal comO A,B,C,D,E O F
            if(decimal > 9){
                hexadecimal[i]=mapHexa[decimal];
            }else{
                hexadecimal[i]=to_string(decimal);
            }
        }
        cout <<"El numero hexadecimal es: ";
        for (size_t i = 0; i < tamanoHexa; i++)
        {
            cout<<hexadecimal[i];
        }   
    }
    getch();
    return 0;
}
