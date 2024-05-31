#ifndef FIGURA_H
#define FIGURA_H

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC = 1,
    COLOR_BLAUCEL = 2,
    COLOR_MAGENTA = 3,
    COLOR_TARONJA = 4,
    COLOR_BLAUFOSC = 5,
    COLOR_VERMELL = 6,
    COLOR_VERD = 7,
    NO_COLOR = 8
} ColorFigura;


typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O = 1,
    FIGURA_I = 2,
    FIGURA_T = 3,
    FIGURA_L = 4,
    FIGURA_J = 5,
    FIGURA_Z = 6,
    FIGURA_S = 7
} TipusFigura;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

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

    void inicialitza(TipusFigura figura, int col, int fila);
    void movimentLateral(int col);
    void baixada();
    void gir(DireccioGir gir);
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