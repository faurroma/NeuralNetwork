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

	vector<vector<double>> trainingInput = getTrainingInput();

	vector<vector<double>> trainingOutput = getTrainingOutput();

	Model copy = Model::read("MNIST.model");

	printV(trainingOutput[16], "expected");
	printV(copy.getOutputFor(trainingInput[16]), "result");

}

