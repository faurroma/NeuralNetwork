/*
 * Layer.cpp
 *
 *  Created on: 21 déc. 2020
 *      Author: faureromain
 * <3 <3 Tichahhh <3 <3
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Layer.hpp"
#include "Functions.hpp"
#include "Model.hpp"

using namespace std;

Model::Model(string lossFct, double learningR) {
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


vector<double> Model::getOutputFor(vector<double> const & input){

	// Copie de input dans un vecteur output qui va changer de couche
	// en couche
	vector<double> output(input);
	// Passage dans chaque couche
	for(int i = 0; i < layers.size(); i++){
		layers[i].forwardPropagation(output);
		activate(output, activationFunctions[i]);
	}
	return output;
}

void Model::activate(vector<double>& values, string& function){
	if (function == "sigmoid")         sigmoid(values);
	else if (function == "identity")   identity(values);
	else if (function == "tanh")       tanH(values);
	else {
		cout << "Wrong activation function name" << endl;
		exit(0);
	}
}

void Model::activatePrime(vector<double>& values, string& function){
	if (function == "sigmoid")         sigmoidPrime(values);
	else if (function == "identity")   identityPrime(values);
	else if (function == "tanh")       tanHPrime(values);
	else {
		cout << "Wrong activation function name" << endl;
		exit(0);
	}
}

void Model::backwardPropagation(vector<double> & dEY){
	for (int i = layers.size() - 1; i>= 0; i--){
		vector<double> input(layers[i].getOutput()); // copy of input to modify it without risk
		activatePrime(input, activationFunctions[i]);
		for (int k = 0; k < input.size(); k++) {
			dEY[k] *= input[k];
		}
		layers[i].backwardPropagation(dEY, learningRate);
	}
}

double Model::loss(vector<double>& expected, vector<double>& prediction){
	if (lossFunction == "binaryCrossEntropy")   return binaryCrossEntropy(expected, prediction);
	else if (lossFunction == "mse")       			 return mse(expected, prediction);
	else {
		cout << "Wrong loss function name" << endl;
		exit(0);
	}
}

vector<double> Model::lossPrime(vector<double>& expected, vector<double>& prediction){
	if (lossFunction == "binaryCrossEntropy")   return binaryCrossEntropyPrime(expected, prediction);
	else if (lossFunction == "mse")                  return msePrime(expected, prediction);
	else {
		cout << "Wrong loss function name" << endl;
		exit(0);
	}
}

void Model::fit(vector<vector<double>> trainingInput,
	 vector<vector<double>> trainingOutput, int epochs){
	for (int e = 0; e < epochs; e++) {
		double err = 0;
		for(int d = 0; d < trainingInput.size(); d++){
			// Calcul de la prédiction
			vector<double> output = getOutputFor(trainingInput.at(d));
			// Calcul de l'erreur pour chaque epoch, uniquement pour le visuel
			err += loss(trainingOutput.at(d), output)/trainingInput.size();
			// BackPropagation
			vector<double> dEY = lossPrime(trainingOutput.at(d), output);
			backwardPropagation(dEY);
		}
		cout << "Epoch " << e+1 << "/" << epochs <<" with error : " << err << " (" << lossFunction << ")" << endl;
	}
}

void Model::write(string name){
	ofstream file;
	file.open("models/" + name, ios::out);
	file << "# LOSS FUNCTION" << endl;
	file << lossFunction << endl;
	file << "# LEARNING RATE" << endl;
	file << learningRate << endl;
	file << "# BEGGINING OF LAYERS DESCRIPTION" << endl;
	int c = 0;
	for (Layer lay: layers){
		file << "#*******LAYER " << c << "******" << endl;
		file << "# DIMENSIONS" << endl;
		file << lay.getInputSize() << "x" << lay.getOutputSize() << endl;
		file << "# ACTIVATION FUNCTION" << endl;
		file << activationFunctions[c] << endl;
		file << "# WEIGHTS" << endl;
		for(int i = 0; i < lay.getInputSize(); i++){
			for(int j = 0; j < lay.getOutputSize(); j++){
				file << lay.getW(i,j) << " ";
			}
			file << endl;
		}
		file << "# BIAS" << endl;
		for (int j = 0; j < lay.getOutputSize(); j++){
			file << lay.getB(j) << endl;
		}
		c++;
	}
	file.close();
 }

Model Model::read(string name){
	string lossFct;
	double learningR;
	string buffer;
	ifstream file;
	file.open("models/" + name);
	// GET LOSS FUNCTION
	getline(file, buffer);
	while(buffer[0] == '#'){
		getline(file, buffer);
	}
	lossFct = buffer;
	//GET LEARNING RATE
	getline(file, buffer);
	while(buffer[0] == '#'){
		getline(file, buffer);
	}
	learningR = stoi(buffer);
	// CREATE MODEL
	Model mod(lossFct, learningR);
	// START LAYERS READING
	getline(file, buffer);
	while(buffer[0] == '#'){
		getline(file, buffer);
	}
	while(!file.eof()){
		// GET DIMENSIONS
		int inputSize;
		int outputSize;
		int pos = buffer.find("x");
		inputSize = stoi(buffer.substr(0, pos));
		buffer.erase(0, pos+1);
		outputSize = stoi(buffer);
		// GET ACTIVATION FUNCTION
		string actFct;
		getline(file, buffer);
		while(buffer[0] == '#'){
			getline(file, buffer);
		}
		actFct = buffer;
		Layer toAdd(inputSize, outputSize);
		// READ WEIGHTS
		for (int i = 0; i < inputSize; i++){
			int j = 0;
			getline(file, buffer);
			while(buffer[0] == '#'){
				getline(file, buffer);
			}
			while ((pos = buffer.find(" ")) != string::npos) {
				toAdd.setW(i, j, stod(buffer.substr(0, pos), NULL));
				buffer.erase(0, pos + 1);
				j++;
			}
		}
		// READ BIAS
		for (int j = 0; j < outputSize; j++){
			getline(file, buffer);
			while(buffer[0] == '#'){
				getline(file, buffer);
			}
			toAdd.setB(j, stod(buffer, NULL));
		}
		mod.add(toAdd, actFct);
		getline(file, buffer);
		while(buffer[0] == '#'){
			getline(file, buffer);
		}
	}
	return mod;
}
