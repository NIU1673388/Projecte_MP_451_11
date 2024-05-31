#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>
#include <fstream>
using namespace std;

class Joc
{
public:

    Joc() {};
    void escriuTauler(const string& nomFitxer);
    void inicialitza(const string& nomFitxer);
    bool giraFigura(DireccioGir direccio);
    bool mouFigura(int dirX);
    int baixaFigura();
    void colocarFigura();

private:
    Tauler m_tauler;
    Figura m_figura;

};

#endif