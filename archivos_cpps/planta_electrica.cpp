#include "../archivos_h/construcciones/planta_electrica.h"

using namespace std;

int Planta_electrica::cantidad_construidos = 0;
int** Planta_electrica::ubicaciones = 0;

Planta_electrica::Planta_electrica(string nombre, int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos) {
    this -> nombre = nombre;
    this -> cantidad_permitida = permitidos;
    this -> materiales_necesarios = new int[3];
    this -> materiales_necesarios[0] = piedra_necesaria;
    this -> materiales_necesarios[1] = madera_necesaria;
    this -> materiales_necesarios[2] = metal_necesario;
    this -> ubicaciones = new int *[cantidad_construidos];
}

Planta_electrica::Planta_electrica(string nombre, int coord_x, int coord_y) {
    this->nombre = nombre;
    this->representacion = nombre[0];
    if (!this->ubicaciones){
        this->ubicaciones = new int*[1];
    }
    else{
        this->redimensionar_ubicaciones(cantidad_construidos + 1);
    }
    this->ubicaciones[cantidad_construidos] = new int[2];
    this->ubicaciones[cantidad_construidos][0] = coord_x;
    this->ubicaciones[cantidad_construidos][1] = coord_y;
    this->cantidad_construidos++;
}

int Planta_electrica::brindar_materiales() {
    return 0;
}
void Planta_electrica::redimensionar_ubicaciones(int nueva_longitud){
    int **nuevo_vector_ubicaciones = new int *[nueva_longitud];
    for (int i = 0; i < this->cantidad_construidos; i++) {
        if (this->ubicaciones[i]) {
            nuevo_vector_ubicaciones[i] = this->ubicaciones[i];
        }
    }
    delete[] this->ubicaciones;
    this->ubicaciones = nuevo_vector_ubicaciones;
}

void Planta_electrica::mostrar_edificio() {
    cout << "--> " << COLOR_VERDE_AGUA << this -> nombre << COLOR_POR_DEFECTO << endl;
    cout << endl;
    cout << "Piedra requerida: " << this -> materiales_necesarios[0] << endl;
    cout << "Madera requerida: " << this -> materiales_necesarios[1] << endl;
    cout << "Metal requerido: " << this -> materiales_necesarios[2] << endl;
    cout << "Construidos hasta el momento: " << this -> cantidad_construidos << endl;
    cout << "Puede construir " << this -> cantidad_permitida - this -> cantidad_construidos << " mas" << endl;
    cout << "Brinda material: NO" << endl;
    cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
}

int Planta_electrica::obtener_construidos() {
    return this -> cantidad_construidos;
}

int** Planta_electrica::obtener_ubicaciones() {
    return this -> ubicaciones;
}

void Planta_electrica::demoler(int coordenada_x, int coordenada_y) {
    int indice = 0;
    bool eliminada = false;
    while (!eliminada) {
        int* coordenadas = this -> ubicaciones[indice];
        if (coordenadas[0] == coordenada_x && coordenadas[1] == coordenada_y) {
            delete [] coordenadas;
            delete[] this -> ubicaciones[indice];
            coordenadas = 0;
            this -> ubicaciones[indice] = 0;
            eliminada = true;
        }
        indice++;
    }
    this -> redimensionar_ubicaciones(this -> cantidad_construidos);
    this -> cantidad_construidos--;
}

void Planta_electrica::mostrar_saludo() {
    cout << COLOR_MARRON <<"Soy una planta electrica y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO <<endl;
}

void Planta_electrica::borrar_ubicaciones() {
    for (int i = 0; i < this->cantidad_permitida; i++){
        delete[] this->ubicaciones[i];
        this->ubicaciones[i] = 0;
    }
    delete[] this->ubicaciones;
    this->ubicaciones = 0;
}

Planta_electrica::~Planta_electrica() {
    /*for (int i = 0; i < this -> cantidad_construidos; i++) {
        delete [] this -> ubicaciones[i];
        this -> ubicaciones[i] = 0;
    }

    delete [] this -> ubicaciones;
    this -> ubicaciones = 0;*/

    cout << "PLANTA ELECTRICA" << endl;
}