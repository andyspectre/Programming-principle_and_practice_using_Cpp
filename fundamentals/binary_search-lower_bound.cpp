#include<iostream>
#include<vector>

using std::cout;
using std::vector;

// Find the first value that is greater than or equal to "target"
int binary_search(vector<int> v, int target) {
        int n = v.size();
        int left = 0;
        int right = n - 1;
        int ans = -1;
        while (left <= right) {
                int mid = left + (right - left) / 2;
                if (v[mid] >= target) {
                        ans = v[mid];
                        right = mid - 1;
                }
                else {left = mid + 1;}

        }
        return ans;
}

int main()
{
        vector<int> v = {1, 2, 5, 6, 9, 10, 15};
        int target = 4;
        int result = binary_search(v, target);
        cout << result << '\n';
}
