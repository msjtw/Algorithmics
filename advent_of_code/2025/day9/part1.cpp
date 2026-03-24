#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> points;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        points.push_back({a, b});
    }

    ll maxi = 0;
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            ll dx = abs(points[i].first - points[k].first) + 1;
            ll dy = abs(points[i].second - points[k].second) + 1;
            maxi = max(maxi, dx * dy);
        }
    }

    cout << maxi;

    return 0;
}
