//
// Created by kimberlyc on 15/04/18.
//

#ifndef MSERVER_ESTRUCTURADATA_H
#define MSERVER_ESTRUCTURADATA_H

#include <iostream>

using namespace std;


class EstructuraData {
private:

    string nombre, tipo, tipoReferencia,valor,ptr;
    int referencias,scope, tamanio;
public:
    int getTamanio() const {
        return tamanio;
    }

public:
    void setAtributos(string Nombre, string Ptr, string Valor, string Tipo, int Referencias, string TipoReferencia, int Scope, int Tamanio) {
            this->nombre = Nombre;
            this->ptr = Ptr;
            this->tipo = Tipo;
            this->valor = Valor;
            this->referencias = Referencias;
            this->tipoReferencia = TipoReferencia;
            this -> scope=Scope;

    }

    void setPtr( string ptr) {
        EstructuraData::ptr = ptr;
    }

    void setReferencias(int referencias) {
        EstructuraData::referencias = referencias;
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
    int getScope() {
        return scope;
    }

    string getValor() {
            return valor;
    }
    string getTipoReferencia() {
        return tipoReferencia;
    }
};



#endif //MSERVER_ESTRUCTURADATA_H
