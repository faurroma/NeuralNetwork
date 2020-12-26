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
#include "Layer.hpp"
#include "Functions.hpp"
#include "Model.hpp"

using namespace std;

Model::Model(string lossFct, double learningR) {
	cout << "New sequential network" << endl;
	learningRate = learningR;
	lossFunction = lossFct;
}

void Model::add(Layer lay, string activation) {
	if (layers.size() > 0 && layers.back().getOutputSize() != lay.getInputSize()){
		cout << "Wrong dimensions for layers" << endl;
		exit(0);
	}
	layers.push_back(lay);
	activationFunctions.push_back(activation);
}


vector<double> Model::getOutputFor(vector<double> input){

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

void Model::activate(vector<double> values, string& function){
	if (function == "sigmoid")         sigmoid(values);
	else if (function == "identity")   identity(values);
	else if (function == "step")       step(values);
	else {
		cout << "Wrong activation function name" << endl;
	}
}

void Model::activatePrime(vector<double> values, string& function){
	if (function == "sigmoid")         sigmoidPrime(values);
	else if (function == "identity")   identityPrime(values);
	else if (function == "step")       stepPrime(values);
	else {
		cout << "Wrong activation function name" << endl;
	}
}

void Model::backwardPropagation(vector<double>& dEY){
	vector<double> dEX;
	// Copie de dEY dans dEX
	for (int i=0; i<dEY.size(); i++) {
		dEX.push_back(dEY[i]);
	}
	for (int i = layers.size() - 1; i>= 0; i--){
		vector<double> input(layers[i].getInput()); // copy of input to modify it without risk
		activatePrime(input, activationFunctions[i]);
		for (int k = 0; k < dEX.size(); k++) {
			dEX[k] *= input[k];
		}
		dEX = layers[i].backwardPropagation(dEX, learningRate);
	}
}

double Model::loss(vector<double> expected, vector<double> prediction){
	return 1;

}

double Model::lossPrime(vector<double> expected, vector<double> prediction){
	return 1;
}

void Model::fit(vector<vector<double>> trainingInput,
	 vector<double> trainingOutput, int epochs){
	for (int e = 0; e < epochs; e++) {
		double err = 0;
		for(int d = 0; d < trainingInput.size(); d++){
			// Calcul de la prédiction
			vector<double> output = getOutputFor(trainingInput[d]);
			vector<double> current_err = loss(trainingOutput[d], output);
			// Calcul de l'erreur pour chaque epoch, uniquement pour le visuel
			for(vector<double>::iterator it = vector.begin(); it != vector.end(); ++it){
			    err += *it;
			}
			// BackPropagation
			backwardPropagation(current_err);
		}
		cout << "Epoch " << e << " with error : " << err << " (" << lossFunction << ")" << endl;
	}
}
