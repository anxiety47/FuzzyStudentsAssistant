#pragma once
#include <iostream>
void Hello () //wypisuje na ekran opis czym jest aplikacja itp
{
	std::cout << "Welcome to the Future Student's Field of Study Assistance Application! " << std::endl;
	std::cout << "We will ask you a few questions regarding your interests, expectations and predictions about Matura exam results. " << std::endl;
	std::cout << "Please, be reasonable with the predictions - it will save you a lot of money from applying to Fields of Study " << std::endl;
	std::cout << "with enormous thresholds!" << std::endl;
}

void DescribeInterestsList() //opisuje jak zaznaczac zainteresowania
{
	std::cout << "Now, you will be presented with a list of interests. We'll ask you to pick 3 of them. " << std::endl;
	std::cout << "Pick the first one by entering the number next to it, and then follow with the importance " << std::endl;
	std::cout << "on a scale from 1 to 10 and press enter." << std::endl;
	std::cout << "For example, if you are very much into Mathematics, enter 1 9." << std::endl;
	std::cout << "Then, follow the same steps for the other 2. If you are interested in less than 3, enter 0 0 instead of the next interest." << std::endl;
}

void ShowInterestsList() //pula mozliwych zainteresowan
{
	std::cout << std::endl;
	std::cout << "Mathematics, 1" << "\t \t \t \t \t \t Electronics, 8" << std::endl;
	std::cout << "Physics and Astronomy, 2" << "\t \t \t \t Geography and Environment, 9" << std::endl;
	std::cout << "Computer Science, 3" << "\t \t \t \t \t Medicine-Connected and Chemistry, 10" << std::endl;
	std::cout << "Robotics, 4" << "\t \t \t \t \t \t Mechanics, 11" << std::endl;
	std::cout << "Engineering, 5" << "\t \t \t \t \t \t Biotechnology, 12" << std::endl;
	std::cout << "Civil Engineering, 6" << "\t \t  \t \t \t Mining and Geology, 13" << std::endl;
	std::cout << "Energetics, 7" << std::endl;
}

void AskForExpectations() //wypisuje o czym beda pozniejsze pytania i jak sie na nie odpowiada
{
	std::cout << std::endl;
	std::cout << "Good job! Now, tell us more about your expectations regarding studies, as well as your future life." << std::endl;
	std::cout << "Answer to each question with a single number on a scale 1-10, where 10 is the Definitely Yes and 1 is Definitely No:" << std::endl;
}

double GetPrestige() //czy chcesz studiowac na prestizowej uczelni
{
	double result;
	std::cout << std::endl;
	std::cout << "Do you want your university to be prestigious?" << std::endl;
	std::cin >> result;
	getchar();
	return result/10;
}

double GetHardWorking() //czy jestes sklonny duzo sie uczyc w skali 0 do 1
{
	double result;
	std::cout << std::endl;
	std::cout << "How hard do you want your studies to be?" << std::endl;
	std::cin >> result;
	getchar();
	return result/10;
}

double GetWorkDuring()//czy chcesz pracowac w trakcie studiow w skali 0 do 1
{
	double result;
	std::cout << std::endl;
	std::cout << "Are you planning to work in the field during your studies?" << std::endl;
	std::cin >> result;
	getchar();
	return result/10;
}

double GetEngineer() //czy zalezy Ci na inzynierze w skali 0 do 1
{
	double result;
	std::cout << std::endl;
	std::cout << "Is it important for you to get an Engineer Degree, rather than Bachelor of Science?" << std::endl;
	std::cin >> result;
	getchar();
	return result/10;
}

double GetMaster() //czy zalezy ci na tym zeby mozna bylo robic magisterke na wydziale
{
	double result;
	std::cout << std::endl;
	std::cout << "Is it important for you to have the possibility to continue onto Master of Science studies at the faculty?" << std::endl;
	std::cin >> result;
	getchar();
	return result/10;
}

