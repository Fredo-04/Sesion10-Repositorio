#include <iostream>
using namespace std;

class Producto{
    string nombre;
    int cantidad;
    float precio;
    public:
    Producto(){}
    Producto(string nom){nombre=nom;}
    Producto(string nombre, int cantidad, float precio){
        this->nombre=nombre;this->cantidad=cantidad;this->precio=precio;
    }   
    void asignarCantidad(int cant){cantidad=cant;}
    void asignarPrecio(float pre){precio=pre;}
    friend ostream& operator<<(ostream& os, const Producto& producto) {
        os << "Nombre: " << producto.nombre << endl;
        os << "Precio: " << producto.precio << endl;
        os << "Stock: " << producto.cantidad << endl;
        return os;
    }
    void vender(int cant) {
        if (cant <= cantidad) {
            cantidad -= cant;
            cout << "Venta realizada. Stock actual: " << cantidad << endl;
        } else {
            cout << "No hay suficiente stock disponible." << endl;
        }
    }
};

int main() {
    Producto producto1("Teclado", 50, 10.5);
    Producto producto2("Mouse", 30, 20.0);

    cout << "Datos iniciales del Teclado:" << endl;
    cout << producto1 << endl;

    cout << "Datos iniciales del Mouse:" << endl;
    cout << producto2 << endl;

    producto1.vender(20);
    producto2.vender(10);

    cout << "Datos actualizados del Teclado:" << endl;
    cout << producto1 << endl;

    cout << "Datos actualizados del Mouse:" << endl;
    cout << producto2 << endl;

    return 0;
}
