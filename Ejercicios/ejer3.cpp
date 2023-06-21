#include <iostream>
using namespace std;

class Persona{
    private: 
        string nombre;
        int edad;
        string direccion;
    public:
        Persona(string nombre){this->nombre=nombre;}
        void setEdad(int ed){
            edad=ed;
        }
        void setDireccion(string dir){
            direccion=dir;
        }
        string getNombre(){return nombre;}
        int getEdad(){return edad;}
        string getDireccion(){return direccion;}

};