double GetWorkAfter() //czy zalezy ci na tym zeby dostac prace zaraz po studiach
{
	double result;
	std::cout << std::endl;
	std::cout << "Is it crucial for you to find the job in this field as soon as you get your degree?" << std::endl;
	std::cin >> result;
	getchar();
	return result/10;
}

void AskForMoneyAspects() //Wypisuje obsluge pytania o wyplata
{
	std::cout << std::endl;
	std::cout << "Great! Next step is about something big (hopefully!) - your incomes. " << std::endl;
	std::cout << "Here, answer with the amount of money in PLN, e.g. 5000, not on a scale from 1-10!" << std::endl;
}
double GetSalary() //pyta ile chcialbys zarabiac pare lat po studiach w zlotowkach, przelicza potem na euro
{
	double result;
	std::cout << std::endl;
	std::cout << "What would be the minimal satisfactory salary for you few years after getting a degree?" << std::endl;
	std::cin >> result;
	getchar();
	std::cout << "You have entered " << result << " zloty, which is equivalent to " << int(result / 4.215) << " euro." << std::endl;
	return result;
}


void AskForBasicMaturaResults(double scores[3]) //pyta o wyniki podstawowej matury i umieszcza je w przekazanej tablicy, kolejnosc - matma, native language(polski), foreign language(angielski), skala 1-100
{
	std::cout << std::endl;
	std::cout << "Awesome! Only one more part to go now, it won't be too pleasent tho." << std::endl;
	std::cout << "It regards the Matura exam. First things first, the basic exams. Tell us please how high you expect to score (in %) at: " << std::endl;
	std::cout << "Maths: ";
	std::cin >> scores[0];
	getchar();
	std::cout << std::endl;
	std::cout << "Native language: ";
	std::cin >> scores[1];
	getchar();
	std::cout << std::endl;
	std::cout << "Foreign language: ";
	std::cin >> scores[2];
	getchar();
	std::cout << std::endl;


}

int GetHowManyAdvanced() //pyta ile przedmiotow rozszerzonych piszesz
{
	int how_many_exams;
	std::cout << std::endl;
	std::cout << "Good, the second-to-last question is: how many Advanced subjects will you take?" << std::endl;
	std::cin >> how_many_exams;
	getchar();
	return how_many_exams;
}

void ShowAdvancedMaturaSubcjects() //daje liste rozszerzen ktore mozna pisac, pomocnicza funkcja dla GetAdvancedMaturaScores (ponizej)
{
	std::cout << std::endl;
	std::cout << "Mathematics, 1" << "\t \t \t \t \t \t Biology, 5" << std::endl;
	std::cout << "Physics, 2" << "\t \t \t \t \t \t Geography, 6" << std::endl;
	std::cout << "Computer Science, 3" << "\t \t \t \t \t English, 7" << std::endl;
	std::cout << "Chemistry, 4" << "\t \t \t \t \t \t Other Foreign Language, 8" << std::endl;
}

void GetAdvancedMaturaScores(int how_many_exams, double scores[8]) //funkcja pokazujaca matury rozszerzona, pyta ktore z nich piszesz (ile piszesz - z pierwszego argumentu) i wpisuje do tablicy (drugi argument) odpowiedzi
{
	std::cout << std::endl;
	std::cout << "OK, last thing now and you will get your results!" << std::endl;
	std::cout << "Which Advanced subjects are you going to take on your Matura exams, and what scores you expect?" << std::endl;
	std::cout << "Enter a number next to the subject in question and the estimated score (in %)." << std::endl;
	std::cout << "For example, if you will write the exam in Mathematics, and you expect to get 70%, enter 1 70." << std::endl;
	ShowAdvancedMaturaSubcjects();
	for(int i=0; i<how_many_exams; i++)
	{
		int a, b;
		std::cin >> a >> b;
		scores[a - 1] = b;
	}
	getchar();

}

void ThankForParticipation() //dziekuje za udzial w zabawie i mowi ze zaraz poda wyniki
{
	std::cout << std::endl;
	std::cout << "Thank you for your time, we greatly appreciate that! Wait a moment, we are calculating the possible solutions." << std::endl;
}

