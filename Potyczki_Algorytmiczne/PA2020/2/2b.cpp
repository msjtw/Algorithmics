//Stanislaw Fielder

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct miasto{
    int moc;
    int odl;
};

int odl = 0, ilosc = 0, m;
miasto miasta[500010] {};

int dp(int i, long long int moc){
    if(i == ilosc-1){
        if(moc >= 0){
            return 0;
        }
        else{
            return 1000000010;
        }
    }
    else{
        if(moc >= 0){
            return min(dp(i+1, moc+miasta[i+1].moc)+miasta[i+1].odl, dp(i+1, miasta[i+1].moc));
        }
        else{
            return dp(i+1, moc+miasta[i+1].moc)+miasta[i+1].odl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int p;
    cin >> p;
    long long int balans = 0;
    for(int i = 0; i < p; i++){
        int a;
        cin >> a;
        if(a != 0){
            m = max(m, a);
            balans += a;
            miasta[ilosc].moc = a;
            miasta[ilosc].odl = odl;
            odl = 0;
            ilosc++;
        }
        odl++;
    }
    if(balans >= 0)
        if(ilosc > 0)
            cout << dp(0, miasta[0].moc) << endl;
        else
            cout << 0;
    else
        cout << -1;

    return 0;
}