/*
 * Layer.cpp
 *
 *  Created on: 21 déc. 2020
 *      Author: faureromain
 * <3 <3 Tichahhh <3 <3
 */
#include <iostream>
#include <string>
#include <vector>
#include "Layer.h"
#include "Functions.h"

using namespace std;

class Model
{
	public:
	// Constructeur avec valeurs
	Model(string lossFct, double learningR) {
		cout << "New sequential network" << endl;
		learningRate = learningR;
		lossFunction = lossFct;
	}

	void add(Layer lay, string activation) {
		layers.push_back(lay);
		activationFunctions.push_back(activation);
	}


	vector<double> getOutputFor(vector<double> input){

		// Copie de input dans un vecteur output qui va changer de couche
		// en couche
		vector<double> output;
		for (int i=0; i<input.size(); i++) {
		        output.push_back(input[i]);
		}
		// Passage dans chaque couche
		for(int i = 0; i < layers.size(); i++){
			output = layers[i].forwardPropagation(output);
			activate(output, activationFunctions[i]);
		}
		return output;

	}


	private:
		vector<Layer> layers;
		vector<string> activationFunctions;
		string lossFunction;
		double learningRate;



		void activate(vector<double> values, string& function){
			if (function == "sigmoid")         sigmoid(values);
			else if (function == "identity")   identity(values);
			else if (function == "step")       step(values);
			else {
				cout << "Wrong activation function name" << endl;
			}
		}

		void backwardPropagation(double dEY[]){
			// TODO
		}

		void fit(vector<vector<double>> trainingInput,
				 vector<vector<double>> trainingOutput){
			// TODO
		}



};
