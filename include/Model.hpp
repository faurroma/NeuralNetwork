#ifndef INCLUDE_MODEL_HPP_
#define INCLUDE_MODEL_HPP_

#include <string>
class Model {
	public:
		Model(std::string lossFct, double learningR);
		void add(Layer lay, std::string activation);
		std::vector<double> getOutputFor(std::vector<double> input);
		void backwardPropagation(std::vector<double>& dEY, std::vector<double>& entree);
		void fit(std::vector<std::vector<double>> trainingInput,
				 std::vector<std::vector<double>> trainingOutput);
	private:
		std::vector<Layer> layers;
		std::vector<std::string> activationFunctions;
		std::string lossFunction;
		double learningRate;

		void activate(std::vector<double> values, std::string& function);
};


#endif /* INCLUDE_MODEL_HPP_ */
