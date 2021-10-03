#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::vector;

int binary_search(vector<int>v, int target) {
	int n = v.size();
	int left = 0;
	int right = n-1;
        while(left <= right) {
	        int mid = left + (right - left) / 2;
		if(v[mid] == target) {
			return mid;
		}
		else if(v[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

int main()
{
	vector<int> v;
	for (int i = 0; i < 100; i+=2) {
		v.push_back(i);
	}
	int result = binary_search(v,18);
	cout << result << '\n';
}

