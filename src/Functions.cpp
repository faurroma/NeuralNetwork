/*
 * Functions.cpp
 *
 *  Created on: 22 déc. 2020
 *      Author: faureromain
 */
#include <math.h>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

void sigmoid(vector<double>& values){
	for(int i = 0; i < values.size(); i++){
		values[i] = exp(values[i])/(exp(values[i]) + 1);
	}
}
void sigmoidPrime(vector<double>& values){
	for(int i = 0; i < values.size(); i++){
		values[i] = exp(-values[i])/(exp(-values[i]) + 1)/(exp(-values[i]) + 1);
	}
}

void identity(vector<double>& values){
}

void identityPrime(vector<double>& values){
	for(int i = 0; i < values.size(); i++){
			values[i] = 1;
		}
}

void tanH(vector<double>& values){
	for(int i = 0; i < values.size(); i++){
				values[i] = tanh(values[i]);
			}
}
void tanHPrime(vector<double>& values){
	for(int i = 0; i < values.size(); i++){
				values[i] = 1 - tanh(values[i]) * tanh(values[i]);
			}
}


void step(std::vector<double>& values){
	for(int i = 0; i < values.size(); i++){
		if (values[i]<= 0){
			values[i] = 0;
		}
		else {
			values[i] = 1;
		}
	}
}

void stepPrime(vector<double>& values){
	
}
double binaryCrossEntropy(vector<double> const & expected, vector<double> const & prediction){
	double cost  = - expected[0] * log(prediction[0] + 0.00000000000001)
				   - expected[1] * log(1 - prediction[0] + 0.00000000000001);
	return cost;
}

vector<double> binaryCrossEntropyPrime(vector<double> const & expected, vector<double> const & prediction){
	vector<double> result {-expected[0]/(prediction[0]+0.000000000000001),
						   -expected[1]/(1- prediction[0]+0.000000000000001)};
	return result;
}

double crossEntropy(vector<double> const & expected, vector<double> const & prediction){
	double cost = 0;
	for (int i = 0; i < expected.size(); i++) {
		cost += -expected[i] * log(prediction[i] + 0.00000000000001);
	}
	return cost;
}


vector<double> crossEntropyPrime(vector<double> const & expected, vector<double> const & prediction){
	vector<double> result(expected.size());
	for(int i = 0; i < expected.size(); i++){
		result[i] = - expected[i]/(prediction[i]+0.000000000000001);
	}
	return result;
}

double mse(vector<double> const & expected, vector<double> const & prediction){
	double cost = 0;
	for (int i = 0; i < expected.size(); i++) {
		cost += (expected[i] -prediction[i])*(expected[i] -prediction[i])/expected.size();
	}
	return cost;
}


vector<double> msePrime(vector<double> const & expected, vector<double> const & prediction){
	vector<double> result(expected.size(), 0);
	for(int i = 0; i < expected.size(); i++){
		result[i] = 2*(prediction[i] - expected[i])/expected.size();
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



