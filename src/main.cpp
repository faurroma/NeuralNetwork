/*
 * main.cpp
 *
 *  Created on: 21 déc. 2020
 *      Author: faureromain
 */
#include <iostream>
#include <algorithm>
#include <string>

#include "xor.hpp"
#include "mnist.hpp"
#include "Layer.hpp"
#include "Model.hpp"
#include "Functions.hpp"
#include "mnist/mnist_reader.hpp"
#include "mnist/mnist_utils.hpp"

using namespace std;

int main (){
	vector<double> i1 = {0, 0};
	vector<double> i2 = {0, 1};
	vector<double> i3 = {1, 0};
	vector<double> i4 = {1, 1};
	Model same = Model::read("XOR.model");
	cout << same.getOutputFor(i1)[0] << endl;
	cout << same.getOutputFor(i2)[0] << endl;
	cout << same.getOutputFor(i3)[0] << endl;
	cout << same.getOutputFor(i4)[0] << endl;

}

