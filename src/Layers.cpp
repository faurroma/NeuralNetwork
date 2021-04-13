#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Functions.hpp"
#include "Layers.hpp"

using namespace std;
using std::vector;

vector<int> Layer::getInputSize() {
	return inputSize;
}

vector<int> Layer::getOutputSize() {
		return outputSize;
}

vector<vector<double>> Layer::getInput() {
	return input;
}

vector<vector<double>> Layer::getOutput() {
	return output;
}

FCLayer::FCLayer(int neuronesEntree, int neuronesSortie){
	inputSize = {neuronesEntree, 1};
	outputSize = {neuronesSortie, 1};
	vector<vector<double>> weight(neuronesEntree);
	for(int i = 0; i<neuronesEntree; i++){
		weight[i].resize(neuronesSortie);
	}
	for(int i = 0; i<neuronesEntree; i++){
		for(int j = 0; j<neuronesSortie; j++){
			weight[i][j] = (double) rand() / RAND_MAX - 0.5;
		}
	}
	w = weight;
	vector<double> bias(neuronesSortie);
	for(int j = 0; j<neuronesSortie; j++){
		bias[j] = (double) rand() / RAND_MAX - 0.5;
	}
	b = bias;
	vector<vector<double>> in (neuronesEntree);
	for (int i = 0; i < neuronesEntree; i++){
		in[i].resize(1, 0);
	}
	input = in;
	vector<vector<double>> out(neuronesSortie);
	for (int i = 0; i < neuronesSortie; i++){
		out[i].resize(1, 0);
	}
	output = out;
}

void FCLayer::forwardPropagation(vector<vector<double>> & in) {
	//Copy of in into input
	for (int i = 0; i < inputSize[0]; i++){
		for (int j = 0; j < inputSize[1]; j++){
			input[i][j] = in[i][j];
		}
	}
	in.resize(outputSize[0]);
	for (int i = 0; i < outputSize[0]; i++){
				in[i].resize(outputSize[1]);
			}
	for (int n = 0; n < outputSize[0]; n++){
		// Calcul sum xi*wij
		double s = 0;
		for (int i = 0; i < inputSize[0]; i++){
			s += w[i][n]*input[i][0];
		}
		in[n][0] = b[n] + s;
		output[n][0] = in[n][0];
	}
}

void FCLayer::backwardPropagation(vector<vector<double>>  & dEY, double const& learningRate) {
	// COPY OF DEY
	vector<vector<double>> cpdEY(dEY.size());
	for (int i = 0; i < cpdEY.size(); i++){
			cpdEY[i].resize(dEY[0].size());
		for (int j = 0; j < dEY[0].size(); j++){
			cpdEY[i][j] = dEY[i][j];
		}
	}
	dEY.resize(inputSize[0]);
	for (int i = 0; i < inputSize[0]; i++){
					dEY[i].resize(1, 0);
	}
	for(int j = 0; j < outputSize[0]; j++)
	{
		for(int i = 0; i < inputSize[0]; i++){
			w[i][j] -= learningRate * cpdEY[j][0]*input[i][0];
			dEY[i][0] += cpdEY[j][0]*w[i][j];
		}
		b[j] -= learningRate * cpdEY[j][0];
	}
}



double FCLayer::getW(int i, int j){
	return w[i][j];
}

void FCLayer::getW(int i, int j, double value){
	w[i][j] = value;
}

double FCLayer::getB(int j){
	return b[j];
}

void FCLayer::setB(int j, double value){
	b[j] = value;
}


FlattenLayer::FlattenLayer(int  x, int y){
	inputSize = {x, y};
	outputSize = {x*y, 1};
	input.resize(x);
	for(int i = 0; i < x; i++){
		input[i].resize(y);
	}
	output.resize(x*y);
}

void FlattenLayer::forwardPropagation(vector<vector<double>> & in) {
	//Copy of in into input
	for (int i = 0; i < inputSize[0]; i++){
		for (int j = 0; j < inputSize[1]; j++){
			input[i][j] = in[i][j];
		}
	}
	in.resize(outputSize[0]);
	for (int i = 0; i < inputSize[0]; i++){
		for (int j = 0; j < inputSize[1]; j++){
			in[i*inputSize[0] + j].resize(1, input[i][j]);
		}
	}
}

void FlattenLayer::backwardPropagation(vector<vector<double>>  & dEY, double const& learningRate) {
	// COPY OF DEY
	vector<vector<double>> dEX(inputSize[0]);
	for (int i = 0; i < inputSize[0]; i++){
		dEX[i].resize(inputSize[1]);
		for (int j = 0; j < inputSize[1]; j++){
			dEX[i][j] = dEY[i*inputSize[0] + j][0];
		}
	}
	dEY = dEX;
}
