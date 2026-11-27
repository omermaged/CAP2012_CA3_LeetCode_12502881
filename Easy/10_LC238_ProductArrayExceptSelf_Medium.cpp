#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        int left = 1;

        // Calculate product of left-side numbers.
        for (int i = 0; i < n; i++) {
            answer[i] = left;
            left *= nums[i];
        }

        int right = 1;

        // Multiply by product of right-side numbers.
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= right;
            right *= nums[i];
        }

        return answer;
    }
};
