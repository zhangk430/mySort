#include<iostream>
#include<fstream>
#include<vector>
#include"sort.h"

using namespace std;

int main(int argc, char **argv) {
	if (argc != 2)
		return 0;
	ifstream in(argv[1]);
	if (!in.is_open()) {
		cout << argv[1] << " not exist!\n";
		return 0;
	}
	vector<double> nums;
	while (!in.eof()) {
		double num;
		in >> num;
		nums.push_back(num);
	}
	in.close();
	sort s;
	s.insertionSort(nums);
	return 1;
}
