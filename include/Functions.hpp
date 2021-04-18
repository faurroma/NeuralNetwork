#ifndef INCLUDE_FUNCTIONS_HPP_
#define INCLUDE_FUNCTIONS_HPP_

#include <math.h>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

void sigmoid(vector<vector<double>> & values){
	for(int i = 0; i < values.size(); i++){
		for (int j = 0; j < values[0].size(); j++){
			values[i][j] = 1/(exp(-values[i][j]) + 1);
		}
	}
}
void sigmoidPrime(vector<vector<double>> & values){
	for(int i = 0; i < values.size(); i++){
		for (int j = 0; j < values[0].size(); j++){
			values[i][j] = 1/(exp(-values[i][j]) + 1) * (1 - 1/(exp(-values[i][j]) + 1));
		}
	}
}


void tanH(vector<vector<double>> & values){
	for(int i = 0; i < values.size(); i++){
		for (int j = 0; j < values[0].size(); j++){
			values[i][j] = tanh(values[i][j]);
		}
	}
}
void tanHPrime(vector<vector<double>> & values){
	for(int i = 0; i < values.size(); i++){
		for (int j = 0; j < values[0].size(); j++){
			values[i][j] = 1 - tanh(values[i][j]) * tanh(values[i][j]);
		}
	}
}

double binaryCrossEntropy(vector<vector<double>> const & expected, vector<vector<double>> const & prediction){
	double cost  = 0;
	for(int i = 0; i < expected.size(); i++){
		for (int j = 0; j < expected[0].size(); j++){
			cost += - (expected[i][j] * log(prediction[i][j] + 0.00000000000001)
	                  + (1-expected[i][j]) * log(1-prediction[i][j] + 0.00000000000001));
		}
	}
	return cost;
}

vector<vector<double>> binaryCrossEntropyPrime(vector<vector<double>> const & expected, vector<vector<double>> const & prediction){
	vector<vector<double>> result(expected.size());
	for(int i = 0; i < expected.size(); i++){
		result[i].resize(expected[0].size());
		for (int j = 0; j < expected[0].size(); j++){
			result[i][j] = (prediction[i][j] - expected[i][j])/(prediction[i][j]*(1-prediction[i][j]));
		}
	}
	return result;
}


double mse(vector<vector<double>> const & expected, vector<vector<double>> const & prediction){
	double cost = 0;
	for (int i = 0; i < expected.size(); i++) {
		for (int j = 0; j < expected[0].size(); j++){
			cost += (expected[i][j] -prediction[i][j])*(expected[i][j] -prediction[i][j])/(expected.size()*expected[0].size());
		}
	}
	return cost;
}


vector<vector<double>> msePrime(vector<vector<double>> const & expected, vector<vector<double>> const & prediction){
	vector<vector<double>> result(expected.size());
	for(int i = 0; i < expected.size(); i++){
		result[i].resize(expected[0].size());
		for (int j = 0; j < expected[0].size(); j++){
			result[i][j] = 2*(prediction[i][j] - expected[i][j])/(expected.size()*expected[0].size());
		}
	}
	return result;
}

void print(string toWrite){
	cout << toWrite << endl;
}
void printV(vector<double> const & values, string title) {
	cout << "   " <<title << ":" << endl;
	for (int i = 0; i<values.size(); i++){
		cout << values[i] << ",  ";
	}
	cout << endl << endl;
}

void printM(vector<vector<double>> const & values, string title) {
	cout << "   " << title << ":" << endl;
	for (int i = 0; i<values.size(); i++){
		for (int j = 0; j<values[0].size(); j++){
			cout << values[i][j] << ",  ";
		}
		cout << endl;
	}
	cout << endl;
}

vector<vector<double>> vectorToMatrix(vector<double>& vec){
	vector<vector<double>> out(vec.size());
	for (int i = 0; i<vec.size(); i++){
		out[i].resize(1, vec[i]);
	}
	return out;
}

#endif /* INCLUDE_FUNCTIONS_HPP_ */
