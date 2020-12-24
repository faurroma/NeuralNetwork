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
void Model::backwardPropagation(vector<double>& dEY, vector<double>& entree){
	vector<double> dEX;
	for (int i=0; i<dEY.size(); i++) {
		        dEX.push_back(dEY[i]);
		}
	for (int i = layers.size() - 1; i>= 0; i--){
		dEX = layers[i].backwardPropagation(dEX, entree, learningRate);
	}
}
void Model::fit(vector<vector<double>> trainingInput,
	 vector<vector<double>> trainingOutput){
	// TODO
}



