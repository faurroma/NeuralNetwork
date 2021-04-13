#include <string>
#include "Layers.hpp"
#include "Functions.hpp"
#include "Model.hpp"


Model::Model(string lossFct, double learningR) : learningRate(learningR), lossFunction(lossFct) {}

void Model::add(Layer* lay, std::string activation){
	if (layers.size() > 0 && layers.back()->getOutputSize() != lay->getInputSize()){
		cout << "Wrong dimensions for layers" << endl;
		exit(0);
	}
	layers.push_back(lay);
	activationFunctions.push_back(activation);
}

vector<vector<double>> Model::getOutputFor(vector<vector<double>> const & input){
	// Copie de input dans un vecteur output qui va changer de couche
	// en couche
	vector<vector<double>> output(input.size());
	for(int i = 0; i < input.size(); i++){
		output[i].resize(input[0].size());
		for(int j = 0; j<input[i].size(); j++){
			output[i][j] = input[i][j];
		}
	}
	// Passage dans chaque couche
	for(int i = 0; i < layers.size(); i++){
		layers[i]->forwardPropagation(output);
		activate(output, activationFunctions[i]);
	}
	return output;
}


void Model::backwardPropagation(vector<vector<double>> & dEY){
	for (int k = layers.size() - 1; k>= 0; k--){
		vector<vector<double>> output = layers[k]->getOutput();
		vector<vector<double>> input(output.size()); // copy of input to modify it without risk
		for(int i = 0; i < output.size(); i ++){
			input[i].resize(output[0].size());
			for(int j = 0; j < output[0].size(); j++){
				input[i][j] = output[i][j];
			}
		}
		activatePrime(input, activationFunctions[k]);
		for (int i= 0; i < input.size(); i++) {
			for(int j = 0; j < input[0].size(); j++) {
				dEY[i][j] *= input[i][j];
			}
		}
		layers[k]->backwardPropagation(dEY, learningRate);
	}
}


void Model::fit(vector<vector<vector<double>>> trainingInput,
		vector<vector<vector<double>>> trainingOutput, int epochs){
	for (int e = 0; e < epochs; e++) {
		double err = 0;
		for(int d = 0; d < trainingInput.size(); d++){
			// Calcul de la prédiction
			vector<vector<double>> output = getOutputFor(trainingInput.at(d));
			// Calcul de l'erreur pour chaque epoch, uniquement pour le visuel
			err += loss(trainingOutput.at(d), output)/trainingInput.size();
			// BackPropagation
			vector<vector<double>> dEY = lossPrime(trainingOutput.at(d), output);
			backwardPropagation(dEY);
		}
		cout << "Epoch " << e+1 << "/" << epochs <<" with error : " << err << " (" << lossFunction << ")" << endl;
	}
}


void Model::activate(vector<vector<double>>& values, string& function){
	if (function == "sigmoid")         sigmoid(values);
	else if (function == "tanh")       tanH(values);
	else {
		cout << "Wrong activation function name" << endl;
		exit(0);
	}
}


void Model::activatePrime(vector<vector<double>>& values, string& function){
	if (function == "sigmoid")         sigmoidPrime(values);
	else if (function == "tanh")       tanHPrime(values);
	else {
		cout << "Wrong activation function name" << endl;
		exit(0);
	}
}

double Model::loss(vector<vector<double>>& expected,
			vector<vector<double>> &prediction){
	if (lossFunction == "binaryCrossEntropy")   return binaryCrossEntropy(expected, prediction);
	else if (lossFunction == "mse")       			 return mse(expected, prediction);
	else {
		cout << "Wrong loss function name" << endl;
		exit(0);
	}
}

vector<vector<double>> Model::lossPrime(vector<vector<double>> & expected,
						 vector<vector<double>> & prediction){
	if (lossFunction == "binaryCrossEntropy")   return binaryCrossEntropyPrime(expected, prediction);
	else if (lossFunction == "mse")                  return msePrime(expected, prediction);
	else {
		cout << "Wrong loss function name" << endl;
		exit(0);
	}
}