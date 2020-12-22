/*
 * Functions.cpp
 *
 *  Created on: 22 déc. 2020
 *      Author: faureromain
 */
#include <math.h>
#include <vector>

using namespace std;

void sigmoid(vector<double>& values){
	for(int i = 0; i < values.size(); i++){
		values[i] = exp(values[i])/(exp(values[i]) + 1);
	}
}
void sigmoid_prime(vector<double>& values){
	for(int i = 0; i < values.size(); i++){
		values[i] = exp(-values[i])/(exp(-values[i]) + 1)/(exp(-values[i]) + 1);
	}
}

void identity(vector<double>& values){
}

void identity_prime(vector<double>& values){
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

void step_prime(vector<double>& values){
	
}


