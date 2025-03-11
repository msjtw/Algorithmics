#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;
typedef long long int LL;

const int MX = 100;
const ll mod = 1e9+7;

void dfs(bool [], int);
int count(const vector<int> &);

pii lvl[MX];
vector<int> adj[MX];

int count(const vector<int> &arr){
    int ret = 0;
    bool vis[MX] {};
    for(int p : arr){
        if(!vis[p]){
            ret++;
            dfs(vis, p);
        }
    }
    return ret;
}

void dfs(bool vis[], int x){
    if(vis[x])
        return;
    vis[x] = true;
    for(int y : adj[x])
        dfs(vis, y);
}

ll fast(ll a, ll p){
    ll res = 1;
    while(p > 0){
        if(p % 2 == 1)
            res = (a * res)%mod;
        a = (a*a)%mod;
        p /= 2;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> lvl[i].first >> lvl[i].second;
    }

    vector<int> kol;
    for(int i = 1; i <=n ;i++){
        kol.push_back(i);
    }

    vector<pii> drops;
    drops.push_back({lvl[n].first, n});
    drops.push_back({lvl[n].second, n});
    for(int i = n-1; i > 0; i--){
        for(int k = 0; k < drops.size(); k++){
            pii d = drops[k];
            if(d.first > lvl[i].first and d.first < lvl[i].second){
                adj[d.second].push_back(i);
                drops.erase(drops.begin()+k);
                k--;
            }
        }
        drops.push_back({lvl[i].first, i});
        drops.push_back({lvl[i].second, i});
    }

    ll res = 0;

    do{
        res += count(kol);
        res %= mod;
    }while(next_permutation(kol.begin(), kol.end()));

    ll fact = 1;
    for(int i = 2; i <= n; i++)
        fact *= i;

    ll pow = fast(fact, mod-2);
    pow *= res;


    cout << pow%mod;

    return 0;
}