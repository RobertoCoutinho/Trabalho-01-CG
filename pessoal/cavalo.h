#ifndef CAVALO_H
#define CAVALO_H
#include<objeto.h>

class Cavalo : public Objeto
{
public:
    Cavalo(int pecaTipo);
    void desenha(float colorR, float colorG,float colorB);
    void cavalo();
};

#endif // CAVALO_H