void ShowAllScores(University TabOfUni[3]) //wypisuje na ekran wszystkie kierunki, mowiac z jakiego sa wydzialu i uniwerku, wraz z membershipem uzytkownika, #spam
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << std::endl << std::endl;
		std::cout << TabOfUni[i].name_of_university << std::endl;
		std::cout << std::endl << std::endl;
		for (int j = 0; j < TabOfUni[i].how_many_faculties; j++)
		{
			std::cout << std::endl;
			std::cout << TabOfUni[i].faculties[j].name_of_faculty << std::endl << std::endl;
			for (int k = 0; k < TabOfUni[i].faculties[j].how_many_fields; k++)
				std::cout << TabOfUni[i].faculties[j].fields[k] << std::endl;
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;
	}

}


void ShowShortScores(FieldOfStudy BestField[5], double Thresholds[5]) //wypisuje 5 najblizszych uzytkownikowi opcji, bardzo dokladnie
{

	if (BestField[0].students_membership_value < 0.15) //jesli bylo ciezko cos znalezc, to mowi zeby moze pomyslec o czym innym
	{
		std::cout << std::endl << "We are very sorry, but we could not find any Field of Study that would really suit you. " << std::endl;
		std::cout << "We advise you to mull it over, as maybe you should consider studying in another city, Humanist Studies," << std::endl;
		std::cout << " or even not going to university but rather seek a job? It is all up to you, good luck!" << std::endl;
	}
	else
	{
		std::cout << std::endl << "We appreciate your time, so here is a summary with a few Fields that we think are most suitable for you." << std::endl << std::endl;

		for (int i = 0; i < 5; i++) //dla kazdego z 5 najlepszych
		{
			std::string tmp1, tmp2; //pomocnicze zmienne zeby byly ladne zdania a nie true i false, o inzynierze i magisterce
			if (BestField[i].engineer_degree)
				tmp1 = "You will get an engineer degree";
			else tmp1 = "You will get a bachelor of science degree";

			if (BestField[i].master_possibility)
				tmp2 = "You can continue M.Sc. studies in this field here";
			else tmp2 = "You can't continue M.Sc. studies in this field here";

			//Ponizsza sciana tekstu wypisuje: dopasowanie studenta do kierunku w %, nazwe kierunku, wydzial i uczelnie,
			//mowi jaki jest prog i porownuje z wynikiem uzytkownika, mowi o inzynierze, magisterce, zarobkach, ilosci nauki, 
			//pracy podczas studiow i pracy po studiach (to wszystko w %). Jeœli prog jest blisko wyniku, wypisuje ze trzeba sie uczyc


			std::cout << "Matching in " << 100 * BestField[i].students_membership_value << "%: Field of study: " << BestField[i].name_of_field
				<< " at " << BestField[i].mother.name_of_faculty << ", " << BestField[i].mother.father.name_of_university << '.' << std::endl;
			std::cout << "Threshold there was " << BestField[i].threshold << ", while your score is " << Thresholds[i] << ". " << std::endl;
			std::cout << tmp1 << ", " << tmp2 << ", you will be earning around " << BestField[i].salary << std::endl;
			std::cout << "We estimate the amount of studying here at " << BestField[i].work_rate * 100 << " %, working while studying at " << BestField[i].work_during_studies * 100
				<< " %, and getting work after studies at " << BestField[i].work_after_studies * 100 << " %." << std::endl;
			if (BestField[i].threshold > Thresholds[i] - 0.05) std::cout << "Be advised, you have to study hard to get accepted here, as your score is near the threshold" << std::endl;
			std::cout << std::endl << std::endl;

		}
	}
}

void Byebye() //funkcja na papa :)
{
	std::cout << std::endl << "Thank you very much, we have reached the end together. We hope that this has been not only fun, but also helpful experience. See you at the University!" << std::endl << std::endl;
}