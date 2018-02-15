#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include "json.hpp"

nlohmann::json verifySorted(const std::vector<int>& sample);

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

	// Initialize result data
	nlohmann::json result;
	result["metadata"] = samples["metadata"];
	result["metadata"]["file"] = inputFilename;
	unsigned int samplesWithInversions = 0;


using namespace std;

int main () {
int myints[] = json; //I want it to pull from json and I am unsure how to do that
vector<int> v(json, json???); //i want the vector to span json

make_heap (v.begin(),v.end());
cout << "initial max heap : " << v.front() << endl;

pop_heap (v.begin(),v.end()); v.pop_back();
cout << "max heap after pop : " << v.front() << endl;

v.push_back(99); push_heap (v.begin(),v.end());
cout << "max heap after push: " << v.front() << endl;

sort_heap (v.begin(),v.end());

cout << "final sorted range :";
for (unsigned i=0; i<v.size(); i++) cout << " " << v[i];

cout << endl;

return 0;
} 
