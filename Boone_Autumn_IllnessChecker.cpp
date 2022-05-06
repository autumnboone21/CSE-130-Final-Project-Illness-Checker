/*
4/21/2022????????????????????????????
Autumn Boone
Final Project
CSE 130 Section A with Dr. Yampolskiy
Description: illness symptoms checker
*/

// libraries
#include<iostream>
#include<cstdlib> // includes rand()
#include<ctime> // includes time()

// abbreviates cout, cin, and endl functions (from "std::cout" to simply "cout")
using namespace std;

class Person
{
	public:
		// assuming that a normal person is healthy (all symptoms are absent/false)
		bool fever = false;
		bool cough = false;
		bool sob = false;
		bool runny = false;
		bool headache = false;
		bool sneeze = false;
		bool fatigue = false;
};

class Patient: public Person
{
	public:
		Patient(){
			// finding random value for fever symptom
			int randNum1 = rand() % 2;
			if (randNum1 == 0)
			{
				fever = false;
			}
			else if (randNum1 == 1)
			{
				fever = true;
			}
			
			// finding random value for cough symptom
			int randNum2 = rand() % 2;
			if (randNum2 == 0)
			{
				cough = false;
			}
			else if (randNum2 == 1)
			{
				cough = true;
			}
			
			// finding random value for shortness of breath symptom
			int randNum3 = rand() % 2;
			if (randNum3 == 0)
			{
				sob = false;
			}
			else if (randNum3 == 1)
			{
				sob = true;
			}
			
			// finding random value for runny nose symptom
			int randNum4 = rand() % 2;
			if (randNum4 == 0)
			{
				runny = false;
			}
			else if (randNum4 == 1)
			{
				runny = true;
			}
			
			// finding random value for headache symptom
			int randNum5 = rand() % 2;
			if (randNum5 == 0)
			{
				headache = false;
			}
			else if (randNum5 == 1)
			{
				headache = true;
			}
			
			// finding random value for sneezing symptom
			int randNum6 = rand() % 2;
			if (randNum6 == 0)
			{
				sneeze = false;
			}
			else if (randNum6 == 1)
			{
				sneeze = true;
			}
			
			// finding random value for fatigue symptom
			int randNum7 = rand() % 2;
			if (randNum7 == 0)
			{
				fatigue = false;
			}
			else if (randNum7 == 1)
			{
				fatigue = true;
			}
		}
		int checkIllness(){
			if (fever && cough && sob && fatigue && !sneeze){
				return 1;
			}
			else if (runny && sneeze && !sob){
				return 2;
			}
			else if (fever && cough && headache && fatigue && !sob && !sneeze){
				return 3;
			}
			else{
				return 4;
			}
		}
};

int main()
{
	// main menu
	cout << "Welcome to Symptoms Checker\n\n";
	cout << "Guide:   * Common   + Sometimes/Rarely   - NO\n";
	cout << "=============================================\n";
	cout << "Symptoms            | COVID-19 | Cold | Flu |\n";
	cout << "Fever               |     *    |   +  |  *  |\n";
	cout << "Cough               |     *    |   +  |  *  |\n";
	cout << "Shortness of Breath |     *    |   -  |  -  |\n";
	cout << "Runny Nose          |     +    |   *  |  +  |\n";
	cout << "Headaches           |     +    |   +  |  *  |\n";
	cout << "Sneezing            |     -    |   *  |  -  |\n";
	cout << "Fatigue             |     *    |   +  |  *  |\n";
	cout << "=============================================\n";
	
	// asking user for how many patients they want to analyze
	cout << "\nEnter the number of patients: ";
	int patientCount = 0;
	cin >> patientCount;
	cout << "Thank you...\n";
	cout << "=============================================\n";
	
	// randomizing symptoms for "patientCount" patients
	// TODO: can you print like this : int covidCount, coldCount, fluCount, otherCount = 0;
	int covidCount = 0;
	int coldCount = 0;
	int fluCount = 0;
	int otherCount = 0;
	int illness = 0;
	srand(time(0));
	Patient patientarray[patientCount];
	for (int i=0; i<patientCount; i++)
	{
		illness = patientarray[i].checkIllness();
		
		// adding how many patients have sickness
		if (illness == 1){
			covidCount++;
		}
		if (illness == 2){
			coldCount++;
		}
		if (illness == 3){
			fluCount++;
		}
		if (illness == 4){
			otherCount++;
		}
	}
	
	// printing how many patients have each illness
	cout << "\nSymptoms Checker...\n\n";
	cout << covidCount << " patients have symptoms of COVID-19\n" << endl;
	cout << coldCount << " patients have symptoms of a cold\n" << endl;
	cout << fluCount << " patients have symptoms of the flu\n" << endl;
	cout << otherCount << " patents may have some other illness\n" << endl;
	cout << "=============================================\n";
	
	
	// printing out the percentages and + signs for each patient that has each illness
	int i;
	float covidPer = (float(covidCount)/patientCount)*100;
	float coldPer = (float(coldCount)/patientCount)*100;
	float fluPer = (float(fluCount)/patientCount)*100;
	float otherPer = (float(otherCount)/patientCount)*100;
	cout << "\nPercentage of each illness:\n\n";
	cout << "COVID-19: [" << covidPer << "%]" << endl;
	for (i=0; i<covidCount; i++)
	{
		cout << "+";
	}
	cout << "\n\n";
	cout << "Cold: [" << coldPer << "%]" << endl;
	for (i=0; i<coldCount; i++)
	{
		cout << "+";
	}
	cout << "\n\n";
	cout << "Flu: [" << fluPer << "%]" << endl;
	for (i=0; i<fluCount; i++)
	{
		cout << "+";
	}
	cout << "\n\n";
	cout << "Other illnesses: [" << otherPer << "%]" << endl;
	for (i=0; i<otherCount; i++)
	{
		cout << "+";
	}
	cout << "\n\n";
}

