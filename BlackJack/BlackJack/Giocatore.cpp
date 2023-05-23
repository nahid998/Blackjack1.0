#include <iostream>
#include "Giocatore.h"

Giocatore::Giocatore() {}

void Giocatore::AggiungiCarta() {
    mano.push_back((rand() % 10) + 1);
}

int Giocatore::GetValoreMano() const {
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

void Giocatore::StampaMano() const {
    std::cout << "Giocatore: ";
    for (int carta : mano) {
        std::cout << carta << " ";
    }
    std::cout << std::endl;
}
