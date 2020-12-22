/*
 * Layer.h
 *
 *  Created on: 21 déc. 2020
 *      Author: faureromain
 */

#ifndef INCLUDE_LAYER_H_
#define INCLUDE_LAYER_H_

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
	Layer(vector<double> in, int nbSortie, vector<vector<double>> weight, vector<double> bias){};
	
	// Constructeur par défaut
	Layer(){};
	
	// Destructeur
	
	~Layer(){};
	
	void forwardPropagation(){};
		
	void backwardPropagation(vector<double> dEY){};
	
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

#endif /* INCLUDE_LAYER_H_ */

