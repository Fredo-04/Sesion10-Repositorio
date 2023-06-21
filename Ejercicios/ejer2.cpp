#include <iostream>
using namespace std;

template<typename T>
T divide(T a, T b){
    if (b == 0){
        throw runtime_error("No se puede dividir por cero");
    }
    return a / b;   
}

int main(){
    try{
        float div1 = divide(10.3,30.1);
        cout << "Resultado 1: " << div1 << endl;
        int div2 = divide (10,2);
        cout << "Resultado 2: " << div2 << endl;
        int div3 = divide (32,0);
        cout << "Resultado 3: " << div3 << endl;
        cout << "Fin\n";
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}