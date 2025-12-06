#include <iostream>
#include <vector>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pll;

vector<pll> ranges;

int fresh = 0;

int is_fresh(ll a){
    for (pll range : ranges) {
        if(a >= range.first and a <= range.second){
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int nr, ni;
    cin >> nr;
    for (int i = 0; i < nr; i++) {
        ll a, b;
        cin >> a >> b;
        ranges.push_back({a, b});
    }
    cin >> ni;
    for (int i = 0; i < ni; i++) {
        ll a;
        cin >> a;
        fresh += is_fresh(a);
    }

    cout << fresh;

    return 0;
}
