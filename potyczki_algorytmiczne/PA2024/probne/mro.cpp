#include<iostream>

using namespace std;

const int MX = 300007;

int res[MX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int k = 0 ; k < n; k++){
        for(int i = 0 ; i < n-1; i++){
            if(s[i] == 'P' and s[i+1] == 'L'){
                res[i]++;
                res[i+1]++;
                s[i] = 'L';
                s[i+1] = 'P';
                i++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << res[i] << " ";
    }

    return 0;
}