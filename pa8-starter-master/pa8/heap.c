#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "heap.h"

/* Your Heap implementation here */
// Some of these functions are not mentioned in the writeup
// but are useful helper functions that you can use 


void swap(Heap* h, int index1, int index2) {
	Entry* temp = h->elements[index1]; 
	h->elements[index1] = h->elements[index2];
	h->elements[index2] = temp;
}

void expandCapacity(Heap* h) {
	int curr_capacity = h->capacity+1; 
	if (h->size < curr_capacity) {
		return; 
	}
	Entry** expanded = calloc(curr_capacity*2, sizeof(Entry*));
	h->capacity = curr_capacity*2; 
	int i;	
	for (i = 0; i < h->size; i += 1) {
		expanded[i] = h->elements[i];
		free(h->elements[i]);
	}
	free(h->elements); 
	h->elements = expanded;
}

void bubbleUp(Heap* h, int index) {
	if (index <= 0) {
		return; 
	}
	Entry* e = h->elements[index];
	printf("index: %d\n", index);
	Entry* p = h->elements[(index-1)/2];
	printf("pindex: %d\n", (index-1)/2);
	if (e->key < p->key) {
		swap(h, index, (index-1)/2); 
		bubbleUp(h, (index-1)/2);
	}
	else {
		return;
	}
}

void add(Heap* h, int k, char* val) {
	if (h->size == h->capacity) {
		expandCapacity(h);
	} 
	h->elements[h->size] = calloc(1, sizeof(Entry));
	h->elements[h->size]->key = k;
	h->elements[h->size]->value = val;
	printf("size: %d\n", h->size);
	h->size += 1;
	if (h->size == 1){
		return; 
	}
	else {	
		bubbleUp(h, h->size-1);
	}	
}

void bubbleDown(Heap* h, int index) {
	if ( index >= h->size){
		return;
	}
	int left_index = index*2 + 1; 
	if (left_index >= h->size){
		return;
	}
	int smaller_child_i =  left_index; 
	int right_index = index*2 + 2; 
	if (h->elements[right_index] != NULL && h->elements[left_index] != NULL 
			&& h->elements[right_index]->key < h->elements[left_index]->key){
		smaller_child_i = right_index; 
	}
	if (h->elements[smaller_child_i] != NULL && h->elements[index] != NULL 
			&& h->elements[smaller_child_i]->key < h->elements[index]->key){
		swap(h, index, smaller_child_i); 
		bubbleDown(h, smaller_child_i); 
	}	
}

char* removeMin(Heap* h) {
	if (h->size == 0) {
		return NULL;
	}
	if (h->size == 1) {
		return h->elements[0]->value;
	}
	Entry* temp = h->elements[0];
	h->elements[0] = h->elements[h->size-1];
	h->size -= 1;
	bubbleDown(h, 0);
	return temp->value;
}

bool isHeapAt(Heap* h, int index) {

}

void cleanupHeap(Heap* h) {
	int i; 
	for (i = 0; i < h->capacity+1; i++) {
		free(h->elements[i]);
	}
	free(h->elements); 
	free(h); 
}

void printHeap(Heap* h) {
	int i;
	for (i = 0; i < h->size; i++){
		printf("i: %d %c  ", i, h->elements[i]->key, h->elements[i]->value);
	}
}

Heap* makeHeap(int capacity) {
	Heap* h = calloc(1, sizeof(Heap)); 
	h->size = 0; 
	h->capacity = capacity;
	h->elements = calloc(capacity+1, sizeof(Entry*));
	return h;
}

char* peek(Heap* heap) {
	if (heap->size == 0){
		return NULL;
	}
	return heap->elements[0]->value;
}

int size(Heap* heap) {
	return heap->size;  
}

