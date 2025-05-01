#pragma once
#include <iostream>
using namespace std;

typedef int datatype;

void Swap(datatype* a, datatype* b);
void Show(datatype arr[], int size, int start, int end);

void SortBubble(datatype* arr, int start, int end);
void SortInsertion(datatype* arr, int start, int end);
void SortSelection(datatype* arr, int start, int end);
