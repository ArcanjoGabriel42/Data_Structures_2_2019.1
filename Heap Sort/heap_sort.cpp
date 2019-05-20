#include "heap_sort.h"
#include <iostream>
#include <limits.h>
using namespace std;

int parent(int index){
	return index/2;
}

int left(int index){
	return 2*index;
}

int right(int index){
	return 2*index + 1;
}

int maximum(Heap *a){
	return a->vector[0];
}

int minimum(Heap *a){
    heap_sort(a);
    int aux = a->vector[0];
    build_max_heap(a);
    return aux;
}

Heap * build(){
    Heap *h = (Heap*)malloc(sizeof(Heap));
    int num;
    cout << "Enter the number of values: ";
    cin >> num;
    h->vector    = (int*)malloc((num)*sizeof(int));
    h->lenght    = num;
    h->heap_size = 0;
    for(int aux = 0; aux < num; aux++){
        cin >> h->vector[aux];
    }
    return h;
}

void build_max_heap(Heap *a){
    a->heap_size = a->lenght;
    int i;
    for(i = a->lenght/2; i >= 0; i--)
        max_heapify(a, i);   
}

void max_heapify(Heap *a, int index){
	int l = left(index);
	int r = right(index);
	int largest = index;

	if (l < a->heap_size){
		if (a->vector[l] > a->vector[index]) //If the child on the left is larger than the parent.
			largest = l;
	}

	if (r < a->heap_size){
        if (a->vector[r] > a->vector[largest]) //If the child on the right is larger than largest.
            largest = r;
	}
	
	if (largest != index){
		int change_aux = a->vector[index];
		a->vector[index] = a->vector[largest]; //change the largest;
		a->vector[largest] = change_aux; //change the largest;
		max_heapify(a,largest);
	}
    print(a);
}

void heap_sort(Heap *a){
	build_max_heap(a);
	int i,change_aux;
	for (i = a->lenght - 1; i > 0; i--){
		change_aux = a->vector[0]; //change the largest A[0] for the last
		a->vector[0] = a->vector[i]; //change the largest A[0] for the last
		a->vector[i] = change_aux; //change the largest A[0] for the last

		a->heap_size = a->heap_size - 1; //decreases the size of the heap since the latter are organized
		max_heapify(a,0); //to keep the property of heap;

	}
    cout << "Finished Heapsort"<< endl;
}

int heap_extract_max(Heap *a){
	if (a->heap_size < 1){
		cout << "Heap underflow";
		return 0;
	}
	int max = a->vector[0];
	a->vector[0] = a->vector[a->heap_size-1];
	a->heap_size = a->heap_size-1;
    //a->lenght = a->lenght-1;
	max_heapify(a,0);
    print(a);
	return max;
}

void heap_increase_key(Heap *a, int index, int key){
    if(key < a->vector[index]){
        cout << "new key is smaller than current key" << endl;
        return;
    }

    a->vector[index] = key;
  
    while(index > 0){
        if(a->vector[parent(index)] < a->vector[index]){
            int aux = a->vector[index];
            a->vector[index] = a->vector[parent(index)];
            a->vector[parent(index)] = aux;
            index = parent(index);
        } 
        else {
            break;
        }
        print(a);
    }
}

void max_heap_insert(Heap *a, int key){
    a->heap_size = a->heap_size + 1;
    a->vector[a->heap_size] = INT_MIN;
    heap_increase_key(a, a->heap_size, key);
    print(a);
}

int heap_extract_min(Heap *a){
    if(a->heap_size < 1){
        cout << "heap underflow" << endl;
        return 0;
    }
    heap_sort(a);
    int min = a->vector[0];
    a->vector[0] = a->vector[a->heap_size-1];
    a->heap_size = a->heap_size - 1;
    //a->lenght = a->lenght-1;
    build_max_heap(a);
    print(a);
    return min;
}

void heap_decrease_key(Heap *a, int index, int key){
    if(key > a->vector[index]){
        cout << "new key is bigger than current key" << endl;
        return;
    }
    a->vector[index] = key;
    print(a);
    max_heapify(a, parent(index));
}

void min_heap_insert(Heap *a, int key){
    a->heap_size = a->heap_size + 1;
    a->vector[a->heap_size-1] = INT_MAX;
    heap_decrease_key(a, a->heap_size-1, key);
    print(a);
}

void print(Heap *a){
	int aux;
    for(aux = 0; aux < a->heap_size; aux++){
        cout << a->vector[aux] << " ";
    }
    cout << " - ";
    for(aux = a->heap_size; aux < a->lenght; aux++){
        cout << a->vector[aux] << " ";
    }
    cout << endl;
}






