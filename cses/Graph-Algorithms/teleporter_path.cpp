#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

vector<set<int>> adj;
vector<int> in;
vector<int> out;

vector<bool> vis;

int dfs(int a) {
    vis[a] = true;

    int total = 0;
    for (int b : adj[a]) {
        if (!vis[b]) {
            total += dfs(b);
        }
    }
    return total + adj[a].size();
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n + 1, {});
    vis.assign(n + 1, false);
    in.assign(n + 1, 0);
    out.assign(n + 1, 0);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].insert(b);
        in[b]++;
        out[a]++;
    }
    // check if every teleport is avaliable
    if (dfs(1) != m) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    if (out[1] - in[1] != 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    if (in[n] - out[n] != 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (in[i] - out[i] != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    vector<int> ans;

    stack<int> s;
    s.push(1);
    while (!s.empty()) {
        int a = s.top();
        if (adj[a].empty()) {
            ans.push_back(a);
            s.pop();
        } else {
            int b = *adj[a].begin();
            adj[a].erase(adj[a].begin());
            s.push(b);
        }
    }

    reverse(ans.begin(), ans.end());

    for (int a : ans) {
        cout << a << " ";
    }

    return 0;
}
