#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <objeto.h>

class Tabuleiro : public Objeto
{
public:
    Tabuleiro(int pecaTipo);
    void desenha();
    void casaTaboleiro();
    void bordaTabuleiro();
};

#endif // TABULEIRO_H
