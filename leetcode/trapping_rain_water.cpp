#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    vector<int> left;
    vector<int> right;

    int n;

    

    int trap(vector<int> &height) {
        n = height.size();

        left.assign(n, 0);
        right.assign(n, 0);

        left[0] = height[0];
        for(int i = 1; i < n; i++){
            left[i] = max(left[i-1], height[i]);
        }
        right[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            right[i] = max(right[i+1], height[i]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += min(left[i],right[i]) - height[i];
        }

        return res;
    }
};
