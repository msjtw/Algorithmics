#include <iostream>

using namespace std;

int t1p[256];
int t1n[256];

int t2p[256];
int t2n[256];


int main(){
    int p;
    cin >> p;
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++){
        if(i%2 == 0){
            t1p[a[i]]++;
        }
        else{
            t1n[a[i]]++;
        }
    }
    for(int i = 0; i < b.size(); i++){
        if(i%2 == 0){
            t2p[b[i]]++;
        }
        else{
            t2n[b[i]]++;
        }
    }

    for(int i = 0; i < 256; i++){
        if(t1n[i] != t2n[i] || t1p[i] != t2p[i]){
            cout << "NIE";
            return 0;
        }
    }

    cout << "TAK";
    return 0;
}