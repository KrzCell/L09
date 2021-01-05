
#include <iostream>
using namespace std;


#define ZadanieA 

#ifdef ZadanieA

double dlOdcinka(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double sumaKatow(double* obX, double* obY, int liczPkt, double x, double y)
{
	double a, b, c, kat, suma = 0;
	for (int i = 0; i < liczPkt; i++)
	{
		int j = (i + 1) % liczPkt;
		c = dlOdcinka(obX[i], obY[i], obX[j], obY[j]);
		a = dlOdcinka(x, y, obX[i], obY[i]);
		b = dlOdcinka(x, y, obX[j], obY[j]);
		kat = acos(0.5 * (a / b + b / a - c * c / (a * b)));
		suma += kat;
	}
	return suma;
}

bool czyPunktNalezyDoObszaru(double* obX, double* obY, int liczPkt, double x, double y)
{
	if (obX == nullptr || obY == nullptr) throw std::invalid_argument("Nullptr!");
	if (liczPkt <= 2) throw std::domain_error("LiczPkt<=2");
	const double DWA_PI = 2.0 * 3.1415926;
	const double EPS = 0.00001;
	double modRoznicy = abs(sumaKatow(obX, obY, liczPkt, x, y) - DWA_PI);
	return (-EPS < modRoznicy&& modRoznicy < EPS);
}

void test_wsp_x()
{
	double tabX[] = { 1.0, 1.0, 1.0, 2.0 };
	double tabY[] = { 3.0, 2.0, 2.0, 1.0 };
	double xP = -0.5;
	double yP = 0.5;
	const int SIZE = sizeof(tabX) / sizeof(double);
	if (czyPunktNalezyDoObszaru(tabX,tabY,SIZE,xP,yP))
	{
		cerr << "Nie ma bledu";
	}
	else {
		cerr << "Blad";
	}
}

void test_wsp_y()
{
	double tabX[] = { 1.0, 1.0, 1.0, 2.0 };
	double tabY[] = { 3.0, 2.0, 2.0, 1.0 };
	double xP = -0.5;
	double yP = 0.5;
	const int SIZE = sizeof(tabX) / sizeof(double);
	if (czyPunktNalezyDoObszaru(tabX, tabY, SIZE, xP, yP) == false)
	{
		cerr << "Nie ma bledu";
	}
	else{
		cerr << "Blad";
	}
}

void test_x_klas_P()
{
	double tabX[] = { 1.0, 1.0, 1.0, 2.0 };
	double tabY[] = { 3.0, 2.0, 2.0, 1.0 };
	double xP = -0.5;
	double yP = 0.5;
	const int SIZE = sizeof(tabX) / sizeof(double);
	if (czyPunktNalezyDoObszaru(nullptr, nullptr, SIZE, xP, yP))
	{
		cerr << "Nie ma bledu";
	}
	else {
		cerr << "Blad";
	}
}

void test_y_klas_P()
{
	try
	{
		double tabX[] = { 1.0, 1.0, 1.0, 2.0 };
		double tabY[] = { 3.0, 2.0, 2.0, 1.0 };
		double xP = -0.5;
		double yP = 0.5;
		const int SIZE = sizeof(tabX) / sizeof(double);
		czyPunktNalezyDoObszaru(tabX, tabY, SIZE, xP, yP);
	}
	catch (invalid_argument)
	{
		cerr << "Nie ma bledu";
	}
	catch (...)
	{
		cerr << "Blad";
	}
}

void main(void)
{
	double tabX[] = { 1.0, 1.0, 1.0, 2.0 };
	double tabY[] = { 3.0, 2.0, 2.0, 1.0 };
	double xP = -0.5;
	double yP = 0.5;
	const int SIZE = sizeof(tabX) / sizeof(double);
	cout << czyPunktNalezyDoObszaru(tabX, tabY, SIZE, xP, yP) << endl;
	test_wsp_x;
	test_wsp_y;
	test_x_klas_P;
	test_y_klas_P;

}

#endif

#ifdef ZadanieB

int wyszukajPierwsza(double* tablica, int rozmiar, double wartSzukana)
{
	// Sparwdzenie poprawności danych wejściowych:
	if (tablica == nullptr) throw std::invalid_argument("tablica = nullptr");
	if (rozmiar < 1) throw std::length_error("rozmiar < 1");

	for (int index = 0; index < rozmiar; index++)
	{
		if (tablica[index] == wartSzukana)
			return index;  // Znaleziono pierwsze wystąpienie - przerywam
	}
	throw std::domain_error("Wratosc nie wystąpila");
}

int ileRazyZnak(const char* text, char znak)
{
	int liczbaWystapien = 0;
	while (*text++)
		if (*text == znak) liczbaWystapien++;
	return liczbaWystapien;
}

int main()
{
	// TU ROZWIĄZUJ ZADANIE B:
}

#endif

#ifdef ZadanieC
int main()
{
	// TU ROZWIĄZUJ ZADANIE C:
}
#endif

