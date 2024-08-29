#include "tabuleiro.h"

Tabuleiro::Tabuleiro(int pecaTipo)
{
    this->pecaTipo = pecaTipo;
}

void Tabuleiro::desenha(){
    glPushMatrix();
    Objeto::desenha();

    int color = 0;
    for(int i=1; i<=8; i++){
      for(int j=1; j<=8; j++){
          if(color%2==0){
              GUI::setColor(0,0,0, 1,true);
              casaTaboleiro();
              glTranslatef(1, 0, 0);
          }
          else{
              GUI::setColor(1,1,1, 1,true);
              casaTaboleiro();
              glTranslatef(1, 0, 0);
          }
          color++;
      }
      glTranslatef(-8, 0, -1);
      color++;
    }
    glPopMatrix();
    glPushMatrix();
    bordaTabuleiro();
    glPopMatrix();
}

void Tabuleiro::casaTaboleiro(){
    //frontal
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,0.5);
        glVertex3f(-0.5,1,0.5);
    glEnd();
    //traseira
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(-0.5,0,-0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(0.5,0,-0.5);
    glEnd();
    //esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,1,0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,-0.5);
    glEnd();
    //direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(0.5,1,0.5);
    glEnd();
    //superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-0.5,1,0.5);
        glVertex3f(0.5,1,0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(-0.5,1,-0.5);
    glEnd();
    //inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,0,-0.5);
        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();
}

void Tabuleiro::bordaTabuleiro(){
    //frontal
    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(1);
    GUI::setColor(0.92,0.78,0.62,1);

    // fernte - frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glTexCoord2d(0,0);
        glVertex3f(-0.9,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(7.9,0,0.9);
        glTexCoord2d(1,1);
        glVertex3f(7.9,1.05,0.9);
        glTexCoord2d(0,1);
        glVertex3f(-0.9,1.05,0.9);
    glEnd();


    // fernte - trazeira
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glTexCoord2d(0,0);
        glVertex3f(-0.9,0,0.5);
        glTexCoord2d(1,0);
        glVertex3f(-0.9,1.05,0.5);
        glTexCoord2d(1,1);
        glVertex3f(7.9,1.05,0.5);
        glTexCoord2d(0,1);
        glVertex3f(7.9,0,0.5);
    glEnd();

    // fernte - topo
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.9,1.05,0.9);
        glTexCoord2d(1,0);
        glVertex3f(7.9,1.05,0.9);
        glTexCoord2d(1,1);
        glVertex3f(7.9,1.05,0.5);
        glTexCoord2d(0,1);
        glVertex3f(-0.9,1.05,0.5);
    glEnd();

    // fernte - inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.9,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(-0.9,0,0.5);
        glTexCoord2d(1,1);
        glVertex3f(7.9,0,0.5);
        glTexCoord2d(0,1);
        glVertex3f(7.9,0,0.9);
    glEnd();

    // direita - frente
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glTexCoord2d(0,0);
        glVertex3f(7.9,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(7.9,0,-7.9);
        glTexCoord2d(1,1);
        glVertex3f(7.9,1.05,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(7.9,1.05,0.9);
    glEnd();
    // direita - trazeira
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glTexCoord2d(0,0);
        glVertex3f(7.5,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(7.5,1.05,0.9);
        glTexCoord2d(1,1);
        glVertex3f(7.5,1.05,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(7.5,0,-7.9);
    glEnd();
    // direita - topo
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glTexCoord2d(0,0);
        glVertex3f(7.5,1.05,0.9);
        glTexCoord2d(1,0);
        glVertex3f(7.9,1.05,0.9);
        glTexCoord2d(1,1);
        glVertex3f(7.9,1.05,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(7.5,1.05,-7.9);
    glEnd();
    // direita - inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glTexCoord2d(0,0);
        glVertex3f(7.5,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(7.5,0,-7.9);
        glTexCoord2d(1,1);
        glVertex3f(7.9,0,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(7.9,0,0.9);
    glEnd();

    // esquerda - frente
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.9,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(-0.9,1.05,0.9);
        glTexCoord2d(1,1);
        glVertex3f(-0.9,1.05,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(-0.9,0,-7.9);
    glEnd();
    // esquerda - trazeira
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.5,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(-0.5,0,-7.9);
        glTexCoord2d(1,1);
        glVertex3f(-0.5,1.05,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(-0.5,1.05,0.9);
    glEnd();
    // esquerda - topo
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.5,1.05,0.9);
        glTexCoord2d(1,0);
        glVertex3f(-0.5,1.05,-7.9);
        glTexCoord2d(1,1);
        glVertex3f(-0.9,1.05,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(-0.9,1.05,0.9);
    glEnd();
    // esquerda - inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.5,0,0.9);
        glTexCoord2d(1,0);
        glVertex3f(-0.9,0,0.9);
        glTexCoord2d(1,1);
        glVertex3f(-0.9,0,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(-0.5,0,-7.9);
    glEnd();

    // trazeira - trazeira
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glTexCoord2d(0,0);
        glVertex3f(7.9,0,-7.9);
        glTexCoord2d(1,0);
        glVertex3f(-0.9,0,-7.9);
        glTexCoord2d(1,1);
        glVertex3f(-0.9,1.05,-7.9);
        glTexCoord2d(0,1);
        glVertex3f(7.9,1.05,-7.9);
    glEnd();
    // trazeira - frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glTexCoord2d(0,0);
        glVertex3f(7.9,0,-7.5);
        glTexCoord2d(1,0);
        glVertex3f(7.9,1.05,-7.5);
        glTexCoord2d(1,1);
        glVertex3f(-0.9,1.05,-7.5);
        glTexCoord2d(0,1);
        glVertex3f(-0.9,0,-7.5);
    glEnd();
    // trazeira - topo
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.9,1.05,-7.9);
        glTexCoord2d(1,0);
        glVertex3f(-0.9,1.05,-7.5);
        glTexCoord2d(1,1);
        glVertex3f(7.9,1.05,-7.5);
        glTexCoord2d(0,1);
        glVertex3f(7.9,1.05,-7.9);
    glEnd();
    // trazeira - inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glTexCoord2d(0,0);
        glVertex3f(-0.9,0,-7.9);
        glTexCoord2d(1,0);
        glVertex3f(7.9,0,-7.9);
        glTexCoord2d(1,1);
        glVertex3f(7.9,0,-7.5);
        glTexCoord2d(0,1);
        glVertex3f(-0.9,0,-7.5);
    glEnd();
    GUI::desabilitaTextura(true,false);
}

