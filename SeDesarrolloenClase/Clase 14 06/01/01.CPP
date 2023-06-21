#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream archivo("ejemplo.txt");
    if (archivo.is_open()){
        string linea;
        int suma;
        while (getline(archivo,linea)){
            int i = stoi(linea);
            suma = i + suma;
        }
        cout << suma << endl;
        archivo.close();
    }
    else{
        cout << "no se pudo abrir\n";
    }
    return 0;
}