#include"sort.h"

void sort::insertionSort(vector<double>& vec) {
	for (int i = 1; i < vec.size(); i++) {
		double num = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > num) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = num;
	}
}
