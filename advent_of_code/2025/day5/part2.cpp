#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> ranges;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        ranges.push_back({a, b});
    }

    sort(ranges.begin(), ranges.end());

    stack<ll> r_stack;
    for (auto r : ranges) {
        if (r_stack.empty()) {
            r_stack.push(r.first);
            r_stack.push(r.second);
            continue;
        }

        ll top = r_stack.top();
        if (r.first <= top) {
            r_stack.pop();
            r_stack.push(max(top, r.second));
        } else {
            r_stack.push(r.first);
            r_stack.push(r.second);
        }
    }

    ll total = 0;
    while (!r_stack.empty()) {
        ll top = r_stack.top();
        r_stack.pop();
        ll bot = r_stack.top();
        r_stack.pop();
        total += top - bot + 1;
    }

    cout << total;

    return 0;
}
