#include"intro2alg.h"

double Intro2Alg::maximalSubarray(const vector<double>& nums, int& s, int& e) {
	if (nums.size() == 0)
		return 0;
	double max = nums[0], max_i = nums[0];
	int max_s = 0, max_e = 1;
	s = 0;  e = 1;	
	for (int i = 1; i < nums.size(); i++) {
		double sum = max_i + nums[i];
		if (sum > nums[i]) {
			max_i = sum;
			max_e++;
		}
		else {
			max_i = nums[i];
			max_s = i; 
			max_e = i + 1;
		}
		if (max < max_i) {
			max = max_i;
			s = max_s;
			e = max_e;
		}
	}
	return max;
}
