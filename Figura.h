#ifndef FIGURA_H
#define FIGURA_H
#include "GraphicManager.h"
#include "InfoJoc.h"
#include <iostream>

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

class Figura
{
public:
    Figura();

    void setTipus(int tipus);
    void setCol(int col) { m_col = col; }
    void setFila(int fila) { m_fila = fila; }
    void setOrientacio(int orien) { m_orientacio = orien; }
    void setTamany(int tamany) { m_tamany = tamany; }

    ColorFigura getColor() { return m_color; }
    TipusFigura getTipus() { return m_tipus; }
    int getFila() { return m_fila; }
    int getCol() { return m_col; }
    int getOrientacio() { return m_orientacio; }
    int getTamany() { return m_tamany; }
    void recuperarFigura(ColorFigura matriu[MAX_ALCADA][MAX_AMPLADA]);

    void inicialitza(TipusFigura figura);
    void movimentLateral(int col);
    void baixada();
    void gir(DireccioGir gir);
    void dibuixa();
    void transposar();
    void girHorari();
    void girAntihorari();



private:

    TipusFigura m_tipus;
    ColorFigura m_color;
    int m_fila, m_col;
    ColorFigura m_forma[MAX_ALCADA][MAX_AMPLADA];
    int m_tamany;
    int m_orientacio;
};


#endif
