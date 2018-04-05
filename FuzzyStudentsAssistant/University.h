#pragma once
#include <iostream>
#include <string>
class Faculty;
class University
{
public:
	University(std::string name = " ", int how_many = 0, double fame = 0, bool is_uni = false) //konstruktor, jesli wywola sie pusty to nada wartosci takie jak po =, ale mozna tez je wszystkie normalnie wpisac
	{
		name_of_university = name;
		how_many_faculties = how_many;
		prestige = fame;
		is_university = is_uni;
		faculties = nullptr;
	}
	~University() {}
	std::string name_of_university; //nazwa uniwersytetu
	int how_many_faculties; //ile wydzialow
	double prestige; //prestiz w skali 0-1
	bool is_university; //czy jest uniwersytetem - PK nie jest
	Faculty* faculties; //tablica na wydzialy


};

