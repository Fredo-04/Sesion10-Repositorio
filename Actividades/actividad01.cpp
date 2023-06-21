#include <iostream>
using namespace std;

class Producto{
    string nombre;
    int cantidad;
    float precio;
    public:
    Producto(string nom){nombre=nom;}
    Producto(string nombre, int cantidad, float precio){
        this->nombre=nombre;this->cantidad=cantidad;this->precio=precio;
    }
    void asignarCantidad(int cant){cantidad=cant;}
    void asignarPrecio(float pre){precio=pre;}
    void imprimirDatos(){
        cout<<nombre<<endl<<"Cantidad: "<<cantidad<<endl<<"Precio: "<<precio;
    }
    
};