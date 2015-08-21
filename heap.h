#ifndef HEAP_H
#define HEAP_H

#include<iostream>
#include<vector>

using namespace std;

enum heap_type {
	MIN_HEAP,
	MAX_HEAP
};	

template<class T>
class myHeap {
	heap_type type;
	vector<T> vec;
public:
	myHeap(){ type = heap_type::MAX_HEAP; }
	myHeap(const vector<T>& input, heap_type ht = heap_type::MAX_HEAP) {
		for (T n : input)
			vec.push_back(n);
		type = ht;
	}
	myHeap(heap_type ht){  type = ht; }
	int parent(size_t i){  return ((i + 1) >> 1) - 1; }
	int left(size_t i){
		size_t left_idx = (i << 1) + 1;  
		return left_idx < vec.size() ? left_idx : -1;  
	}
	int right(size_t i){  
		size_t right_idx = (i + 1) << 1;
		return right_idx < vec.size() ? right_idx : -1;
	} 
	T root() {  return vec[0];  }
	size_t size() {  return vec.size();   }
	void clear(){  vec.clear();  }
	void maxHeapify(int i) {
		if (i >= vec.size() / 2)
			return;
		int l = left(i);
		int r = right(i);
		int largest = i;
		switch(type) {
			case MAX_HEAP:
				if (l >= 0 && vec[l] > vec[i])
					largest = l;
				if (r >= 0 && vec[r] > vec[largest])
					largest = r;
				if (largest != i) {
					swap(vec[i], vec[largest]);
					maxHeapify(largest);
				}
				break;
			case MIN_HEAP:
				if (l >= 0 && vec[l] < vec[i])
					largest = l;
				if (r >= 0 && vec[r] < vec[largest])
					largest = r;
				if (largest != i) {
					swap(vec[i], vec[largest]);
					maxHeapify(largest);
				}
				break;
			default:
				break;			
		}
	}
	void floatUp(int i) {
		if (i <= 0 || i >= vec.size())
			return;
		int p = parent(i);
		switch(type) {
			case MAX_HEAP:
				if (vec[i] > vec[p]) {
					swap(vec[i], vec[p]);
					floatUp(p);
				}
				break;
			case MIN_HEAP:
				if (vec[i] < vec[p]) {
					swap(vec[i], vec[p]);
					floatUp(p);
				}
				break;
			default:
				break;
		}
	}
	void buildMaxHeap() {
		for (int i = vec.size() / 2 - 1; i >= 0; i--) {
			maxHeapify(i);
		} 
	}
	void insert(const T& val) {
		vec.push_back(val);
		floatUp(vec.size() - 1);
	}
	void remove(int i) {
		if (i < vec.size()) {
			vec[i] = vec[vec.size() - 1];
			vec.pop_back();
			maxHeapify(i);
		}
	}
	T extractMax() {
		T max = vec[0];
		vec[0] = vec[vec.size() - 1];
		vec.pop_back();
		maxHeapify(0);
		return max;
	}
	void modify(int i, const T& val) {
		if (i < vec.size()) {
			vec[i] = val;
			floatUp(i);
			maxHeapify(i);
		}
	}
	void print() {
		for (T n : vec)
			cout << n << " ";
		cout << "\n";
	}
};


#endif
