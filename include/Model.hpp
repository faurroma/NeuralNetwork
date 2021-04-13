#ifndef INCLUDE_MODEL_HPP_
#define INCLUDE_MODEL_HPP_

using namespace std;

class Model {
	public:
		Model(string lossFct, double learningR);

		void add(Layer* lay, std::string activation);

		vector<vector<double>> getOutputFor(vector<vector<double>> const & input);


		void backwardPropagation(vector<vector<double>> & dEY);


		void fit(vector<vector<vector<double>>> trainingInput,
				vector<vector<vector<double>>> trainingOutput, int epochs);

//
//		void write(string name);
//		static Model read(string name);

	private:
		std::vector<Layer*> layers;
		std::vector<std::string> activationFunctions;
		std::string lossFunction;
		double learningRate;

		void activate(vector<vector<double>>& values, string& function);


		void activatePrime(vector<vector<double>>& values, string& function);

		double loss(vector<vector<double>>& expected,
					vector<vector<double>> &prediction);

		vector<vector<double>> lossPrime(vector<vector<double>> & expected,
								 vector<vector<double>> & prediction);


};


#endif /* INCLUDE_MODEL_HPP_ */
