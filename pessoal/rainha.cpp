#include "rainha.h"

Rainha::Rainha(int pecaTipo)
{
    this->pecaTipo = pecaTipo;
}

void Rainha::rainha(){
    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(0);
    glPushMatrix();

    GUI::setColor(this->colorR,this->colorG,this->colorB,true);


    glRotatef(-90, 1, 0, 0);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.65, 0.65, 0.15, 100, 60);

    glTranslatef(0, 0, 0.15);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.57, 0.57, 0.15, 100, 60);

    glTranslatef(0, 0, 0.15);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.46, 0.23, 1.15, 60, 100);

    glTranslatef(0, 0, 1.1);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.33, 0.33, 0.15, 100, 60);

    glTranslatef(0, 0, 0.15);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.23, 0.38, 0.35, 60, 100);

    glTranslatef(0, 0, 0.35);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.32, 0.06, 0.20, 60, 100);
    GUI::desabilitaTextura(true,false);
    glPopMatrix();
    glPushMatrix();

    GUI::drawSphere(0, 2.15, 0, 0.1);
    glPopMatrix();
}

void Rainha::desenha(float colorR, float colorG,float colorB){
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
    rainha();
    glPopMatrix();
}
