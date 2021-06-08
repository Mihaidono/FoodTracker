#include "Produs.h"

bool Produs::checkDate(string dateline)
{
	ifstream f("Istoric.txt");
	string line;
	while (!f.eof())
	{
		getline(f, line);
		if (line == dateline)
			return true;
		line.clear();
	}
	return false;
	f.close();
}

double Produs::addUp(string fname,string data)
{
	ifstream f;
	f.open(fname.c_str());
	string line; int i, ok = 0, isline = 0;
	string prodname;
	double sum = 0;
	while (!f.eof())
	{
		i = 0;
		getline(f, line);
		if (checkDate(line) == true && line != data && ok == 1)
			break;
		if (line == data)
		{
			isline = 0;
			ok = 1;
			while (i <= 3)
			{
				if (i == 1)
					prodname = line;
				if (i == 2)
					cantitate = alim.getValue(line, 'd');
				if (i == 3)
				{
					portie = int(alim.getValue(line, 'i'));
					sum = sum + calcCalorii(prodname);
				}
				line.clear();
				i++;
				getline(f, line);
			}
		}
		prodname.clear();
		if (line.empty() == false && ok == 1)
		{
			isline = 0;
			while (i <= 2)
			{
				if (i == 0)
					prodname = line;
				if (i == 1)
					cantitate = alim.getValue(line, 'd');
				if (i == 2)
				{
					portie = int(alim.getValue(line, 'i'));
					sum = sum + calcCalorii(prodname);
				}
				line.clear();
				i++;
				getline(f, line);
			}
		}
		prodname.clear();
		if (line.empty())
			isline++;
		else isline = 0;

		if (line.empty() == true && isline == 2)
			break;
	}
	f.close();
	return sum;
}

void Produs::showProduse(int choice,string data)
{
	int ok = 0, i = 0;
	string line;
	ifstream f;
	if (choice == 1)
		f.open("MicDejun.txt");
	else if (choice == 2)
		f.open("Pranz.txt");
	else if (choice == 3)
		f.open("Cina.txt");
	else if (choice == 4)
		f.open("Gustari.txt");
	if(f.peek() == ifstream::traits_type::eof())
		cout << "Nu exista produse consumate!\n";
	else
	{
		while (!f.eof())
		{
			getline(f, line);
			if (line == data)
			{
				ok = 1;
				while (!f.eof())
				{
					getline(f, line);
					if (line.empty())
						i++;
					else i = 0;
					cout << line << endl;
					line.clear();
					if (i == 2)
						break;
				}
			}
			if (ok == 1)
				break;
		}
		if (ok == 0)
			cout << "Nu exista produse consumate in aceasta data!\n";
	}
	f.close();
}

void Produs::storeProdus(int choice, string data)
{
	ifstream f; string line; bool ok=false;
	if (choice == 1)
		f.open("MicDejun.txt", ios::app);
	else if (choice == 2)
		f.open("Pranz.txt", ios::app);
	else if (choice == 3)
		f.open("Cina.txt", ios::app);
	else if (choice == 4)
		f.open("Gustari.txt", ios::app);
	while (!f.eof())
	{
		getline(f, line);
		if (line == data)
			ok = true;
	}
	f.close(); 
	ofstream g;
	if (choice == 1)
		g.open("MicDejun.txt", ios::app);
	else if (choice == 2)
		g.open("Pranz.txt", ios::app);
	else if (choice == 3)
		g.open("Cina.txt", ios::app);
	else if (choice == 4)
		g.open("Gustari.txt", ios::app);

	if (ok == true)
		g << alim.getName() << "\nCantitate :"
		<< cantitate << ";\nPortie:" << portie << ";\n\n";
	else
		g  << data << "\n" << alim.getName() << "\nCantitate :"
		<< cantitate << ";\nPortie:" << portie << ";\n\n";
	g.close();
}
//functie privata deja apelata in create

