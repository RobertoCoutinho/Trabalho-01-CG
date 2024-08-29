#ifndef REI_H
#define REI_H
#include <objeto.h>

class Rei : public Objeto
{
public:
    Rei(int pecaTipo);
    void desenha(float colorR, float colorG,float colorB);
    void cruzRei();
    void rei();
};

#endif // REI_H
