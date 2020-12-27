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
#include "mnist/mnist_reader.hpp"

using namespace std;

/* XOR

int main(){
	cout << "Test beginning" << endl;
	Model testMod("binaryCrossEntropy", 0.1);
	testMod.add(Layer(2, 3), "tanh");
	testMod.add(Layer(3, 1), "sigmoid");

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
	testMod.fit(trainingInput, trainingOutput, 1000);
	vector<double> p1 = testMod.getOutputFor(i1);
	vector<double> p2 = testMod.getOutputFor(i2);
	vector<double> p3 = testMod.getOutputFor(i3);
	vector<double> p4 = testMod.getOutputFor(i4);
	vector<vector<double>> predicted = {p1, p2, p3, p4};
	printM(trainingOutput, "Expected");
	printM(predicted, "Prediction");
	cout << endl << "Test end !" << endl;
	return 0;

}

*/
int main (){
	// Load MNIST data
	    mnist::MNIST_dataset<vector, vector<uint8_t>, uint8_t> dataset =
	        mnist::read_dataset<vector, vector, uint8_t, uint8_t>("datasets");

	    cout << "Nbr of training images = " << dataset.training_images.size() << endl;
	    cout << "Nbr of training labels = " << dataset.training_labels.size() << endl;
	    cout << "Nbr of test images = " << dataset.test_images.size() << endl;
	    cout << "Nbr of test labels = " << dataset.test_labels.size() << endl;
}


