#include <iostream>
#include <string>
using namespace std;


void registrarVenta() {
    string producto;
    float monto;

    cout << "Producto: ";
    cin>>producto ;             
    getline(cin, producto);

    cout << "Monto: ";
    cin >> monto;

    ofstream archivo;
    archivo.open("ventas.txt", ios::app);   

    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return;
    }

    archivo << producto << " - $" << monto << endl;
    archivo.close();

    cout << "Venta registrada correctamente." << endl;
}


void mostrarVentas() {
    ifstream archivo("ventas.txt");

    if (!archivo.is_open()) {
        cout << "Aun no hay ventas registradas." << endl;
        return;
    }

    string linea;
    int contador = 0;

    cout << "\n--- VENTAS REGISTRADAS ---" << endl;
    while (getline(archivo, linea)) {
        cout << ++contador << ". " << linea << endl;
    }
    archivo.close();

    if (contador == 0) {
        cout << "El archivo esta vacio." << endl;
    }
}

int main() {
    int opcion;

    do {
        cout << "\n===== REGISTRO DE VENTAS =====" << endl;
        cout << "1. Registrar una venta" << endl;
        cout << "2. Mostrar todas las ventas" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarVenta();
                break;
            case 2:
                mostrarVentas();
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 3);

    return 0;
}