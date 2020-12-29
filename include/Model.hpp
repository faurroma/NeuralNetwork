#ifndef INCLUDE_MODEL_HPP_
#define INCLUDE_MODEL_HPP_

#include <string>
class Model {
	public:
		Model(std::string lossFct, double learningRvector);
		void add(Layer lay, std::string activation);
		std::vector<double> getOutputFor(std::vector<double> const & input);
		void backwardPropagation(std::vector<double>& dEY);
		void fit(std::vector<std::vector<double>> trainingInput,
				 std::vector<std::vector<double>> trainingOutput, int epochs);
		void write(string name);
		static Model read(string name);
	private:
		std::vector<Layer> layers;
		std::vector<std::string> activationFunctions;
		std::string lossFunction;
		double learningRate;

		void activate(std::vector<double>& values, std::string& function);
		void activatePrime(vector<double>& values, std::string& function);

		double loss(vector<double>& expected, vector<double> &prediction);
		vector<double> lossPrime(vector<double>& expected, vector<double>& prediction);


};


#endif /* INCLUDE_MODEL_HPP_ */
