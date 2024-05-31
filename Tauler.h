#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
    Tauler();

    void setCasella(ColorFigura color, int col, int fila) { m_tauler[col][fila] = color; }

    void copiaTauler(ColorFigura tauler[MAX_FILA][MAX_COL]);
    void insertarFigura(ColorFigura tauler[MAX_FILA][MAX_COL], Figura& figura);
    void actualitzaTauler(ColorFigura tauler[MAX_FILA][MAX_COL], Figura& figura);
    bool chocaFigura(Figura& figura);
    int eliminarFiles();
    bool comprovarFila(int fila);
    void eliminarFila(int fila);


private:

    ColorFigura m_tauler[MAX_FILA][MAX_COL];
};
#endif