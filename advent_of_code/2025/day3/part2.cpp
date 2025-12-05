#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

const int MX = 20;
typedef long long ll;

ll memo[107][MX];
string s;

ll total = 0;

ll dp(int p, int left) {
    if (memo[p][left] != -1) {
        return memo[p][left];
    }

    ll res;
    if (100 - p == left) {
        res = stoll(s.substr(p, left));
    }  else {
        ll a;
        if (left == 1) {
            a = s[p]-'0';
        } else {
            a = dp(p + 1, left - 1) + (s[p] - '0') * pow(10, left-1);
        }
        ll b = dp(p + 1, left);
        res = max(a, b);
    }

    memo[p][left] = res;
    return res;
}

int main(int argc, char *argv[]) {
    int p;
    cin >> p;
    while (p --> 0) {
        cin >> s;
        for (int i = 0; i < 107; i++) {
            for (int k = 0; k < MX; k++) {
                memo[i][k] = -1LL;
            }
        }
        ll maxi = dp(0, 12);
        total += maxi;
        cout << s << " " << maxi << endl;
    }
    cout << total;
    return 0;
}
