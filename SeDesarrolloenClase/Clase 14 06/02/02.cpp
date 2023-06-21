#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream archivo("ejemplo.txt");
    char caracter;
    int contador = 0;  
    if (archivo.is_open()){
        while (archivo.get(caracter)){
        if (isalpha(caracter)){
            contador++;
            }
        cout << "El archivo tiene " << contador << " letras." << endl;
        }
    }
    else{
        cout << "No se pudo abrir el archivo." << endl;
        return 0;
    }
    archivo.close();

    return 0;
}
