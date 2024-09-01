#include "cavalo.h"

Cavalo::Cavalo(int pecaTipo)
{
    this->pecaTipo = pecaTipo;
    model = new Model3DS("../3ds/horse.3ds");
}

void Cavalo::cavalo(){
    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(0);
    GUI::setColor(this->colorR,this->colorG,this->colorB,true);
    cavalo3DS();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, -0.3);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.57, 0.57, 0.15, 100, 60);

    glTranslatef(0, 0, 0.13);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.65, 0.65, 0.15, 100, 60);

    GUI::desabilitaTextura(true,false);
}

void Cavalo::cavalo3DS(){
    glPushMatrix();
    glTranslatef(0,1.13,0);
    glRotatef(-90,1,0,0);
    glScalef(0.01,0.01,0.01);
    model->draw(false);
    glPopMatrix();
}

void Cavalo::desenha(float colorR, float colorG, float colorB){
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
    cavalo();
    glPopMatrix();
}
