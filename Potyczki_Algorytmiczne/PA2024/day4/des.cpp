#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>

using namespace std;

typedef pair<uint, uint> pii;
typedef unsigned long long int ull;

vector<pii> roz;

ull n, m;

ull res(ull num, ull r){
    if(r == m)
        return 1;
    ull ret = 0;
    ull a, b;
    tie(a, b) = roz[r];
    ull a1 = num&(1ULL<<a);
    ull b1 = num&(1ULL<<b);
    if(a1  > 0 and b1 == 0){
        return 0;
    }
    if(a1 == 0 and b1 > 0){
        ull cnum = num;
        cnum |= 1ULL<<a;
        cnum &= ~(1ULL<<b);
        ret += res(cnum, r+1);
    }
    ret += res(num, r+1);
    return ret%2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(ull i = 0 ; i  < m ; i ++){
        ull a, b;
        cin >> a >> b;
        a = n - a;
        b = n - b;
        roz.push_back({a, b});
    }

    reverse(roz.begin(), roz.end());

    for(ull i = 1; i <= n; i++){
        ull start = 0;
        start = (1LL<<(i))-1;
        ull r = 0;
        for(ull k = 0; k <= (n-i); k++){
            r += res(start, 0);
            start <<= 1;
        }
        cout << r%2 << " ";
    }
    cout << endl;

    return 0;
}