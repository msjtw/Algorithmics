#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

char mmap1[150][150]{};
char mmap2[150][150]{};

int main(int argc, char *argv[]) {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string line;
        cin >> line;
        strcpy(&mmap1[i][1], line.c_str());
    }

    int count = 0;
    int total = 0;
    do {
        count = 0;
        vector<pii> dirs = {{1, -1}, {1, 0},   {1, 1},  {0, -1},
                            {0, 1},  {-1, -1}, {-1, 0}, {-1, 1}};
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= n; k++) {
                if (mmap1[i][k] == '.') {
                    mmap2[i][k] = '.';
                    continue;
                }
                int neigh = 0;
                for (pii dir : dirs) {
                    neigh +=
                        (mmap1[i + dir.first][k + dir.second] == '@' ? 1 : 0);
                }
                if (neigh < 4) {
                    mmap2[i][k] = '.';
                    total++;
                    count++;
                } else {
                    mmap2[i][k] = '@';
                }
            }
        }
        cout << "removed " << count << endl;
        swap(mmap1, mmap2);
    } while (count > 0);

    cout << total;

    return 0;
}
