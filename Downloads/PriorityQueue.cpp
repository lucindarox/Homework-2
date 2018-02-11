#include "PriorityQueue.h"
#include <iostream>

using namespace std;

PriorityQueue::PriorityQueue(int max_size)
{
	maxSize = max_size;
	currSize = 0;
	pQueue = new unsigned int[maxSize+1];
}

PriorityQueue::~PriorityQueue()
{
	delete[] pQueue;
}

void PriorityQueue::insert(unsigned int k)
{
	if (currSize == maxSize)
		cout << "PriorityQueue::insert called on full priority queue";
	pQueue[++currSize] = k;
	heapifyUp(currSize-1);
}

void PriorityQueue::removeMax()
{
	if (0 == currSize)
		cout << "PriorityQueue::removeMax called on an empty priority queue";
	pQueue[1] = pQueue[currSize];
	heapifyDown(1);
	currSize--;
}

void PriorityQueue::removeKey(unsigned int k)
{
	bool bFound = false;
	for (int i = 1; i <= currSize; i++)
	{
		if (k == pQueue[i])
		{
			pQueue[i] = pQueue[currSize];
			bFound = true;
			break;
		}
	}

	if (false == bFound)
		cout << "PriorityQueue::removeKey key " << k << " not found";

	heapifyDown(1);
	currSize--;
}

void PriorityQueue::change(unsigned int k, unsigned int newK)
{
	bool bFound = false;
	for (int i = 1; i <= currSize; i++)
	{
		if (k == pQueue[i])
		{
			pQueue[i] = newK;
			bFound = true;
			break;
		}
	}

	if (false == bFound)
		cout << "PriorityQueue::change key " << k << " not found";

	heapifyDown(1);	
}

void PriorityQueue::heapifyUp(int i)
{
	if (i >= 0 && pQueue[i] > pQueue[parent(i)])
	{
		swap(pQueue[i], pQueue[parent(i)]);
		heapifyUp(parent(i));
	}
}

void PriorityQueue::heapifyDown(int i)
{
	int leftChild = left(i);
	int rightChild = right(i);

	int temp = i;

	if (leftChild<currSize && pQueue[leftChild] > pQueue[i])
		temp = leftChild;

	if (rightChild<currSize && pQueue[rightChild] > pQueue[temp])
		temp = rightChild;

	if (i != temp)
	{
		swap(pQueue[i], pQueue[temp]);
		heapifyDown(temp);	
	}
}

int PriorityQueue::parent(int i)
{
	return (i - 1) / 2;
}

int PriorityQueue::left(int i)
{
	return (2*i)+1;
}

int PriorityQueue::right(int i)
{
	return (2*i)+2;
}

void PriorityQueue::swap(unsigned int &num1, unsigned int &num2)
{
	unsigned int temp = num1;
	num1 = num2;
	num2 = temp;
}