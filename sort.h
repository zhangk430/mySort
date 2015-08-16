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
	void mergeSort(vector<T>& vec) {
		vec = mergeSort(vec, 0, vec.size() - 1);
	}

private:
	vector<T> mergeSort(vector<T>& vec, int i, int j) {
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
	vector<T> merge(vector<T>& vec1, vector<T>& vec2) {
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
