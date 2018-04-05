
#include "MembershipFunctions.h"
#include "FieldOfStudy.h"
#include "Faculty.h"
#include "University.h"
#include "Interests.h"
#include "Communication.h"
#include "Initializations.h"
#include "Variables.h"
int main()
{
	////////////////////////////////INICJALIZACJE////////////////////////////////////////////////
	FieldOfStudy BestField[5];
	double ThresholdsBestField[5];
	University TabOfUni[3]; //zawiera uniwersytety, a w nich zawieraja sie wydzialy, a w nich kierunki
	InitializeUniversisites(TabOfUni); //nadawanie nazw, progow i innych atrybutow dla uniwersystetow, wydzialow i kierunkow
	for (int i = 0; i < 5; i++)
		BestField[i] = TabOfUni[0].faculties[0].fields[i];
	//////////////////////////////KONIEC INICJALIZACJI//////////////////////////////////////////////



	/////////////////////////////ROZMOWA Z UZYTKOWNIKEM///////////////////////////////////////////
	Hello(); //wypisywanie powitalnych linijek
	DescribeInterestsList(); //opisuje jak wpisac zainteresowania do programu
	ShowInterestsList(); //wypisuje mozliwe do wybrania zainteresowania
	std::cin >> interests[0][0] >> interests[0][1]; //uzytkownik wybiera 3 z nich i ich wagi
	std::cin >> interests[1][0] >> interests[1][1];
	std::cin >> interests[2][0] >> interests[2][1];
	getchar();
	if (interests[1][0] == none) interests[1][1] = 0.3; //jesli uzytkownik powiedzial, ze nie ma zainteresowan, to tez jakas wiedza dla nas
	if (interests[2][0] == none) interests[2][1] = 0.3; //dlatego nie dajemy wtedy wagi 0, tylko 3, aby premiowac czysta matematyke dla matematykow itp
	std::cout << "Now, if you have that one thing that you really hate, share it with us, we won't tell your teacher!" << std::endl; //dodana rzecz - mozna tez nie lubic jakiegos przedmiotu, wtedy jesli jest on jednym z 3 na kierunku to obnizamy zgodnosc uzytkownika i kierunku o "wage nienawisci" :)
	std::cout << "Put it the same way you did with your hobbies - number of subject, and how much you dislike it" << std::endl;
	std::cin >> disliked[0][0] >> disliked[0][1];
	getchar();
	disliked[0][1] /= 10;
	AskForExpectations(); //wypisuje wstep do kolejnych pytan, jak na nie odpowiadac itp
	how_prestigious = GetPrestige(); //prestiz uczelni
	hard_work = GetHardWorking(); //jak duzo uzytkownik chce sie uczyc - zarowno za malo jak i za duzo obniza membership value
	work_during = GetWorkDuring(); //czy chce pracowac w trakcie studiow
	engineer_importance = GetEngineer(); //czy zalezy mu na tytule inzyniera
	master_importance = GetMaster(); //czy zalezy mu na mozliwosci kontynuowania studiow na tym samym wydziale (w swoim kierunku)
	work_after = GetWorkAfter(); //czy zalezy mu na tym zeby od razu po studiach znalezc prace
	AskForMoneyAspects(); //wypisuje wstep do pytania o zarobki i w jaki sposob odpowiadac
	salary = GetSalary(); //jak duzo uzytkownik chce zarabiac pare lat po studiach - program automatycznie przelicza tez na euro
	AskForBasicMaturaResults(Scores); //pytamy jakie wyniki przewiduje z podstawowych matur i wpisujemy je do tablicy Scores
	how_many_adv = GetHowManyAdvanced(); //pytamy ile rozszerzen bedzie pisal
	GetAdvancedMaturaScores(how_many_adv, AdvancedScores); //przedmioty i przewidywane wyniki wpisujemy do tablicy AdvancedScores
	ThankForParticipation(); //dziekujemy za odpowiedzi, mowimy zeby chwile poczekac na wyniki

	////////////////KONIEC ODPOWIEDZI UZYTKOWNIKA////////////////////////////////



	/////////////////////////////LICZENIE WSKAZNIKOW REKRUTACYJNYCH, MEMBERSHIP FUNCTIONY DLA POSZCZEGOLNYCH POL////////////////////////////

	for (int i = 0; i < TabOfUni[0].how_many_faculties; i++) //dla kazdego wydzialu na UJ liczymy wynik rekrutacyjny uzytkownika
		TabOfUni[0].faculties[i].CountStudentScoreUJ(Scores, AdvancedScores);
	for (int i = 0; i < TabOfUni[1].how_many_faculties; i++) //dla kazdego wydzialu na AGH liczymy wynik rekrutacyjny uzytkownika
		TabOfUni[1].faculties[i].CountStudentScoreAGH(Scores, AdvancedScores);
	for (int i = 0; i < TabOfUni[2].how_many_faculties; i++) //dla kazdego wydzialu na PK liczymy wynik rekrutacyjny uzytkownika
		TabOfUni[2].faculties[i].CountStudentScorePK(Scores, AdvancedScores);
	std::cout << TabOfUni[2].faculties[0].student_score;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j<TabOfUni[i].how_many_faculties; j++)
			for (int k = 0; k < TabOfUni[i].faculties[j].how_many_fields; k++)
			{
				TabOfUni[i].faculties[j].fields[k].CompareInterests(TabOfUni[i].faculties[j], interests, disliked); //Obliczenie zgodnosci zainteresowan
				threshold_membership = linear_membership_function(TabOfUni[i].faculties[j].student_score, TabOfUni[i].faculties[j].fields[k].threshold - 0.1, TabOfUni[i].faculties[j].fields[k].threshold + 0.1); //czy uda mu sie dostac, niewielka tolerancja dla wahan progu
				if (TabOfUni[i].faculties[j].fields[k].engineer_degree == true) engineer_membership = 1; //jesli kierunek daje inzyniera to obojetne
				else engineer_membership = linear_membership_function(1 - engineer_importance, 0, 1); //jesli nie daje, to im wazniejsze to bylo dla uzytkownika,tym mniejszy powinien byc membership, stad 1-engineer
				if (TabOfUni[i].faculties[j].fields[k].master_possibility == true) master_membership = 1; //analogicznie jak engineer
				else master_membership = linear_membership_function(1 - master_importance, 0, 1); // analogicznie jak engineer
				work_rate_membership = triangular_membership_function(hard_work, TabOfUni[i].faculties[j].fields[k].work_rate, 0.5); //pytamy jak duzo chcialby sie uczyc, wiec zarowno za malo jak i za duzo sa zle, dlatego triangular
				work_after_membership = linear_membership_function(TabOfUni[i].faculties[j].fields[k].work_after_studies, 0, work_after); //kolejnosc jest taka, bo chcemy sie dowiedziec tak jakby jaki procent wymagan uzytkownika spelnia kierunek - jesli on chce 8 a dajemy 5, to 5/8. Jesli ponad 100% to 1.
				work_during_membership = linear_membership_function(TabOfUni[i].faculties[j].fields[k].work_during_studies, 0, work_during); //jak wyzej
				salary_membership = linear_membership_function(TabOfUni[i].faculties[j].fields[k].salary, salary / 2, salary); //mniej niz 2x to co napisal uzytkownik nie chce zarabiac na pewno, potem im wiecej tym bardziej powinien sie przekonywac
				interests_membership = TabOfUni[i].faculties[j].fields[k].interests_compability; //efekt funkcji wywolanej w linii 62, jesli zainteresowanie uzytkownika bylo zgodne z kierunkiem to dodajemy do licznika i mianownika, jesli nie to tylko do mianownika, main focusy wydzialu tez maja pewne (male) znaczenie
				prestige_membership = linear_membership_function(TabOfUni[i].prestige, how_prestigious / 2, how_prestigious); //prestiz, jest jeden dla calej uczelni, nie ma dla wydzialow, jesli ktos chce prestiz 10 to o mniej niz 5 nie chce slyszec, a potem to mu bedzie roslo, stad takie progi
				double Tab[9]; //tablica pomocnicza zeby mozna bylo przejechac petla po membershipach, szukajac minimum, ponizej przypisania do tej tablicy
				Tab[0] = threshold_membership; Tab[1] = engineer_membership; Tab[2] = master_membership; Tab[3] = work_rate_membership;
				Tab[4] = work_after_membership; Tab[5] = work_during_membership; Tab[6] = salary_membership; Tab[7] = interests_membership; Tab[8] = prestige_membership;
				TabOfUni[i].faculties[j].fields[k].students_membership_value = Minimum_Aggregation(Tab); //przypisanie do kierunku NAJWAZNIEJSZEJ wartosci - dopasowania kierunku i uzytkownika
				TabOfUni[i].faculties[j].fields[k].CheckIfNotBests(BestField, ThresholdsBestField, TabOfUni[i].faculties[j]); //sprawdzenie, czy obecnie rozwazany kierunek nie jest jednym z 5 najlepszych obecnie napotkanych pod katem dopasowania - jesli jest, to wrzucamy go na odpowiedniej pozycji, tak zeby tablica byla posortowana
			}

	ShowShortScores(BestField, ThresholdsBestField); //duzo dokladniejsze wypisanie 5 najlepszych propozycji dla uzytkownika, jesli wszystkie sa beznadziejne (ponizej 40%) to mowimy mu ze moze to nie jest do konca dla niego
	std::cout << std::endl << "Would you like to see specific results? Put 'y' and enter to see them, 'n' and enter not to. " << std::endl;
	char yes_or_no;
	std::cin >> yes_or_no; //jesli uzytkownik odpowiedzial ze chce dokladne wyniki to dajemy mu je
	getchar();
	if (yes_or_no == 'y')
		ShowAllScores(TabOfUni); //Pelny wypis wynikow, kazda uczelnia, wydzial i kierunek razem z dopasowaniem uzytkownika do niego 
	Byebye(); //Rzewne pozegnania
	getchar();
	return 0;

}