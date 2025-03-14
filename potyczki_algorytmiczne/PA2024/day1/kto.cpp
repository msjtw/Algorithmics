#include<iostream>

using namespace std;

int scoreA = 0;
int scoreB = 0;
int resA[12];
int resB[12];

int main(){
    ios_base::sync_with_stdio(false);
    
    for(int i = 0 ; i < 18; i++){
        int a;
        cin >> a;
        scoreA += a;
        resA[a]++;
    }
    for(int i = 0 ; i < 18; i++){
        int a;
        cin >> a;
        scoreB += a;
        resB[a]++;
    }

    if(scoreA == scoreB){
        for(int i = 10; i >= 0; i--){
            if(resA[i] > resB[i]){
                cout << "Algosia";
                return 0;
            }
            if(resA[i] < resB[i]){
                cout << "Bajtek";
                return 0;
            }
        }
    }
    else{
        if(scoreA > scoreB)
            cout << "Algosia";
        else
            cout << "Bajtek";
        return 0;
    }

    cout << "remis";
    return 0;
}
