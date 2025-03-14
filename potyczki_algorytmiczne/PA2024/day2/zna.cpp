#include<iostream>
#include<map>

using namespace std;

const int MX = 300007;

map<int, int> types;

int res[MX];

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int a;
        cin >> a;
        types[a]++;
    }
    for(auto a : types){
        int num = a.second;
        int div = 1;
        while(num/div > 0){
            res[div] += (num/div)*div;
            div ++;
        }
    }

    for(int i = 1 ; i <= n; i++){
        cout << res[i] << " ";
    }
}