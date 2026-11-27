#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maximum = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {

            int current = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > current) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty()) {
                    width = i;
                }
                else {
                    width = i - st.top() - 1;
                }

                int area = height * width;

                maximum = max(maximum, area);
            }

            if (i < n) {
                st.push(i);
            }
        }

        return maximum;
    }
};
