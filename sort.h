#ifndef SORT_H
#define SORT_H

#include<vector>
#include<iostream>
#include"heap.h"

using namespace std;

template<class T>
class sort {
public:
	void insertionSort(vector<T>& vec) {
		for (size_t i = 1; i < vec.size(); i++) {
			T num = vec[i];
			int j = i - 1;
			while (j >= 0 && vec[j] > num) {
				vec[j + 1] = vec[j];
				j--;
			}
			vec[j + 1] = num;
		}
	}
	void mergeSort(vector<T>& vec) {
		vec = mergeSort(vec, 0, vec.size() - 1);
	}
	int partition(vector<T>& vec, int p, int r) {
		if (p >= r || r >= vec.size()) 
			return -1;
		int i = p - 1;
		T pivot = vec[r];
		for (size_t j = p; j <= r; j++) {
			if (vec[j] <= pivot) {
				i = i + 1;
				swap(vec[i], vec[j]);
			}
		}
		return i;
	}
	void quicksort(vector<T>& vec, int p, int r) {
		if (p < r) {
			int q = partition(vec, p, r);
			quicksort(vec, p, q - 1);
			quicksort(vec, q + 1, r);
		}
	}
	void heapsort(vector<T>& vec) {
		myHeap<T> h(vec, heap_type::MIN_HEAP);
		h.print();
		h.buildMaxHeap();
		cout << "building heap: ";
		h.print();
		h.remove(5);
		cout << "After insertion: ";
		h.print();		
		vec.clear();
		while (h.size()) {
			T max = h.extractMax();
			vec.push_back(max);
		}
	}
private:
	vector<T> mergeSort(const vector<T>& vec, int i, int j) {
		vector<T> res;
		if (i == j) {
			res.push_back(vec[i]);
			return res;
		}
		int mid = (i + j) / 2;
		vector<T> left = mergeSort(vec, i, mid);
		vector<T> right = mergeSort(vec, mid + 1, j);
		res = merge(left, right);
		return res;
	}
	vector<T> merge(const vector<T>& vec1, const vector<T>& vec2) {
		vector<T> res;
		int as = 0, ae = vec1.size(), bs = 0, be = vec2.size();
		while (as < ae && bs < be) {
			if (vec1[as] <= vec2[bs])
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