void Produs::createProdus(int choice,string data)
{
	string name; int input;
funct2:
	system("cls");
	cout << "Introdu produsul consumat:\nNume: ";
	cin.ignore();
	getline(cin, name);
	if (alim.checkAliment(name) == -1)
	{
		cout << "Nu exista alimentul in baza de date\nDoriti sa-l creati?"
			<< "\n1.Da\n2.Nu";
		cin >> input;
		if (input == 1)
			alim.createAliment();
		else goto funct2;
	}
	else
	{
		double gram; int port;
		alim.setName(name);
		cout << "Cantitatea consumata(grame): "; cin >> gram;
		cout << "Portia(ex: 1 mar/2 mere etc...): "; cin >> port;
		portie = port;
		cantitate = gram;
		storeProdus(choice,data);
	}
}

double Produs::calcCalorii(string nume)
{
	alim.getAliment(nume);
	double proteine, grasimi, carbohidrati, calorii;
	proteine = alim.getProteine() * (cantitate * 0.1);
	grasimi = alim.getGrasimi() * (cantitate * 0.1);
	carbohidrati = alim.getGlucide() * (cantitate * 0.1);

	proteine = proteine * 4 * portie;
	grasimi = grasimi * 9 * portie;
	carbohidrati = carbohidrati * 4 * portie;

	calorii = proteine + grasimi + carbohidrati;
	return calorii;
	
}

double Produs::calculProgres(string data)
{	
	double fsum;
	fsum = addUp("Cina.txt",data) + addUp("Pranz.txt",data) 
		+ addUp("Gustari.txt",data)+ addUp("MicDejun.txt",data);
	return fsum;
}

void Produs::depositDate(string data)
{
	bool ok = false;
	ifstream f("Istoric.txt");
	string line;
	while (!f.eof())
	{
		getline(f, line);
		if (line == data)
			ok = true;
	}
	f.close();
	ofstream g;
	g.open("Istoric.txt", ios::app);
	if (ok == false)
		g << data << endl;
	g.close();
}

void Produs::sortfl()
{
	string line1;
	string line2;
	vector<string> vec;
	ifstream f("Istoric.txt");
	while (!f.eof())
	{
		getline(f, line1);
		if(!line1.empty())
			vec.push_back(line1);
		line1.clear();
	}
	if (vec.size() >= 2)
		for (auto i = 0; i != vec.size() - 1; i++)
			for (auto j = i + 1; j != vec.size(); j++)
		{
			line1 = vec.at(i).substr(6,4);
			line2 = vec.at(j).substr(6,4);
			if (line1 < line2)
				vec.at(i).swap(vec.at(j));
			else if (line1 == line2)
			{
				line1 = vec.at(i).substr(3, 2);
				line2 = vec.at(j).substr(3, 2);
				if (line1 < line2)
					vec.at(i).swap(vec.at(j));
				else if (line1 == line2)
				{
					line1 = vec.at(i).substr(0, 2);
					line2 = vec.at(j).substr(0, 2);
					if (line1 < line2)
						vec.at(i).swap(vec.at(j));
				}
			}
		}
	f.close();
	ofstream g("Istoric.txt");
	for (auto i = 0; i != vec.size(); i++)
		g << vec.at(i) << endl;
	g.close();
}

void Produs::printDate(double dob)
{
	sortfl();
	string line;
	ifstream f("Istoric.txt");
	while (!f.eof())
	{
		getline(f, line);
		if (!line.empty())
		cout << "Pentru data: " << line << endl
			<< "Calorii consumate: " <<int(calculProgres(line)) << endl
			<< "Goal: " << dob << endl << endl;
		line.clear();
	}
	f.close();
}

bool Produs::ispopulatedIstoric()
{
	ifstream f("Istoric.txt");
	if (f.peek() == ifstream::traits_type::eof())
		return false;
	return true;
}


//------------ Get si set definite ------------

Aliment Produs::getAliment() { return alim; }

double Produs::getCantitate() { return cantitate; }

int Produs::getPortie() { return portie; }