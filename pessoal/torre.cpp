#include "torre.h"

Torre::Torre(int pecaTipo)
{
    this->pecaTipo = pecaTipo;
}

void Torre::torre(){

    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(0);
    GUI::setColor(this->colorR,this->colorG,this->colorB,true);
    glTranslatef(0,1.45,0);
    cabecaTorre();
    glTranslatef(0,-1.45,0);

    glTranslatef(0,-0.35, 0);

    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, -1.8);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.47, 0.47, 0.15, 100, 60);

    glTranslatef(0, 0, 0.15);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.4, 0.4, 1, 60, 100);

    glTranslatef(0, 0, 1);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.57, 0.57, 0.15, 100, 60);

    glTranslatef(0, 0, 0.13);
    Desenha::gluClosedCylinder(gluNewQuadric(), 0.65, 0.65, 0.15, 100, 60);

    GUI::desabilitaTextura(true,false);

}

void Torre::desenha(float colorR, float colorG,float colorB){
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
    torre();
    glPopMatrix();
}

void Torre::cabecaTorre(){
    //frontal
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,0.2,0.5);
        glVertex3f(-0.5,0.2,0.5);
    glEnd();
    //traseira
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(-0.5,0,-0.5);
        glVertex3f(-0.5,0.2,-0.5);
        glVertex3f(0.5,0.2,-0.5);
        glVertex3f(0.5,0,-0.5);
    glEnd();
    //esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,0.2,0.5);
        glVertex3f(-0.5,0.2,-0.5);
        glVertex3f(-0.5,0,-0.5);
    glEnd();
    //direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,0.2,-0.5);
        glVertex3f(0.5,0.2,0.5);
    glEnd();
    //superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-0.5,0.2,0.5);
        glVertex3f(0.5,0.2,0.5);
        glVertex3f(0.5,0.2,-0.5);
        glVertex3f(-0.5,0.2,-0.5);
    glEnd();
    //inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,0,-0.5);
        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();

    //batente frente frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.3,0.2,0.5);
        glVertex3f(0.3,0.2,0.5);
        glVertex3f(0.3,0.4,0.5);
        glVertex3f(-0.3,0.4,0.5);
    glEnd();
    //batente frente esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-0.3,0.2,0.5);
        glVertex3f(-0.3,0.4,0.5);
        glVertex3f(-0.3,0.4,0.35);
        glVertex3f(-0.3,0.2,0.35);
    glEnd();
    //batente frente direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.3,0.2,0.5);
        glVertex3f(0.3,0.2,0.35);
        glVertex3f(0.3,0.4,0.35);
        glVertex3f(0.3,0.4,0.5);
    glEnd();
    //batente frente traseira
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(-0.3,0.2,0.35);
        glVertex3f(-0.3,0.4,0.35);
        glVertex3f(0.3,0.4,0.35);
        glVertex3f(0.3,0.2,0.35);
    glEnd();
    //batente frente superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-0.3,0.4,0.5);
        glVertex3f(0.3,0.4,0.5);
        glVertex3f(0.3,0.4,0.35);
        glVertex3f(-0.3,0.4,0.35);
    glEnd();

    //batente traz frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(-0.3,0.2,-0.5);
        glVertex3f(-0.3,0.4,-0.5);
        glVertex3f(0.3,0.4,-0.5);
        glVertex3f(0.3,0.2,-0.5);
    glEnd();
    //batente traz esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-0.3,0.2,-0.5);
        glVertex3f(-0.3,0.2,-0.35);
        glVertex3f(-0.3,0.4,-0.35);
        glVertex3f(-0.3,0.4,-0.5);
    glEnd();
    //batente frente direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.3,0.2,-0.5);
        glVertex3f(0.3,0.4,-0.5);
        glVertex3f(0.3,0.4,-0.35);
        glVertex3f(0.3,0.2,-0.35);
    glEnd();
    //batente traz traseira
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.3,0.2,-0.35);
        glVertex3f(0.3,0.2,-0.35);
        glVertex3f(0.3,0.4,-0.35);
        glVertex3f(-0.3,0.4,-0.35);
    glEnd();
    //batente traz superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-0.3,0.4,-0.5);
        glVertex3f(-0.3,0.4,-0.35);
        glVertex3f(0.3,0.4,-0.35);
        glVertex3f(0.3,0.4,-0.5);
    glEnd();

    //batente esquerda frente
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-0.5,0.2,0.3);
        glVertex3f(-0.5,0.4,0.3);
        glVertex3f(-0.5,0.4,-0.3);
        glVertex3f(-0.5,0.2,-0.3);
    glEnd();
    //batente esquerda traz
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(-0.35,0.2,0.3);
        glVertex3f(-0.35,0.2,-0.3);
        glVertex3f(-0.35,0.4,-0.3);
        glVertex3f(-0.35,0.4,0.3);
    glEnd();
    //batente esquerda direita
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.35,0.2,0.3);
        glVertex3f(-0.35,0.4,0.3);
        glVertex3f(-0.5,0.4,0.3);
        glVertex3f(-0.5,0.2,0.3);
    glEnd();
    //batente esquerda esquerda
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(-0.35,0.2,-0.3);
        glVertex3f(-0.5,0.2,-0.3);
        glVertex3f(-0.5,0.4,-0.3);
        glVertex3f(-0.35,0.4,-0.3);
    glEnd();
    //batente frente superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-0.5,0.4,0.3);
        glVertex3f(-0.35,0.4,0.3);
        glVertex3f(-0.35,0.4,-0.3);
        glVertex3f(-0.5,0.4,-0.3);
    glEnd();

    //batente direita frente
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.5,0.2,0.3);
        glVertex3f(0.5,0.2,-0.3);
        glVertex3f(0.5,0.4,-0.3);
        glVertex3f(0.5,0.4,0.3);
    glEnd();
    //batente direita traz
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(0.35,0.2,0.3);
        glVertex3f(0.35,0.4,0.3);
        glVertex3f(0.35,0.4,-0.3);
        glVertex3f(0.35,0.2,-0.3);
    glEnd();
    //batente direita direita
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(0.35,0.2,-0.3);
        glVertex3f(0.35,0.4,-0.3);
        glVertex3f(0.5,0.4,-0.3);
        glVertex3f(0.5,0.2,-0.3);
    glEnd();
    //batente direita esquerda
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(0.5,0.2,0.3);
        glVertex3f(0.5,0.4,0.3);
        glVertex3f(0.35,0.4,0.3);
        glVertex3f(0.35,0.2,0.3);
    glEnd();
    //batente frente superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(0.5,0.4,0.3);
        glVertex3f(0.5,0.4,-0.3);
        glVertex3f(0.35,0.4,-0.3);
        glVertex3f(0.35,0.4,0.3);
    glEnd();
}

