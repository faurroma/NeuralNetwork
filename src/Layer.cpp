/*
 * Layer.cpp
 *
 *  Created on: 21 déc. 2020
 *      Author: faureromain
 * <3 <3 Tichahhh <3 <3
 */
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Layer.hpp"
#include "Functions.hpp"

using namespace std;
using std::vector;

	Layer::Layer(int neuronesEntree, int neuronesSortie)
	{
		inputSize = neuronesEntree;
		outputSize = neuronesSortie;

		vector<vector<double>> weight(neuronesEntree);
		for(int i = 0; i<neuronesEntree; i++)
		{
			weight[i].resize(neuronesSortie);
		}
		
		for(int i = 0; i<neuronesEntree; i++)
		{
			for(int j = 0; j<neuronesSortie; j++)
			{
				weight[i][j] = (double) rand() / RAND_MAX - 0.5;
			}
		}
		w = weight;
		vector<double> bias(neuronesSortie);
		for(int j = 0; j<neuronesSortie; j++)
					{
					    bias[j] = (double) rand() / RAND_MAX - 0.5;
					}
		b = bias;

		vector<double> in (neuronesEntree, 0);
		input = in;
		vector<double> out (neuronesSortie, 0);
		output = out;
		
	}

	void Layer::forwardPropagation(vector<double> & in){
		//Copy of in into input
		for (int i = 0; i < inputSize; i++) input[i] = in[i];
		in.resize(outputSize);
		for (int n = 0; n < outputSize; n++){
			// Calcul sum xi*wij
			double s = 0;
			for (int i = 0; i < inputSize; i++){
				s += w[i][n]*input[i];

			}
			in[n] = b[n] + s;
			output[n] = in[n];
		}
	}

	void Layer::backwardPropagation(vector<double> & dEY, double const& learningRate){
		vector<double> cpdEY(dEY);
		dEY.resize(inputSize, 0);
		for(int j = 0; j < outputSize; j++)
		{
			for(int i = 0; i < inputSize; i++){
				w[i][j] -= learningRate * cpdEY[j]*input[i];
				dEY[i] += cpdEY[j]*w[i][j];
			}
			b[j] -= learningRate * cpdEY[j];

		}
	}

	int Layer::getInputSize(){
		return inputSize;
	}

	int Layer::getOutputSize(){
		return outputSize;
	}

	vector<double> Layer::getInput(){
		return input;
	}

	vector<double> Layer::getOutput(){
		return output;
	}
