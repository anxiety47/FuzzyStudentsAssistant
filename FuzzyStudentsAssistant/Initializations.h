#pragma once
#include "FieldOfStudy.h"
#include "Faculty.h"
#include "University.h"
#include "Interests.h"
#include <allocators>


void InitializeUniversisites(University TabOfUni[3]) //tworzenie wszystkich uniwersytetow, w nich wydzialow a w nich kierunkow, wraz ze wszystkimi ich atrybutami
{
	//tworzenie uniwerku - nazwa, ile wydzialow, prestiz, czy uniwesytet
	University UJ("Jagiellonian University", 5, 1, true); //
	University AGH("AGH University of Science and Technology", 9, 0.9, true);
	University PK("Cracow University of Science", 6, 0.6, false);
	//przypisania do tablicy
	TabOfUni[0] = UJ;
	TabOfUni[1] = AGH;
	TabOfUni[2] = PK;
	//tworzenie tablicy wydzialow dla uniwerkow
	for(int i=0; i<3; i++)
		TabOfUni[i].faculties = new Faculty[TabOfUni[i].how_many_faculties];


	////////////////////////////UJ///////////////////////////////////////////////

	//tworzenie wydzialu - nazwa, ile kierunkow, numer zainteresowania1, numer zainteresowania2
	Faculty WMII("Faculty of Mathematics and Informatics", 5, mathematics, computer_science, TabOfUni[0]);	
	Faculty WFAiIS("Faculty of Physics, Astronomy and Applied Computer Science",4,physics_and_astronomy,computer_science, TabOfUni[0]);	//fizyka i informatyka
	Faculty WChUJ("Faculty of Chemistry", 2, medicine_and_chemistry, geography_and_environment, TabOfUni[0]); //chemia i srodowisko
	Faculty WBiNoZ("Faculty of Biology and Earth Sciences", 2, geography_and_environment, mining_and_geology, TabOfUni[0]); //geografia i geologia
	Faculty WBBiB("Faculty of Biochemistry, Biophysics and Biotechnology", 3, biotechnology, medicine_and_chemistry, TabOfUni[0]); //biotechnologie  i chemia
	//przypisanie wydzialow do UJ
	TabOfUni[0].faculties[0] = WMII;
	TabOfUni[0].faculties[0].SetMaturasRate(1, 1, 1, 0, 0, 0, 1, 1);
	TabOfUni[0].faculties[1] = WFAiIS;
	TabOfUni[0].faculties[1].SetMaturasRate(1, 1, 1, 0, 0, 0, 1, 1);
	TabOfUni[0].faculties[2] = WChUJ;
	TabOfUni[0].faculties[2].SetMaturasRate(1, 0, 0, 1, 1, 1, 1, 1);
	TabOfUni[0].faculties[3] = WBiNoZ;
	TabOfUni[0].faculties[3].SetMaturasRate(1, 0, 0, 0, 1, 1, 1, 1);
	TabOfUni[0].faculties[4] = WBBiB;
	TabOfUni[0].faculties[4].SetMaturasRate(1, 1, 0, 1, 1, 0, 1, 1);
		
	//Tworzenie miejsca na kierunki na konkretnym wydziale
	TabOfUni[0].faculties[0].fields = new FieldOfStudy[TabOfUni[0].faculties[0].how_many_fields];
	TabOfUni[0].faculties[1].fields = new FieldOfStudy[TabOfUni[0].faculties[1].how_many_fields];
	TabOfUni[0].faculties[2].fields = new FieldOfStudy[TabOfUni[0].faculties[2].how_many_fields];
	TabOfUni[0].faculties[3].fields = new FieldOfStudy[TabOfUni[0].faculties[3].how_many_fields];
	TabOfUni[0].faculties[4].fields = new FieldOfStudy[TabOfUni[0].faculties[4].how_many_fields];

	//tworzenie kierunku, prog, inzynier, magister, duzo pracy, praca rownolegle, praca po, zarobki, staz pieniazki, zainteresowania 1 2 3
	//Przypisanie kierunku do wydzialu
	
	//WMII
	// matematyka
	FieldOfStudy WMII_Mathematics("Mathematics", 0.6, false, true, 0.7, 0.1, 0.2, 4500, mathematics, computer_science, none, TabOfUni[0].faculties[0]);
	TabOfUni[0].faculties[0].fields[0] = WMII_Mathematics;
	// matematyka komputerowa
	FieldOfStudy WMII_Computer_Mathematics("Computer Mathematics", 0.6, false, true, 0.8, 0.4, 0.4, 5000, mathematics, computer_science, none, TabOfUni[0].faculties[0]);
	TabOfUni[0].faculties[0].fields[1] = WMII_Computer_Mathematics;
	// informatyka
	FieldOfStudy WMII_Computer_Science("Computer Science", 0.79, false, true, 0.75, 0.8, 0.85, 6700, mathematics, computer_science, none, TabOfUni[0].faculties[0]);
	TabOfUni[0].faculties[0].fields[2] = WMII_Computer_Science;
	// informatyka analityczna
	FieldOfStudy WMII_Analytical_Computer_Science("Analytical Computer Science", 0.86, false, true, 1, 0.9, 1, 10000, mathematics, computer_science, none, TabOfUni[0].faculties[0]);
	TabOfUni[0].faculties[0].fields[3] = WMII_Analytical_Computer_Science;
	// informatyka (spec. bioinformatyka)
	FieldOfStudy WMII_Bio_Computer_Science("Bio Computer Science", 0.375, false, true, 0.4, 0.4, 0.75, 5500, mathematics, computer_science, none, TabOfUni[0].faculties[0]);
	TabOfUni[0].faculties[0].fields[4] = WMII_Bio_Computer_Science;

	//WFAiIS
	// informatyka
	FieldOfStudy WFAiIS_Computer_Science("Computer Science", 0.455, false, true, 0.45, 0.7, 0.8, 3845, mathematics, computer_science, physics_and_astronomy, TabOfUni[0].faculties[1]);
	TabOfUni[0].faculties[1].fields[0] = WFAiIS_Computer_Science;
	//Fizyka
	FieldOfStudy WFAiIS_Physics("Physics", 0.33, false, true, 0.4, 0.3, 0.6, 3400, mathematics, physics_and_astronomy, none, TabOfUni[0].faculties[1]);
	TabOfUni[0].faculties[1].fields[1] = WFAiIS_Physics;
	// Astronomia
	FieldOfStudy WFAiIS_Astronomy("Astronomy", 0.2, false, true, 0.3, 0.25, 0.4, 5100, mathematics, physics_and_astronomy, none, TabOfUni[0].faculties[1]);
	TabOfUni[0].faculties[1].fields[2] = WFAiIS_Astronomy;
	// Zaawansowane materia³y i nanotechnologie
	FieldOfStudy WFAiIS_Advanced_Materials_and_Nanotechnology("Advanced Materials and Nanotechnology", 0.095, false, true, 0.5, 0.2, 0.35, 3835, mathematics, physics_and_astronomy, engineering, TabOfUni[0].faculties[1]);
	TabOfUni[0].faculties[1].fields[3] = WFAiIS_Advanced_Materials_and_Nanotechnology;

	//WChUJ
	// chemia
	FieldOfStudy WChUJ_Chemistry("Chemistry", 0.45, false, true, 0.55, 0.15, 0.35, 3300, medicine_and_chemistry, none, none, TabOfUni[0].faculties[2]);
	TabOfUni[0].faculties[2].fields[0] = WChUJ_Chemistry;
	// ochrona srodowiska
	FieldOfStudy WChUJ_Environmental_Studies("Environmental Studies", 0.17, false, true, 0.2, 0.5, 0.2, 3047, geography_and_environment, medicine_and_chemistry, none, TabOfUni[0].faculties[2]);
	TabOfUni[0].faculties[2].fields[1] = WChUJ_Environmental_Studies;

	//WBiNoZ
	// geologia
	FieldOfStudy WBiNoZ_Geology("Geology", 0.56, false, true, 0.3, 0.2, 0.5, 3600, mining_and_geology, medicine_and_chemistry, geography_and_environment, TabOfUni[0].faculties[3]);
	TabOfUni[0].faculties[3].fields[0] = WBiNoZ_Geology;
	// geografia
	FieldOfStudy WBiNoZ_Geography("Geography", 0.533, false, true, 0.3, 0.3, 0.4, 3600, mining_and_geology, medicine_and_chemistry, geography_and_environment, TabOfUni[0].faculties[3]);
	TabOfUni[0].faculties[3].fields[1] = WBiNoZ_Geography;

	// WBBiB
	//biotechnologia
	FieldOfStudy WBBiB_Biotechnology("Biotechnology", 0.725, false, true, 0.6, 0.35, 0.3, 3500, biotechnology, physics_and_astronomy, engineering, TabOfUni[0].faculties[4]);
	TabOfUni[0].faculties[4].fields[0] = WBBiB_Biotechnology;
	//biofizyka
	FieldOfStudy WBBiB_Biophysics("Biophisics", 0.21, false, true, 0.35, 0.2, 0.5, 2900, biotechnology, physics_and_astronomy, none, TabOfUni[0].faculties[4]);
	TabOfUni[0].faculties[4].fields[1] = WBBiB_Biophysics;
	//biochemia
	FieldOfStudy WBBiB_Biochemistry("Biochemistry", 0.7, false, true, 0.65, 0.2, 0.55, 5000, biotechnology, medicine_and_chemistry, none, TabOfUni[0].faculties[4]);
	TabOfUni[0].faculties[4].fields[2] = WBBiB_Biochemistry;
	

	////////////////////////////AGH///////////////////////////////////////////////
	//tworzenie wydzialu - nazwa, ile kierunkow, numer zainteresowania1, numer zainteresowania2
	Faculty WGiG("Faculty of Mining and Geoengineering", 3, mining_and_geology, building_engineering, TabOfUni[1]);	//gornictwo i geologia, budownictwo
	Faculty WIMiIP("Faculty of Metals Engineering and Industrial Computer Science", 3, engineering, computer_science, TabOfUni[1]);	//inzynieria i informatyka
	Faculty WEAIiIB("Faculty of Electrical Engineering, Automatics, Computer Science and Biomedical Engineering", 5, electronics, robotics, TabOfUni[1]); //elektronika  i robotyka
	Faculty WIEiT("Faculty of Computer Science, Electronics and Telecommunications", 4, electronics, computer_science, TabOfUni[1]); //elektronika i informatyka
	Faculty WIMiR("Faculty of Mechanical Engineering and Robotics", 5, robotics,mechanics, TabOfUni[1]); //robotyka i mechanika
	Faculty WGGiOS("Faculty of Geology, Geophysics and Environmental Protection", 6, geography_and_environment, mining_and_geology, TabOfUni[1]); // srodowisko, gornictwo i  geologia	
	Faculty WEiP("Faculty of Energy and Fuels", 2,energetics,medicine_and_chemistry, TabOfUni[1]); //energetyka i chemia
	Faculty WFiIS("Faculty of Physics and Applied Computer Science", 3, physics_and_astronomy, computer_science, TabOfUni[1]); //fizyka i informatyka
	Faculty WMS("Faculty of Applied Mathematics", 1, mathematics, none, TabOfUni[1]); // matematyka
	
	//przypisanie wydzialow AGH
	TabOfUni[1].faculties[0] = WGiG;
	TabOfUni[1].faculties[0].SetMaturasRate(1, 1, 0, 0, 0, 1, 1, 1);
	TabOfUni[1].faculties[1] = WIMiIP;
	TabOfUni[1].faculties[1].SetMaturasRate(1, 1, 1, 1, 0, 0, 1, 1);
	TabOfUni[1].faculties[2] = WEAIiIB;
	TabOfUni[1].faculties[2].SetMaturasRate(1, 1, 1, 0, 1, 0, 1, 1);
	TabOfUni[1].faculties[3] = WIEiT;
	TabOfUni[1].faculties[3].SetMaturasRate(1, 1, 1, 0, 0, 0, 1, 1);
	TabOfUni[1].faculties[4] = WIMiR;
	TabOfUni[1].faculties[4].SetMaturasRate(1, 1, 0, 0, 0, 0, 1, 1);
	TabOfUni[1].faculties[5] = WGGiOS;
	TabOfUni[1].faculties[5].SetMaturasRate(1, 1, 1, 0, 0, 1, 1, 1);
	TabOfUni[1].faculties[6] = WEiP;
	TabOfUni[1].faculties[7].SetMaturasRate(1, 1, 0, 1, 0, 0, 1, 1);
	TabOfUni[1].faculties[7] = WFiIS;
	TabOfUni[1].faculties[7].SetMaturasRate(1, 1, 1, 0, 0, 0, 1, 1);
	TabOfUni[1].faculties[8] = WMS;
	TabOfUni[1].faculties[8].SetMaturasRate(1, 0, 0, 0, 0, 0, 1, 1);


	//Tworzenie miejsca na kierunki na konkretnym wydziale
	TabOfUni[1].faculties[0].fields = new FieldOfStudy[TabOfUni[1].faculties[0].how_many_fields];
	TabOfUni[1].faculties[1].fields = new FieldOfStudy[TabOfUni[1].faculties[1].how_many_fields];
	TabOfUni[1].faculties[2].fields = new FieldOfStudy[TabOfUni[1].faculties[2].how_many_fields];
	TabOfUni[1].faculties[3].fields = new FieldOfStudy[TabOfUni[1].faculties[3].how_many_fields];
	TabOfUni[1].faculties[4].fields = new FieldOfStudy[TabOfUni[1].faculties[4].how_many_fields];
	TabOfUni[1].faculties[5].fields = new FieldOfStudy[TabOfUni[1].faculties[5].how_many_fields];
	TabOfUni[1].faculties[6].fields = new FieldOfStudy[TabOfUni[1].faculties[6].how_many_fields];
	TabOfUni[1].faculties[7].fields = new FieldOfStudy[TabOfUni[1].faculties[7].how_many_fields];
	TabOfUni[1].faculties[8].fields = new FieldOfStudy[TabOfUni[1].faculties[8].how_many_fields];
	
	//WGiG
	// budownictwo
	FieldOfStudy WGiG_Civil_Engineering("Civil Engineering", 0.8, true, true, 0.4, 0.35, 0.6, 3960, building_engineering, mining_and_geology, none, TabOfUni[1].faculties[0]);
	TabOfUni[1].faculties[0].fields[0] = WGiG_Civil_Engineering;
	// gornictwo i geologia
	FieldOfStudy WGiG_Mining_and_Geology("Mining and Geology", 0.29, true, true, 0.3, 0.25, 0.5, 5800, mining_and_geology, none, none, TabOfUni[1].faculties[0]);
	TabOfUni[1].faculties[0].fields[1] = WGiG_Mining_and_Geology;
	// inzynieria srodowiska
	FieldOfStudy WGiG_Environmental_Engineering("Environmental Engineering", 0.3, true, true, 0.15, 0.4, 0.25, 3200, geography_and_environment, engineering, none, TabOfUni[1].faculties[0]);
	TabOfUni[1].faculties[0].fields[2] = WGiG_Environmental_Engineering;

	//WIMiIP
	//informatyka stosowana
	FieldOfStudy WIMiIP_Applied_Computer_Science("Applied Computer Science", 0.7, true, true, 0.6, 0.8, 0.85, 5500, computer_science, engineering, mathematics, TabOfUni[1].faculties[1]);
	TabOfUni[1].faculties[1].fields[0] = WIMiIP_Applied_Computer_Science;
	//inzynieria materialowa
	FieldOfStudy WIMiIP_Materials_Science("Materials Science", 0.562, true, true, 0.65, 0.2, 0.45, 4272, engineering, mathematics, physics_and_astronomy, TabOfUni[1].faculties[1]);
	TabOfUni[1].faculties[1].fields[1] = WIMiIP_Materials_Science;
	// inzynieria obliczeniowa
	FieldOfStudy WIMiIP_Computational_Engineering("Computational Engineering", 0.540, true, true, 0.5, 0.15, 0.45, 4000, engineering, mathematics, computer_science, TabOfUni[1].faculties[1]);
	TabOfUni[1].faculties[1].fields[2] = WIMiIP_Computational_Engineering;

	//WEAIiIB
	//automatyka i robotyka
	FieldOfStudy WEAIiIB_Automatics_and_Robotics("Automatics and Robotics", 0.883, true, true, 0.7, 0.7, 0.7, 4500, robotics, mechanics, electronics, TabOfUni[1].faculties[2]);
	TabOfUni[1].faculties[2].fields[0] = WEAIiIB_Automatics_and_Robotics;
	//inzynieria biomedyczna
	FieldOfStudy WEAIiIB_Biomedical_Engineering("Biomedical Engineering", 0.8, true, true, 0.8, 0.3, 0.7, 4400, engineering, medicine_and_chemistry, none, TabOfUni[1].faculties[2]);
	TabOfUni[1].faculties[2].fields[1] = WEAIiIB_Biomedical_Engineering;
	//informatyka
	FieldOfStudy WEAIiIB_Computer_Science("Computer Science", 0.902, true, true, 0.85, 0.9, 0.9, 7000, computer_science, none, none, TabOfUni[1].faculties[2]);
	TabOfUni[1].faculties[2].fields[2] = WEAIiIB_Computer_Science;
	//elektrotechnika
	FieldOfStudy WEAIiIB_Electrotechnics("Electrotechnics", 0.718, true, true, 0.65, 0.75, 0.8, 4344, electronics, engineering, none, TabOfUni[1].faculties[2]);
	TabOfUni[1].faculties[2].fields[3] = WEAIiIB_Electrotechnics;
	//mikroelektronika w technice i medycynie
	FieldOfStudy WEAIiIB_Microelectronics_in_Industry_and_Medicine("Microelectronics in Industry and Medicine", 0.8, true, true, 0.75, 0.4, 0.85, 4200, electronics, engineering, medicine_and_chemistry, TabOfUni[1].faculties[2]);
	TabOfUni[1].faculties[2].fields[4] = WEAIiIB_Microelectronics_in_Industry_and_Medicine;

	//WIEiT
	//elektronika
	FieldOfStudy WIEiT_Electronics("Electronics", 0.792, true, true, 0.8, 0.55, 0.8, 4500, electronics, none, none, TabOfUni[1].faculties[3]);
	TabOfUni[1].faculties[3].fields[0] = WIEiT_Electronics;
	//elektronika  i telekomunikacja
	FieldOfStudy WIEiT_Electronics_and_Telecommunications("Electronics and Telecommunications", 0.798, true, true, 0.85, 0.65, 0.85, 4800, electronics, engineering, none, TabOfUni[1].faculties[3]);
	TabOfUni[1].faculties[3].fields[1] = WIEiT_Electronics_and_Telecommunications;
	//informatyka
	FieldOfStudy WIEiT_Computer_Science("Computer Science", 0.912, true, true, 0.9, 0.9, 0.95, 8000, computer_science, none, none, TabOfUni[1].faculties[3]);
	TabOfUni[1].faculties[3].fields[2] = WIEiT_Computer_Science;
	//teleinforamtyka
	FieldOfStudy WIEiT_Teleinformatics("Teleinformatics", 0.88, true, true, 0.85, 0.75, 0.9, 4200, computer_science, electronics, none, TabOfUni[1].faculties[3]);
	TabOfUni[1].faculties[3].fields[3] = WIEiT_Teleinformatics;

	//WIMiR
	//Automatyka i robotyka
	FieldOfStudy WIMiR_Automatics_and_Robotics("Automatics and Robotics", 0.854, true, true, 0.7, 0.7, 0.7, 4200, robotics, mechanics, engineering, TabOfUni[1].faculties[4]);
	TabOfUni[1].faculties[4].fields[0] = WIMiR_Automatics_and_Robotics;
	//inzynieria akustyczna
	FieldOfStudy WIMiR_Acoustic_Engineering("Acoustic Engineering", 0.776, true, true, 0.5, 0.1, 0.2, 3000, engineering, none, none, TabOfUni[1].faculties[4]);
	TabOfUni[1].faculties[4].fields[1] = WIMiR_Acoustic_Engineering;
	//inzynieria mechaniczna  i materia³owa
	FieldOfStudy WIMiR_Mechanical_and_Materials_Engineering("Mechanical and Materials Engineering", 0.522, true, true, 0.4, 0.4, 0.5, 3350, engineering, mechanics, none, TabOfUni[1].faculties[4]);
	TabOfUni[1].faculties[4].fields[2] = WIMiR_Mechanical_and_Materials_Engineering;
	//mechatronika
	FieldOfStudy WIMiR_Mechatronics("Mechatronics", 0.782, true, true, 0.75, 0.55, 0.75, 4300, engineering, electronics, mechanics, TabOfUni[1].faculties[4]);
	TabOfUni[1].faculties[4].fields[3] = WIMiR_Mechatronics;
	//mechanika i budowa maszyn
	FieldOfStudy WIMiR_Mechanical_Engineering("Mechanical Engineering", 0.64, true, true, 0.75, 0.7, 0.8, 3700, mechanics, engineering, none, TabOfUni[1].faculties[4]);
	TabOfUni[1].faculties[4].fields[4] = WIMiR_Mechanical_Engineering;

	//WGGiOS
	//ekologiczne zrodla energii
	FieldOfStudy WGGiOS_Ecological_Sources_of_Energy("Ecological Sources of Energy", 0.8, true, true, 0.3, 0.2, 0.3, 3800, geography_and_environment, engineering, none, TabOfUni[1].faculties[5]);
	TabOfUni[1].faculties[5].fields[0] = WGGiOS_Ecological_Sources_of_Energy;
	//geofizyka
	FieldOfStudy WGGiOS_Geophysics("Geophysics", 0.508, true, true, 0.35, 0.15, 0.4, 4800, geography_and_environment, physics_and_astronomy, none, TabOfUni[1].faculties[5]);
	TabOfUni[1].faculties[5].fields[1] = WGGiOS_Geophysics;
	//gornictwo i geologia
	FieldOfStudy WGGiOS_Mining_and_Geology("Mining and Geology", 0.456, true, true, 0.35, 0.2, 0.55, 3900, mining_and_geology, none, none, TabOfUni[1].faculties[5]);
	TabOfUni[1].faculties[5].fields[2] = WGGiOS_Mining_and_Geology;
	//informatyka stosowana
	FieldOfStudy WGGiOS_Applied_Computer_Science("Applied Computer Science", 0.732, true, true, 0.5, 0.75, 0.7, 4700, computer_science, physics_and_astronomy,none, TabOfUni[1].faculties[5]);
	TabOfUni[1].faculties[5].fields[3] = WGGiOS_Applied_Computer_Science;
	//inzynieria srodowiska
	FieldOfStudy WGGiOS_Environmental_Engineering("Environmental Engineering", 0.502, true, true, 0.35, 0.45, 0.4, 4000, geography_and_environment, engineering, none, TabOfUni[1].faculties[5]);
	TabOfUni[1].faculties[5].fields[4] = WGGiOS_Environmental_Engineering;
	// ochrona srodowiska
	FieldOfStudy WGGiOS_Environmental_Protection("Environmental Protection", 0.404, true, true, 0.2, 0.2, 0.35, 3347, geography_and_environment, none, none, TabOfUni[1].faculties[5]);
	TabOfUni[1].faculties[5].fields[5] = WGGiOS_Environmental_Protection;

	//WEiP
	//energetyka
	FieldOfStudy WEiP_Energy_Engineering("Energy Engineering", 0.6, true, true, 0.6, 0.25, 0.45, 4887, energetics, engineering, none, TabOfUni[1].faculties[6]);
	TabOfUni[1].faculties[6].fields[0] = WEiP_Energy_Engineering;
	// technologia chemiczna
	FieldOfStudy WEiP_Chemical_Technology("Chemical Technology", 0.3, true, true, 0.4, 0.2, 0.35, 3200, medicine_and_chemistry, energetics, none, TabOfUni[1].faculties[6]);
	TabOfUni[1].faculties[6].fields[1] = WEiP_Chemical_Technology;

	//WFiIS
	// fizyka medyczna
	FieldOfStudy WFiIS_Medical_Physics("Medical Physics", 0.564, true, true, 0.55, 0.25, 0.45, 3475, physics_and_astronomy, medicine_and_chemistry, none, TabOfUni[1].faculties[7]);
	TabOfUni[1].faculties[7].fields[0] = WFiIS_Medical_Physics;
	// fizyka techniczna
	FieldOfStudy WFiIS_Technical_Physics("Technical Physics", 0.568, true, true, 0.65, 0.25, 0.45, 4100, physics_and_astronomy, computer_science, mathematics, TabOfUni[1].faculties[7]);
	TabOfUni[1].faculties[7].fields[1] = WFiIS_Technical_Physics;
	//informatyka stosowana
	FieldOfStudy WFiIS_Applied_Computer_Science("Applied Computer Science", 0.842, true, true, 0.8, 0.8, 0.8, 6044, computer_science, physics_and_astronomy, mathematics, TabOfUni[1].faculties[7]);
	TabOfUni[1].faculties[7].fields[2] = WFiIS_Applied_Computer_Science;

	//WMS
	//matematyka stosowana
	FieldOfStudy WMS_Mathematics("Mathematics", 0.744, false, true, 0.6, 0.1, 0.2, 3000, mathematics, none, none, TabOfUni[1].faculties[8]);
	TabOfUni[1].faculties[8].fields[0] = WMS_Mathematics;



	////////////////////////////PK////////////////////////////////////////////////
	//tworzenie wydzialu - nazwa, ile kierunkow, numer zainteresowania1, numer zainteresowania2
	Faculty WFMiI("Faculty of Physics, Mathematics and Computer Science", 4, physics_and_astronomy, mathematics, TabOfUni[2]); // wydzia³ fizyki matematyki i informatyki	
	Faculty WIEiK("Faculty of Electrical and Computer Engineering", 3, electronics, computer_science, TabOfUni[2]);	//wydzia³ inzynierii elektrycznej i komputerowej
	Faculty WIL("Faculty of Civil Engineering", 1, building_engineering, 0, TabOfUni[2]);	//wydzial inzynierii l¹dowej
	Faculty WIS("Faculty of Environmental Engineering", 2, geography_and_environment, building_engineering, TabOfUni[2]);	// wydzial inzynierii œrodowiska 
	Faculty WM("Faculty of Mechanical Engineering", 7, mechanics, engineering, TabOfUni[2]);		// wydzia³ mechaniczny
	Faculty WIiTC("Faculty of Chemical Engineering and Technology", 4, biotechnology, medicine_and_chemistry, TabOfUni[2]); // wydzia³ inzynierii i technologii chemicznej	

	//przypisanie wydzialow AGH
	TabOfUni[2].faculties[0] = WFMiI;
	TabOfUni[2].faculties[0].SetMaturasRate(1, 1, 1, 0, 0, 0, 0, 0);
	TabOfUni[2].faculties[1] = WIEiK;
	TabOfUni[2].faculties[1].SetMaturasRate(1, 1, 1, 0, 0, 0, 0, 0);
	TabOfUni[2].faculties[2] = WIL;
	TabOfUni[2].faculties[2].SetMaturasRate(1, 1, 0, 0, 0, 0, 0, 0);
	TabOfUni[2].faculties[3] = WIS;
	TabOfUni[2].faculties[3].SetMaturasRate(1, 1, 0, 0, 0, 1, 0, 0);
	TabOfUni[2].faculties[4] = WM;
	TabOfUni[2].faculties[4].SetMaturasRate(1, 1, 1, 0, 1, 0, 0, 0);
	TabOfUni[2].faculties[5] = WIiTC;
	TabOfUni[2].faculties[5].SetMaturasRate(1, 1, 0, 1, 1, 0, 0, 0);


	//Tworzenie miejsca na kierunki na konkretnym wydziale
	TabOfUni[2].faculties[0].fields = new FieldOfStudy[TabOfUni[2].faculties[0].how_many_fields];
	TabOfUni[2].faculties[1].fields = new FieldOfStudy[TabOfUni[2].faculties[1].how_many_fields];
	TabOfUni[2].faculties[2].fields = new FieldOfStudy[TabOfUni[2].faculties[2].how_many_fields];
	TabOfUni[2].faculties[3].fields = new FieldOfStudy[TabOfUni[2].faculties[3].how_many_fields];
	TabOfUni[2].faculties[4].fields = new FieldOfStudy[TabOfUni[2].faculties[4].how_many_fields];
	TabOfUni[2].faculties[5].fields = new FieldOfStudy[TabOfUni[2].faculties[5].how_many_fields];
	
	// WFMiI
	// fizyka techniczna
	FieldOfStudy WFMiI_Technical_Physics("Technical Physics", 0.2, true, true, 0.35, 0.3, 0.3, 3700, physics_and_astronomy, computer_science, none, TabOfUni[2].faculties[0]);
	TabOfUni[2].faculties[0].fields[0] = WFMiI_Technical_Physics;
	//informatyka
	FieldOfStudy WFMiI_Computer_Science("Computer Science", 0.52, true, true, 0.45, 0.75, 0.7, 4500, computer_science, none, none, TabOfUni[2].faculties[0]);
	TabOfUni[2].faculties[0].fields[1] = WFMiI_Computer_Science;
	//matematyka
	FieldOfStudy WFMiI_Mathematics("Mathematics", 0.3, false, true, 0.4, 0.1, 0.2, 3000, mathematics, none, none, TabOfUni[2].faculties[0]);
	TabOfUni[2].faculties[0].fields[2] = WFMiI_Mathematics;
	// nanotechnologie  i nanomaterialy
	FieldOfStudy WFMiI_Nanotechnologies_and_Nanomaterials("Nanotechnologies and Nanomaterials", 0.2, true, false, 0.3, 0.3, 0.3, 3600, physics_and_astronomy, engineering, none, TabOfUni[2].faculties[0]);
	TabOfUni[2].faculties[0].fields[3] = WFMiI_Nanotechnologies_and_Nanomaterials;

	//WIEiK
	// elektrotechnika
	FieldOfStudy WIEiK_Electrotechnics("Electrotechnics", 0.46, true, true, 0.4, 0.5, 0.55, 3400, electronics, engineering, none, TabOfUni[2].faculties[1]);
	TabOfUni[2].faculties[1].fields[0] = WIEiK_Electrotechnics;
	//energetyka
	FieldOfStudy WIEiK_Energy_Engineering("Energy Engineering", 0.43, true, true, 0.3, 0.25, 0.3, 3800, energetics, engineering, none, TabOfUni[2].faculties[1]);
	TabOfUni[2].faculties[1].fields[1] = WIEiK_Energy_Engineering;
	//informatyka
	FieldOfStudy WIEiK_Computer_Science("Computer Science", 0.67, true, false, 0.35, 0.7, 0.75, 5000, computer_science, engineering, none, TabOfUni[2].faculties[1]);
	TabOfUni[2].faculties[1].fields[2] = WIEiK_Computer_Science;
	
	//WIL
	//budownictwo
	FieldOfStudy WIL_Civil_Engineering("Civil Engineering", 0.38, true, true, 0.4, 0.3, 0.7, 3200, building_engineering, none, none, TabOfUni[2].faculties[2]);
	TabOfUni[2].faculties[2].fields[0] = WIL_Civil_Engineering;

	//WIS
	//budownictwo
	FieldOfStudy WIS_Civil_Engineering("Civil Engineering", 0.2, true, true, 0.30, 0.25, 0.6, 2800, building_engineering, geography_and_environment, none, TabOfUni[2].faculties[3]);
	TabOfUni[2].faculties[3].fields[0] = WIS_Civil_Engineering;
	// inzynieria srodowiska
	FieldOfStudy WIS_Environmental_Engineering("Environmental Engineering", 0.2, true, true, 0.15, 0.20, 0.15, 2600, geography_and_environment, engineering, none, TabOfUni[2].faculties[3]);
	TabOfUni[2].faculties[3].fields[1] = WIS_Environmental_Engineering;

	//WM
	// automatyka i robotyka
	FieldOfStudy WM_Automatics_and_Robotics("Automatics and Robotics", 0.48, true, true, 0.5, 0.65, 0.6, 3500, robotics, mechanics, engineering, TabOfUni[2].faculties[4]);
	TabOfUni[2].faculties[4].fields[0] = WM_Automatics_and_Robotics;
	//energetyka
	FieldOfStudy WM_Energy_Engineering("Energy Engineering", 0.28, true, true, 0.35, 0.3, 0.3, 3300, energetics, engineering, none, TabOfUni[2].faculties[4]);
	TabOfUni[2].faculties[4].fields[1] = WM_Energy_Engineering;
	//informatyka stosowana
	FieldOfStudy WM_Applied_Computer_Science("Applied Computer Science", 0.47, true, true, 0.35, 0.75, 0.6, 4200, computer_science, engineering, none, TabOfUni[2].faculties[4]);
	TabOfUni[2].faculties[4].fields[2] = WM_Applied_Computer_Science;
	//inzynieria biomedyczna
	FieldOfStudy WM_Biomedical_Engineering("Biomedical Engineering", 0.535, true, true, 0.4, 0.25, 0.4, 3400, engineering, medicine_and_chemistry, none, TabOfUni[2].faculties[4]);
	TabOfUni[2].faculties[4].fields[3] = WM_Biomedical_Engineering;
	// inzynieria materia³owa
	FieldOfStudy WM_Materials_Engineering("Materials Engineering", 0.25, true, true, 0.25, 0.25, 0.35, 3100, engineering, physics_and_astronomy, none, TabOfUni[2].faculties[4]);
	TabOfUni[2].faculties[4].fields[4] = WM_Materials_Engineering;
	// inzynieria wzornictwa przemyslowego
	FieldOfStudy WM_Industrial_Design_Engineering("Industrial Design Engineering", 0.51, true, false, 0.4, 0.15, 0.3, 3700, engineering, none, none, TabOfUni[2].faculties[4]);
	TabOfUni[2].faculties[4].fields[5] = WM_Industrial_Design_Engineering;
	// mechanika i budowa maszyn
	FieldOfStudy WM_Mechanical_Engineering("Mechanical Engineering", 0.37, true, true, 0.3, 0.6, 0.6, 3000, mechanics, engineering, none, TabOfUni[2].faculties[4]);
	TabOfUni[2].faculties[4].fields[6] = WM_Mechanical_Engineering;

	// WIiTC
	//biotechnologia
	FieldOfStudy WIiTC_Biotechnology("Biotechnology", 0.5, true, true, 0.3, 0.3, 0.2, 2900, biotechnology,engineering, none, TabOfUni[2].faculties[5]);
	TabOfUni[2].faculties[5].fields[0] = WIiTC_Biotechnology;
	//inzynieria chemiczna i procesowa
	FieldOfStudy WIiTC_Chemical_and_Process_Engineering("Chemical and Process Engineering", 0.52, true, true, 0.35, 0.2, 0.2, 3800, medicine_and_chemistry, engineering, none, TabOfUni[2].faculties[5]);
	TabOfUni[2].faculties[5].fields[1] = WIiTC_Chemical_and_Process_Engineering;
	// nanotechnologie  i nanomaterialy
	FieldOfStudy WIiTC_Nanotechnologies_and_Nanomaterials("Nanotechnologies and Nanomaterials", 0.28, true, false, 0.25, 0.3, 0.3, 3800, physics_and_astronomy, engineering, none, TabOfUni[2].faculties[5]);
	TabOfUni[2].faculties[5].fields[2] = WIiTC_Nanotechnologies_and_Nanomaterials;
	//technologia chemiczna
	FieldOfStudy WIiTC_Chemical_Technology("Chemical Technology", 0.4, true, false, 0.35, 0.25, 0.25, 3600, medicine_and_chemistry, engineering, none, TabOfUni[2].faculties[5]);
	TabOfUni[2].faculties[5].fields[3] = WIiTC_Chemical_Technology;

}
