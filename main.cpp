#include <iostream>

using namespace std;

#include <vector>
#include <peao.h>
#include <tabuleiro.h>
#include <bispo.h>
#include <torre.h>
#include <rei.h>
#include <rainha.h>
#include <cavalo.h>

//Model3DS model3ds("../3ds/cartest.3DS");

vector<Objeto*> objetos;
Objeto* tabuleiro = new Tabuleiro(0);
int posSelecionado = -1;
bool pause = false;

float centro_x = 3.5;
float centro_y = 14;
float centro_z = 10;

float olho_x = 3.5;
float olho_y = 4;
float olho_z = 0;

float up_x = 0;
float up_y = 1;
float up_z = 0;

int direcao_translacao = 1;
bool define_camera_livre = false;

void defineCamera1(){
    centro_x = 3.5;
    centro_y = 14;
    centro_z = 10;

    olho_x = 3.5;
    olho_y = 4;
    olho_z = 0;

    up_x = 0;
    up_y = 1;
    up_z = 0;
}

void defineCamera2(){
    centro_x = 3.5;
    centro_y = 14;
    centro_z = -17;

    olho_x = 3.5;
    olho_y = 4;
    olho_z = -7;

    up_x = 0;
    up_y = 1;
    up_z = 0;

}

/*
Vetor3D transformedPoint(Vetor3D p)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glRotatef(objetos[0]->a.z,0,0,1);
    glRotatef(objetos[0]->a.y,0,1,0);
    glRotatef(objetos[0]->a.x,1,0,0);

    float matrix[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
    glPopMatrix();

    float pos[4] = {p.x,p.y,p.z, 1.0};
    float res[4];

    glutGUI::multGLMatrixByVector(res,matrix,pos);

    Vetor3D res3D = Vetor3D(res[0],res[1],res[2]);
    return res3D;
}*/

void displayInner() {
    GUI::setLight(6,3.5,8,-3.5,true,false);

    glPushMatrix();
    tabuleiro->desenha();
    glPopMatrix();

    //peoes brancos
    glPushMatrix();
    glTranslatef(0,1,-1);
    glScalef(0.5,0.5,0.5);
    for (int i = 0; i < objetos.size(); ++i) {
        if(objetos[i]->pecaTipo == 1){
            static_cast<Peao*>(objetos[i])->desenha(1.0,1.0,1.0);
            glTranslatef(2,0,0);
        }
    }
    glPopMatrix();

    //Bispos Brancos
    glPushMatrix();
    glTranslatef(2,1,0);
    for (int i = 0; i < objetos.size(); ++i) {
        if(objetos[i]->pecaTipo == 3){
            glPushMatrix();
            glScalef(0.5,0.5,0.5);
            static_cast<Bispo*>(objetos[i])->desenha(1.0,1.0,1.0);
            glPopMatrix();
            glTranslatef(3,0,0);
        }
    }
    glPopMatrix();

    //Torres Brancas
    glPushMatrix();
    glTranslatef(0,1,0);
    for (int i = 0; i < objetos.size(); ++i) {
        if(objetos[i]->pecaTipo == 5){
            glPushMatrix();
            glScalef(0.5,0.5,0.5);
            static_cast<Torre*>(objetos[i])->desenha(1.0,1.0,1.0);
            glPopMatrix();
            glTranslatef(7,0,0);
        }
    }
    glPopMatrix();

    //Cavalos Brancos
    glPushMatrix();
    glTranslatef(1,1,0);
    for (int i = 0; i < objetos.size(); ++i) {
        if(objetos[i]->pecaTipo == 11){
            glPushMatrix();
            glScalef(0.5,0.5,0.5);
            static_cast<Cavalo*>(objetos[i])->desenha(1.0,1.0,1.0);
            glPopMatrix();
            glTranslatef(5,0,0);
        }
    }
    glPopMatrix();

    //Rei Branco
    glPushMatrix();
    glTranslatef(3,1,0);
    glScalef(0.5,0.63,0.5);
    for (int i = 0; i < objetos.size(); ++i) {
        if(objetos[i]->pecaTipo == 7){
            static_cast<Rei*>(objetos[i])->desenha(1.0,1.0,1.0);
        }
    }
    glPopMatrix();

    //Rainha Branco
    glPushMatrix();
    glTranslatef(4,1,0);
    glScalef(0.5,0.63,0.5);
    for (int i = 0; i < objetos.size(); ++i) {
        if(objetos[i]->pecaTipo == 9){
            static_cast<Rainha*>(objetos[i])->desenha(1.0,1.0,1.0);
        }
    }
    glPopMatrix();

    //peoes pretos
    glPushMatrix();
    glTranslatef(0,1,-6);
    glScalef(0.5,0.5,0.5);
    for (int i = 0; i < objetos.size(); ++i) {
        if(objetos[i]->pecaTipo == 2){
            static_cast<Peao*>(objetos[i])->desenha(0.2,0.2,0.2);
            glTranslatef(2,0,0);
        }
    }
    glPopMatrix();

    //Bispos Pretos
    glPushMatrix();
    glTranslatef(2,1,-7);
    for (int i = 0; i < objetos.size(); ++i) {
        if(objetos[i]->pecaTipo == 4){
            glPushMatrix();
            glScalef(0.5,0.5,0.5);
            static_cast<Bispo*>(objetos[i])->desenha(0.2,0.2,0.2);
            glPopMatrix();
            glTranslatef(3,0,0);
        }
    }
    glPopMatrix();

    //Torres Pretas
    glPushMatrix();
    glTranslatef(0,1,-7);
    for (int i = 0; i < objetos.size(); ++i) {
        if(objetos[i]->pecaTipo == 6){
            glPushMatrix();
            glScalef(0.5,0.5,0.5);
            static_cast<Torre*>(objetos[i])->desenha(0.2,0.2,0.2);
            glPopMatrix();
            glTranslatef(7,0,0);
        }
    }
    glPopMatrix();

    //Rei Preto
    glPushMatrix();
    glTranslatef(3,1,-7);
    glScalef(0.5,0.63,0.5);
    for (int i = 0; i < objetos.size(); ++i) {
        if(objetos[i]->pecaTipo == 8){
            static_cast<Rei*>(objetos[i])->desenha(0.2,0.2,0.2);
        }
    }
    glPopMatrix();

    //Rainha Preto
    glPushMatrix();
    glTranslatef(4,1,-7);
    glScalef(0.5,0.63,0.5);
    for (int i = 0; i < objetos.size(); ++i) {
        if(objetos[i]->pecaTipo == 10){
            static_cast<Rainha*>(objetos[i])->desenha(0.2,0.2,0.2);
        }
    }
    glPopMatrix();

    //Cavalos pretos
    glPushMatrix();
    glTranslatef(1,1,-7);
    for (int i = 0; i < objetos.size(); ++i) {
        if(objetos[i]->pecaTipo == 12){
            glPushMatrix();
            glScalef(0.5,0.5,0.5);
            static_cast<Cavalo*>(objetos[i])->desenha(0.2,0.2,0.2);
            glPopMatrix();
            glTranslatef(5,0,0);
        }
    }
    glPopMatrix();
}

