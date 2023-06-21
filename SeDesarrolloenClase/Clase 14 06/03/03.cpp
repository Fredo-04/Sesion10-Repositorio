#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream archivo("ejemplo.txt");
    char caracter;
    int contador = 0;  
    if (archivo.is_open()){
        while (archivo.get(caracter)){
            caracter = tolower(caracter);
            if (isalpha(caracter) && (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u')){
                contador++;
            }
        }
        cout << "El archivo tiene " << contador << " vocales." << endl;
    }
    else{
        cout << "No se pudo abrir el archivo." << endl;
        return 0;
    }
    archivo.close();

    return 0;
}
