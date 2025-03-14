#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long int ll;


ll mul(ll a){
    ll res = 1;
    while(a > 0){
        res *= a%10;
        a /= 10;
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        for(int k = 1; k <= n; k++){
            cerr << k << ": ";
            int a = k;
            do{
                a = mul(a);
                cout << a << " ";
            }while(a > 9);
            cout << endl;   
        }
    }
    return 0;
}
