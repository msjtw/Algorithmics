#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 8;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> memo;

int dp(int a, int visited) {
    if (memo[a][visited] != INF) {
        return memo[a][visited];
    }

    if (a == n) {
        return visited == (1 << n) - 1 ? 1 : 0;
    }

    ll ret = 0;
    for (int b : adj[a]) {
        if (!(visited & (1 << (b - 1)))) {
            // not yet visited
            ret += dp(b, visited | (1 << (b - 1)));
            ret %= MOD;
        }
    }
    memo[a][visited] = ret;
    return ret;
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    memo.resize(n + 1, vector<int>((1 << n), INF));

    int a, b;
    while (m-- > 0) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dp(1, 1);
    cout << memo[1][1];
    return 0;
}
