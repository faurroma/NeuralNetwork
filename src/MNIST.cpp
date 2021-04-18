/*
 * mnist.cpp
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
#include "mnist/mnist_reader.hpp"
#include "mnist/mnist_utils.hpp"

using namespace std;

vector<vector<vector<double>>> getTrainingInput(){
	mnist::MNIST_dataset<vector, vector<uint8_t>, uint8_t> dataset =
		    mnist::read_dataset<vector, vector, uint8_t, uint8_t>("datasets");
	int nbImages = dataset.training_images.size();
	int tailleImages = dataset.training_images[0].size();
	vector<vector<vector<double>>> trainingInput(nbImages);
	for (int k = 0; k < nbImages; k++){
		trainingInput[k].resize(28);
		for (int i = 0; i<28; i++){
			trainingInput[k][i].resize(28);
			for (int j = 0; j<28; j++){
				trainingInput[k][i][j] = (double) dataset.training_images[k][i*28+ j]/255;
			}
		}
	}
	return trainingInput;
}

vector<vector<vector<double>>> getTrainingOutput(){
	mnist::MNIST_dataset<vector, vector<uint8_t>, uint8_t> dataset =
		    mnist::read_dataset<vector, vector, uint8_t, uint8_t>("datasets");
	int nbImages = dataset.training_images.size();
	int tailleImages = dataset.training_images[0].size();
	int nbLabel = dataset.training_labels.size();
	vector<vector<vector<double>>> trainingOutput(nbLabel);
	for (int k = 0; k<nbLabel; k++){
		trainingOutput[k].resize(10);
		for(int i = 0; i<10; i++){
			trainingOutput[k][i].resize(1, 0);
		}
		trainingOutput[k][(int) dataset.training_labels[k]][0] = 1;
	}
	return trainingOutput;
}


vector<vector<vector<double>>> getTestingInput(){
	mnist::MNIST_dataset<vector, vector<uint8_t>, uint8_t> dataset =
		    mnist::read_dataset<vector, vector, uint8_t, uint8_t>("datasets");
	int nbImagesTest = dataset.test_images.size();
	int tailleImagesTest = dataset.test_images[0].size();
	vector<vector<vector<double>>> testInput(nbImagesTest);
	for (int k = 0; k<nbImagesTest; k++){
			testInput[k].resize(28);
		for (int i = 0; i<28; i++){
			testInput[k][i].resize(28);
			for (int j = 0; j<28; j++){
				testInput[k][i][j] = (double) dataset.test_images[k][i*28 + j]/255;
			}
		}
	}
	return testInput;
}

vector<vector<vector<double>>> getTestingOutput(){
	mnist::MNIST_dataset<vector, vector<uint8_t>, uint8_t> dataset =
		    mnist::read_dataset<vector, vector, uint8_t, uint8_t>("datasets");
	int nbImagesTest = dataset.test_images.size();
	vector<vector<vector<double>>> testingOutput(nbImagesTest);
	for (int k = 0; k < nbImagesTest; k++){
		testingOutput[k].resize(10);
		for (int i = 0; i < 10; i++){
			testingOutput[k][i].resize(1, 0);
		}
		testingOutput[k][(int) dataset.test_labels[k]][0] = 1;
	}
	return testingOutput;
}
int main(){
			vector<vector<vector<double>>> trainingOutput = getTrainingOutput();
			vector<vector<vector<double>>> trainingInput = getTrainingInput();
			mnist::MNIST_dataset<vector, vector<uint8_t>, uint8_t> dataset =
					    mnist::read_dataset<vector, vector, uint8_t, uint8_t>("datasets");
			Model testMod("mse", 0.1);
			testMod.add(new FlattenLayer(28, 28), "sigmoid");
			testMod.add(new FCLayer(28*28, 50), "sigmoid");
			testMod.add(new FCLayer(50, 10), "sigmoid");
			testMod.fit(trainingInput, trainingOutput, 30);
			cout << endl << "***Learning END***" << endl << endl;

			cout << "Testing...";
			int nbImagesTest = dataset.test_images.size();
			int tailleImagesTest = dataset.test_images[0].size();
			vector<vector<vector<double>>> testInput = getTestingInput();
			int reussi = 0;
			int rate = 0;

			for (int k = 0; k < nbImagesTest; k++){
				vector<vector<double>> p = testMod.getOutputFor(testInput[k]);
				int lab = dataset.test_labels[k];
				int maxElementIndex = -1;
				double max = -1;
				for (int i = 0; i < p.size(); i++){
					if (p[i][0] >= max){
						max = p[i][0];
						maxElementIndex = i;
					}
				}
				if (maxElementIndex == lab){
					reussi++;
				}
				else{
					rate++;
					cout << "ChiffreTest réel :" << endl;
					cout << lab << endl;
					cout << "ChiffreTest trouvé :" << endl;
					cout << maxElementIndex << endl;
					printM(p, "Probs");
					int s = 0;
					for (int i = 0; i < 28*28; i++){
						s += 1;
						if (testInput[k][i/28][i%28] > 150/255){
							cout << "#";
						}
						else{
							cout << " ";
							}
						if (s%28 == 0){
							cout << endl;
						}
					}
				}
			}
			float accuracy = (double) reussi/nbImagesTest;
			cout << "finished";
			cout << endl;
			cout << endl;
			cout << "*********** Results***********" << endl;
			cout << "     ACCURACY : " << accuracy << endl;
			cout << "******************************" << endl;
			return 0;

}


