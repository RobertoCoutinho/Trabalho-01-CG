#include "rei.h"

Rei::Rei(int pecaTipo)
{
    this->pecaTipo = pecaTipo;
}

void Rei::rei(){
    glPushMatrix();

    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(0);
    GUI::setColor(this->colorR,this->colorG,this->colorB,true);

    glPushMatrix();

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
    glPopMatrix();

    glTranslatef(0, 2, 0);
    cruzRei();
    GUI::desabilitaTextura(true,false);
    glPopMatrix();
}

void Rei::desenha(float colorR, float colorG, float colorB){
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
    rei();
    glPopMatrix();
}

void Rei::cruzRei(){
    //vertical frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.05,0,0.05);
        glVertex3f(0.05,0,0.05);
        glVertex3f(0.05,0.4,0.05);
        glVertex3f(-0.05,0.4,0.05);
    glEnd();
    //vertical traz
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(-0.05,0,-0.05);
        glVertex3f(-0.05,0.4,-0.05);
        glVertex3f(0.05,0.4,-0.05);
        glVertex3f(0.05,0,-0.05);
    glEnd();
    //vertical esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-0.05,0,0.05);
        glVertex3f(-0.05,0.4,0.05);
        glVertex3f(-0.05,0.4,-0.05);
        glVertex3f(-0.05,0,-0.05);
    glEnd();
    //vertical direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.05,0,0.05);
        glVertex3f(0.05,0,-0.05);
        glVertex3f(0.05,0.4,-0.05);
        glVertex3f(0.05,0.4,0.05);
    glEnd();
    //vertical superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-0.05,0.4,0.05);
        glVertex3f(0.05,0.4,0.05);
        glVertex3f(0.05,0.4,-0.05);
        glVertex3f(-0.05,0.4,-0.05);
    glEnd();
    //horizontal frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.15,0.2,0.05);
        glVertex3f(0.15,0.2,0.05);
        glVertex3f(0.15,0.3,0.05);
        glVertex3f(-0.15,0.3,0.05);
    glEnd();
    //horizontal traz
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(-0.15,0.2,-0.05);
        glVertex3f(-0.15,0.3,-0.05);
        glVertex3f(0.15,0.3,-0.05);
        glVertex3f(0.15,0.2,-0.05);
    glEnd();
    //horizontal superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-0.15,0.3,0.05);
        glVertex3f(0.15,0.3,0.05);
        glVertex3f(0.15,0.3,-0.05);
        glVertex3f(-0.15,0.3,-0.05);
    glEnd();
    //horizontal inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(-0.15,0.2,0.05);
        glVertex3f(-0.15,0.2,-0.05);
        glVertex3f(0.15,0.2,-0.05);
        glVertex3f(0.15,0.2,0.05);
    glEnd();
    //horizontal direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.15,0.2,0.05);
        glVertex3f(0.15,0.2,-0.05);
        glVertex3f(0.15,0.3,-0.05);
        glVertex3f(0.15,0.3,0.05);
    glEnd();
    //horizontal esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-0.15,0.2,0.05);
        glVertex3f(-0.15,0.3,0.05);
        glVertex3f(-0.15,0.3,-0.05);
        glVertex3f(-0.15,0.2,-0.05);
    glEnd();
}
