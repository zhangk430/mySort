#ifndef SORT_H
#define SORT_H

#include<vector>
#include<iostream>

using namespace std;

template<class T>
class sort {
public:
	void insertionSort(vector<T>& vec) {
		for (int i = 1; i < vec.size(); i++) {
			T num = vec[i];
			int j = i - 1;
			while (j >= 0 && vec[j] > num) {
				vec[j + 1] = vec[j];
				j--;
			}
			vec[j + 1] = num;
		}
	}
};


#endif
