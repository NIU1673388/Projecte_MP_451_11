#include "Joc.h"
#include <iostream>

using namespace std;

TipusFigura IntAFigura(int valor)
{
    switch (valor)
    {
    case 0:
        return FIGURA_O;
    case 1:
        return FIGURA_I;
    case 2:
        return FIGURA_T;
    case 3:
        return FIGURA_L;
    case 4:
        return FIGURA_J;
    case 5:
        return FIGURA_Z;
    case 6:
        return FIGURA_S;
    default:
        return NO_FIGURA;
    }
}

TipusFigura ColorAFigura(ColorFigura colorFigura)
{
    switch (colorFigura)
    {
    case COLOR_GROC:
        return FIGURA_O;
    case COLOR_BLAUCEL:
        return FIGURA_I;
    case COLOR_MAGENTA:
        return FIGURA_T;
    case COLOR_TARONJA:
        return FIGURA_L;
    case COLOR_BLAUFOSC:
        return FIGURA_J;
    case COLOR_VERMELL:
        return FIGURA_Z;
    case COLOR_VERD:
        return FIGURA_S;
    default:
        return NO_FIGURA;
    }
}


void Joc::inicialitzaNormal()
{

    novaFigura();
    for (int i = 0; i < MAX_FILA; i++)
        for (int j = 0; j < MAX_COL; j++)
            m_tauler.setCasella(COLOR_NEGRE, i, j);

}

void Joc::inicialitzaTest(string fitxerInicial, string fitxerFigura, string fitxerMoviments)
{

    ifstream fitxer(fitxerInicial);
    if (fitxer.is_open())
    {
        
    }

}


void Joc::inicialitza(const string& nomFitxer)
{
    ifstream fitxer(nomFitxer);
    if (fitxer.is_open())
    {
        int tipus, fila, col, orientacio;
        fitxer >> tipus >> fila >> col >> orientacio;

        TipusFigura tipusFigura;

        switch (tipus)
        {
        case 0:
            tipusFigura = NO_FIGURA;
            break;
        case 1:
            tipusFigura = FIGURA_O;
            break;
        case 2:
            tipusFigura = FIGURA_I;
            break;
        case 3:
            tipusFigura = FIGURA_T;
            break;
        case 4:
            tipusFigura = FIGURA_L;
            break;
        case 5:
            tipusFigura = FIGURA_J;
            break;
        case 6:
            tipusFigura = FIGURA_Z;
            break;
        case 7:
            tipusFigura = FIGURA_S;
            break;
        default:
            tipusFigura = NO_FIGURA;
            break;
        }

        m_figura.setCol(col - 1);
        m_figura.setFila(fila - 1);
        m_figura.inicialitza(tipusFigura);

        for (int i = 0; i < orientacio; i++)
        {
            m_figura.gir(GIR_HORARI);
        }
        int color;
        for (int i = 0; i < MAX_FILA; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
            {
                fitxer >> color;
                ColorFigura colorCasella;

                switch (color)
                {
                case 0:
                    colorCasella = COLOR_NEGRE;
                    break;
                case 1:
                    colorCasella = COLOR_GROC;
                    break;
                case 2:
                    colorCasella = COLOR_BLAUCEL;
                    break;
                case 3:
                    colorCasella = COLOR_MAGENTA;
                    break;
                case 4:
                    colorCasella = COLOR_TARONJA;
                    break;
                case 5:
                    colorCasella = COLOR_BLAUFOSC;
                    break;
                case 6:
                    colorCasella = COLOR_VERMELL;
                    break;
                case 7:
                    colorCasella = COLOR_VERD;
                    break;
                default:
                    colorCasella = NO_COLOR;
                    break;
                }

                m_tauler.setCasella(colorCasella, i, j);
            }
        }
    }
    fitxer.close();
}


void Joc::escriuTauler(const string& nomFitxer)
{
    ofstream fitxer;
    fitxer.open(nomFitxer);

    if (fitxer.is_open())
    {
        ColorFigura matriu_tauler[MAX_FILA][MAX_COL];
        m_tauler.actualitzaTauler(matriu_tauler, m_figura);

        for (int i = 0; i < MAX_FILA; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
            {
                fitxer << matriu_tauler[i][j];
            }
            fitxer << endl;
        }
        fitxer.close();
    }
}

void Joc::colocarFigura()
{
    ColorFigura copiaFigura[MAX_ALCADA][MAX_AMPLADA];
    m_figura.recuperarFigura(copiaFigura);
    int tamany = m_figura.getTamany();
    int col = m_figura.getCol();
    int fila = m_figura.getFila();

    for (int i = 0; i < tamany; i++)
    {
        for (int j = 0; j < tamany; j++)
        {
            if (copiaFigura[i][j] != COLOR_NEGRE)
                m_tauler.setCasella(copiaFigura[i][j], fila + i, col + j);
        }
    }
}

int Joc::baixaFigura(bool& acabar)
{
    int nEliminades = 0;
    Figura figura = m_figura;
    figura.baixada();
    bool choca = m_tauler.chocaFigura(figura);

    if (!choca)
        m_figura.baixada();
    else {
        acabar = true;
        colocarFigura();
        nEliminades = m_tauler.eliminarFiles();
        m_figura.inicialitza(NO_FIGURA);
    }
    return nEliminades;
}

bool Joc::mouFigura(int dirX)
{
    Figura figura = m_figura;

    figura.movimentLateral(dirX);

    if (m_tauler.chocaFigura(figura))
        return false;
    else {

        m_figura.movimentLateral(dirX);
        return true;
    }
}


bool Joc::giraFigura(DireccioGir direccio)
{
    Figura figura = m_figura;

    figura.gir(direccio);

    if (m_tauler.chocaFigura(figura))
        return false;
    else
        m_figura.gir(direccio);
    return true;
}


int Joc::baixaCop()
{
    int nEliminades = 0;
    Figura figura = m_figura;
    bool choca = false;

    do
    {
        figura.baixada();
        choca = m_tauler.chocaFigura(figura);

        if (!choca)
            m_figura.baixada();
        else {
            colocarFigura();
            nEliminades = m_tauler.eliminarFiles();
            m_figura.inicialitza(NO_FIGURA);
        }
    } while (!choca);
    return nEliminades;
}

bool Joc::colisioFiguraTauler(Figura figura)
{
    return m_tauler.chocaFigura(figura);
}

void Joc::dibuixa()
{
    m_tauler.dibuixa();
    m_figura.dibuixa();
}

void Joc::novaFigura()
{
    int valor = rand() % 7;
    m_figura.inicialitza(IntAFigura(valor));
    m_figura.setCol(5);
    m_figura.setFila(0);

}
bool Joc::jocAcabat()
{
    bool trobat = false;
    if (m_figura.getFila() - 1 <= 0)
    {
        trobat = true;
    }
    return trobat;
}