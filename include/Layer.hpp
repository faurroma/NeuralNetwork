#ifndef INCLUDE_LAYER_HPP_
#define INCLUDE_LAYER_HPP_

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

	virtual void backwardPropagation(vector<vector<double>>  & dEY, double const& learningRate)= 0;

	vector<int> getInputSize()
	{
			return inputSize;
	}

	vector<int> getOutputSize()
	{
			return outputSize;
	}

	vector<vector<double>> getInput()
	{
			return input;
	}

	vector<vector<double>> getOutput()
	{
			return output;
	}

	vector<vector<double>> input;
	vector<vector<double>> output;
	vector<int> inputSize;
	vector<int> outputSize;

};

class FCLayer : public Layer {
	public:
		~FCLayer(){};
		FCLayer(int neuronesEntree, int neuronesSortie){
			inputSize = {neuronesEntree, 1};
			outputSize = {neuronesSortie, 1};
			vector<vector<double>> weight(neuronesEntree);
			for(int i = 0; i<neuronesEntree; i++){
				weight[i].resize(neuronesSortie);
			}
			for(int i = 0; i<neuronesEntree; i++){
				for(int j = 0; j<neuronesSortie; j++){
					weight[i][j] = (double) rand() / RAND_MAX - 0.5;
				}
			}
			w = weight;
			vector<double> bias(neuronesSortie);
			for(int j = 0; j<neuronesSortie; j++){
				bias[j] = (double) rand() / RAND_MAX - 0.5;
			}
			b = bias;
			vector<vector<double>> in (neuronesEntree);
			for (int i = 0; i < neuronesEntree; i++){
				in[i].resize(1, 0);
			}
			input = in;
			vector<vector<double>> out (neuronesSortie);
			for (int i = 0; i < neuronesSortie; i++){
				out[i].resize(1, 0);
			}
			output = out;
		}

		void forwardPropagation(vector<vector<double>> & in) override {
			//Copy of in into input
			for (int i = 0; i < inputSize[0]; i++){
				for (int j = 0; j < inputSize[1]; j++){
					input[i][j] = in[i][j];
				}
			}
			in.resize(outputSize[0]);
			for (int i = 0; i < outputSize[0]; i++){
						in[i].resize(outputSize[1]);
					}
			for (int n = 0; n < outputSize[0]; n++){
				// Calcul sum xi*wij
				double s = 0;
				for (int i = 0; i < inputSize[0]; i++){
					s += w[i][n]*input[i][0];
				}
				in[n][0] = b[n] + s;
				output[n][0] = in[n][0];
			}
		}

		void backwardPropagation(vector<vector<double>>  & dEY, double const& learningRate) override {
			// COPY OF DEY
			vector<vector<double>> cpdEY(dEY.size());
			for (int i = 0; i < cpdEY.size(); i++){
					cpdEY[i].resize(dEY[0].size());
				for (int j = 0; j < dEY[0].size(); j++){
					cpdEY[i][j] = dEY[i][j];
				}
			}
			dEY.resize(inputSize[0]);
			for (int i = 0; i < inputSize[0]; i++){
							dEY[i].resize(1, 0);
			}
			for(int j = 0; j < outputSize[0]; j++)
			{
				for(int i = 0; i < inputSize[0]; i++){
					w[i][j] -= learningRate * cpdEY[j][0]*input[i][0];
					dEY[i][0] += cpdEY[j][0]*w[i][j];
				}
				b[j] -= learningRate * cpdEY[j][0];
			}
		}



		double getW(int i, int j){
			return w[i][j];
		}

		void getW(int i, int j, double value){
			w[i][j] = value;
		}

		double getB(int j){
			return b[j];
		}

		void setB(int j, double value){
			b[j] = value;
		}
	private:
		vector<vector<double>> w;

		vector<double> b;
};

class FlattenLayer : public Layer {
	public:
		~FlattenLayer(){};
		FlattenLayer(int  x, int y){
			inputSize = {x, y};
			outputSize = {x*y, 1};
			input.resize(x);
			for(int i = 0; i < x; i++){
				input[i].resize(y);
			}
			output.resize(x*y);
		}

		void forwardPropagation(vector<vector<double>> & in) override {
			//Copy of in into input
			for (int i = 0; i < inputSize[0]; i++){
				for (int j = 0; j < inputSize[1]; j++){
					input[i][j] = in[i][j];
				}
			}
			in.resize(outputSize[0]);
			for (int i = 0; i < inputSize[0]; i++){
				for (int j = 0; j < inputSize[1]; j++){
					in[i*inputSize[0] + j].resize(1, input[i][j]);
				}
			}
		}
		void backwardPropagation(vector<vector<double>>  & dEY, double const& learningRate) override {
			// COPY OF DEY
			vector<vector<double>> dEX(inputSize[0]);
			for (int i = 0; i < inputSize[0]; i++){
				dEX[i].resize(inputSize[1]);
				for (int j = 0; j < inputSize[1]; j++){
					dEX[i][j] = dEY[i*inputSize[0] + j][0];
				}
			}
			dEY = dEX;
		}
};
#endif /* INCLUDE_LAYER_HPP_ */
