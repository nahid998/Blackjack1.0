#include <iostream>
#include "Giocatore.h"
#include "Banco.h"

int main() {
    int puntata;
    std::cout << "Benvenuto al Blackjack! Quanto vuoi puntare? ";
    std::cin >> puntata;

    Giocatore giocatore;
    Banco banco;

    giocatore.AggiungiCarta();
    giocatore.AggiungiCarta();
    banco.AggiungiCarta();
    banco.AggiungiCarta();

    bool gameOver = false;
    bool giocatoreHaVinto = false;

    while (!gameOver) {
        giocatore.StampaMano();
        banco.StampaManoParziale();

        if (giocatore.GetValoreMano() > 21) {
            gameOver = true;
            giocatoreHaVinto = false;
            break;
        }

        if (giocatore.GetValoreMano() == 21) {
            gameOver = true;
            giocatoreHaVinto = true;
            break;
        }

        char risposta;
        std::cout << "Vuoi pescare un'altra carta? (s/n): ";
        std::cin >> risposta;

        if (risposta == 's') {
            giocatore.AggiungiCarta();
        }
        else {
            gameOver = true;
        }
    }

    while (banco.GetValoreMano() < 17) {
        banco.AggiungiCarta();
    }

    giocatore.StampaMano();
    banco.StampaMano();

    if (giocatoreHaVinto) {
        std::cout << "Il giocatore ha vinto!" << std::endl;
    }
    else {
        std::cout << "Il banco ha vinto!" << std::endl;
    }

    return 0;
}


