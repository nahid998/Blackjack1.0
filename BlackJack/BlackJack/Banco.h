#ifndef BANCO_H
#define BANCO_H

#include <vector>

class Banco {
private:
    std::vector<int> mano;

public:
    Banco();

    void AggiungiCarta();
    int GetValoreMano() const;
    void StampaManoParziale() const;
    void StampaMano() const;
};

#endif
