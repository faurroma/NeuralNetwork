/*
 * Functions.cpp
 *
 *  Created on: 22 déc. 2020
 *      Author: faureromain
 */
#include <math.h>
#include <vector>
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

double crossEntropy(vector<double> expected, vector<double> score){
	double cost = 0;
	for (int i = 0; i < expected.size(); i++) {
		cost += -expected[i] * log(score[i]);
	}
	return cost;
}

vector<vector<double>> dotMatrix(const vector<vector<double>> & A, const vector<vector<double>> & B)
{
    vector<vector<double>> result(A.size());
	for (int i = 0; i < A.size(); i++) {
		result[0].resize(B[0].size(), 0);
		for (int j = 0; j < B[0].size(); j++){
			for (int k = 0; k < B.size() ; k++) {
				result[i][j]+=A[i][k]*B[k][j];  
			}
		}
	}
    return result;
}
vector<vector<double>> sumMatrix(const vector<vector<double>> & A, const vector<vector<double>> & B)
{
    vector<vector<double>> result(A.size());
	for (int i = 0; i < A.size(); i++) {
		result[0].resize(B[0].size(), 0);
		for (int j = 0; j < B[0].size(); j++){
			result[i][j] = A[i][j] + B[i][j];  
		}
	}
    return result;
}




