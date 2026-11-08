#include <vector>

using namespace std;

const int INF = 1e9 + 8;

class Solution {
  public:
    vector<int> hold;
    vector<int> height;
    int n;

    int dp(int pos) {
        if (hold[pos] > -1) {
            return hold[pos];
        }

        int res = INF;
        if (pos == n - 1) {
            return height[pos];
        } else {
            if (pos > 0) {
                res = min(res, dp(pos - 1));
            }
            if (pos < n - 1) {
                res = min(res, dp(pos + 1));
            }
        }

        res = max(res, height[pos]);
        hold[pos] = res;
        return res;
    }

    int trap(vector<int> &_height) {
        height = _height;
        n = height.size();

        hold.assign(n, -1);

        dp(0);

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += max(0, hold[i] - height[i]);
        }

        return res;
    }
};
