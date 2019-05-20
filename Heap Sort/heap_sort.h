#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_ 
using namespace std;

typedef struct heap{
	int lenght;
	int heap_size;
	int *vector;
}Heap;

Heap *build();

int parent(int index);

int left(int index);

int right(int index);

int maximum(Heap *a);

int minimum(Heap *a);

int heap_extract_min(Heap *a);

int heap_extract_max(Heap *a);

void build_max_heap(Heap *a);

void max_heapify(Heap *a, int index);

void heap_sort(Heap *a);

void heap_increase_key(Heap *a, int index, int key);

void max_heap_insert(Heap *a, int key);

void heap_decrease_key(Heap *a, int index, int key);

void min_heap_insert(Heap *a, int key);

void print(Heap *a);

#endif