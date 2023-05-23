#include <iostream>
#include "Banco.h"

Banco::Banco() {}

void Banco::AggiungiCarta() {
    mano.push_back((rand() % 10) + 1);
}

int Banco::GetValoreMano() const {
    int valore = 0;
    int numeroAssi = 0;

    for (int carta : mano) {
        if (carta == 1) {
            valore += 11;
            numeroAssi++;
        }
        else if (carta > 1 && carta <= 10) {
            valore += carta;
        }
        else {
            valore += 10;
        }
    }

    while (valore > 21 && numeroAssi > 0) {
        valore -= 10;
        numeroAssi--;
    }

    return valore;
}

void Banco::StampaManoParziale() const {
    std::cout << "Banco: " << mano[0] << " X" << std::endl;
}

void Banco::StampaMano() const {
    std::cout << "Banco: ";
    for (int carta : mano) {
        std::cout << carta << " ";
    }
    std::cout << std::endl;
}
