// Stanislaw Fiedler

#include <iostream>
#include <algorithm>

using namespace std;

struct op{
    int p;
    int q;
    int col;
};

bool com(op l, op r){
    return l.p < r.p;
}

op changes[1000100] {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cans, oper;
    cin >> cans >> oper;
    for(int i = 0; i < oper; i++){
        cin >> changes[i].p >> changes[i].q >> changes[i].col;
    }

    sort(changes,changes+oper,com);

    int am = 0;
    int l_yel = 0, l_blu = 0, l_red = 0;
    for(int i = 0; i < oper; i++){
        do{
            switch(changes[i].col){
                case 1:
                    l_yel = max(l_yel ,changes[i].q);
                    break;
                case 2:
                    l_blu = max(l_blu ,changes[i].q);
                    break;
                case 3:
                    l_red = max(l_red ,changes[i].q);
                    break;
            }
            i++;
        }while(i < oper && changes[i-1].p == changes[i].p);
        i--;

        //cout << changes[i].p << " " << bool(l_yel >= changes[i].p) << " " << bool(l_blu >= changes[i].p) << " " << bool(l_red < changes[i+1].p) << endl;
        if(i < oper-1 && l_yel >= changes[i].p && l_blu >= changes[i].p && l_red < changes[i+1].p && l_yel > l_red && l_blu > l_red){
            //cout << max(changes[i].p, l_red+1) << "  " << min(changes[i+1].p, min(l_blu+1, l_yel+1)) << "  " << min(changes[i+1].p, min(l_blu+1, l_yel+1)) - max(changes[i].p, l_red+1) << endl;
            am += min(changes[i+1].p, min(l_blu+1, l_yel+1)) - max(changes[i].p, l_red+1);
        }    
    }
    if(l_yel > l_red && l_blu > l_red){
        am += min(l_blu, l_yel) - max(l_red, changes[oper-1].p-1);
        //cout << min(l_blu, l_yel) - max(l_red, changes[oper-1].p-1) << endl;
    }

    cout << am << endl;
    return 0;
}