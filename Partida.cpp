#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"
#include <vector>

Partida::Partida()
{
    m_nivell = 0;
    m_punts = 0;
    m_temps = 0;
    m_acabar = false;
    m_velocitat = 1.00;
}

void Partida::actualitza(int mode, double deltaTime)
{
    m_temps += deltaTime;
    if (mode == 1)
    {
        bool finalitzatFigura = false;
        int filesFetes = 0;
        int key = -1;

        if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
            key = KEYBOARD_RIGHT;
        else if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
            key = KEYBOARD_LEFT;
        else if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
            key = KEYBOARD_DOWN;
        else if (Keyboard_GetKeyTrg(KEYBOARD_UP))
            key = KEYBOARD_UP;
        else if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
            key = KEYBOARD_SPACE;
        else if (Keyboard_GetKeyTrg(KEYBOARD_M))
            key = KEYBOARD_M;
        switch (key)
        {
        case KEYBOARD_RIGHT:
            m_joc.mouFigura(1);
            break;
        case KEYBOARD_LEFT:
            m_joc.mouFigura(-1);
            break;
        case KEYBOARD_DOWN:
            m_joc.giraFigura(GIR_ANTI_HORARI);
            break;
        case KEYBOARD_UP:
            m_joc.giraFigura(GIR_HORARI);
            break;
        case KEYBOARD_SPACE:
            while (!finalitzatFigura)
                filesFetes = m_joc.baixaFigura(finalitzatFigura);
            break;
        case KEYBOARD_M:
            m_joc.baixaFigura(finalitzatFigura);
            break;
        default:
            break;
        }
        if (m_temps > m_velocitat)
        {
            m_temps = 0;
            filesFetes = m_joc.baixaFigura(finalitzatFigura);
        } if (finalitzatFigura)
        {
            if (m_joc.jocAcabat())
                      m_acabar = true;
            else
            {
                actualitzarPunts(filesFetes);
                m_joc.novaFigura();
            }
        }
        m_joc.dibuixa();
    }

}

void Partida::inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments)
{
    if (mode == 1)
    {
        m_joc.inicialitzaNormal();
    }
    else if (mode == 2)
    {
        m_joc.inicialitzaTest(fitxerInicial, fitxerFigures, fitxerMoviments);
    }

}
void Partida::actualitzarPunts(int filesFetes)
{
    switch (filesFetes)
    {
    case 0:
        m_punts += 10;
        break;
    case 1:
        m_punts += 100;
        break;
    case 2:
        m_punts += 150;
        break;
    case 3:
        m_punts += 175;
        break;
    case 4:
        m_punts += 200;
        break;
    }
    if (m_punts > 1000)
    {
        m_velocitat -= 0.1;
        m_nivell++;
    }
}

vector<int> leerPuntuaciones(const string& nombreFichero)
{
    vector<int> puntuaciones;
    ifstream ficheroEntrada(nombreFichero);
    int puntuacion;

    while (ficheroEntrada >> puntuacion)
    {
        puntuaciones.push_back(puntuacion);
    }

    ficheroEntrada.close();
    return puntuaciones;
}

void guardarPuntuaciones(const string& nombreFichero, const vector<int>& puntuaciones)
{
    ofstream ficheroSalida(nombreFichero);

    for (int puntuacion : puntuaciones)
    {
        ficheroSalida << puntuacion << endl;
    }

    ficheroSalida.close();
}

void ordenarPuntuaciones(vector<int>& puntuaciones)
{
    for (size_t i = 0; i < puntuaciones.size(); ++i)
    {
        for (size_t j = i + 1; j < puntuaciones.size(); ++j)
        {
            if (puntuaciones[j] > puntuaciones[i])
            {
                int temp = puntuaciones[i];
                puntuaciones[i] = puntuaciones[j];
                puntuaciones[j] = temp;
            }
        }
    }
}

void actualizarPuntuaciones(const string& nombreFichero, int nuevaPuntuacion)
{

    vector<int> puntuaciones = leerPuntuaciones(nombreFichero);

    puntuaciones.push_back(nuevaPuntuacion);

    ordenarPuntuaciones(puntuaciones);

    if (puntuaciones.size() > 10)
    {
        puntuaciones.resize(10);
    }

    guardarPuntuaciones(nombreFichero, puntuaciones);
}

void Partida::Puntuacions()
{
    const string nombreFichero = "Rank.txt";
    actualizarPuntuaciones(nombreFichero, m_punts);
}



