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
    void inicialitzaNormal();
    void inicialitzaTest(string fitxerInicial, string fitxerFigura, string fitxerMoviments);
    void inicialitza(const string& nomFitxer);
    bool giraFigura(DireccioGir direccio);
    int baixaCop();
    bool colisioFiguraTauler(Figura figura);
    bool jocAcabat();

    void dibuixa();
    void novaFigura();
    bool mouFigura(int dirX);
    int baixaFigura(bool& acabar);
    void colocarFigura();

private:
    Tauler m_tauler;
    Figura m_figura;



};

#endif