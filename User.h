#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class User
{
private:
	string nume;
	int varsta;
	int sex;
	double inaltime;
	double greutate;
	double bmi;
	int activitate; //activitate { sedentar=1, usoara=2, moderata=3, intensa=4 };
	int scop; //scop { scadere=1, mentinere=2, crestere=3 };
	int metabolism; //metabolism { rapid=1, normal=2, lent=3 };
public:
//------------functii principale------------

	void deleteUser();
	void storeUser();
	void getUser();
	void createUser();
	int checkUser();
	void editUser(int);
	double maxCalorii();

//------------get si set pt date ------------
	void setNume(string);
	string getNume();

	void setSex(int);
	int getSex();

	void setVarsta(int);
	int getVarsta();

	void setInaltime(double);
	double getInaltime();

	void setGreutate(double);
	double getGreutate();

	void setGreutate_Dorita(double);
	double getGreutate_Dorita();

	void setActivitate(int);
	int getActivitate();

	void setScop(int);
	int getScop();

	void setMetabolism(int);
	int getMetabolism();

	void setBMI();
	double getBMI();
};