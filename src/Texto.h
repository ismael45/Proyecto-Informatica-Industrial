#pragma once
#include "freeglut.h"
#include <string>

class Texto {
private:
    int posX;
    int posY;
    std::string texto;
    void* font;

public:
    Texto(int tableroPosX, int tableroPosY) {
        posX = tableroPosX + 350; // Ajustamos la posición x para que el texto esté centrado
        posY = tableroPosY + 550; // Ajustamos la posición y para que el texto esté encima del tablero
        texto = "AJEDREZ";
        font = GLUT_BITMAP_TIMES_ROMAN_24;
    }

    void dibujar() {
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0.0, glutGet(GLUT_WINDOW_WIDTH), 0.0, glutGet(GLUT_WINDOW_HEIGHT));
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH_TEST);

        glColor3f(0.0f, 0.0f, 0.0f); // Color blanco para el texto
        glRasterPos2i(posX, posY);
        for (std::string::iterator i = texto.begin(); i != texto.end(); ++i) {
            char c = *i;
            glutBitmapCharacter(font, c);
        }

        glEnable(GL_LIGHTING);
        glEnable(GL_DEPTH_TEST);
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
    }
};
