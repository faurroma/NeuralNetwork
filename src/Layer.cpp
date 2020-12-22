/*
 * Layer.cpp
 *
 *  Created on: 21 déc. 2020
 *      Author: faureromain
 * <3 <3 Tichahhh <3 <3
 */
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
using std::vector;

class Layer
{
	public:
	/* Constructeur avec valeurs
	 *
	 */
	Layer(int neuronesEntree, int neuronesSortie)
	{
		vector<vector<double>> weight(neuronesEntree);
		for(int i = 0; i<neuronesEntree; i++)
		{
			weight[i].resize(neuronesSortie);
		}
		
		for(int i = 0; i<neuronesEntree; i++)
		{
			for(int j = 0; j<neuronesSortie; j++)
			{
				weight[i][j] = rand() % 100;
			}
		}
		
		w = weight;
		vector<double> bias(neuronesSortie);
		
	}
	
	// Constructeur par défaut
	Layer(){}
	
	// Destructeur
	
	~Layer(){
		for (int i = 0; i < w.size(); i++){
			w[i].clear();
		}
		w.clear();
		b.clear();
	}
	
	vector<double> forwardPropagation(vector<double> const& input){
		vector<double> output;
		for (int n = 0; n < w.size(); n++){
			// Calcul sum xi*wij
			double s = 0;
			for (int i = 0; i < input.size(); i++){
				s += w[n][i]*input[i];
			}
			output.push_back(b[n] + s);
		}
		return output;
	}

	vector<double> backwardPropagation(vector<double>& dEY, vector<double> const& entree, double const& learningRate){
		int nombreSortie = dEY.size();
		int nombreEntree = entree.size();
		// Calcul de dE/dw
		vector<vector<double>> dEW(nombreEntree);
		for(int i = 0; i < nombreEntree; i++)
		{
			for(int i = 0; i < nombreEntree; i++){
				for (int j = 0; j < nombreSortie; j++){
					dEW[i].push_back(dEY[j]*entree[i]);
				}
			}
		}	

		// Mise à jour de w
		for (int i = 0; i < nombreEntree; i++){
			for (int j = 0; j < nombreSortie; j++){
			    w[i][j] -= learningRate * dEW[i][j];
			}
		}
		// dE/db = dE/dy
		for (int j = 0; j < nombreSortie; j++){
			b[j] -= learningRate * dEY[j];
		}
		// Calcul de dE/dx
		vector<double> dEX(nombreEntree);
		for (int i = 0; i < nombreEntree; i++){
			double s = 0;
			for (int j = 0; j < nombreSortie; j++){
				s += dEY[j]*w[i][j];
			}
			dEX[i] = s;
		}
		return dEX;
	}
	
	private:

		vector<vector<double>> w;
		vector<double> b;
		
};
