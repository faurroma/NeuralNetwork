#ifndef INCLUDE_FUNCTIONS_HPP_
#define INCLUDE_FUNCTIONS_HPP_

void sigmoid(std::vector<double>& values);

void identity(std::vector<double>& values);

void step(std::vector<double>& values);

double crossEntropy(vector<double> expected, vector<double> score);

#endif /* INCLUDE_FUNCTIONS_HPP_ */