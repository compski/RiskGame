#pragma once
#include "Strategy.h"
#include <ctime>
#include <iostream>
using std::vector;
using std::cout;

//Derived class
class Random : public Strategy{

public:

	void doStrategy(Country *c1){

		vector<Country*> VectorCountry = c1->getAdjacencyVector();
		
		for (vector<Country*>::iterator it = VectorCountry.begin(); it != VectorCountry.end(); ++it){
			if (c1->getNumArmies() > (*it)->getNumArmies()){
				if ((rand() % 2) + 1 == 2){
					bool countryConquered = BattleEngine::attack(c1, (*it));
					break;
				}//Random number between 1 and 2. if 2 it will attack
			}
		}

		cout << "\t Computer Turns End" << endl;
	};
};