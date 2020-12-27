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
double crossEntropy(vector<double> &expected, vector<double>& prediction);

vector<double> crossEntropyPrime(vector<double>& expected, vector<double>& prediction);

double binaryCrossEntropy(vector<double>& expected, vector<double>& prediction);

vector<double> binaryCrossEntropyPrime(vector<double>& expected, vector<double>& prediction);

double mse(vector<double>& expected, vector<double>& prediction);

vector<double> msePrime(vector<double>& expected, vector<double>& prediction);

// USEFUL FUNCTIONS
void printV(vector<double> values, string title);

void printM(vector<vector<double>> values, string title);

#endif /* INCLUDE_FUNCTIONS_HPP_ */
