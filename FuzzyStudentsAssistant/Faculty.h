#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "University.h"
#include "Variables.h"
class FieldOfStudy;
class Faculty;
double maximum_advanced_science(Faculty x, double AdvancedMaturaResults[8]);
double maximum_advanced_language(Faculty x, double AdvancedMaturaResults[8]);
University EmptyUniversity;
class Faculty
{
public:
	Faculty(std::string name = " ", int how_many = 0, int focus1= 0, int focus2 = 0, University& uni = EmptyUniversity)
	{
		name_of_faculty = name;
		how_many_fields = how_many;
		main_focus1 = focus1;
		main_focus2 = focus2;
		fields = nullptr;
		father = uni;
		
	}
	~Faculty() {}
	std::string name_of_faculty; //nazwa wydzialu
	int how_many_fields; //ile kierunkow na tym wydziale
	int main_focus1; //glowna rzecz na tym wydziale
	int main_focus2; //glowna rzecz na tym wydziale nr 2
	FieldOfStudy* fields;
	University father;
	int MaturasRate[8]; //tablica w ktorej jesli 0 to dana matura sie nie wlicza, a jak 1 to sie wlicza
	void SetMaturasRate(int mathematics, int physics, int computer_science, int chemistry, int biology, int geography, int english, int other_language) //ciag 0 i 1 odpowiadajacy temu czy dana matura sie liczy czy nie
	{
		MaturasRate[0] = mathematics;
		MaturasRate[1] = physics;
		MaturasRate[2] = computer_science;
		MaturasRate[3] = chemistry;
		MaturasRate[4] = biology;
		MaturasRate[5] = geography;
		MaturasRate[6] = english;
		MaturasRate[7] = other_language;
	}
	double student_score;
	void CountStudentScoreUJ(double BasicMaturaResults[3], double AdvancedMaturaResults[8])
	{
		double language = std::max(BasicMaturaResults[2] / 2, maximum_advanced_language(*this, AdvancedMaturaResults));
		double science = std::max(maximum_advanced_science(*this, AdvancedMaturaResults), BasicMaturaResults[0] / 2);
		student_score = (2 * science + language)/300; // 3 * 100, bo progi na dostanie siê na studia s¹ w przedziale 0-1
		
	}

	void CountStudentScoreAGH(double BasicMaturaResults[3], double AdvancedMaturaResults[8])
	{
		double tmp = maximum_advanced_science(*this, AdvancedMaturaResults);
		if (tmp >= 80)	tmp += 100;													//jesli z rozszerzenia by³o wiecej ni¿ 80 pkt dodajemy do wyniku 100
		else tmp = std::max(tmp + 2 * (tmp - 30),AdvancedMaturaResults[0] + BasicMaturaResults[0]);	// dla wyniku z rozszerzenia mniejszego ni¿ 80
		double science = 4 * tmp;

		double tmp2 = maximum_advanced_language(*this, AdvancedMaturaResults);
		if (tmp2 >= 80) tmp2 += 100;
		else tmp2 = std::max(tmp2 + 2 * (tmp2 - 30), AdvancedMaturaResults[6] + BasicMaturaResults[2]);
		double language = tmp2;

		student_score = (science + language)/ 1000;
	}

	void CountStudentScorePK(double BasicMaturaResults[3], double AdvancedMaturaResults[8])
	{
		double advanced = 2 * maximum_advanced_science(*this, AdvancedMaturaResults);
		double basic = BasicMaturaResults[0];
		if (basic > advanced)	student_score = basic/200;
		else student_score = advanced/200;




	}
};

double maximum_advanced_language(Faculty x, double AdvancedMaturaResults[8])
{
	if (AdvancedMaturaResults[6] < AdvancedMaturaResults[7])
		return AdvancedMaturaResults[7];
	else return AdvancedMaturaResults[6];

}

double maximum_advanced_science(Faculty x, double AdvancedMaturaResults[8])
{
	double tabOfSubject[6];
	for (int i = 0; i < 6; i++)
	tabOfSubject[i] = AdvancedMaturaResults[i] * x.MaturasRate[i];	

	double max = -1000000;
	for(int i = 0; i < 6; i++)
	{
		if (max < tabOfSubject[i])
			max = tabOfSubject[i];
	}
	return max;
}

