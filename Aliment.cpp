#include "Aliment.h"

double Aliment::getValue(string line,char a)
{
	string cont;
	for (auto i = 0; i != line.size(); i++)
		if (line.at(i) == ':')
			do
			{
				i++;
				cont.push_back(line.at(i));
			} while (line.at(i+1) != ';');
			if (a == 'd')
				return stod(cont);
			else if (a == 'i')
				return stoi(cont);
	return 0;
} 
//transforma string in int sau double in functie de 'a'

void Aliment::getAliment(string cont)
{
	int i = 1, ok = 0;
	string line;
	ifstream f("Alimente.txt");
	while (!f.eof())
	{
		getline(f, line);
		if (cont.compare(line) == 0)
		{
			ok = 1;
			while (i <= 10)
			{
				if (i == 1)
					name = line;
				if (i == 2)
					valenerg = getValue(line,'d');
				if (i == 3)
					grasimi = getValue(line, 'd');
				if (i == 4)
					acizigrasi = getValue(line, 'd');
				if (i == 5)
					glucide = getValue(line, 'd');
				if (i == 6)
					zaharuri = getValue(line, 'd');
				if (i == 7)
					fibre = getValue(line, 'd');
				if (i == 8)
					proteine = getValue(line, 'd');
				if (i == 9)
					sare = getValue(line, 'd');
				if (i == 10)
					cantitate = getValue(line, 'd');
				line.clear();
				getline(f, line);
				i++;
			}
		}
		if (ok == 1)
			break;
	}
	f.close();
}

void Aliment::storeAliment()
{
	ofstream f;
	f.open("Alimente.txt",ios::app);
	f << "\n{\n" << name << "\nValoare energetica :" << valenerg << ";\nGrasimi :"
		<< grasimi << ";\nAcizi Grasi :" << acizigrasi << ";\nGlucide :" <<
		glucide << ";\n    -din care zaharur :" << zaharuri << ";\nFibre :"
		<< fibre << ";\nProteine :" << proteine << ";\nSare :" << sare << ";\nCantitate: "
		<< cantitate << ";\n}\n";
	f.close();
}

int Aliment::checkAliment(string alim)
{
	string line;
	ifstream f("Alimente.txt");
	while (!f.eof())
	{
		getline(f, line);
		if (alim.compare(line) == 0)
		{
			f.close();
			return 1;
		}
	}
	f.close();
	return -1;
}

void Aliment::createAliment()
{
	string nume;
falim1:
	system("cls");
	cout << "Ati ales sa introduceti un aliment!\nNume: ";
	getline(cin, nume);
	if (nume != "") 
	{
		if (checkAliment(nume) == 1)
		{
			cout << "Alimentul este deja creat! Introduceti alt aliment\n";
			Sleep(3000);
			goto falim1;
		}
		else
		{
			double value;
			name = nume;
			cout << "Valoare energetica: "; cin >> value; valenerg = value;
			cout << "Grasimi: "; cin >> value; grasimi = value;
			cout << "Acizi Grasi: "; cin >> value; acizigrasi = value;
			cout << "Glucide: "; cin >> value; glucide = value;
			cout << "Zaharuri: "; cin >> value; zaharuri = value;
			cout << "Fibre: "; cin >> value; fibre = value;
			cout << "Proteine: "; cin >> value; proteine = value;
			cout << "Sare: "; cin >> value; sare = value;
			cout << "Cantitate: "; cin >> value; cantitate = value;
			storeAliment();
		}
	}
	else
		goto falim1;
}

void Aliment::vizTotalAlim()
{
	ifstream f("Alimente.txt");
	string line;
	while (!f.eof())
	{
		getline(f, line);
		if (line != "{" && line != "}")
			cout << line << endl;
		else cout << "==========================\n";
		line.clear();
	}
	f.close();
}

//------------ Get si set definite ------------

void Aliment::setName(string s)
{
	this->name = s;
}

string Aliment::getName() { return name; }

void Aliment::setValEnerg(double a)
{
	this->valenerg = a;
}

double Aliment::getValEnerg() { return valenerg; }

void Aliment::setGrasimi(double b)
{
	this->grasimi = b;
}

double Aliment::getGrasimi() { return grasimi; }

void Aliment::setAciziG(double c)
{
	this->acizigrasi = c;
}

double Aliment::getAciziG() { return acizigrasi; }

void Aliment::setGlucide(double d)
{
	this->glucide = d;
}

double Aliment::getGlucide() { return glucide; }

void Aliment::setZaharuri(double e)
{
	this->zaharuri = e;
}

double Aliment::getZaharuri() { return zaharuri; }

void Aliment::setFibre(double f)
{
	this->fibre = f;
}

double Aliment::getFibre() { return fibre; }

void Aliment::setProteine(double g)
{
	this->proteine = g;
}

double Aliment::getProteine() { return proteine; }

void Aliment::setSare(double h)
{
	this->sare = h;
}

double Aliment::getSare() { return sare; }

void Aliment::setCantitate(double i)
{
	this->cantitate = i;
}

double Aliment::getCantitate() { return cantitate; }