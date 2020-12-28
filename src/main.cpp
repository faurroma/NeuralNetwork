/*
 * main.cpp
 *
 *  Created on: 21 déc. 2020
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
	mnist::MNIST_dataset<vector, vector<uint8_t>, uint8_t> dataset =
		        mnist::read_dataset<vector, vector, uint8_t, uint8_t>("datasets");

		    cout << "Nbr of training images = " << dataset.training_images.size() << endl;
		    cout << "Nbr of training labels = " << dataset.training_labels.size() << endl;
		    cout << "Nbr of test images = " << dataset.test_images.size() << endl;
		    cout << "Nbr of test labels = " << dataset.test_labels.size() << endl;

    		int nbImages = dataset.training_images.size();
			int tailleImages = dataset.training_images[0].size();
			vector<vector<double>> trainingInput(nbImages);
			for (int i = 0; i<nbImages; i++){
				trainingInput[i].resize(tailleImages);
				for (int j = 0; j<tailleImages; j++){
					trainingInput[i][j] = (double) dataset.training_images[i][j]/255;
					}
				}
			int nbLabel = dataset.training_labels.size();
			vector<vector<double>> trainingOutput(nbLabel);
			for (int i = 0; i<nbLabel; i++){
				trainingOutput[i].resize(10, 0);
				trainingOutput[i][(int) dataset.training_labels[i]] = 1;
			}
			cout << "Learning..." << endl;
			Model testMod("mse", 0.1	);
			testMod.add(Layer(28*28, 15), "sigmoid");
			testMod.add(Layer(15, 10), "sigmoid");
			testMod.fit(trainingInput, trainingOutput, 10);
			cout << "***Learning END***" << endl << endl;

			cout << "Testing...";
			int nbImagesTest = dataset.test_images.size();
			int tailleImagesTest = dataset.test_images[0].size();
			vector<vector<double>> testInput(nbImages);

			for (int i = 0; i<nbImagesTest; i++){
					testInput[i].resize(tailleImagesTest);
				for (int j = 0; j<tailleImagesTest; j++){
					testInput[i][j] = (double) dataset.test_images[i][j]/255;
				}
			}
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

			return 0;
}


/*
 *
 */
