#include<iostream>
#include<fstream>
#include<vector>
#include"sort.h"

using namespace std;

template<class T>
void print(vector<T>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
}

int main(int argc, char **argv) {
	if (argc != 2)
		return 0;
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
	print<double>(nums);
	in.close();
	sort<double> s;
	s.mergeSort(nums);
	print<double>(nums);
	return 1;
}
