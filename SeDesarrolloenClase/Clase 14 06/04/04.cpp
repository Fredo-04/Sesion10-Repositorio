#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream archivo("fecha.txt");
    int annio;
    if (archivo.is_open()){
        string linea;
        int suma[3];
        int contsum=0;
        while (getline(archivo,linea)){
            int i = stoi(linea);
            suma[contsum] = i;
        }
        if((suma[0]<=14) && (suma[1]<=6)){
            annio = 2023 - suma[2];
        }
        else{
            annio = 2023 - suma[2] - 1;
        }
        cout << "Edad: " << annio << endl;
        archivo.close();
    }
    else{
        cout << "no se pudo abrir\n";
    }
    return 0;
}