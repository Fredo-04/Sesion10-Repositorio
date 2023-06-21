#include <iostream>
using namespace std;

int main(){
    cout << "inicio\n";
    int num;
    try{
        cout << "inicio try\n";
        cin >> num;
        throw(num);
        cout << "no sale";}
        catch(int i){
            cout << "error int\n";
        }
        catch(float i){
            cout << "error float\n";
        }
        catch(double i){
            cout << "error double\n";
        }
        catch(char const* x){
            cout << "error cadena\n";
        }
        

    return 0;
}