#include <iostream>

using namespace std;

const int MX = 5000*5000*2 + 7;

int poss[MX];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        for(int k = i; k < n; k++){
            poss[(i*i + k*k)]++;
        }
        /* cerr<< i; */
    }
    /* cout << "gen end" << endl; */
    int res = 0;
    for(int d = 1; d <= n; d++){
        for(int h = 1; h <= n; h++){
            if(d*d - h*h < 0){
                continue;
            }
            res += poss[d*d - h*h];
            if(poss[d*d - h*h]){
                /* cout <<  d*d - h*h << " + " << h*h << " = " << d*d << endl; */
            }
        }
     }
    cout << res;
    return 0;
}
