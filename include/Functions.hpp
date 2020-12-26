#ifndef INCLUDE_FUNCTIONS_HPP_
#define INCLUDE_FUNCTIONS_HPP_


// ACTIVATION FUNCTIONS AND THEIR DERIVATIVE
void sigmoid(std::vector<double>& values);

void sigmoidPrime(std::vector<double>& values);

void identity(std::vector<double>& values);

void identityPrime(std::vector<double>& values);

void step(std::vector<double>& values);

void stepPrime(std::vector<double>& values);


// LOSS FUNCTIONS AND THEIR DERIVATIVE
double crossEntropy(vector<double> expected, vector<double> score);

// USEFUL FUNCTIONS


#endif /* INCLUDE_FUNCTIONS_HPP_ */
