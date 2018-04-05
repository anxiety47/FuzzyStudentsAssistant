#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>

double ObliczWynikUJ(double BasicScores[3], double AdvancedScores[8], int how_many_subjects)
{
	
}
double ObliczWynikAGH(double BasicScores[3], double AdvancedScores[8], int how_many_subjects)
{
	
}
double ObliczWynikPK(double BasicScores[3], double AdvancedScores[8], int how_many_subjects)
{
	double mathematical =  std::max(std::max(std::max(BasicScores[0], 2*AdvancedScores[0]), 2*AdvancedScores[1]), 2*AdvancedScores[2]);
	double nature = std::max(std::max(std::max(BasicScores[0], 2 * AdvancedScores[0]), 2 * AdvancedScores[1]), 2 * AdvancedScores[2]);
}