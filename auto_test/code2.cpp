#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

vector<pll> arr;

const int MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;
    arr.push_back({x, y});
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        char c;
        int len;
        cin >> c >> len;
        if(c == 'N'){
            y += len;
        }
        if(c == 'E'){
            x += len;
        }
        if(c == 'S'){
            y -= len;
        }
        if(c == 'W'){
            x -= len;
        }
        arr.push_back({x, y});
    }

    long long int res = 0;

    for(int i = 0; i < (int)arr.size()-1; i++){
        ll add1 = arr[i].first*arr[i+1].second ;
        ll add2 = arr[i+1].first*arr[i].second ;

        ll add = (add1-add2);

        res = (res + add)%MOD;
    }

    cout << abs(res) << endl;

    return 0;
}