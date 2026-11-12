#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

class Solution {
  public:
    struct tile {
        int x, y;
        int hold;
    };

    struct cmp {
        bool operator()(tile &l, tile &r) { return l.hold > r.hold; }
    };

    priority_queue<tile, vector<tile>, cmp> q;
    vector<vector<int>> hold;
    int n, m;

    int trapRainWater(vector<vector<int>> &heightMap) {
        n = heightMap.size();
        m = heightMap[0].size();

        hold.assign(n, vector<int>(m, -1));

        for (int i = 1; i < m - 1; i++) {
            q.push(tile{0, i, heightMap[0][i]});
            hold[0][i] = heightMap[0][i];
            q.push(tile{n - 1, i, heightMap[n - 1][i]});
            hold[n - 1][i] = heightMap[n - 1][i];
        }
        for (int i = 0; i < n; i++) {
            q.push(tile{i, 0, heightMap[i][0]});
            hold[i][0] = heightMap[i][0];
            q.push(tile{i, m - 1, heightMap[i][m - 1]});
            hold[i][m - 1] = heightMap[i][m - 1];
        }

        const vector<pii> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            for (auto &dir : dirs) {
                int new_x = top.x + dir.first;
                int new_y = top.y + dir.second;
                if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m)
                    continue;
                if (hold[new_x][new_y] != -1)
                    continue;
                int new_h = max(top.hold, heightMap[new_x][new_y]);
                q.push(tile{new_x, new_y, new_h});
                hold[new_x][new_y] = new_h;
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                res += hold[i][k] - heightMap[i][k];
            }
        }

        return res;
    }
};
