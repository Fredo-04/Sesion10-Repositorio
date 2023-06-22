#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Producto{
public:
    string nombre;
    int cantidad;
    float precio;

    Producto() {}
    Producto(string nom) { nombre = nom; }
    Producto(string nombre, int cantidad, float precio){
        this->nombre = nombre;
        this->cantidad = cantidad;
        this->precio = precio;
    }

    void asignarCantidad(int cant) { cantidad = cant; }
    void asignarPrecio(float pre) { precio = pre; }

    friend ostream& operator<<(ostream& os, const Producto& producto){
        os << "Nombre: " << producto.nombre << endl;
        os << "Precio: " << producto.precio << endl;
        os << "Stock: " << producto.cantidad << endl;
        return os;
    }

    void vender(int cant) {
        if (cant <= cantidad) {
            cantidad -= cant;
            cout << "Venta realizada. Stock actual: " << cantidad << endl;
        }
        else {
            cout << "No hay suficiente stock disponible." << endl;
        }
    }
};

void escribirInventario(const vector<Producto> inventario){
    ofstream archivo("inventario.csv");

    // Escribir encabezados
    archivo << "Nombre,Cantidad,Precio" << endl;

    for (const auto& producto : inventario){
        archivo << producto.nombre << ",";
        archivo << producto.cantidad << ",";
        archivo << producto.precio << endl;
    }

    archivo.close();
}

Producto buscarProducto(const vector<Producto>& inventario, const string& nombre) {
    for (const auto& producto : inventario){
        if (producto.nombre == nombre) {
            return producto;
        }
    }
    return Producto();
}

int main() {
    vector<Producto> inventario;

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

    inventario.push_back(producto1);
    inventario.push_back(producto2);

    escribirInventario(inventario);

    string nombreBusqueda = "Teclado";
    Producto productoEncontrado = buscarProducto(inventario, nombreBusqueda);
    if(productoEncontrado.nombre.empty()){
        cout << "El producto '" << nombreBusqueda << "' no se encuentra en el inventario." << endl;
    }
    else{
        cout << "Producto encontrado:" << endl;
        cout << productoEncontrado << endl;
    }

    return 0;
}
