#include<iostream>
#include<vector>
#include<algorithm>
#include<array>

using namespace std;

typedef long long int ll;

const int MX = 7007;
const ll oo = 1e18+7;

struct zelek{
    ll kolor;
    ll masa;
    ll cena;
};

bool cmp(zelek l, zelek r){
    return l.kolor < r.kolor;
}

array<ll, MX> dp[MX];

vector<zelek> arr;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, kolory, m;
    cin >> n >> kolory >> m;
    for(int i = 0 ; i < n; i++){
        zelek a;
        cin >> a.kolor >> a.masa >> a.cena;
        arr.push_back(a);
    }

    for(int i = 0 ; i < MX; i++){
        for(int k = 0 ; k < MX; k++){
            dp[i][k] = oo;
        }
    }

    dp[0][0] = 0;

    sort(arr.begin(), arr.end(), cmp);

    for(int i = 0; i < n; i++){
        for(int k = 0; k < m; k++){
            int idx = (k - arr[i].masa)%m;
            if(idx < 0)
                idx += m;
            int kol = arr[i].kolor;
            dp[kol][k] = min(dp[kol][k], dp[kol-1][idx]+arr[i].cena);
        }
    }

    ll tab[MX][2];

    for(int i = 0 ; i < m; i++){
        tab[i][0] = dp[kolory][i];
        tab[i][1] = tab[i][0];
    }
    tab[0][0] = 0;
    tab[0][1] = -1;

    for(int i = 1; i < m; i++){
        for(ll k = i; k < m; k++){
            ll idx = (i+k)%m;
            ll sum = tab[i][0] + tab[k][0];
            tab[idx][1] = min(tab[idx][1], sum);
        }
    }

    for(int z = 0; z < m; z++){
        ll mini = oo;
        int pos;
        for(ll i = 0; i < m; i++){
            if(tab[i][1] != -1 and tab[i][1] <= mini){
                mini = tab[i][1];
                pos = i;
            }
        }
        if(mini == oo)
            break;
        tab[pos][0] = tab[pos][1];
        tab[pos][1] = -1;
        for(int i = 0; i < m; i++){
            int idx = (pos+i)%m;
            ll sum = tab[pos][0] + tab[i][0];
            tab[idx][1] = min(tab[idx][1], sum);
        }
    }

    for(int i = 0 ; i < m; i++){
        cout << (tab[i][0] == oo ? -1 : tab[i][0]) << '\n';
    }

    return 0;
}