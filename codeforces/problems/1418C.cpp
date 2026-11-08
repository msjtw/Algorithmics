#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9 + 7;

vector<int> bosses;
vector<vector<vector<int>>> memo;

int n;

// turn: me - 0; friend - 1;
int dp(int boss, int turn, int power) {
    // cout << string(2 * boss, ' ') << boss << " " << turn << " " << power
    // << endl;

    if (memo[boss][turn][power - 1] != INF) {
        // cout << string(2 * boss, ' ') << memo[boss][turn][power - 1] << endl;
        return memo[boss][turn][power - 1];
    }

    int ret = INF;
    int need_skip = bosses[boss] && turn;
    int other = turn != true;

    if (boss == n - 1) {
        ret = 0;
    } else if (power == 2) {
        int v0 = dp(boss + 1, turn, power - 1); // same turn
        int v1 = dp(boss + 1, other, 2);        // other turn
        ret = min(v0, v1);

    } else if (power == 1) {
        // no more power other turn
        ret = dp(boss + 1, other, 2); // other turn
    } else {
        exit(1);
    }

    ret += need_skip;

    memo[boss][turn][power - 1] = ret;
    // cout << string(2 * boss, ' ') << memo[boss][turn][power - 1] << endl;
    return ret;
}

int main() {
    int p;
    cin >> p;
    while (p-- > 0) {
        cin >> n;
        bosses.clear();
        memo.assign(n, vector<vector<int>>(2, vector<int>(2, INF)));

        int a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            bosses.push_back(a);
        }
        dp(0, 1, 2);
        // cerr << "a" << endl;
        cout << memo[0][1][1] << endl;
    }
}
