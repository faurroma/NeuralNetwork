#ifndef INCLUDE_FUNCTIONS_HPP_
#define INCLUDE_FUNCTIONS_HPP_


// ACTIVATION FUNCTIONS AND THEIR DERIVATIVE
void sigmoid(std::vector<std::vector<double>>& values);

void sigmoidPrime(std::vector<std::vector<double>> & values);

void tanH(std::vector<std::vector<double>> & values);

void tanHPrime(std::vector<std::vector<double>> & values);

// LOSS FUNCTIONS AND THEIR DERIVATIVE
double binaryCrossEntropy(std::vector<std::vector<double>> const & expected, std::vector<std::vector<double>> const & prediction);

std::vector<std::vector<double>> binaryCrossEntropyPrime(std::vector<std::vector<double>> const & expected, std::vector<std::vector<double>> const & prediction);

double mse(std::vector<std::vector<double>> const & expected, std::vector<std::vector<double>> const & prediction);

std::vector<std::vector<double>> msePrime(std::vector<std::vector<double>> const & expected, std::vector<std::vector<double>> const & prediction);

// USEFUL FUNCTIONS
void print(std::string);

void printV(std::vector<double> const & values, std::string title);

void printM(std::vector<std::vector<double>> const & values, std::string title);

std::vector<std::vector<double>> vectorToMatrix(std::vector<double>& vec);

#endif /* INCLUDE_FUNCTIONS_HPP_ */
