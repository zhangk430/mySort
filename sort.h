#ifndef SORT_H
#define SORT_H

#include<vector>
#include<iostream>
#include<functional>
#include"heap.h"

template<typename T, typename F = std::less<T>>
class mySort {
public:
	void insertionSort(std::vector<T>& vec, F f = F());
	void mergeSort(std ::vector<T>& vec, F f = F());
	int partition(std::vector<T>& vec, int p, int r, F f = F());
	void quicksort(std::vector<T>& vec, int p, int r, F f = F());
	void heapsort(std::vector<T>& vec, F f = F());
private:
	std::vector<T> mergeSort(const std::vector<T>& vec, int i, int j, F f = F());
	std::vector<T> merge(const std::vector<T>& vec1, const std::vector<T>& vec2, F f = F());
};

#include "sort.hpp"

#endif
