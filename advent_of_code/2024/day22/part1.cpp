#include <iostream>

using namespace std;

const int ITER = 2000;
const int MOD = 16777216;

int main(){
    long long int res= 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        uint a;
        cin >> a;
        for (int i = 0; i < ITER; i++){
            uint tmp = a*64;
            a = tmp^a;
            a = a%MOD;
            tmp = a/32;
            a = tmp^a;
            a = a%MOD;
            tmp= a*2048;
            a = tmp^a;
            a = a%MOD;
        }
        res += a;
    }
    cout << res;
    return 0;
}
