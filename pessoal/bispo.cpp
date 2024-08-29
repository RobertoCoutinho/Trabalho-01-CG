#include "bispo.h"

Bispo::Bispo(int pecaTipo)
{
    this->pecaTipo = pecaTipo;
}

void Bispo::bispo(){

    glTranslatef(0,-0.35, 0);
    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(0);
    GUI::setColor(this->colorR,this->colorG,this->colorB,true);

    GUI::drawSphere(0,2.51,0, 0.12);

    GUI::drawSphere(0,2.15,0, 0.3);

    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, -1.8);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.33, 0.33, 0.15, 100, 60);

    glTranslatef(0, 0, 0.15);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.13, 0.40, 1, 60, 100);

    glTranslatef(0, 0, 1);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.5, 0.5, 0.15, 100, 60);

    glTranslatef(0, 0, 0.13);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.6, 0.6, 0.15, 100, 60);

    glTranslatef(0, 0, -1.39);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.27, 0.27, 0.15, 100, 60);

    GUI::desabilitaTextura(true,false);
}

void Bispo::desenha(float colorR, float colorG,float colorB){
    glPushMatrix();
    Objeto::desenha();
    if (selecionado) {
        this->colorR = 0;
        this->colorG = 1;
        this->colorB = 1;
    }
    else {
        this->colorR = colorR;
        this->colorG = colorG;
        this->colorB = colorB;
    }
    bispo();
    glPopMatrix();
}
