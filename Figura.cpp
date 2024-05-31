#include "Figura.h"

ColorFigura TipusAColor(TipusFigura tipus) {
	switch (tipus)
	{
	case FIGURA_O:
		return COLOR_GROC;
	case FIGURA_I:
		return COLOR_BLAUCEL;
	case FIGURA_T:
		return COLOR_MAGENTA;
	case FIGURA_L:
		return COLOR_TARONJA;
	case FIGURA_J:
		return COLOR_BLAUFOSC;
	case FIGURA_Z:
		return COLOR_VERMELL;
	case FIGURA_S:
		return COLOR_VERD;
	default:
		return NO_COLOR;
	}
}


Figura::Figura()
{
	m_col = 0;
	m_fila = 0;
	m_color = NO_COLOR;
	m_tipus = NO_FIGURA;
	m_tamany = 0;
	m_orientacio = 0;

	for (int i = 0; i < MAX_ALCADA; i++)
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			m_forma[i][j] = m_color;
		}
	}
}

void Figura::recuperarFigura(ColorFigura matriu[MAX_ALCADA][MAX_AMPLADA])
{
	for (int i = 0; i < m_tamany; i++)
	{
		for (int j = 0; j < m_tamany; j++)
		{
			matriu[i][j] = m_forma[i][j];
		}
	}
}


void Figura::baixada() {
	m_fila++;
}

void Figura::movimentLateral(int dirX) {
	m_col += dirX;
}


void Figura::inicialitza(TipusFigura figura, int col, int fila) {

	m_color = TipusAColor(figura);
	ColorFigura matriu[MAX_AMPLADA][MAX_ALCADA];

	for (int i = 0; i < MAX_AMPLADA; i++)
	{
		for (int j = 0; j < MAX_ALCADA; j++)
			matriu[i][j] = COLOR_NEGRE;
	}

	switch (figura)
	{
	case NO_FIGURA:
		m_tamany = 0;
		break;

	case FIGURA_T:
		m_tamany = 3;

		matriu[0][1] = COLOR_MAGENTA;
		matriu[1][0] = COLOR_MAGENTA;
		matriu[1][1] = COLOR_MAGENTA;
		matriu[1][2] = COLOR_MAGENTA;

		break;

	case FIGURA_Z:
		m_tamany = 3;

		matriu[0][0] = COLOR_VERMELL;
		matriu[0][1] = COLOR_VERMELL;
		matriu[1][1] = COLOR_VERMELL;
		matriu[1][2] = COLOR_VERMELL;
		break;

	case FIGURA_S:
		m_tamany = 3;

		matriu[0][1] = COLOR_VERD;
		matriu[0][2] = COLOR_VERD;
		matriu[1][0] = COLOR_VERD;
		matriu[1][1] = COLOR_VERD;
		break;

	case FIGURA_O:
		m_tamany = 2;

		matriu[0][0] = COLOR_GROC;
		matriu[0][1] = COLOR_GROC;
		matriu[1][0] = COLOR_GROC;
		matriu[1][1] = COLOR_GROC;
		break;

	case FIGURA_I:
		m_tamany = 4;
		matriu[1][0] = COLOR_BLAUCEL;
		matriu[1][1] = COLOR_BLAUCEL;
		matriu[1][2] = COLOR_BLAUCEL;
		matriu[1][3] = COLOR_BLAUCEL;
		break;

	case FIGURA_L:
		m_tamany = 3;
		matriu[0][2] = COLOR_TARONJA;
		matriu[1][0] = COLOR_TARONJA;
		matriu[1][1] = COLOR_TARONJA;
		matriu[1][2] = COLOR_TARONJA;
		break;

	case FIGURA_J:
		m_tamany = 3;

		matriu[0][0] = COLOR_BLAUFOSC;
		matriu[1][0] = COLOR_BLAUFOSC;
		matriu[1][1] = COLOR_BLAUFOSC;
		matriu[1][2] = COLOR_BLAUFOSC;

		break;
	}

	for (int i = 0; i < MAX_AMPLADA; i++)
	{
		for (int j = 0; j < MAX_ALCADA; j++)
			m_forma[i][j] = matriu[i][j];
	}

}


void Figura::transposar()
{
	ColorFigura temp[MAX_AMPLADA][MAX_ALCADA];

	for (int i = 0; i < m_tamany; i++)
	{
		for (int j = 0; j < m_tamany; j++)
			temp[i][j] = m_forma[j][i];
	}

	for (int i = 0; i < m_tamany; i++)
	{
		for (int j = 0; j < m_tamany; j++)
			m_forma[i][j] = temp[i][j];
	}
}


void Figura::girHorari()
{
	transposar();

		for (int i = 0; i < m_tamany; i++) {
			for (int j = 0; j < m_tamany / 2; j++) {
				ColorFigura temp = m_forma[i][j];
				m_forma[i][j] = m_forma[i][m_tamany - 1 - j];
				m_forma[i][m_tamany - 1 - j] = temp;
			}
		}
}


void Figura::girAntihorari()
{
	transposar();

	for (int j = 0; j < m_tamany; j++) 
	{
		for (int i = 0; i < m_tamany / 2; i++)
		{
			ColorFigura temp = m_forma[i][j];
			m_forma[i][j] = m_forma[m_tamany - 1 - i][j];
			m_forma[m_tamany - 1 - i][j] = temp;
		}
	}
	
}

void Figura::gir(DireccioGir gir)
{
	if (gir == GIR_HORARI)
		girHorari();
	else
		girAntihorari();

}