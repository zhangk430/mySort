#ifndef SORT_H
#define SORT_H

#include<vector>
#include<iostream>
#include<functional>
#include<algorithm>
#include"heap.h"

using namespace std;

template<class T>
class mySort {
public:
	void insertionSort(vector<T>& vec, function<bool(const T&, const T&)> func = 0) {
		for (size_t i = 1; i < vec.size(); i++) {
			T num = vec[i];
			int j = i - 1;
			while (j >= 0 && (func ? func(num, vec[j]) : num < vec[j])) {
				vec[j + 1] = vec[j];
				j--;
			}
			vec[j + 1] = num;
		}
	}
	void mergeSort(vector<T>& vec, function<bool(const T&, const T&)> func = 0) {
		vec = mergeSort(vec, 0, vec.size() - 1, func);
	}
	int partition(vector<T>& vec, int p, int r, function<bool(const T&, const T&)> func = 0) {
		if (p >= r || r >= vec.size()) 
			return -1;
		int i = p;
		T pivot = vec[r];
		for (size_t j = p; j < r; j++) {
			if (func ? func(vec[j], pivot) : vec[j] < pivot) {
				swap(vec[i], vec[j]);
				i++;
			}
		}
		swap(vec[i], vec[r]);
		return i;
	}
	void quicksort(vector<T>& vec, int p, int r, function<bool(const T&, const T&)> func = 0) {
		if (p < r) {
			int q = partition(vec, p, r, func);
			quicksort(vec, p, q - 1, func);
			quicksort(vec, q + 1, r, func);
		}
	}
	void heapsort(vector<T>& vec, function<bool(const T&, const T&)> func = 0) {
		if (vec.size() <= 1)
			return ;
		myHeap<T> h(vec, heap_type::MIN_HEAP);
		h.buildMaxHeap();
		vec.clear();
		while (h.size()) {
			T max = h.extractMax();
			vec.push_back(max);
		}
		if (func && !func(vec[0], vec[1]))
			reverse(vec.begin(), vec.end());
	}
private:
	vector<T> mergeSort(const vector<T>& vec, int i, int j, function<bool(const T&, const T&)> func = 0) {
		vector<T> res;
		if (i == j) {
			res.push_back(vec[i]);
			return res;
		}
		int mid = (i + j) / 2;
		const vector<T>& left = mergeSort(vec, i, mid, func);
		const vector<T>& right = mergeSort(vec, mid + 1, j, func);
		res = merge(left, right, func);
		return res;
	}
	vector<T> merge(const vector<T>& vec1, const vector<T>& vec2, function<bool(const T&, const T&)> func = 0) {
		vector<T> res;
		int as = 0, ae = vec1.size(), bs = 0, be = vec2.size();
		while (as < ae && bs < be) {
			if (func ? func(vec1[as], vec2[bs]) : vec1[as] <= vec2[bs])
				res.push_back(vec1[as++]);
			else 
				res.push_back(vec2[bs++]);
		}
		while (as < ae) res.push_back(vec1[as++]);
		while (bs < be) res.push_back(vec2[bs++]);
		return res;
	}
};


#endif
