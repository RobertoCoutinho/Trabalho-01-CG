#include "peao.h"

Peao::Peao(int pecaTipo)
{
    this->pecaTipo = pecaTipo;
}

void Peao::peao(){
    glTranslatef(0,-0.35, 0);
    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(0);
    GUI::setColor(this->colorR,this->colorG,this->colorB,true);

    GUI::drawSphere(0,2,0, 0.3);
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, -1.8);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.33, 0.33, 0.15, 100, 60);

    glTranslatef(0, 0, 0.15);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.17, 0.5, 1, 60, 100);

    glTranslatef(0, 0, 1);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.57, 0.57, 0.15, 100, 60);

    glTranslatef(0, 0, 0.13);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.65, 0.65, 0.15, 100, 60);

    GUI::desabilitaTextura(true,false);
}

void Peao::desenha(float colorR, float colorG,float colorB){
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
    peao();
    glPopMatrix();

}
