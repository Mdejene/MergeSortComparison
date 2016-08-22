//
//  MergeSorts.h
//  MergeSorts
//
//  Created by Fekadeab Dejene on 2016-08-19.
//
//

#ifndef MergeSorts_MergeSorts_h
#define MergeSorts_MergeSorts_h
#include <assert.h>
#define MIN(a,b) a > b ? b : a
#define MAX(a,b) a > b ? a : b

static void RecursiveMergeSort(int data[], size_t length);
static void __recursiveMergeSort(int data[], int temp[], size_t begin, size_t end);

static void IterativeMergeSort(int data[], size_t length);
static void __iterativeMergeSort(int data[],int temp[], size_t begin, size_t end);

static void __merge(int p1[],int temp[], size_t begin, size_t middle, size_t end);


static void RecursiveMergeSort(int data[], size_t length){
    int* temp = (int*)malloc(sizeof(int) * length);
    assert(temp != NULL);
    __recursiveMergeSort(data, temp, 0, length-1);
}
    
static void __recursiveMergeSort(int data[], int temp[], size_t begin, size_t end){
    size_t middle;
    if (begin  < end ) {
        middle = (end + begin) / 2;
        __recursiveMergeSort(data, temp, begin, middle);
        __recursiveMergeSort(data, temp, middle+1, end);
        __merge(data, temp, begin, middle, end);
    }
}

static void IterativeMergeSort(int data[], size_t length){
    int* temp = (int*)malloc(sizeof(int) * length);
    assert(temp != NULL);
    __iterativeMergeSort(data, temp, 0, length -1);
}
static void __iterativeMergeSort(int data[], int temp[], size_t begin, size_t end){
    size_t step;
    size_t start;
    size_t length = end - begin;
    size_t minEnd;
    for (step = 1; step < length; step = step << 1) {
        for(start = 0; start + step < length; start += step << 1){
            minEnd = step + step + start - 1;
            minEnd = minEnd > end ? end  : minEnd;
            __merge(data, temp,  start, start+step -1,  minEnd );
        }
    }
}


static void __merge(int data[], int temp[], size_t begin, size_t middle, size_t end) {
    
    size_t p1Index = begin;
    size_t p2Index = middle + 1;
    size_t i = begin;
    while(p1Index <= middle && p2Index<= end){
        if(data[p1Index] < data[p2Index]){
            temp[i++] = data[p1Index++];
        }
        else{
            temp[i++] = data[p2Index++];
        }
    }
    while(p1Index <= middle){
        temp[i++] = data[p1Index++];
    }
    
    while(p2Index <= end){
        temp[i++] = data[p2Index++];
    }
    
    p1Index = begin;
    while(p1Index < i){
        data[p1Index] = temp[p1Index];
        ++p1Index;
    }
    
}

#endif
