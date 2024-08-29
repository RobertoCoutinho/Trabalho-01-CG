#ifndef PEAO_H
#define PEAO_H

#include<objeto.h>

class Peao : public Objeto
{
public:
    Peao(int pecaTipo);
    void desenha(float colorR, float colorG,float colorB);
    void peao();
};

#endif // PEAO_H
