#include "Tauler.h"
IMAGE_NAME DeColorAFigura(ColorFigura color)
{
    switch (color)
    {
    case COLOR_GROC:
        return GRAFIC_QUADRAT_GROC;
    case COLOR_BLAUCEL:
        return GRAFIC_QUADRAT_BLAUCEL;
    case COLOR_MAGENTA:
        return GRAFIC_QUADRAT_MAGENTA;
    case COLOR_TARONJA:
        return GRAFIC_QUADRAT_TARONJA;
    case COLOR_BLAUFOSC:
        return GRAFIC_QUADRAT_BLAUFOSC;
    case COLOR_VERMELL:
        return GRAFIC_QUADRAT_VERMELL;
    case COLOR_VERD:
        return GRAFIC_QUADRAT_VERD;
    default:
        return GRAFIC_NUM_MAX;
    }
}

Tauler::Tauler()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
            m_tauler[i][j] = COLOR_NEGRE;
    }
}

void Tauler::copiaTauler(ColorFigura copiaTauler[MAX_FILA][MAX_COL])
{
    for (int i = 0; i < MAX_FILA; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            copiaTauler[i][j] = m_tauler[i][j];
        }
    }
}

void Tauler::insertarFigura(ColorFigura tauler[MAX_FILA][MAX_COL], Figura& figura)
{
    int tamany = figura.getTamany();
    int colf = figura.getCol();
    int filaf = figura.getFila();

    ColorFigura matriu[MAX_ALCADA][MAX_AMPLADA];
    figura.recuperarFigura(matriu);

    for (int i = 0; i < tamany; i++)
    {
        for (int j = 0; j < tamany; j++)
        {
            int fila = filaf + i;
            int columna = colf + j;
            if (fila >= 0 && columna >= 0 && fila < MAX_FILA && columna < MAX_COL)
            {
                if (matriu[i][j] != COLOR_NEGRE)
                    tauler[fila][columna] = matriu[i][j];
            }
        }
    }
}


void Tauler::actualitzaTauler(ColorFigura tauler[MAX_FILA][MAX_COL], Figura& figura)
{
    copiaTauler(tauler);
    insertarFigura(tauler, figura);
}


bool boreras(int col, int fila, int tamany, ColorFigura temp[][MAX_AMPLADA]) {
    if (col < 1)
    {
        for (int i = 0; i < tamany; i++)
        {
            if (temp[i][0] != COLOR_NEGRE)
            {
                return true;
            }
        }
    }

    if ((col + tamany) > MAX_COL + 1)
    {
        for (int i = 0; i < tamany; i++)
        {
            if (temp[i][MAX_COL - col + 1] != COLOR_NEGRE)
            {
                return true;
            }
        }
    }

    if ((fila + tamany) > MAX_FILA + 1)
    {
        for (int j = 0; j < tamany; j++)
        {
            if (temp[MAX_FILA - fila][j] != COLOR_NEGRE)
            {
                return true;
            }
        }
    }
    return false;
}

bool Tauler::chocaFigura(Figura& figura)
{
    ColorFigura temp[MAX_ALCADA][MAX_AMPLADA];
    figura.recuperarFigura(temp);

    int col = figura.getCol();
    int fila = figura.getFila();
    int tamany = figura.getTamany();

    bool borera = boreras(col, fila, tamany, temp);

    if (!borera)
    {
        for (int i = 0; i < tamany; i++)
        {
            for (int j = 0; j < tamany; j++)
            {
                if (temp[i][j] != COLOR_NEGRE && m_tauler[fila + i][col + j] != COLOR_NEGRE)
                {
                    borera = true;
                    break;
                }
            }
        }
    }
    return borera;
}

bool Tauler::comprovarFila(int fila)
{
    for (int j = 0; j < MAX_COL; j++)
    {
        if (m_tauler[fila][j] == COLOR_NEGRE)
            return false;
    }
    return true;
}


void Tauler::eliminarFila(int fila)
{
    for (int i = fila; i > 0; i--)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j] = m_tauler[i - 1][j];
        }
    }
    for (int k = 0; k < MAX_COL; k++)
    {
        m_tauler[0][k] = COLOR_NEGRE;
    }
}



int Tauler::eliminarFiles()
{
    int nEliminades = 0;

    for (int i = 0; i < MAX_FILA; i++)
    {
        if (comprovarFila(i))
        {
            eliminarFila(i);
            nEliminades++;
        }
    }
    return nEliminades;
}



void Tauler::dibuixa()
{
    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
    for (int i = 0; i < N_FILES_TAULER; i++)
    {
        for (int j = 0; j < N_COL_TAULER + 1; j++)
        {
            if (m_tauler[i][j] != COLOR_NEGRE)
                GraphicManager::getInstance()->drawSprite(DeColorAFigura(m_tauler[i][j]), POS_X_TAULER + (j * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false);
        }
    }
}