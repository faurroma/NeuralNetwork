/*
 * Model.h
 *
 *  Created on: 22 déc. 2020
 *      Author: faureromain
 */

#ifndef INCLUDE_MODEL_H_
#define INCLUDE_MODEL_H_


class Model {
	public:
		Model(std::string lossFct, double learningR);
		void add(Layer lay, std::string activation);
		std::vector<double> getOutputFor(std::vector<double> input);
	private:
		std::vector<Layer> layers;
		std::vector<std::string> activationFunctions;
		std::string lossFunction;
		double learningRate;

		void activate(std::vector<double> values, std::string function);
		void backwardPropagation(double dEY[]);
		void fit(std::vector<std::vector<double>> trainingInput,
				 std::vector<std::vector<double>> trainingOutput);
};


#endif /* INCLUDE_MODEL_H_ */
