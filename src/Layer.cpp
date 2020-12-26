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
#include "Layer.hpp"

using namespace std;
using std::vector;

	Layer::Layer(int neuronesEntree, int neuronesSortie)
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
				weight[i][j] = (double) rand()/ RAND_MAX;
			}
		}
		w = weight;
		vector<double> bias(neuronesSortie, 0);
		b = bias;
		
	}
	
	// Constructeur par défaut
	Layer::Layer(){}
	
	// Destructeur
	
	Layer::~Layer(){
		for (int i = 0; i < w.size(); i++){
			w[i].clear();
		}
		w.clear();
		b.clear();
	}
	
	vector<double> Layer::forwardPropagation(vector<double> const & in){
		input = in;
		vector<double> out;
		for (int n = 0; n < w[0].size(); n++){
			// Calcul sum xi*wij
			double s = 0;
			for (int i = 0; i < input.size(); i++){
				s += w[i][n]*in[i];

			}
			out.push_back(b[n] + s);
		}
		output = out;
		return out;
	}

	vector<double> Layer::backwardPropagation(vector<double> const & dEY, double const& learningRate){
		int nombreSortie = w[0].size();
		int nombreEntree = w.size();
		// Calcul de dE/dw
		vector<vector<double>> dEW(nombreEntree);
		for(int i = 0; i < nombreEntree; i++)
		{
			dEW[i].resize(nombreSortie);
			for(int j = 0; j < nombreSortie; j++){
				dEW[i][j] = dEY[j]*input[i];

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
		vector<double> dEX(nombreEntree, 0);
		for (int i = 0; i < nombreEntree; i++){
			for (int j = 0; j < nombreSortie; j++){
				dEX[i] += dEY[j]*w[i][j];
			}
		}
		return dEX;
	}

	int Layer::getInputSize(){
		return w.size();
	}

	int Layer::getOutputSize(){
		return w[0].size();
	}

	vector<double> Layer::getInput(){
		return input;
	}

	vector<double> Layer::getOutput(){
		return output;
	}
