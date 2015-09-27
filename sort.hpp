#ifndef SORT_HPP
#define SORT_HPP

#include "sort.h"
#include <algorithm>

template <typename T, typename F>
void mySort<T, F>::insertionSort(std::vector<T>& vec, F f) {
	for (size_t i = 1; i < vec.size(); i++) {
		T num = vec[i];
		int j = i - 1;
		while (j >= 0 && f(num, vec[j])) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = num;
	}
}

template <typename T, typename F>
void mySort<T, F>::mergeSort(std::vector<T>& vec, F f) {
		vec = mergeSort(vec, 0, vec.size() - 1, f);
	}

template <typename T, typename F>
int mySort<T, F>::partition(std::vector<T>& vec, int p, int r, F f) {
	if (p >= r || r >= vec.size()) 
		return -1;
	int i = p;
	T pivot = vec[r];
	for (int j = p; j < r; j++) {
		if (f(vec[j], pivot)) {
			std::swap(vec[i], vec[j]);
			i++;
		}
	}
	std::swap(vec[i], vec[r]);
	return i;
}

template <typename T, typename F>
void mySort<T, F>::quicksort(std::vector<T>& vec, int p, int r, F f) {
	if (p < r) {
		int q = partition(vec, p, r, f);
		quicksort(vec, p, q - 1, f);
		quicksort(vec, q + 1, r, f);
	}
}

template <typename T, typename F>
void mySort<T, F>::heapsort(std::vector<T>& vec, F f) {
	if (vec.size() <= 1)
		return ;
	myHeap<T> h(vec, heap_type::MIN_HEAP);
	h.buildMaxHeap();
	vec.clear();
	while (h.size()) {
		T max = h.extractMax();
		vec.push_back(max);
	}
	if (!f(vec[0], vec[1]))
		std::reverse(vec.begin(), vec.end());
}

template <typename T, typename F>
std::vector<T> mySort<T, F>::mergeSort(const std::vector<T>& vec, int i, int j, F f) {
	if (i == j) {
		std::vector<T> res;
		res.push_back(vec[i]);
		return res;
	}
	int mid = (i + j) / 2;
	const std::vector<T>& left = mergeSort(vec, i, mid, f);
	const std::vector<T>& right = mergeSort(vec, mid + 1, j, f);
	return merge(left, right, f);
}

template <typename T, typename F>
std::vector<T> mySort<T, F>::merge(const std::vector<T>& vec1, const std::vector<T>& vec2, F f) {
	std::vector<T> res;
	int as = 0, ae = vec1.size(), bs = 0, be = vec2.size();
	while (as < ae && bs < be) {
		if (f(vec1[as], vec2[bs]))
			res.push_back(vec1[as++]);
		else 
			res.push_back(vec2[bs++]);
	}
	while (as < ae) res.push_back(vec1[as++]);
	while (bs < be) res.push_back(vec2[bs++]);
	return res;
}


#endif
