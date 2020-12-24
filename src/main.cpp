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
	oui.push_back(100);
	oui.push_back(100);
	oui.push_back(100);
	oui.push_back(100);
	oui.push_back(100);
	vector<double> result = testMod.getOutputFor(oui);
	for (int i = 0; i<result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	cout << "Test end !" << endl;
	return 0;

}

