#include <iostream>
#include <set>

using namespace std;

set<pair<int,int>> edges;

int main(){
    
    int res = 0;

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(a == b){
            res++;
        }
        else{
            if(a > b)
                swap(a, b);
            if(edges.find({a, b}) != edges.end()){
                res++;
            }
            else{
                edges.insert({a, b});
            }
        }
    }
    cout << res;
}
