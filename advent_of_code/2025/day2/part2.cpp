#include <climits>
#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pii;

vector<pii> ranges;
vector<pii> ranges2;

ll res = 0;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        ranges.push_back({a, b});
    }

    for (pii range : ranges) {
        ll a, b;
        tie(a, b) = range;
        int la = log10(a) + 1;
        int lb = log10(b) + 1;
        if (lb > la){
            ranges2.push_back({a, pow(10,la)-1});
            ranges2.push_back({pow(10,la), b});
        }
        else{
            ranges2.push_back({a, b});
        }
    }

    for (pii range : ranges2) {
        unordered_set<ll> found;
        ll a, b;
        tie(a, b) = range;
        int len = (log10(a) + 1);

        for (int l = 1; l <= len/2; l++) {
            if (len % l != 0){
                // cout << endl;
                continue;
            }
            // cout << "rep " << l << ": ";
            int reps = len / l;
            ll top = pow(10, l);
            ll c = 0;

            while (true) {
                ll d = 0;
                for (int i = 0; i < reps; i++){
                    d *= top;
                    d += c;
                }
                c++;
                if (d < a) {
                    continue;
                }
                if (d > b)
                    break;
                if (found.find(d) != found.end()) {
                    // cout << endl;
                    continue;
                }
                // cout << d << " ";
                found.insert(d);
                if (res > LONG_LONG_MAX - d) {
                    cout << "overflow: " << res << endl;
                    res = 0;
                }
                res += d;
            }

            // cout << endl;
        }
    }
    cout << res;

    return 0;
}
