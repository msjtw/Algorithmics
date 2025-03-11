#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long int ll;

const int MX = 507;

int pxs[MX];
vector<ll> arr;
map<ll, vector<int>> num;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        pxs[i] = pxs[i-1]+a;
    }

    for(int i = 1; i <= n; i++){
        for(int k = i; k <= n; k++){
            num[pxs[k] - pxs[i-1]].push_back(arr.size());
            arr.push_back(pxs[k] - pxs[i-1]);
        }
    }

    for(auto a : num){
        sort(a.second.begin(), a.second.end());
    }

    ll res = 0;
    for(int i = 0 ; i < arr.size(); i++){
        for(int k = i+1; k < arr.size(); k++){
            ll a = arr[i];
            ll b = arr[k];
            ll c = 0-a-b;
            if(num.count(c) > 0){
                auto it = upper_bound(num[c].begin(), num[c].end(), k);
                res += num[c].end() - it;
            }
        }
    }

    cout << res;

    return 0;
}