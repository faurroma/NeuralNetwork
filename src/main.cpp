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



int main(){
	cout << "Test beginning" << endl;
	Model testMod("test", 0.001);
	testMod.add(Layer(5, 6), "identity");
	testMod.add(Layer(6,4), "identity");
	vector<double> oui;
	oui.push_back(0.5);
	oui.push_back(0);
	oui.push_back(0.4);
	oui.push_back(0.4);
	vector<double> non;
	non.push_back(4);
	non.push_back(3);
	non.push_back(2);
	non.push_back(3);
	vector<double> result = testMod.getOutputFor(non);
	for (int i = 0; i<result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	testMod.backwardPropagation(oui, non);
	cout << "after backwardPropagation" << endl;
	result = testMod.getOutputFor(non);
	for (int j = 0; j<result.size(); j++) {
		cout << result[j] << " ";
	}
	cout << endl;
	cout << "Test end !" << endl;
	return 0;

}

