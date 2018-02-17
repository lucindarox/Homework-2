#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;
#ifndef HEAP_H
#define   HEAP_H

struct Element
{
    int keyElement;
};
class HEAP {
    public:
        HEAP ();
        HEAP (int, int, Element[]);
        HEAP (int, int, int);
        HEAP (int, int);
        ~HEAP(void);
        void addIntoHeap(HEAP, int);
    
        void size_set(int fsize) {end_size=fsize;}
    
        int size_get() {return heapSize;}
        void size_set(int vn) {heapSize=vn;}
        void size_inc() {heapSize++;}
        void dec_size() {heapSize--;}
        int capacity_get() {return hapCapa;}
    
    
        Element element_get(int vn) {return element[(vn-1)];}
        void element_key_set(int heapNode, int keyElement) {this->element[(heapNode-1)].keyElement = keyElement;}
        void element_set(int heapNode, Element ith_elem) {this->element[(heapNode-1)] = ith_elem;}
        int parent_get(int heapNode)
        {
            if(heapNode == 1)
                return NULL;
            else
                return floor(heapNode/2);
        }
         Element get_parent_element(int heapNode)
        {
           return (this->element_get(this->parent_get(heapNode)));
        }
        bool parent_has_two_children(int heapNode)
        {
            if(this->heapSize >= this->parent_get(heapNode)*2+1)
                return true;
            else
                return false;
        }
        Element get_right_child_element(int heapNode)
        {
            return this->element_get((2*heapNode)+1);
        }
        int get_right_child(int heapNode)
        {
            if(2*heapNode+1 <= this->heapSize)
                return heapNode*2+1;
            else
                return INT_MAX;
        }
        Element get_left_child_element(int heapNode)
        {
            return this->element_get(2*heapNode);
        }
        int get_left_child(int heapNode)
        {
            if(heapNode*2 <= this->size_get())
                return heapNode*2;
            else
                return INT_MAX;
        }
        bool is_element(int heapNode)
        {
            if(heapNode <= this->heapSize)
                return true;
            else
                return false;
        }
        void swap_with_parent(int heapNode)
        {
        
            Element parent_element = this->get_parent_element(heapNode);
            this->element_set(this->parent_get(heapNode), this->element_get(heapNode));
            this->element_set(heapNode, parent_element);
            return;
        }

        int swap_with_right_child(int heapNode)
        {
             Element current_element = this->element_get(heapNode);
            this->element_set(heapNode, this->get_right_child_element(heapNode));
            this->element_set(this->get_right_child(heapNode), current_element);
            return this->get_right_child(heapNode);
        }
        int swap_with_left_child(int heapNode)
        {
             Element current_element = this->element_get(heapNode);
            this->element_set(heapNode, this->get_left_child_element(heapNode));
            this->element_set(this->get_left_child(heapNode), current_element);
            return this->get_left_child(heapNode);
        }

    private:
        int hapCapa;
        int heapSize;
        int end_size;
        Element *element;
    

};

HEAP InitializeHeap(int);
int DeleteMaxHeap(HEAP&);
void InsertToHeap(HEAP&, Element);
void addIntoHeap(HEAP&, int);
void BuildHeap(HEAP&, Element[], int);
void IncreaseKeyHeap(HEAP&, int, int);
void PrintHeap(HEAP);
void Heapify(HEAP&, int);
void Sort_Heap(HEAP&);
#endif   /* HEAP_H */
