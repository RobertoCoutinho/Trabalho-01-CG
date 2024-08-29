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
    centro_z = -20;

    olho_x = 3.5;
    olho_y = 4;
    olho_z = 0;

    up_x = 0;
    up_y = 1;
    up_z = 0;
}

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
}

void displayInner() {
    GUI::setLight(6,3.5,8,-3.5,true,false);
    GUI::setLight(6,3.5,8,-8,true,false);
    GUI::setLight(6,3.5,8,3,true,false);

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

        /*
        gluLookAt(
            glutGUI::cam->e.x,
            glutGUI::cam->e.y,
            glutGUI::cam->e.z,
            glutGUI::cam->c.x,
            glutGUI::cam->c.y,
            glutGUI::cam->c.z,
            glutGUI::cam->u.x,
            glutGUI::cam->u.y,
            glutGUI::cam->u.z);
        */

        gluLookAt(
            centro_x,centro_y,centro_z,
            olho_x, olho_y, olho_z,
            up_x,up_y,up_z);

        displayInner();

        if (!objetos.empty()) {
            glLoadIdentity();
            glViewport(0, 3*glutGUI::height/4, glutGUI::width/4, glutGUI::height/4);
            Vetor3D zlocalemCoordsGlobais = transformedPoint(Vetor3D(0,0,1));
            Vetor3D olho = objetos[0]->t + zlocalemCoordsGlobais*1.2;
            Vetor3D centro = olho + zlocalemCoordsGlobais;

            Vetor3D ylocalemCoordsGlobais = transformedPoint(Vetor3D(0,1,0));
            Vetor3D up = ylocalemCoordsGlobais;

            gluLookAt(olho.x,olho.y,olho.z, centro.x,centro.y,centro.z, up.x,up.y,up.z);
            displayInner();
        }


        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->t.x += 55 * glutGUI::dtx;
            objetos[posSelecionado]->t.y += 55 * glutGUI::dty;
            objetos[posSelecionado]->t.z += 55 * glutGUI::dtz;
            /*
            objetos[posSelecionado]->a.x += glutGUI::dax;
            objetos[posSelecionado]->a.y += glutGUI::day;
            objetos[posSelecionado]->a.z += glutGUI::daz;

            objetos[posSelecionado]->s.x += glutGUI::dsx;
            objetos[posSelecionado]->s.y += glutGUI::dsy;
            objetos[posSelecionado]->s.z += glutGUI::dsz;
            */
        }
    //    glutGUI::dtx = 0.0; glutGUI::dty = 0.0; glutGUI::dtz = 0.0;
    //    glutGUI::dax = 0.0; glutGUI::day = 0.0; glutGUI::daz = 0.0;
    //    glutGUI::dsx = 0.0; glutGUI::dsy = 0.0; glutGUI::dsz = 0.0;

        //objeto transformado
        //glPushMatrix();
    //        glTranslatef(glutGUI::tx,glutGUI::ty,glutGUI::tz);
    //        glRotatef(glutGUI::az,0,0,1);
    //        glRotatef(glutGUI::ay,0,1,0);
    //        glRotatef(glutGUI::ax,1,0,0);
    //        GUI::drawOrigin(1);
    //        glScalef(glutGUI::sx,glutGUI::sy,glutGUI::sz);
    //        GUI::setColor(0,0,1);
    //        //GUI::drawBox(0,0,0, 1,1,1);
    //        //GUI::drawBox(1,1,0, 2,2,1);
    //        //casa();
    //        //personagem();
    //        //GUI::draw3ds(model3ds);

        //glPopMatrix();

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
        break;
    case '2':
        defineCamera2();
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado = 16;
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


    case 'O':
        incluirObjeto = !incluirObjeto;
        break;
    case 'p':
        if (incluirObjeto) {
            //objetos.push_back( new Personagem() );
        }
        break;
    case 'x':
        if (incluirObjeto) {
            objetos.push_back( new Peao(1) );
        }
        break;
    case 'P':
        pause = !pause;
        break;
    case 'c':
        if (incluirObjeto) {
            //objetos.push_back( new Carro() );
        }
        break;
    case 'C':
        if (incluirObjeto) {
            //objetos.push_back( new Casa() );
        }
        break;
    case '4':
        if (incluirObjeto) {
            //objetos.push_back( new novoObjeto() );
        }
        break;
//    case 'i':
//        //glutGUI::tx = 0.0;
//        //glutGUI::ty = 0.0;
//        //glutGUI::tz = 0.0;
//        //glutGUI::ax = 0.0;
//        //glutGUI::ay = 0.0;
//        //glutGUI::az = 0.0;
//        //glutGUI::sx = 1.0;
//        //glutGUI::sy = 1.0;
//        //glutGUI::sz = 1.0;
//        //glutGUI::lx = 0.0;
//        //glutGUI::ly = 0.0;
//        //glutGUI::lz = 0.0;
//        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
//            objetos[posSelecionado]->t.x = 0.0;
//            objetos[posSelecionado]->t.y = 0.0;
//            objetos[posSelecionado]->t.z = 0.0;

//            objetos[posSelecionado]->a.x += glutGUI::dax;
//            objetos[posSelecionado]->a.y += glutGUI::day;
//            objetos[posSelecionado]->a.z += glutGUI::daz;

//            objetos[posSelecionado]->s.x += glutGUI::dsx;
//            objetos[posSelecionado]->s.y += glutGUI::dsy;
//            objetos[posSelecionado]->s.z += glutGUI::dsz;
//        }
//        break;

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
    iniciarPecas();
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenha,teclado);
}


//while(true) {
//    desenha();
//    interacaoUsuario();
//}
