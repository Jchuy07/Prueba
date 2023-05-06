#include <iostream>
#include <fstream>
#include <filesystem>
#include "windows.h"

using namespace std;
void crearArchivos(int cantidad, int personas, int dias );
int contarArchivosDeDirectorio();
void listarArchivosDeDirectorio();
void mostrarDetalles();



int main()
{
    int cantidad, personas, dias  ;
    switch() {

        case 1:
            cout << "Ingrese el numero de archivos" << endl;
            break;
        case 2:
            cout << "Ingrese el numero de personase " << endl;
            break;
        case 3:
            cout << "Ingrese el numero de dias " << endl;
            break;
    }
    crearArchivos( cantidad, personas, dias );
    cout << contarArchivosDeDirectorio();
    cout << endl;
    listarArchivosDeDirectorio();
    mostrarDetalles();
    return 0;
}

void crearArchivos(int cantidad, int personas, int dias ) {
    string nombreArchivo = "archivo";

    float tarifaDiaria = 100.0; //almacenar el valor en numero real
    int i; //archivos o personas

    for (i = 0; i < cantidad; i++) {
        ofstream file;
        file.open("C:/Users/janet/OneDrive/Escritorio/progra/" + nombreArchivo + to_string(i) + ".txt");
        float costoTotal = personas * tarifaDiaria * dias ;

        file << "Personas: " << personas << "\n";
        file << "dias: " << dias << "\n";
        file << "Costo total: " << costoTotal << "\n";


        file.close();
    }
    cout << "Archivos creados: " << i;
}

void listarArchivosDeDirectorio(){
        WIN32_FIND_DATA findFileData;
        HANDLE          hFind;
        hFind = FindFirstFile("C:/Users/janet/OneDrive/Escritorio/progra/*", &findFileData);

        if (hFind == INVALID_HANDLE_VALUE)
            cout << "Ruta incorrecta";
        else
        {
            cout << findFileData.cFileName << '\n'; //El primer archivo
            // Listamos todos los archivos

            while (FindNextFile(hFind, &findFileData) != 0)
                cout << findFileData.cFileName << '\n';
        }
}

int contarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:/Users/janet/OneDrive/Escritorio/progra/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta incorrecta";
    else
    while (FindNextFile(hFind, &findFileData)!=0){
        cantidadDeArchivos=cantidadDeArchivos+1;
    }
    return cantidadDeArchivos-1;
}

void mostrarDetalles(){
    std::filesystem::directory_iterator directoryIterator("C:/Users/janet/OneDrive/Escritorio/progra/");
    for (const auto& entry : directoryIterator) {
        if (!std::filesystem::is_directory(entry.status())) {
            std::cout << entry.path().filename() << " "
                    << file_size(entry.path()) << std::endl;
        }
    }
}
