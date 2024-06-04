#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>
#include "InfoJoc.h"
#include "Joc.h"

using namespace std;

class Partida
{
public:
    Partida();

    void actualitza(int mode, double deltaTime);
    void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
    Joc getJoc() { return m_joc; }
    bool getPartidaAcabada() { return m_acabar; }
    int getPuntuacio() { return m_punts; }
    int getNivell() { return m_nivell; }
    void actualitzarPunts(int filesFetes);
    void Puntuacions();

private:

    double m_temps;
    double m_velocitat;
    static const int MIDA = 4;
    Joc m_joc;
    ColorFigura m_forma[MIDA][MIDA];
    int m_fila, m_columna, m_punts, m_nivell;
    bool m_acabar;
};

#endif