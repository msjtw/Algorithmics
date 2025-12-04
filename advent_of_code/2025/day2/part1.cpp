#include <climits>
#include <iostream>
#include <cmath>
#include <vector>

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
        if (la % 2 != 0) {
            a = pow(10, la);
        }
        if (lb % 2 != 0) {
            b = pow(10, lb - 1) - 1;
        }
        la = log10(a) + 1;
        lb = log10(b) + 1;
        if (b < a) {
            continue;
        }
        cout << la << " " <<  a << " " << lb << " " << b << endl;
        if (la != lb) {
            
        } else {
            ranges2.push_back({a, b});
        }
    }

    for (pii range : ranges2) {
        ll a, b;
        tie(a, b) = range;
        int l = (log10(a) + 1)/2;
        ll top = pow(10, l);
        ll c1 = a % top;
        ll c2 = b % top;
        ll c = min(c1, c2);
        c=0;

        cout << a << " " << b << ": ";
        while (true) {
            ll d = c*top + c;
            c++;
            if (d < a) {
                continue;
            }
            if(d > b)
                break;
            cout << d << " ";
            if (res > LONG_LONG_MAX - d){
                cout << "->" << res << endl;;
                res = 0;
            }
            res += d;
        }

        cout << endl;
    }
    cout << res;

    return 0;
}
