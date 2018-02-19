
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

#include "json.hpp"

#include "PriorityQueue.h"

using namespace std;
using json = nlohmann::json;

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
	
	//creat an array using push_back
	json j;
	j.push_back("foo");
	j.push_back(1);
	j.push_back(true);
	
// Initialize result data
/*
	nlohmann::json result;
	result["metadata"] = samples["metadata"];
	result["metadata"]["file"] = inputFilename;
	unsigned int samplesWithInversions = 0;
*/
	std::vector<int> sampleData;
	// Reserving / resizing space for sample data prevents overhead from vector resizing
	// due to multiple push_back's. Reserve only reserves memory for the vector, while
	// resize changes the number of elements currently in the vector.
	sampleData.resize(result["metadata"]["arraySize"]);
	
	/*
	for (auto itr = samples.begin(); itr != samples.end(); ++itr) {
		if (itr.key() != "metadata") {
			auto sample = itr.value();
			std::copy(sample.begin(), sample.end(), sampleData.begin());
			result[itr.key()] = verifySorted(sampleData);
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
}
	*/
	/*
Class Stack
valueStack := empty stack
minStack := empty stack
	
	procedure top()
		return (valueStack.top(), minStack.top())
	
	procedure push(value)
		if stack.is.Empty() then
			valueStack.push(value)
			minStack.push(value)
		else
			valueStack.push(value)
			minStack.push(min(value, minStack.top()))
		end if
	procedure pop()
			valueStack.pop()
			minStack.pop()
	procedure min()
			return minStack.top()
		*/
			
int main () {
vector<int> v(); //Want it to turn JSON into vector array so I can turn it into a heap below.

make_heap (v.begin(),v.end());

 cout << "heap:   ";
    for (const auto &i : v) {
     cout << i << ' ';
    }   
  

/*pop_heap (v.begin(),v.end()); v.pop_back();
cout << "max heap after pop : " << v.front() << endl;
	//need to store the value that is popped out at the end of an array large enough to hold all the values +1

v.push_back(99); push_heap (v.begin(),v.end());
cout << "max heap after push: " << v.front() << endl;
*/
   sort_heap(v.begin(), v.end());
  
    std::cout <<endl<< "now sorted:   ";
    for (const auto &i : v) {                                                   
        cout << i << ' ';
    }   
    std::cout <<endl;

return 0;
} 

