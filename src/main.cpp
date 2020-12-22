/*
 * main.cpp
 *
 *  Created on: 21 déc. 2020
 *      Author: faureromain
 */
#include <iostream>
#include <string>
#include "Layer.h"
#include "Model.h"



int main(){
	cout << "Test" << endl;
	Model testMod("test", 0.001);
	testMod.add(Layer(5, 6), "sigmoid");
	testMod.add(Layer(6,3), "identity");
	cout << "Sucess !" << endl;

}

