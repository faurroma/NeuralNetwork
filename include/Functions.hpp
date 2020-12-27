#ifndef INCLUDE_FUNCTIONS_HPP_
#define INCLUDE_FUNCTIONS_HPP_


// ACTIVATION FUNCTIONS AND THEIR DERIVATIVE
void sigmoid(std::vector<double>& values);

void sigmoidPrime(std::vector<double>& values);

void identity(std::vector<double>& values);

void identityPrime(std::vector<double>& values);

void tanH(vector<double>& values);

void tanHPrime(vector<double>& values);

void step(std::vector<double>& values);

void stepPrime(std::vector<double>& values);


// LOSS FUNCTIONS AND THEIR DERIVATIVE
double crossEntropy(vector<double> const & expected, vector<double> const & prediction);

vector<double> crossEntropyPrime(vector<double> const & expected, vector<double> const & prediction);

double binaryCrossEntropy(vector<double> const & expected, vector<double> const & prediction);

vector<double> binaryCrossEntropyPrime(vector<double> const & expected, vector<double> const & prediction);

double mse(vector<double> const & expected, vector<double> const & prediction);

vector<double> msePrime(vector<double> const & expected, vector<double> const & prediction);

// USEFUL FUNCTIONS
void print(string);

void printV(vector<double> const & values, string title);

void printM(vector<vector<double>> const & values, string title);

#endif /* INCLUDE_FUNCTIONS_HPP_ */
