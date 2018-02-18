
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
int myints[] = {JSON}; //I want it to call from JSON here
vector<int> v(JSON, JSON); //Want it to turn JSON into vector array so I can turn it into a heap below.

make_heap (v.begin(),v.end());
cout << "Initial max heap : " << v.front() << endl;

pop_heap (v.begin(),v.end()); v.pop_back();
cout << "max heap after pop : " << v.front() << endl;
	//need to store the value that is popped out at the end of an array large enough to hold all the values +1

v.push_back(99); push_heap (v.begin(),v.end());
cout << "max heap after push: " << v.front() << endl;

sort_heap (v.begin(),v.end());

cout << "final sorted range :";
for (unsigned i=0; i<v.size(); i++) cout << " " << v[i];

cout << endl;

return 0;
} 

--------------//below this line, is another code that I'm trying to work with.
	/*

  heapSort example using priority queue from Sedgewick's Algorithms in C++

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include JSON


void insert(int);
int hremove(void);
void downheap(int);
void upheap(int);
void heapSort(struct numbers*)
int *heapArray;
int N=0;

int main()
{
    int i;
    struct numbers vals = //from JSON
    heapSort(&vals);

    // prove that it worked

    for (i=0; i<vals.size; i++)
        printf("%d ", vals.values[i]);
    printf("\n");
    return 0;
}

void insert(int item)
{
    heapArray[++N] = item;
    upheap(N);
}

// remove is in stdio.h

int hremove(void)
{
    int v = heapArray[1];
    heapArray[1] = heapArray[N--];
    downheap(1);
    return v;
}

void downheap(int k)
{
    int j, v;
    v = heapArray[k];
    while (k <= N/2)
    {
        j = k+k;
        if (j < N && heapArray[j] < heapArray[j+1]) j++;
        if (v >= heapArray[j]) break;
        heapArray[k] = heapArray[j]; k = j;
    }

    heapArray[k] = v;
}

void upheap(int k)
{
    int v;
    v = heapArray[k];
    while (heapArray[k/2] <= v)
    {
        heapArray[k] = heapArray[k/2];
        k = k/2;
    }
    heapArray[k] = v;
}

void heapSort(struct numbers *vals)
{
    // allocate a heapArray sufficient to hold all values plus sentinel
    heapArray = malloc(vals->size * sizeof(int) + 1);
    int max=0;
    int i=0;

    // find the largest value in vals->values and store it as a sentinel in heapArray[0]

    for (i = 0; i < vals->size; i++)
    {
        max = (vals->values[i] > max) ? vals->values[i] : max;
    }

    heapArray[0] = max+1;

    // this inserts the values, which places them into descending order in the heap
    for (i = 0; i < vals->size; i++)
    {
        insert(vals->values[i]);
    }

    // this removes the values from the heap from largest to smallest, they are stored

    // from the end of the array to the beginning to get the ascending array in order

    while (i--)
        vals->values[i] = hremove();

    free(heapArray);
}

