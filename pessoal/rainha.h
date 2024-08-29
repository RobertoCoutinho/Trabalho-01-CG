#ifndef RAINHA_H
#define RAINHA_H
#include <objeto.h>

class Rainha : public Objeto
{
public:
    Rainha(int pecaTipo);
    void desenha(float colorR, float colorG,float colorB);
    void rainha();
};

#endif // RAINHA_H
