#include "FoodTracker.h"
#include <stdio.h>
#include <Windows.h>
#include <iomanip>

ostream& operator<<(ostream& o, User& u)
{
	o << "Datele utilizatorului:\nNumele: " << u.getNume() << endl
		<< "Varsta: " << u.getVarsta() << endl << "Sex: ";

	if (u.getSex() == 1)
		o << "Barbat\n";
	else o << "Femeie\n";

	o << "Inaltime: " << u.getInaltime() << endl << "Greutate: "
		<< u.getGreutate() << endl << "Bmi-ul utilizatorului este: "
		<< u.getBMI() << endl << "Tipul de activitate selectat este: ";
	if (u.getActivitate() == 1)
		o << "sedentar\n";
	else if (u.getActivitate() == 2)
		o << "usoara\n";
	else if (u.getActivitate() == 3)
		o << "moderata\n";
	else if (u.getActivitate() == 4)
		o << "intensa\n";
	o << "Scopul utilizatorului este de ";
	if (u.getScop() == 1)
		o << "scadere\n";
	else if (u.getScop() == 2)
		o << "mentinere\n";
	else if (u.getScop() == 3)
		o << "crestere\n";
	o << "Metabolismul este: ";
	if (u.getMetabolism() == 1)
		o << "rapid\n";
	else if (u.getMetabolism() == 2)
		o << "normal\n";
	else if (u.getMetabolism() == 3)
		o << "lent\n";
	o << endl;
	return o;
}

ostream& operator<<(ostream& o, Aliment& alim)
{
	o << "Nume: " << alim.getName() << "\nValoare energetica :" << alim.getValEnerg()
		<< ";\nGrasimi :" << alim.getGrasimi() << ";\nAcizi Grasi :"
		<< alim.getAciziG() << ";\nGlucide :" << alim.getGlucide()
		<< ";\n    -din care zaharur :" << alim.getZaharuri() << ";\nFibre :"
		<< alim.getFibre() << ";\nProteine :" << alim.getProteine() << ";\nSare :"
		<< alim.getSare() << ";\nCantitate: "
		<< alim.getCantitate() << ";\n";
	return o;
}

