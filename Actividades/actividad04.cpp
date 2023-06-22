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

// Función para escribir el inventario en un archivo CSV
void escribirInventario(const vector<Producto> inventario){
    try {
        ofstream archivo("inventario.csv");
        if (!archivo) {
            throw runtime_error("Error al abrir el archivo.");
        }

        // Escribir encabezados
        archivo << "Nombre,Cantidad,Precio" << endl;

        for (const auto& producto : inventario){
            archivo << producto.nombre << ",";
            archivo << producto.cantidad << ",";
            archivo << producto.precio << endl;
        }

        archivo.close();
    }
    catch (const exception& e) {
        cout << "Error al escribir el inventario: " << e.what() << endl;
    }
}

// Función para buscar un producto por nombre en el inventario
Producto buscarProducto(const vector<Producto>& inventario, const string& nombre) {
    for (const auto& producto : inventario){
        if (producto.nombre == nombre) {
            return producto;
        }
    }

    // Si el producto no se encuentra, se devuelve un objeto Producto vacío
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

    // Agregar los productos al inventario
    inventario.push_back(producto1);
    inventario.push_back(producto2);

    // Escribir el inventario actualizado en el archivo
    escribirInventario(inventario);

    // Buscar un producto por nombre en el inventario
    string nombreBusqueda = "Teclado";
    try {
        Producto productoEncontrado = buscarProducto(inventario, nombreBusqueda);
        if (productoEncontrado.nombre.empty()){
            throw runtime_error("Producto no encontrado");
        }
        else {
            cout << "Producto encontrado:" << endl;
            cout << productoEncontrado << endl;
        }
    }
    catch (const exception& e) {
        cout << "Error al buscar el producto: " << e.what() << endl;
    }

    return 0;
}
