#include "tetris.h"
#include <iostream>
#include <fstream>
#include <windows.h>

int Tetris::mostraMenu()
{
    int opcio = 0;
    cout << "--------------TETRIS--------------" << endl;
    cout << "1.Normal" << endl;
    cout << "2.Mode Test" << endl;
    cout << "3.Mostrar Puntuacions " << endl;
    cout << "4.Sortir" << endl;
    cout << "-----------------------------------" << endl;
    cout << " Seleccio: ";
    cin >> opcio;
    return opcio;
}

void Tetris::inicialitzaJoc(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments)
{
    m_partida.inicialitza(mode, fitxerInicial, fitxerFigures, fitxerMoviments);
}

bool Tetris::juga(int mode, double deltaTime)
{
    if (mode == 1)
    {
        if (!m_partida.getPartidaAcabada())
        {
            m_partida.actualitza(mode, deltaTime);
            string msg = "Punts: " + to_string(m_partida.getPuntuacio()) + ", Nivell: " + to_string(m_partida.getNivell());
            GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, msg);
        }
        else
        {
            m_partida.Puntuacions();
            m_partida.getJoc().dibuixa();
            string PyN = "Punts: " + to_string(m_partida.getPuntuacio()) + ", Nivell: " + to_string(m_partida.getNivell());
            GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, PyN);
            GraphicManager::getInstance()->drawFont(FONT_WHITE_30, SCREEN_SIZE_X / 2 - 180, SCREEN_SIZE_Y / 2 - 50, 2.0, "GAME OVER!!");
        }
        return m_partida.getPartidaAcabada();
    }
    else if (mode == 2)
    {
        exit(0);
    }
    else if (mode == 3)
    {
        ifstream fitxer("Rank.txt");

        if (!fitxer.is_open()) 
        {
            cerr << "Error. No s'ha obert l'archiu"<< endl;
        }

        string linea;
        while (fitxer.eof()) 
        {
            cout << linea << endl;
        }

        fitxer.close();
    }
    else if (mode == 4)
    {
        exit(0);
    }
    else
    {
        cout << "Mode secret no desbloquejat";
        cin.get();
        cin.get();
        exit(0);
    }
}