FoodTracker::FoodTracker()
{
	int choice;
Meniu1:
	system("cls");
	cout << "Meniu[1-3]\n\n---Alege o optiune:---\n\n"
		 <<"1.Creaza Utilizator\n2.Accesare Utilizator\n"
		 <<"3.Editeaza Utilizatorul\n4.Treci la urmatorul meniu\n5.Exit\n";
	cin >> choice;
	system("cls");
	switch (choice)
	{
	case 1:
		if (user.checkUser() == 1)
		{
			system("cls");
			cout << "Deja exista un utilizator creat!\n";
			user.getUser();
			cout << user << endl;
		testmeniuutilizator11:
			cout<<"Apasa (1) ca sa te intorci."
				<<"\nApasa (2) ca sa il stergi.";
			cin >> choice;
			if (choice == 2)
			{
				user.deleteUser();
				goto Meniu1;
			} else
			if (choice == 1)
				goto Meniu1;
			else cout << "Valoarea tastata este gresita\n";
			goto testmeniuutilizator11;
		}
		else
		{
			user.createUser();
			system("cls");
			cout << user << endl;
		testmeniuutilizator12:
			cout << "Apasa (1) ca sa te intorci.";
			cin >> choice;
			if (choice == 1)
				goto Meniu1;
			else cout << "Valoarea tastata este gresita\n";
			goto testmeniuutilizator12;
		}
		break;
	case 2:
		if(user.checkUser()==1)
		{
			user.getUser();
			cout << user;
		testmeniuutilizator21:
			cout << "Apasa (1) ca sa te intorci.";
			cin >> choice;
			if (choice == 1)
				goto Meniu1;
			else cout << "Valoarea tastata este gresita\n";
			goto testmeniuutilizator21;
		}
		else 
		{
			cout << "\nCreaza un utilizator mai intai\n";
		testmeniuutilizator22:
			cout<<"->Apasa(1) pentru a crea un utilizator";
			cout << "\n->Apasa(2) pentru a merge inapoi in meniul principal\n";
			cin >> choice;
			if (choice == 2)
				goto Meniu1;
			else if (choice == 1 && user.checkUser() == -1)
				user.createUser();
			else if (choice == 1 && user.checkUser() == 1)
			{
				system("cls");
				cout << "Ati creat deja userul:\n";
				cout << user;
			} else
				cout << "Valoarea tastata este gresita\n";
			goto testmeniuutilizator22;

		}
		break;
	case 3:
		if (user.checkUser() == -1)
		{
			cout << "creaza un utilizator ca sa poti schimba date!";
		testmeniuutilizator31:
			cout << "\nApasa (1) ca sa te intorci.";
			cin >> choice;
			if (choice == 1)
				goto Meniu1;
			else cout << "Valoarea tastata este gresita\n";
			goto testmeniuutilizator31;
		}
		cout << "Ce doresti sa editezi?:" << endl
			<< "1.Numele\n2.Varsta\n3.Sexul din pacate\n4.Inaltimea\n"
			<< "5.Greutatea\n6.Activitatea\n7.Scopul\n8.Metabolismul\n"
			<< "9.Inapoi la meniul 1\n";
		cin >> choice;
		if (choice == 9)
			goto Meniu1;
		user.editUser(choice);
	testmeniuutilizator32:
		cout << "Apasa (1) ca sa te intorci.";
		cin >> choice;
		if (choice == 1)
			goto Meniu1;
		else cout << "Valoarea tastata este gresita\n";
		goto testmeniuutilizator32;
		break;
	case 4:
		goto Meniu2;
	case 5:
		exit(0);
	default:
		cout << "Optiunea nu este valida\n";
		Sleep(1000);
		goto Meniu1;
		break;
	}

	//----------------sfarsit meniu1----------------

Meniu2:
	system("cls");
	cout << "Meniu[2-3]\n\n---Alege o optiune:---\n\n"
		<< "1.Vizualizeaza alimente\n2.Introdu un aliment\n"
		<<"3.Treci la urmatorul meniu\n4.Exit\n";
	cin >> choice;
	system("cls");
	switch (choice)
	{
	case 1:
		alim.getAliment().vizTotalAlim();
	testmeniualiment11:
		cout << "Apasa (1) ca sa te intorci.";
		cin >> choice;
		if (choice == 1)
			goto Meniu2;
		else cout << "Valoarea tastata este gresita\n";
		goto testmeniualiment11;
		break;
	case 2:
	reintrodu1:
		alim.getAliment().createAliment();
		cout << "\nDoriti sa introduceti alt aliment?\n1.Da\n2.Nu\n";
	testmeniualimente22:
		cin >> choice;
		if (choice == 2)
			goto Meniu2;
		else if (choice == 1)
			goto reintrodu1;
		else
		{
		cout << "Valoarea tastata este gresita(1-Da | 2-Nu)\n";
		goto testmeniualimente22;
		}
		break;
	case 3:
		goto Meniu3;
	case 4:
		exit(0);
	default:
		cout << "Optiunea nu este valida\n";
		Sleep(1000);
		goto Meniu2;
		break;
	}

	//----------------sfarsit meniu 2----------------

Meniu3:
	string datac;
	system("cls");
	cout << "Meniu[3-3]\n\n---Alege o optiune:---\n\n"
		<< "1.Afiseaza istoricul\n2.Introdu o data calendaristica"
		<< "\n3.Treci la urmatorul meniu.\n4.Exit\n";
	cin >> choice;
	system("cls");
	user.getUser();
	switch (choice)
	{
	case 1:
		system("cls");
		if (alim.ispopulatedIstoric() == true)
			alim.printDate(user.maxCalorii());
		else cout << "Nu sunt date in Istoric!\n";
	isto1:
		cout << "Apasa (1) ca sa te intorci.";
		cin >> choice;
		if (choice == 1)
			goto Meniu3;
		else cout << "Valoarea tastata este gresita\n";
		goto isto1;
		break;
	case 2:
		cout << "Introduceti data sub format dd.mm.yyyy: ";
		cin.ignore();
		getline(cin, datac);
		alim.depositDate(datac);
	minimen3:
		system("cls");
		cout << "-----Pentru data " << datac << " :\n"
			<< "1.Vizualizare progres\n2.Vizualizare produse\n"
			<< "3.Introduceti un produs consumat\n4.Intoarce-te la meniul anterior\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "-----Pentru data " << datac << " :\n"
				<< "Vizualizare progres\n\t1.Progres expected\n\t2.Progres real"
				<<"\nVizualizare produse\nIntroduceti un produs consumat"
				<<"\nIntoarce-te la meniul anterior\n";
			cin >> choice;
			switch (choice)
			{
			case 1:
				system("cls");
				if (user.maxCalorii() > alim.calculProgres(datac))
					cout << "Pentru data de: " << datac <<
					" mai trebuie sa consumati: " << user.maxCalorii()
					- alim.calculProgres(datac) << " calorii\n";
				else
					cout << "Ati depasit numarul de calorii propuse cu:  "
					<< alim.calculProgres(datac) - user.maxCalorii()
					<< " calorii\n";
			loopi1:
				cout << "Apasa (1) ca sa te intorci.";
				cin >> choice;
				if (choice == 1)
					goto minimen3;
				else cout << "Valoarea tastata este gresita\n";
				goto loopi1;
				break;
			case 2:
			minimenp1:
				system("cls");
				cout << "-----Pentru data " << datac << " :\n"
					<< "Vizualizare progres\n\tProgres expected\n\tProgres real\n"
					<<"\t   > 1.Mic Dejun\n\t   > 2.Pranz"
					<<"\n\t   > 3.Cina\n\t   > 4.Gustari\n\t   > 5.Pe toata ziua"
					<< "\nVizualizare produse\nIntroduceti un produs consumat"
					<< "\nIntoarce-te la meniul anterior\n";
				cin >> choice;
				switch (choice)
				{
				case 1:
					system("cls");
					cout << "Caloriile consumate pana acum sunt: " 
						<< alim.addUp("MicDejun.txt",datac)<< endl;
				loopi11:
					cout << "\nApasa (1) ca sa te intorci.";
					cin >> choice;
					if (choice == 1)
						goto minimen3;
					else cout << "Valoarea tastata este gresita\n";
					goto loopi11;
					break;
				case 2:
					system("cls");
					cout << "Caloriile consumate pana acum sunt: "
					<< alim.addUp("Pranz.txt", datac) << endl;
				loopi12:
					cout << "\nApasa (1) ca sa te intorci.";
					cin >> choice;
					if (choice == 1)
						goto minimen3;
					else cout << "Valoarea tastata este gresita\n";
					goto loopi12;
					break;
				case 3:
					system("cls");
					cout << "Caloriile consumate pana acum sunt: "
					<< alim.addUp("Cina.txt", datac) << endl;
				loopi13:
					cout << "\nApasa (1) ca sa te intorci.";
					cin >> choice;
					if (choice == 1)
						goto minimen3;
					else cout << "\nValoarea tastata este gresita\n";
					goto loopi13;
					break;
				case 4:
					system("cls");
					cout << "Caloriile consumate pana acum sunt: "
					<< alim.addUp("Gustari.txt", datac) << endl;
				loopi14:
					cout << "\nApasa (1) ca sa te intorci.";
					cin >> choice;
					if (choice == 1)
						goto minimen3;
					else cout << "Valoarea tastata este gresita\n";
					goto loopi14;
					break;
				case 5:
					cout << "Caloriile consumate in total in data de: " << datac << " sunt: "
						<< alim.calculProgres(datac) << endl;
				loopi15:
					cout << "\nApasa (1) ca sa te intorci.";
					cin >> choice;
					if (choice == 1)
						goto minimen3;
					else cout << "Valoarea tastata este gresita\n";
					goto loopi15;
					break;
				default:
					cout << "Optiunea nu este valida\n";
					Sleep(700);
					goto minimenp1;
					break;
				}
				break;
			default:
				cout << "Optiunea nu este valida\n";
				Sleep(700);
				goto minimen3;
				break;
			}
			break;
		case 2:
			Vizalim:
			system("cls");
			cout << "-----Pentru data " << datac << " :\n"
				<< "Vizualizare progres\nVizualizare produse\n"
				<<"\t>1.Mic Dejun\n\t>2.Pranz\n\t>3.Cina\n\t>4.Gustari\n"
				<< "Introduceti un produs consumat\nIntoarce-te la meniul anterior\n";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
				alim.showProduse(1,datac);
			loop1:
				cout << "Apasa (1) ca sa te intorci.";
				cin >> choice;
				if (choice == 1)
					goto minimen3;
				else cout << "Valoarea tastata este gresita\n";
				goto loop1;
				break;
			case 2:
				alim.showProduse(2, datac);
			loop2:
				cout << "Apasa (1) ca sa te intorci.";
				cin >> choice;
				if (choice == 1)
					goto minimen3;
				else cout << "Valoarea tastata este gresita\n";
				goto loop2;
				break;
			case 3:
				alim.showProduse(3, datac);
			loop3:
				cout << "Apasa (1) ca sa te intorci.";
				cin >> choice;
				if (choice == 1)
					goto minimen3;
				else cout << "Valoarea tastata este gresita\n";
				goto loop3;
				break;
			case 4:
				alim.showProduse(4, datac);
			loop4:
				cout << "Apasa (1) ca sa te intorci.";
				cin >> choice;
				if (choice == 1)
					goto minimen3;
				else cout << "Valoarea tastata este gresita\n";
				goto loop4;
				break;
			default:
				cout << "Optiunea nu este valida\n";
				Sleep(1000);
				goto Vizalim;
				break;
			}
			break;
		case 3:
		Intralim:
			system("cls");
			cout << "-----Pentru data " << datac << " :\n"
				<< "Vizualizare progres\nVizualizare produse\n"
				<< "Introduceti un produs consumat\n"
				<< "\t>1.Mic Dejun\n\t>2.Pranz\n\t>3.Cina\n\t>4.Gustari\n"
				<<"Intoarce-te la meniul anterior\n";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
				alim.createProdus(1, datac);
			loop41:
				cout << "Apasa (1) ca sa te intorci.";
				cin >> choice;
				if (choice == 1)
					goto minimen3;
				else cout << "Valoarea tastata este gresita\n";
				goto loop41;
				break;
			case 2:
				alim.createProdus(2, datac);
			loop42:
				cout << "Apasa (1) ca sa te intorci.";
				cin >> choice;
				if (choice == 1)
					goto minimen3;
				else cout << "Valoarea tastata este gresita\n";
				goto loop42;
				break;
			case 3:
				alim.createProdus(3, datac);
			loop43:
				cout << "Apasa (1) ca sa te intorci.";
				cin >> choice;
				if (choice == 1)
					goto minimen3;
				else cout << "Valoarea tastata este gresita\n";
				goto loop43;
				break;
			case 4:
				alim.createProdus(4, datac);
			loop44:
				cout << "Apasa (1) ca sa te intorci.";
				cin >> choice;
				if (choice == 1)
					goto minimen3;
				else cout << "Valoarea tastata este gresita\n";
				goto loop44;
				break;
			default:
				cout << "Optiunea nu este valida\n";
				Sleep(1000);
				goto Intralim;
				break;
			}
			break;
		case 4:
			goto Meniu3;
			break;
		default:
			cout << "Optiunea nu este valida\n";
			Sleep(1000);
			goto minimen3;
			break;
		}

		break;
	case 3:
		goto Meniu1;
		break;
	case 4:
		exit(0);
	default:
		cout << "Optiunea nu este valida\n";
		Sleep(1000);
		goto Meniu3;
		break;
	}

	//----------------sfarsit meniu 3----------------

}