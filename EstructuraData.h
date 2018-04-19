//
// Created by kimberlyc on 15/04/18.
//

#ifndef MSERVER_ESTRUCTURADATA_H
#define MSERVER_ESTRUCTURADATA_H

#include <iostream>

using namespace std;


class EstructuraData {
private:

    string nombre, tipo, tipoReferencia,valor;
    int referencias;
    string ptr;


public:
    void setAtributos(string Nombre, string Ptr, string Valor, string Tipo, int Referencias, string TipoReferencia) {
            this->nombre = Nombre;
            this->ptr = Ptr;
            this->tipo = Tipo;
            this->valor = Valor;
            this->referencias = Referencias;
            this -> ptr=Ptr;
            this->tipoReferencia = TipoReferencia;


    }

    string getNombre() {
            return nombre;
    }

    string getTipo() {
            return tipo;
    }

    string getPtr() {
            return ptr;
    }

    int getReferencias() {
            return referencias;
    }

    string getValor() {
            return valor;
    }
    string getTipoReferencia() {
        return tipoReferencia;
    }
};



#endif //MSERVER_ESTRUCTURADATA_H
