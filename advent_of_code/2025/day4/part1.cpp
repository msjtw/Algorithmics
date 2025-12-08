#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int mmap[150][150]{};
char mmap2[150][150]{};

int main(int argc, char *argv[]) {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string line;
        cin >> line;
        for (int k = 1; k <= n; k++) {
            if (line[k - 1] == '@') {
                mmap[i][k] = 1;
                mmap2[i][k] = '@';
            }
        }
    }

    int res = 0;
    vector<pii> dirs = {{1, -1}, {1, 0},   {1, 1},  {0, -1},
                        {0, 1},  {-1, -1}, {-1, 0}, {-1, 1}};
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++) {
            if (mmap[i][k] == 0) {
                continue;
            }
            int total = 0;
            for (pii dir : dirs) {
                total += mmap[i + dir.first][k + dir.second];
            }
            if (total < 4) {
                mmap2[i][k] = 'x';
                res++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++) {
            cout << (mmap2[i][k] == 0 ? '.' : mmap2[i][k]);
        }
        cout << endl;
    }
    cout << res;

    return 0;
}