void desenha() {
    if (!pause) {
        GUI::displayInit();

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        if(define_camera_livre){
            gluLookAt(
                glutGUI::cam->e.x, glutGUI::cam->e.y, glutGUI::cam->e.z,
                glutGUI::cam->c.x, glutGUI::cam->c.y, glutGUI::cam->c.z,
                glutGUI::cam->u.x, glutGUI::cam->u.y, glutGUI::cam->u.z);
        }
        else{
            gluLookAt(
                centro_x,centro_y,centro_z,
                olho_x, olho_y, olho_z,
                up_x, up_y, up_z);
        }

        displayInner();

        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->t.x += 55 * (direcao_translacao * glutGUI::dtx);
            objetos[posSelecionado]->t.y += 55 * (direcao_translacao * glutGUI::dty);
            objetos[posSelecionado]->t.z += 55 * (direcao_translacao * glutGUI::dtz);
        }
        GUI::displayEnd();
    }
}

bool incluirObjeto = false;

void teclado(unsigned char key, int x, int y) {
    if (!incluirObjeto) {
        GUI::keyInit(key,x,y);
    }

    switch (key) {
    case '1':
        defineCamera1();
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado = -1;
        direcao_translacao = 1;
        break;
    case '2':
        defineCamera2();
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado = 16;
        direcao_translacao = -1;
        break;
    case 'c':
        define_camera_livre = !define_camera_livre;
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;

    case 'n':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado++;
        posSelecionado = posSelecionado%objetos.size();
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;
    case 'b':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado--;
        if (posSelecionado < 0) {
            posSelecionado = objetos.size()-1;
        }
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;
    default:
        break;
    }
}

void iniciarPecas(){
    //Torre preta
    objetos.push_back( new Torre(6) );
    //Cavalo preto
    objetos.push_back(new Cavalo(12));
    //Bispo preto
    objetos.push_back( new Bispo(4) );
    //Rei Preto
    objetos.push_back( new Rei(8) );
    //Rainha Preta
    objetos.push_back( new Rainha(10) );
    //Bispo preto
    objetos.push_back( new Bispo(4) );
    //Cavalo preto
    objetos.push_back(new Cavalo(12));
    //Torre preta
    objetos.push_back( new Torre(6) );
    //Peoes pretos
    for(int i = 0; i < 8; i++){
        objetos.push_back( new Peao(2) );
    }

    //Torre branca
    objetos.push_back( new Torre(5) );
    //Cavalo branco
    objetos.push_back(new Cavalo(11));
    //Bispo branco
    objetos.push_back( new Bispo(3) );
    //Rei Branco
    objetos.push_back( new Rei(7) );
    //Rainha Branca
    objetos.push_back( new Rainha(9) );
    //Bispo branco
    objetos.push_back( new Bispo(3) );
    //Cavalo branco
    objetos.push_back(new Cavalo(11));
    //Torre branca
    objetos.push_back( new Torre(5) );
    //Peoes brancos
    for(int i = 0; i < 8; i++){
        objetos.push_back( new Peao(1) );
    }
}

int main()
{
    glutGUI::trans_obj = true;
    iniciarPecas();
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenha,teclado);
}


//while(true) {
//    desenha();
//    interacaoUsuario();
//}
