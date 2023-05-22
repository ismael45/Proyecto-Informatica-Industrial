#include "Menu.h"
using namespace std;

void Menu::dibuja_Fondo() {
    sprite = { "bin/imagenes/etsidi.png", posicion.x + 0.07f, posicion.y - 0.03f, 70, 70 };

    glPushMatrix();
    glTranslatef(0, 0, 0);
    sprite.draw();
    glPopMatrix();
}


void Menu::dibuja_opcion_1() {
    sprite = { "bin/imagenes/1v1.png", posicion.x + 0.07f, posicion.y - 0.03f, 10, 10 };

    glPushMatrix();
    glTranslatef(-20, 17, 3);
    sprite.draw();
    glPopMatrix();
}

void Menu::dibuja_opcion_2() {
    sprite = { "bin/imagenes/1vpc.png", posicion.x + 0.07f, posicion.y - 0.03f, 10, 10 };

    glPushMatrix();
    glTranslatef(20, 17, 3);
    sprite.draw();
    glPopMatrix();
}

void Menu::dibuja_texto() {
    sprite = { "bin/imagenes/ajedrez.png", posicion.x + 0.07f, posicion.y - 0.03f, 20, 10 };

    glPushMatrix();
    glTranslatef(0, 20, 3);
    sprite.draw();
    glPopMatrix();
}

int Menu::detectarClic(int x, int y) {
   
    POINT cursor;
    GetCursorPos(&cursor);
    x = cursor.x;
    y = cursor.y;
    bool botonPresionado = (GetAsyncKeyState(VK_LBUTTON) & 0x8000);

    if (263 <= x && x <= 350 && 177 <= y && y <= 245 && botonPresionado) {
        cout << "Opcion 1" << endl;
        return 1;

    }
    else if (731 <= x && x <= 814 && 177 <= y && y <= 245 && botonPresionado) {
        cout << "Opcion 2" << endl;
        return 2;
    }
    else return 0;
}





