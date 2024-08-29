#ifndef TORRE_H
#define TORRE_H
#include<objeto.h>

class Torre : public Objeto
{
public:
    Torre(int pecaTipo);
    void desenha(float colorR, float colorG,float colorB);
    void cabecaTorre();
    void torre();
};

#endif // TORRE_H
