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
	Layer();
	~Layer();
	vector<double> forwardPropagation(vector<double> const & input);

	vector<double> backwardPropagation(vector<double> const & dEY, double const& learningRate);

	int getInputSize();

	int getOutputSize();

	vector<double> getInput();

	vector<double> getOutput();
	
	private:

		vector<vector<double>> w;
		vector<double> b;
		vector<double> input;
		vector<double> output;

};


#endif /* INCLUDE_LAYER_HPP_ */
