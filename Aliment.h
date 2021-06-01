#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <Windows.h>
using namespace std;

class Aliment
{
protected:
	string name;
	double valenerg;
	double grasimi;
	double acizigrasi;
	double glucide;
	double zaharuri;
	double fibre;
	double proteine;
	double sare;
	double cantitate;
public:
//------------functii principale------------

	void storeAliment();
	int checkAliment(string);
	void getAliment(string);
	double getValue(string,char);
	void createAliment();
	void vizTotalAlim();

//------------get si set pt date ------------

	void setName(string = "-");
	string getName();
	void setValEnerg(double = 0);
	double getValEnerg();
	void setGrasimi(double = 0);
	double getGrasimi();
	void setAciziG(double = 0);
	double getAciziG();
	void setGlucide(double = 0);
	double getGlucide();
	void setZaharuri(double = 0);
	double getZaharuri();
	void setFibre(double = 0);
	double getFibre();
	void setProteine(double = 0);
	double getProteine();
	void setSare(double = 0);
	double getSare();
	void setCantitate(double = 0);
	double getCantitate();
};