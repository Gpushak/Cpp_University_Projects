#pragma once
#include <vector>

void Merge(vector<int>& vect, int beginIndex, int endIndex, int middleIndex) {
    int leftIndex = beginIndex;
    int rightIndex = middleIndex + 1;
    int mergeArrLenght = endIndex - beginIndex + 1;
    int* mergeArr = new int[mergeArrLenght];

    for (int i = 0; i < mergeArrLenght; i++) {
        if (leftIndex <= middleIndex &&
            (rightIndex > endIndex || vect[leftIndex] < vect[rightIndex]))
        {
            mergeArr[i] = vect[leftIndex++];
        }
        else
        {
            mergeArr[i] = vect[rightIndex++];
        }
    }

    int currentIndex = beginIndex;
    for (int i = 0; i < mergeArrLenght; i++) {
        vect[currentIndex++] = mergeArr[i];
    }

    delete[] mergeArr;
}

void SliceAndMerge(vector<int>& vect, int beginIndex, int endIndex) {
    if (beginIndex < endIndex) {
        int middleIndex = (beginIndex + endIndex) / 2;
        SliceAndMerge(vect, beginIndex, middleIndex);
        SliceAndMerge(vect, middleIndex + 1, endIndex);
        Merge(vect, beginIndex, endIndex, middleIndex);
    }
}

void MergeSort(vector<int>& vect) {
    if (vect.size() > 1) {
        SliceAndMerge(vect, 0, vect.size() - 1);
    }
}