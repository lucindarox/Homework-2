#include <cstdio>

#include <fstream>
#include <iostream>
#include <vector>
#include "PriorityQueue.h"

#include "json.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Usage: %s inputFile\n", argv[0]);
		return EXIT_FAILURE;
	}

	// Get samples
	std::ifstream inputFile(argv[1]);
	nlohmann::json samples;

	std::ofstream ofile("output.json");

	if (inputFile.is_open()) {
		inputFile >> samples;
	} else {
		printf("Unable to open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	int arraySize = samples["metadata"]["arraySize"];
	int nSamples = samples["metadata"]["numSamples"];

	for (int i = 1; i <= nSamples; i++) {
		// std::cout << samples["Sample" + std::to_string(i)];

		PriorityQueue p(4);
		for (int x : samples["Sample" + std::to_string(i)]) {
			p.insert(x);
		}

		/*
		 * The instructions state that the sorted values should be placed into the end of the input array
		 * which will over write the array but also allows us to create the sorted version without increasing
		 * memory usage any further. By using heap sort, we are increasing memory usage at proportional to the
		 * size of the input.
		 */
		for (int j = 0; j < arraySize; j++) {
			int x = p.removeMax();
			samples["Sample" + std::to_string(i)][arraySize - j - 1] = x;
		}

	}

	ofile << samples;
	ofile.close();
	return EXIT_SUCCESS;

}
