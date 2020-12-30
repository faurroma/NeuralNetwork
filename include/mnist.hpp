/*
 * mnist.hpp
 *
 *  Created on: 29 déc. 2020
 *      Author: faureromain
 */

#ifndef INCLUDE_MNIST_HPP_
#define INCLUDE_MNIST_HPP_

#include <vector>

int exempleMNIST();

std::vector<std::vector<double>> getTrainingInput();
std::vector<std::vector<double>> getTrainingOutput();
std::vector<std::vector<double>> getTestingInput();
std::vector<std::vector<double>> getTestingOutput();

#endif /* INCLUDE_MNIST_HPP_ */
