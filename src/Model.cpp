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

Model::Model(string lossFct, double learningR, vector<double> entry) {
	cout << "New sequential network" << endl;
	learningRate = learningR;
	lossFunction = lossFct;
	valeurs.push_back(entry);
}

void Model::add(Layer lay, string activation) {
	if (layers.size() != 0 && layers.back().getOutputSize() != lay.getInputSize()){
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
		for (int j = 0; j < output.size(); j++){
			valeurs[j+1] = output;
		}
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
	vector<vector<double>> cpEntree;
	for (int i=0; i<valeurs.size()-1; i++) {
		for (int j = 0; j < valeurs[i].size(); j++){
			cpEntree[i][j].push_back(valeurs[i][j]);
		}
	}
	for (int i = layers.size() - 1; i>= 0; i--){
		activatePrime(cpEntree[i], activationFunctions[i]);
		for (int j = 0; j < dEX.size(); j++){
			dEX[j] = layers[i].backwardPropagation(dEX, entree, learningRate)[j] * cpEntree[i][j];
		}
	}
}

void Model::fit(vector<vector<double>> trainingInput,
	 vector<vector<double>> trainingOutput){
	// TODO
}
