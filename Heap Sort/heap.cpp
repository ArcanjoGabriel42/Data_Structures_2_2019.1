#include "heap_sort.h"
#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    int i,v;
    /*Populatete Heap*/
	Heap *h = build();

    /* Makes their sons be lesser than them*/
    build_max_heap(h);
    cout << "Now we have a bodybuilder" << endl;

    /*Organize them*/
    heap_sort(h);
    cout << "Organized" << endl;

    /* Makes their sons be lesser than them to extract the maximum*/
    build_max_heap(h);

    cout << "Here is the big one:" << maximum(h) << endl;

    /*Removing the bigger one*/
    cout << heap_extract_max(h) << endl;
    cout << "Removed the big one" << endl;

    /* Insert new keys*/
    cout << "Inform a index be promoted and his new value(index(space)value):";
    cin >> i >> v;
    heap_increase_key(h, i, v);

    cout << "Another one:";
    cin >> i >> v;
    heap_increase_key(h, i, v);

    cout << "Inform a number to be inserted in the beggining:";
    cin >> v;
    max_heap_insert(h, v);

    cout << "Little one:" << minimum(h) << endl;

    cout << "Removed: "<< heap_extract_min(h) << endl;

    cout << "Inform a index be demoted and his new value(index(space)value):";
    cin >> i >> v;
    heap_decrease_key(h, i, v);

    cout << "Inform a number to be inserted in the end:";
    cin >> v;
    min_heap_insert(h, v);

    return 0;
}
