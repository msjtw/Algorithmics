#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long int ll;

vector<pair<ll,ll>> intrv;
vector<ll> poss;

int main(){
    ll n, m, s;
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        intrv.push_back({a,b});
    }
    sort(intrv.begin(),intrv.end());

    for(int i = 0; i < m; i++){
        ll a = intrv[i].first-1;
        ll b = intrv[i].second+1;
        if(i == 0){
            if(a != 0){
                poss.push_back(a);
            }
        }
        else{
            if(intrv[i-1].second != a){
                poss.push_back(a);
            }
        }
        if(i == m-1){
            if(b != n+1){
                poss.push_back(b);
            }
        }
        else{
            if(intrv[i+1].first != b){
                poss.push_back(b);
            }
        }
    }
    ll res = n;
    ll res_dist = n;
    for(ll house : poss){
        if(abs(house - s) < res_dist){
            res_dist = abs(house - s);
            res = house;
        }
    }

    cout << res;

    return 0;
}
