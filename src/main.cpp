/*
 * main.cpp
 *
 *  Created on: 21 déc. 2020
 *      Author: faureromain
 */
#include <iostream>
#include <string>
#include "Layer.hpp"
#include "Model.hpp"
#include "Functions.hpp"



int main(){
	cout << "Test beginning" << endl;
	Model testMod("mse", 0.1);
	testMod.add(Layer(2, 3), "tanh");
	testMod.add(Layer(3, 1), "tanh");

	vector<double> i1 = {0, 0};
	vector<double> i2 = {0, 1};
	vector<double> i3 = {1, 0};
	vector<double> i4 = {1, 1};

	vector<double> o1 = {0};
	vector<double> o2 = {1};
	vector<double> o3 = {1};
	vector<double> o4 = {0};
	vector<vector<double>> trainingInput = {i1, i2, i3, i4};
	vector<vector<double>> trainingOutput = {o1, o2, o3, o4};
	testMod.fit(trainingInput, trainingOutput, 200);
	vector<double> result = testMod.getOutputFor(i1);
	for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
	cout << endl << "Test end !" << endl;
	return 0;

}

