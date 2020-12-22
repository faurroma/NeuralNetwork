/*
 * Layer.h
 *
 *  Created on: 21 déc. 2020
 *      Author: faureromain
 */

#ifndef INCLUDE_LAYER_H_
#define INCLUDE_LAYER_H_

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
using std::vector;

class Layer
{
	public:
	
	// Constructeur avec valeurs
	Layer(int neuronesEntree, int neuronesSortie);
	Layer();
	vector<double> forwardPropagation(vector<double> input);

	vector<double> backwardPropagation(vector<double> dEY, vector<double> entree, double learningRate);
	
	private:

		vector<vector<double>> w;
		vector<double> b;
		
};


#endif /* INCLUDE_LAYER_H_ */

