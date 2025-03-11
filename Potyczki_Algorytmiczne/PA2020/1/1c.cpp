#include <iostream>
#include <string>

using namespace std;

int tab[3][5] {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int p;
    cin >> p;
    string a;
    while(p--){
        cin >> a;
        tab[a[1]-'A'][a[0]-'1']++;
    }

    bool tak = true;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if(tab[i][j] < 1){
                tak = false;
                cout << ".";
            }   
            cout << tab[i][j] << " ";
        }
        if(tab[i][4] < 2){
            tak = false;
            cout << ".";
        }
        cout << tab[i][4] << " " << endl;
    }
    if(tak)
        cout << "TAK";
    else
        cout << "NIE";
    return 0;
}