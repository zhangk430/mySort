#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<time.h>
#include"intro2alg.h"

using namespace std;

template<class T>
void print(vector<T>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
}

void help(char *argv) {
	cout << "Usage: " << argv << " filename <command> <order>\n";
	cout << "command: -i use insertion sort\n         -m use merge sort\n       -q use quick sort\n       -h use heap sort\n";
	cout << "order: 0: ascending 1: descending default: ascending\n";
}

int main(int argc, char **argv) {
	if (argc != 3 && argc != 4) {
		help(argv[0]);
		return 0;
	}
	string cmd(argv[2]);
	if (cmd != "-i" && cmd != "-m" && cmd != "-q" && cmd != "-h") {
		help(argv[0]);
		return 0;
	}
	if (argc == 4 && *argv[3] != '0' && *argv[3] != '1') {
		help(argv[0]);
		return 0;
	}
	bool order = argc == 4 ? *argv[3] - '0' : 0;
	ifstream in(argv[1]);
	if (!in.is_open()) {
		cout << argv[1] << " not exist!\n";
		return 0;
	}
	vector<double> nums;
	while (in.good()) {
		double num;
		in >> num;
		if (in.eof()) break;
		nums.push_back(num);
	}
	in.close();
	cout << "Entire Array: ";
	print<double>(nums);
	mySort<double> s;
	mySort<double, greater<double>> s_greater; 
	clock_t tStart = clock();
	if (cmd == "-i") {
		if (!order)
			s.insertionSort(nums);
		else
			s_greater.insertionSort(nums);
	}
	else if (cmd == "-m") {
		if (!order)
			s.mergeSort(nums);
		else
			s_greater.mergeSort(nums);
	}
	else if (cmd == "-q") {
		if (!order)
			s.quicksort(nums, 0, nums.size() - 1);
		else		
			s_greater.quicksort(nums, 0, nums.size() - 1);
	}
	else if (cmd == "-h") {
		if (!order)
			s.heapsort(nums);
		else
			s_greater.heapsort(nums);
	}
/*	Intro2Alg i2a;
	int s, e;
	double max = i2a.maximalSubarray(nums, s, e);*/
	clock_t tEnd = clock();
	cout << "After sorting: ";
	print<double>(nums);
//	cout << "Maximal Subarray: " << max << " starting at " << s << " ending at " << e << endl;
	cout << "Time taken " << (double)(tEnd - tStart)/CLOCKS_PER_SEC*1000 << " ms\n";
	return 1;
}
