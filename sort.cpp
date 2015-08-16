#include"sort.h"

void sort::insertionSort(vector<T>& vec) {
	for (int i = 1; i < vec.size(); i++) {
		T num = vec[i];
		j = i - 1;
		while (j >= 0 && vec[j] > num) {
			vec[j + 1] = vec[j];
		}
		vec[j] = num;
	}
}
