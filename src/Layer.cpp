/*
 * Layer.cpp
 *
 *  Created on: 21 déc. 2020
 *      Author: faureromain
 */

#include <iostream>
#include "Layer.h"

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
	
	void forwardPropagation(double w[][], double b[]){
		for (int j = 0; j < nombreSortie; j++){
			// Calcul sum xi*wij
			double s = 0;
			for (int i = 0; i < nombreEntree; i++){
				s += x[i] + w[i][j];
			}
			y[j] = b[j] + s;
		}
		// Activation 
		
	}
		
	void backwardPropagation(double dEY[]){
		// Calcul de dE/dw
		for(int i = 0; i < nombreEntree; i++){
			for (int j = 0; j < nombreSortie; j++){
				dEW[i][j] = dEY[j]*entree[i];
			}
		}
		// Calcul de dE/db
		for (int j = 0; j < nombreSortie; j++){
			dEB[j] = dEY[j];
		}
		// Calcul de dE/dx
		for (int i = 0; i < nombreEntree; i++){
			double s = 0;
			for (int j = 0; j < nombreSortie; j++){
				s += dEY[j]*w[i][j];
			}
			dEX[i] = s;
		}
	}
	
	virtual void forwardActivation();
	
	virtual void backwardActivation();
	
	private:
		int const nombreEntree;
		double entree[nombreEntree];
		int const nombreSortie;
		double nombreSortie[];
		double dEW[nombreEntree][nombreSortie];
		double dEB[nombreSortie];
		double dEX[nombreSortie];
		
		
};
