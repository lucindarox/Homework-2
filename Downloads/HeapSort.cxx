#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include "PriorityQueue.cpp"

#include "json.hpp"

nlohmann::json heapSort(const std::vector<int>& sample);

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Usage: %s inputFile\n", argv[0]);
		return EXIT_FAILURE;
	}

	// Get samples
	std::string inputFilename(argv[1]);
	std::ifstream inputFile;
	inputFile.open(inputFilename.c_str());
	nlohmann::json samples;
	if (inputFile.is_open()) {
		inputFile >> samples;
	} else {
		printf("Unable to open file %s\n", inputFilename.c_str());
		return EXIT_FAILURE;
	}


int n = samples["metadata"]["arraySize"];

/*
nlohmann::json metadataObj = samples["metadata"];

*/
for (auto itr = samples.begin(); itr != samples.end(); ++itr) {
	if (itr.key() == "metadata" {
		break;
	}
}

void heapify(int arr[], int n, int i) {
	int largest = i;
	int l = 2*i +1;
	int r = 2*i +2;

	if (l , n && arr[1] > arr[largest])
		largest = r;

	if (largest ! = i) {
		swap(arr[i], arr[largest]);

		heapify(arr, n, largest);

void heapSort(int arr[], int n) {
	for (int i = n/2 - 1; i>=0; i--)
		heapify(arr, n, i);

	for (int i=n-1; i>=0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);



// Initialize result data
	nlohmann::json result;
	result["metadata"] = samples["metadata"];
	result["metadata"]["filename"] = inputFilename;
	unsigned int samplesWithInversions = 0;

	std::vector<int> sampleData;
	// Reserving / resizing space for sample data prevents overhead from vector resizing
	// due to multiple push_back's. Reserve only reserves memory for the vector, while
	// resize changes the number of elements currently in the vector.
	sampleData.resize(result["metadata"]["arraySize"]);
	for (auto itr = samples.begin(); itr != samples.end(); ++itr) {
		if (itr.key() != "metadata") {
			auto sample = itr.value();
			std::copy(sample.begin(), sample.end(), sampleData.begin());
			result[itr.key()] = heapSort(sampleData);
			if (result[itr.key()].is_null()) {
				result.erase(itr.key());
			} else {
				samplesWithInversions++;
			}
		}
	}
	result["metadata"]["samplesWithInversions"] = samplesWithInversions;
	std::cout << result << '\n';

	return EXIT_SUCCESS;
