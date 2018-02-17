#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;
#include "heap.h"
#include "debug.h"

HEAP::HEAP(int capa_heap, int size_heap, Element element_heap[])
{
    hapCapa = capa_heap;
    heapSize = size_heap;
    element = new Element[capa_heap];

    for(int vi = 0 ; vi < size_heap ; vi++ )
    {
        element[vi] = element_heap[vi];
    }
}
HEAP::HEAP()
{
}
HEAP::HEAP(int capa_heap, int size_heap)
{
    hapCapa = capa_heap;
    element = new Element[capa_heap];
    heapSize = size_heap;
}
HEAP::~HEAP(void)
{
    element = new Element[1];
    delete[] element;
}

HEAP InitializeHeap(int capa_heap)
{
    HEAP return_heap(capa_heap, 0);
    return return_heap;
}

void BuildHeap(HEAP &heap_i, Element va[], int heapSize)
{
    int init_size = heap_i.size_get();

    debug("heapSize of va", heapSize);
    debug("Size before build heap", heap_i.size_get());

    //Make the heap in the order of the array
    for (int vi = init_size ; vi < heapSize+init_size&& vi < heap_i.capacity_get(); vi++)
    {
        if(vi > heap_i.capacity_get())
            cout << "Error!!!";
        InsertToHeap(heap_i, va[vi-init_size]);
    }

    debug("Size of the heap after build heap", heap_i.size_get());
    debug(heap_i.element_get(0).keyElement);
    debug("vi",floor(heap_i.size_get()/2));
    for(int vi=floor(heap_i.size_get()/2); vi >= 1 ; vi--)
    {
        Heapify(heap_i, vi);
    }
}

void InsertToHeap(HEAP &heap_i, Element ith_elem)
{
    heap_i.size_inc();
    heap_i.element_set(heap_i.size_get(), ith_elem);
}

void Heapify(HEAP &heap_i, int element)
{
    debug("Heapify");
    int key_left, key_right, big;
    int head = heap_i.element_get(element).keyElement;
    int left_node = heap_i.get_left_child(element);
    int right_node = heap_i.get_right_child(element);
    if(left_node <= heap_i.size_get())
    {
        key_left = heap_i.get_left_child_element(element).keyElement;
        if(key_left > head)
            big = left_node;
        else
            big = element;
    }
    else
        big = element;
    if(right_node <= heap_i.size_get())
    {
        key_right = heap_i.get_right_child_element(element).keyElement;
        if(key_right > heap_i.element_get(big).keyElement)
            big = right_node;
    }
    if(big != element)
    {
        Element largest_element = heap_i.element_get(big);
        heap_i.element_set(big, heap_i.element_get(element));
        heap_i.element_set(element, largest_element);
        Heapify(heap_i, big);
    }
}
void addIntoHeap(HEAP &heap_i, int keyElement)
{
    Element new_element;
    new_element.keyElement = keyElement;
    InsertToHeap(heap_i, new_element);
    for(int vi=floor(heap_i.size_get()/2); vi >= 1 ; vi--)
    {
        Heapify(heap_i, vi);
    }
}
int DeleteMaxHeap(HEAP &heap_i)
{
    Element deleted_element = heap_i.element_get(1);
    heap_i.element_set(1, heap_i.element_get(heap_i.size_get()));
    heap_i.dec_size();
    for(int vi=floor(heap_i.size_get()/2); vi >= 1 ; vi--)
    {
        Heapify(heap_i, vi);
    }
    return deleted_element.keyElement;
}

void IncreaseKeyHeap(HEAP &heap_i, int element, int keyElement)
{
    heap_i.element_key_set(element, keyElement);
    while(element > 1 && heap_i.get_parent_element(element).keyElement < keyElement)
    {
        heap_i.swap_with_parent(element);
        element = heap_i.parent_get(element);
    }
}
void PrintHeap(HEAP heap_i)
{
    cout << heap_i.capacity_get() << "\n";
    cout << heap_i.size_get() << "\n";
    for (int vi=1 ; vi <= heap_i.size_get() ; vi++)
    {
        cout << heap_i.element_get(vi).keyElement << "\n";
    }
}
