#ifndef INCLUDE_LAYER_HPP_
#define INCLUDE_LAYER_HPP_

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
using std::vector;

class Layer
{
	public:

	// Constructeur avec valeurs
	Layer(int neuronesEntree, int neuronesSortie);

	void forwardPropagation(vector<double> & input);

	void backwardPropagation(vector<double>  & dEY, double const& learningRate);

	int getInputSize();

	int getOutputSize();

	vector<double> getInput();

	vector<double> getOutput();
	
	private:

		vector<vector<double>> w;
		vector<double> b;
		vector<double> input;
		vector<double> output;
		int inputSize;
		int outputSize;

};


#endif /* INCLUDE_LAYER_HPP_ */
