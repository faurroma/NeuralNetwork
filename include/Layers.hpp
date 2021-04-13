#ifndef INCLUDE_LAYERS_HPP_
#define INCLUDE_LAYERS_HPP_

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Functions.hpp"

using namespace std;
using std::vector;

class Layer
{
	public:

		virtual void forwardPropagation(vector<vector<double>> & in) = 0;
		virtual void backwardPropagation(vector<vector<double>>  & dEY, double const& learningRate) = 0;

		vector<int> getInputSize();

		vector<int> getOutputSize();

		vector<vector<double>> getInput();

		vector<vector<double>> getOutput();

		vector<vector<double>> input;
		vector<vector<double>> output;
		vector<int> inputSize;
		vector<int> outputSize;

};

class FCLayer : public Layer {
	
	public:
		
		~FCLayer(){};

		FCLayer(int neuronesEntree, int neuronesSortie);

        void forwardPropagation(vector<vector<double>> & in) override;

        void backwardPropagation(vector<vector<double>>  & dEY, double const& learningRate) override;

		double getW(int i, int j);

		void getW(int i, int j, double value);

		double getB(int j);

		void setB(int j, double value);

	private:

		vector<vector<double>> w;

		vector<double> b;
};


class FlattenLayer : public Layer {

	public:

		~FlattenLayer(){};

		FlattenLayer(int  x, int y);

        void forwardPropagation(vector<vector<double>> & in) override;

        void backwardPropagation(vector<vector<double>>  & dEY, double const& learningRate) override;
};


#endif /* INCLUDE_LAYERS_HPP_ */
