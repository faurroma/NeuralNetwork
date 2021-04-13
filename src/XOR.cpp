/*
 * exempleXOR.cpp
 *
 *  Created on: 29 déc. 2020
 *      Author: faureromain
 */
#include <iostream>
#include <algorithm>
#include <string>
#include "Layers.hpp"
#include "Model.hpp"
#include "Functions.hpp"


int exempleXOR(){
	cout << "Test beginning" << endl;
	Model testMod("mse", 0.1);
	testMod.add(new FCLayer(2, 3), "tanh");
	testMod.add(new FCLayer(3, 1), "tanh");

	vector<vector<double>> i1 = {{0}, {0}};
	vector<vector<double>> i2 = {{0}, {1}};
	vector<vector<double>> i3 = {{1}, {0}};
	vector<vector<double>> i4 = {{1}, {1}};

	vector<vector<double>> o1 = {{0}};
	vector<vector<double>> o2 = {{1}};
	vector<vector<double>> o3 = {{1}};
	vector<vector<double>> o4 = {{0}};
	vector<vector<vector<double>>> trainingInput = {i1, i2, i3, i4};

	vector<vector<vector<double>>> trainingOutput = {o1, o2, o3, o4};
	testMod.fit(trainingInput, trainingOutput, 1000);
	vector<vector<double>> p1 = testMod.getOutputFor(i1);
	vector<vector<double>> p2 = testMod.getOutputFor(i2);
	vector<vector<double>> p3 = testMod.getOutputFor(i3);
	vector<vector<double>> p4 = testMod.getOutputFor(i4);
	printM(o1, "Expected 1");
	printM(p1, "Prediction 1");
	printM(o2, "Expected 2");
	printM(p2, "Prediction 2");
	printM(o3, "Expected 3");
	printM(p3, "Prediction 3");
	printM(o4, "Expected 4");
	printM(p4, "Prediction 4");
	cout << endl << "Test end !" << endl;
	return 0;
}



