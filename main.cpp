#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<time.h>
#include"sort.h"

using namespace std;

template<class T>
void print(vector<T>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
}

void help(char *argv) {
	cout << "Usage: " << argv << " filename <command>\n";
	cout << "command: -i use insertion sort\n         -m use merge sort\n";
}

int main(int argc, char **argv) {
	if (argc != 3) {
		help(argv[0]);
		return 0;
	}
	string cmd(argv[2]);
	if (cmd != "-i" && cmd != "-m") {
		help(argv[0]);
		return 0;
	}
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
	std::cout << "Before sorting: ";
	print<double>(nums);
	sort<double> s;
	clock_t tStart = clock();
	if (cmd == "-i")
		s.insertionSort(nums);
	else if (cmd == "-m")
		s.mergeSort(nums);
	clock_t tEnd = clock();
	cout << "After sorting: ";
	print<double>(nums);
	cout << "Time taken " << (double)(tEnd - tStart)/CLOCKS_PER_SEC*1000 << " ms\n";
	return 1;
}
