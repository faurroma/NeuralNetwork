/*
 * mnist.cpp
 *
 *  Created on: 29 déc. 2020
 *      Author: faureromain
 */

#include <iostream>
#include <algorithm>
#include <string>
#include "Layer.hpp"
#include "Model.hpp"
#include "Functions.hpp"
#include "mnist/mnist_reader.hpp"
#include "mnist/mnist_utils.hpp"

using namespace std;

vector<vector<double>> getTrainingInput(){
	mnist::MNIST_dataset<vector, vector<uint8_t>, uint8_t> dataset =
		    mnist::read_dataset<vector, vector, uint8_t, uint8_t>("datasets");
	int nbImages = dataset.training_images.size();
	int tailleImages = dataset.training_images[0].size();
	vector<vector<double>> trainingInput(nbImages);
	for (int i = 0; i<nbImages; i++){
		trainingInput[i].resize(tailleImages);
		for (int j = 0; j<tailleImages; j++){
			trainingInput[i][j] = (double) dataset.training_images[i][j]/255;
		}
	}
	return trainingInput;
}

vector<vector<double>> getTrainingOutput(){
	mnist::MNIST_dataset<vector, vector<uint8_t>, uint8_t> dataset =
		    mnist::read_dataset<vector, vector, uint8_t, uint8_t>("datasets");
	int nbImages = dataset.training_images.size();
	int tailleImages = dataset.training_images[0].size();
	int nbLabel = dataset.training_labels.size();
	vector<vector<double>> trainingOutput(nbLabel);
	for (int i = 0; i<nbLabel; i++){
		trainingOutput[i].resize(10, 0);
		trainingOutput[i][(int) dataset.training_labels[i]] = 1;
	}
	return trainingOutput;
}


vector<vector<double>> getTestingInput(){
	mnist::MNIST_dataset<vector, vector<uint8_t>, uint8_t> dataset =
		    mnist::read_dataset<vector, vector, uint8_t, uint8_t>("datasets");
	int nbImagesTest = dataset.test_images.size();
	int tailleImagesTest = dataset.test_images[0].size();
	vector<vector<double>> testInput(nbImagesTest);
	for (int i = 0; i<nbImagesTest; i++){
			testInput[i].resize(tailleImagesTest);
		for (int j = 0; j<tailleImagesTest; j++){
			testInput[i][j] = (double) dataset.test_images[i][j]/255;
		}
	}
	return testInput;
}

vector<vector<double>> getTestingOutput(){
	mnist::MNIST_dataset<vector, vector<uint8_t>, uint8_t> dataset =
		    mnist::read_dataset<vector, vector, uint8_t, uint8_t>("datasets");
	int nbImagesTest = dataset.test_images.size();
	vector<vector<double>> testingOutput(nbImagesTest);
	for (int i = 0; i < nbImagesTest; i++){
		testingOutput[i].resize(10, 0);
		testingOutput[i][(int) dataset.test_labels[i]] = 1;
	}
	return testingOutput;
}
int exempleMNIST(){
			vector<vector<double>> trainingOutput = getTrainingOutput();
			vector<vector<double>> trainingInput = getTrainingInput();
			mnist::MNIST_dataset<vector, vector<uint8_t>, uint8_t> dataset =
					    mnist::read_dataset<vector, vector, uint8_t, uint8_t>("datasets");
			Model testMod("mse", 0.1	);
			testMod.add(Layer(28*28, 150), "sigmoid");
			testMod.add(Layer(150, 50), "sigmoid");
			testMod.add(Layer(50, 10), "sigmoid");
			testMod.fit(trainingInput, trainingOutput, 10);
			cout << "***Learning END***" << endl << endl;

			cout << "Testing...";
			int nbImagesTest = dataset.test_images.size();
			int tailleImagesTest = dataset.test_images[0].size();
			vector<vector<double>> testInput = getTestingInput();
			int reussi = 0;
			int rate = 0;

			for (int i = 0; i < nbImagesTest; i++){
				vector<double> p = testMod.getOutputFor(testInput[i]);
				int lab = dataset.test_labels[i];
				int maxElementIndex = std::max_element(p.begin(),p.end()) - p.begin();
				if (maxElementIndex == lab){
					reussi += 1;
				}
				else{
					rate += 1;
//					cout << "ChiffreTest réel :" << endl;
//					cout << lab << endl;
//					cout << "ChiffreTest trouvé :" << endl;
//					cout << maxElementIndex << endl << " with probabilities : " << endl;
//					for (int j = 0; j < 10; j++){
//						cout << p[j] << " ";
//					}
//					cout << endl;
//					int s = 0;
//					for (int j = 0; j < 28*28; j++){
//						s += 1;
//						if (testInput[i][j] > 150/255){
//							cout << "#";
//						}
//						else{
//							cout << " ";
//							}
//						if (s%28 == 0){
//							cout << endl;
//						}
//					}
				}
			}
			float accuracy = (double) reussi/nbImagesTest;
			cout << "finished";
			cout << endl;
			cout << endl;
			cout << "*********** Resultats*********" << endl;
			cout << "     ACCURACY : " << accuracy << endl;
			cout << "******************************" << endl;
			testMod.write("MNIST.model");
			return 0;

}


