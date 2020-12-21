/*
 * Layer.cpp
 *
 *  Created on: 21 déc. 2020
 *      Author: faureromain
 */

#include <iostream>
#include <string>
#include <vector>

class Layer
{
	public:
	
	// Constructeur avec valeurs
	Layer(double in[], double out[])
	{
		entree = in;
		sortie = out;
	}
	
	// Constructeur par défaut
	Layer(){}
	
	// Destructeur
	
	~Layer(){
		if(entree!= NULL){
			delete[] entree;
		}
		if(sortie!= NULL){
			delete[] sortie;
		}
	}
	
	private:
	
		double entree[];
		double sortie[];
		
		
};
