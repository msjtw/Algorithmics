#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef pair<bool, bool> pbb;

map<string, vector<string>> adj;

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        stringstream l(line);
        string start;
        l >> start;
        start.pop_back();
        string eend;
        while (l >> eend) {
            cout << start << " " << eend << endl;
            adj[start].push_back(eend);
        }
    }

    int res = 0;

    queue<pair<map<string, bool>,string>> q;
    q.push({{{"svr", true}},"svr"});
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        // for (string a : s) {
        //     cout << a << " ";
        // }
        // cout << endl;
        string eend = s[s.size() - 1];
        if (eend == "out") {
            bool fft = (find(s.begin(), s.end(), "fft") != s.end() ? 1 : 0);
            bool dac = (find(s.begin(), s.end(), "dac") != s.end() ? 1 : 0);
            if (fft and dac) {
                res++;
            }
            continue;
        }
        for (auto u : adj[eend]) {
            if(find(s.begin(), s.end(), u) != s.end()){
                cerr << "skip";
                continue;
            }
            auto ns = s;
            ns.push_back(u);
            q.push(ns);
        }
    }

    cout << res;

    return 0;
}
