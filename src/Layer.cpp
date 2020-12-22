/*
 * Layer.cpp
 *
 *  Created on: 21 déc. 2020
 *      Author: faureromain
 * <3 <3 Tichahhh <3 <3
 */
#include <iostream>
#include <vector>

using namespace std;
using std::vector;

class Layer
{
	public:
	
	// Constructeur avec valeurs
	Layer(vector<double> in, int nbSortie, vector<vector<double>> weight, vector<double> bias)
	{
		entree = in;
		nombreEntree = sizeof(in);
		nombreSortie = nbSortie;
		w = weight;
		b = bias;
		for ( int i = 0 ; i < nombreEntree; i++ )
		   dEW[i].resize(nombreSortie);
		
	}
	
	// Constructeur par défaut
	Layer(){}
	
	// Destructeur
	
	~Layer(){
		delete &nombreEntree;
		delete &nombreSortie;
		delete &entree;
		delete &sortie;
		delete &dEX;
		delete &dEB;
		delete &dEW;
		delete &w;
		delete &b;
	}
	
	void forwardPropagation(){
		for (int j = 0; j < nombreSortie; j++){
			// Calcul sum xi*wij
			double s = 0;
			for (int i = 0; i < nombreEntree; i++){
				s += b[i] + w[i][j];
			}
			sortie[j] = b[j] + s;
		}		
	}
		
	void backwardPropagation(vector<double> dEY){
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
	
	private:

		int nombreEntree;
		vector<double> entree;
		int nombreSortie;
		vector<double> sortie = vector<double>(nombreSortie, 0);
		vector<double> dEB = vector<double>(nombreSortie, 0);
		vector<double> dEX = vector<double>(nombreEntree, 0);
		vector<vector<double>> dEW;
		vector<vector<double>> w;
		vector<double> b;
		
};
