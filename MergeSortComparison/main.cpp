//
//  main.cpp
//  MergeSortComparison
//
//  Created by Fekadeab Dejene on 2016-08-19.
//
//

#include <iostream>
#include "MergeSorts.h"
#include "SimpleTimer.h"


int * GenerateRandomArray(size_t amount){
    int* ptr = (int*)malloc(amount * sizeof(int));
    assert(ptr != NULL);
    for(size_t i = 0; i < amount; i++){
        ptr[i] = rand() % 100000;
    }
    return ptr;
}

void printList(int data[], int len){
    for(int i = 0; i < len; i++){
        std::cout<< data[i] << "\n";
    }
}
int main(int argc, const char * argv[]) {
    int len = 10000000;
    int*t1  = GenerateRandomArray(len);
    int*t2  = GenerateRandomArray(len);
    
    SetCurrentTimeStamp();
    IterativeMergeSort(t1, len);
    std::cout<< "Iterative runs in: \n" << GetElapsedMilliSeconds() << "ms\n";
    SetCurrentTimeStamp();
    RecursiveMergeSort(t2, len);
    std::cout<< "Recursive runs in: \n" << GetElapsedMilliSeconds() << "ms\n";
    free(t1);
    t1 = NULL;
    free(t2);
    t2 = NULL;
    return 0;
}



