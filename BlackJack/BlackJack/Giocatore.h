#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <vector>

class Giocatore {
private:
    std::vector<int> mano;

public:
    Giocatore();

    void AggiungiCarta();
    int GetValoreMano() const;
    void StampaMano() const;
};

#endif