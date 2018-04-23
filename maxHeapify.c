/*
* Max Heapify using an array.
*/
int* maxHeapify(int parent, int size, int* to_beHeapified){
    int leftChild = parent*2+1;
    int rightChild;
    int largest;

    if(size % 2 != 0 || parent != size/2-1 )
        rightChild = parent*2+2;
    else
        rightChild = 0;


    if(parent == -1 || size <= leftChild || size <= rightChild)
        return to_beHeapified;

    if(rightChild && to_beHeapified[rightChild] > to_beHeapified[leftChild])
        largest = rightChild;
    else
        largest = leftChild;

    if(to_beHeapified[largest] > to_beHeapified[parent]){
        swap(&to_beHeapified[largest],&to_beHeapified[parent]);
        maxHeapify(largest,size,to_beHeapified);
    }

    return maxHeapify(parent-1,size,to_beHeapified);
}

void swap(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
