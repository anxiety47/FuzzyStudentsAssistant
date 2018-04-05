#pragma once
#include <iostream>
#include <string>
#include "Faculty.h"
#include "Variables.h"
Faculty EmptyFaculty;
class FieldOfStudy
{
public:
	FieldOfStudy(std::string name = " ", double thres = 0, bool engineer = false, bool master = false, double hard_work = 0, double work_during = 0,
		double work_after = 0, int money = 0, int interest1 = 0, int interest2=0, int interest3=0, Faculty& faculty = EmptyFaculty) //mozna zrobic FieldOfStudy(), wtedy beda te wartosci po =
	{
		name_of_field = name; //nazwa kierunku
		threshold = thres; //prog dostania sie (od 0 do 1 jako % z maksa na danej uczelni)
		engineer_degree = engineer; //czy bedziesz inzynierem
		master_possibility = master; //czy mozna kontynuowac studia na wydziale
		work_rate = hard_work; //czy duzo sie trzeba uczyc, od 0 do 1
		work_during_studies = work_during; //czy da sie pracowac jednoczesnie ze studiami, od 0 do 1
		work_after_studies = work_after; //czy latwo znalezc prace zaraz po studiach, od 0 do 1
		salary = money; //oczekiwana srednia pensja pare lat po studiach
		first_interest = interest1; //glowna rzecz na kierunku, np u nas informatyka (rzekomo)
		second_interest = interest2; //mniej glowna rzecz na kierunku, np u nas fizyka (ehh)
		third_interest = interest3; //jeszcze mniej glowna rzecz, np matma
		interests_compability = 0;
		students_membership_value = 0;
		mother = faculty;
		
	}
	~FieldOfStudy() {}
	std::string name_of_field;
	double threshold; //prog, skalowany do 1 jako max punktow na danej uczelni
	bool engineer_degree;
	bool master_possibility;
	double work_rate;
	double work_during_studies;
	double work_after_studies;
	int salary;
	int first_interest;
	int second_interest;
	int third_interest;
	double interests_compability;
	double students_membership_value;
	Faculty mother;
	void CompareInterests(Faculty faculty, double interests[3][2], double disliked[1][2])
	{
		double nominator = 0;
		double denominator = 0;
		double disliked_weight = 0;
		if (disliked[0][0] == first_interest || disliked[0][0] == second_interest || disliked[0][0] == third_interest)
			disliked_weight = disliked[0][1];
		if (interests[0][0] == 0)
		{
			interests_compability = 1 - disliked_weight; return; //jesli byly same 0 to go nie obchodzi wiec wszedzie mu pasuje = wszystkie kierunki 1
		}
		if(interests[0][0] == first_interest || interests[0][0] == second_interest || interests[0][0] == third_interest)
		{
			if(interests[0][0] == faculty.main_focus1 || interests[0][0] == faculty.main_focus2)
			{
				nominator += 0.15;
				denominator += 0.15;
			}
			else if (faculty.main_focus2 != 0) denominator += 0.1;
			nominator += interests[0][1]/10;
			denominator += interests[0][1]/10;
		}
		else denominator += interests[0][1]/10;
		if (interests[1][0] == first_interest || interests[1][0] == second_interest || interests[1][0] == third_interest)
		{
			if (interests[1][0] == faculty.main_focus1 || interests[1][0] == faculty.main_focus2)
			{
				nominator += 0.15;
				denominator += 0.15;
			}
			else if(faculty.main_focus2!=0) denominator += 0.1;
			nominator += interests[1][1]/10;
			denominator += interests[1][1]/10;
		}
		else denominator += interests[1][1]/10;
		if (interests[2][0] == first_interest || interests[2][0] == second_interest || interests[2][0] == third_interest)
		{
			if (interests[2][0] == faculty.main_focus1 || interests[2][0] == faculty.main_focus2)
			{
				nominator += 0.15;
				denominator += 0.15;
			}
			else if (faculty.main_focus2 != 0) denominator += 0.1;
			nominator += interests[2][1]/10;
			denominator += interests[2][1]/10;
		}
		else denominator += interests[2][1]/10;

		interests_compability = nominator / denominator - disliked_weight;
	}
	void CheckIfNotBests(FieldOfStudy BestField[5], double thresholds[5], Faculty faculty)
	{

		if (students_membership_value > BestField[4].students_membership_value)
		{
			if (students_membership_value > BestField[0].students_membership_value)
			{
				BestField[4] = BestField[3];
				BestField[3] = BestField[2];
				BestField[2] = BestField[1];
				BestField[1] = BestField[0];
				BestField[0] = *this;
				thresholds[0] = faculty.student_score;
			}
			else if (students_membership_value > BestField[1].students_membership_value)
			{
				BestField[4] = BestField[3];
				BestField[3] = BestField[2];
				BestField[2] = BestField[1];
				BestField[1] = *this;
				thresholds[1] = faculty.student_score;
			}
			else if (students_membership_value > BestField[2].students_membership_value)
			{
				BestField[4] = BestField[3];
				BestField[3] = BestField[2];
				BestField[2] = *this;
				thresholds[2] = faculty.student_score;
			}
			else if (students_membership_value > BestField[3].students_membership_value)
			{
				BestField[4] = BestField[3];
				BestField[3] = *this;
				thresholds[3] = faculty.student_score;
			}
			else if (students_membership_value > BestField[4].students_membership_value)
			{
				BestField[4] = *this;
				thresholds[4] = faculty.student_score;
			}
		}
	}
	
};

std::ostream& operator<< (std::ostream& screen, const FieldOfStudy& field) //przeladowanie zeby dzialalo cout << kierunek, obecnie mowi o nazwie, progu, inzynierze, kontynuowaniu na magistra, stazach i zarobkach
{
	std::string tmp1, tmp2;
	if (field.engineer_degree)
		tmp1 = "You will get an engineer degree";
	else tmp1 = "You will get a bachelor of science degree";

	if (field.master_possibility)
		tmp2 = "You can continue M.Sc. studies in this field here";
	else tmp2 = "You can't continue M.Sc. studies in this field here";


	screen << "Matching in " << 100* field.students_membership_value << "%: Field of study: " << field.name_of_field << ", threshold: " << field.threshold << ", " << tmp1 << ", " << tmp2 << ", you will be earning around " << field.salary << std::endl;
	return screen;
}