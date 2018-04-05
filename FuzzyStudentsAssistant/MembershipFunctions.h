#pragma once

double triangular_membership_function(double x, double x_opt, double x_left_right) //trojkatna funkcja przynaleznosci, x_opt to punkt w ktorym wartosc funkcji jest 1, a w x_opt +- x_left_right jest 0
{
	double a, b;
	if (x == x_opt)
		return 1;
	else if (x <= x_opt - x_left_right || x >= x_opt + x_left_right)
		return 0;
	else if (x < x_opt && x > x_opt - x_left_right)
	{
		a = 1 / x_left_right;
		b = (x_left_right - x_opt) / x_left_right;
	}
	else if (x > x_opt && x < x_opt + x_left_right)
	{
		a = -1 / x_left_right;
		b = (x_opt + x_left_right) / x_left_right;
	}
	return x*a + b;
}

double linear_membership_function(double x, double x_val0, double x_val1) //funkcja liniowa, x_val0 - ostatni punkt z zerem, x_val1 - pierwszy punkt z 1, pomiedzy nimi liniowo rosnie (i tylko rosnie!)
{
	double a, b;
	if (x >= x_val1) 
		return 1;
	else if (x <= x_val0)
		return 0;
	else if (x < x_val1 && x > x_val0)
	{
		a = 1 / (x_val1 - x_val0);
		b = -(x_val0) / (x_val1 - x_val0);
		return x*a + b;
	}
}

double Minimum_Aggregation(double Tab[9])
{

	double min = 1;
	for (int i = 0; i < 9; i++)
	{
		if (min > Tab[i])
			min=Tab[i];
	}
	return min;
}