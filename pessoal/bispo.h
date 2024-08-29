#ifndef BISPO_H
#define BISPO_H
#include<objeto.h>

class Bispo : public Objeto
{
public:
    Bispo(int pecaTipo);
    void desenha(float colorR, float colorG,float colorB);
    void bispo();
};

#endif // BISPO_H
