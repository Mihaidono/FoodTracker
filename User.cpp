#include "User.h"

void User::deleteUser()
{
	ofstream f("User.txt");
	f.close();
}

void User::storeUser()
{
	ofstream f("User.txt");
	f << "{\n" << nume << "\n" << varsta << "\n";
	if (sex == 1)
		f << "Barbat";
	else f << "Femeie";
	f << "\n" << inaltime << "\n" << greutate << "\n" << bmi << "\n";
	//-------store activitate-------
	if (activitate == 1)
		f << "Sedentar(Activitate)\n";
	else if (activitate == 2)
		f << "Usoara(Activitate)\n";
	else if (activitate == 3)
		f << "Moderata(Activitate)\n";
	else if (activitate == 4)
		f << "Intensa(Activitate)\n";
	//-------store scop-------
	if (scop == 1)
		f << "Scadere(Scop)\n";
	else if (scop == 2)
		f << "Mentinere(Scop)\n";
	else if (scop == 3)
		f << "Crestere(Scop)\n";
	//-------store metabolism-------
	if (metabolism == 1)
		f << "Rapid(Metabolism)\n";
	else if (metabolism == 2)
		f << "Normal(Metabolism)\n";
	else if (metabolism == 3)
		f << "Lent(Metabolism)\n";
	f << "}\n";
	f.close();
}

void User::getUser()
{
	ifstream f("User.txt");
	int i = 1, var = 0; double dob = 0; string content;
	while (!f.eof())
	{
		getline(f, content);
		//nume
		if (i == 2)
			nume = content;
		//varsta
		if (i == 3)
		{
			var = stoi(content);
			varsta = var;
		}
		//sex
		if (i == 4 && content.front() == 'B')
			sex = 1;
		else if (i == 4 && content.front() == 'F')
			sex = 2;
		//inaltime
		if (i == 5)
		{
			dob = stof(content);
			inaltime = dob;
		}
		//greutate
		if (i == 6)
		{
			dob = stof(content);
			greutate = dob;
		}
		//bmi
		if (i == 7)
		{
			dob = stod(content);
			bmi = dob;
		}
		//activitate
		if (i == 8 && content.front() == 'S')
			activitate = 1;
		else if(i == 8 && content.front() == 'U')
			activitate = 2;
		else if(i == 8 && content.front() == 'M')
			activitate = 3;
		else if(i == 8 && content.front() == 'I')
			activitate = 4;
		//scop
		if (i == 9 && content.front() == 'S')
			scop = 1;
		else if (i == 9 && content.front() == 'M')
			scop = 2;
		else if (i == 9 && content.front() == 'C')
			scop = 3;
		//metabolism
		if (i == 10 && content.front() == 'R')
			metabolism = 1;
		else if (i == 10 && content.front() == 'N')
			metabolism = 2;
		else if (i == 10 && content.front() == 'L')
			metabolism = 3;
		i++;
		content.clear();
	}
	f.close();
}

void User::createUser()
{
	string name;		int vt, sx, av, sp, mb;		double greut, inalt;
	cout << "Ati ales sa creati un user!\nNume: ";
	cin.ignore();
	getline(cin, name);
	cout << "Varsta: "; cin >> vt;
	cout << "Sex:\n1.Masculin\n2.Feminin\n--"; cin >> sx;
	cout << "Inaltimea: "; cin >> inalt;
	cout << "Greutatea: "; cin >> greut;
	cout << "Ce tip de activitate aveti?:\n1.sedentar\n2.usoara\n3.moderata\n4.intensa\n ";cin >> av; 
	cout << "Care este scopul dumneavoastra?:\n1.Scadere\n2.Mentinere\n3.Crestere\n";cin >> sp; 
	cout << "Ce tip de metabolism aveti?:\n1.Rapid\n2.Normal\n3.Lent\n";cin >> mb; 

//-----------initializez datele userului--------------
	nume = name;
	varsta = vt;
	sex = sx;
	activitate = av;
	greutate = greut;
	inaltime = inalt;
	scop = sp;
	metabolism = mb;
	setBMI();
	storeUser(); //le adaug in fisier
}

int User::checkUser()
{
	string line;
	ifstream f("User.txt");
	getline(f, line);
	if (line.size() == 0)
	{
		cout << "Nu exista useri creati!\n";
		f.close();
		return -1;
	}
	f.close();
	return 1;
}

void User::editUser(int alg)
{
	getUser();
	cin.ignore();
	if (alg == 1)
	{
		cout << "\nScrieti noul nume: ";
		string newname;
		getline(cin, newname);
		nume = newname;
	}
	if (alg == 2)
	{
		cout << "\nScrieti noua varsta: ";
		int nvt; cin >> nvt;
		varsta = nvt;
	}
	if (alg == 3)
	{
		cout << "\nScrieti noul sex: ";
		int nsx; cin >> nsx;
		sex = nsx;
	}
	if (alg == 4)
	{
		cout << "\nScrieti noua inaltime: ";
		double inalt; cin >> inalt;
		inaltime = inalt;
	}
	if (alg == 5)
	{
		cout << "\nScrieti noua greutate: ";
		double greut; cin >> greut;
		greutate = greut;
	}
	if (alg == 6)
	{
		cout << "\nScrieti noua activitate:"
			<<"\n1.Sedentar\n2.Usoara\n3.Moderata\n4.Intensa\n";
		int nav; cin >> nav;
		activitate = nav;
	}
	if (alg == 7)
	{
		cout << "\nScrieti noul scop: "
			<<"\n1.Scadere\n2.Mentinere\n3.Crestere\n";
		int nsp; cin >> nsp;
		scop = nsp;
	}
	if (alg == 8)
	{
		cout << "\nScrieti noul metabolism: "
			<<"\n1.Rapid\n2.Normal\n3.Lent\n";
		int nmt; cin >> nmt;
		metabolism = nmt;
	}
	setBMI();
	storeUser();
}

double User::maxCalorii()
{
	double A, B, C, metab = 0;
	A = 10 * greutate;
	B = 6.25 * inaltime * 0.01;
	C = 5 * double(varsta);
	if (sex == 1)
		metab = A + B - C + 5;
	else metab = A + B - C - 161;
	if (scop == 1)
		return metab * 1200;
	else if (scop == 2)
		return metab * 1375;
	else if (scop == 3)
		return metab * 1550;
	else if (scop == 4)
		return metab * 1900;
	return 0;

}


//------------ Get si set definite ------------

void User::setScop(int scp)
{
	scop = scp;
}
void User::setMetabolism(int met)
{
	metabolism = met;
}
void User::setActivitate(int act)
{
	activitate = act;
}
void User::setBMI()
{
	bmi = greutate / (inaltime * inaltime);
}
void User::setNume(string k)
{
	nume = k;
}
void User::setVarsta(int v)
{
	varsta = v;
}
void User::setInaltime(double h)
{
	inaltime = h;
}
void User::setGreutate(double g)
{
	greutate = g;
}
void User::setSex(int s)
{
	sex = s;
}
int User::getSex() { return sex; }
string User::getNume() { return nume; }
int User::getVarsta() { return varsta; }
double User::getInaltime() { return inaltime; }
double User::getGreutate() { return greutate; }
int User::getActivitate() { return activitate; }
int User::getScop() { return scop; }
int User::getMetabolism() { return metabolism; }
double User::getBMI() { return bmi; }