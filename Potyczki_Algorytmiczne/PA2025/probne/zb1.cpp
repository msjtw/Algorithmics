#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> divs;

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    divs.resize(n+m+1);
    for(int i = 1; i <= n; i++){
        divs[i].push_back(i);
    }

    for(int i = n+1; i <= n+m; i++){
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 1){
            //suma
            for(int x : divs[a])
                divs[i].push_back(x);
            for(int x : divs[b])
                divs[i].push_back(x);
        }
        else if(op == 2){
            //przecięcie

        }
        else {
            //negacja

        }
    }
    return 0;
}
