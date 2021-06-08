#pragma once
#include "Aliment.h"

class Produs
{
private:
	Aliment alim;
	double cantitate;
	int portie;
	void storeProdus(int, string);
	void sortfl();
public:
//------------functii principale------------

	void createProdus(int, string);
	void showProduse(int, string);
	double calculProgres(string);
	double addUp(string, string);	
	void depositDate(string);
	void printDate(double);
	bool ispopulatedIstoric();
	bool checkDate(string);
	double calcCalorii(string nume);

//------------get si set pt date ------------
	Aliment getAliment();
	double getCantitate();
	int getPortie();
};

