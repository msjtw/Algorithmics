#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, vector<string>> adj;

int dfs(string a, int len, const string &start, bool t){
    if(len == 3){
        if(a == start and t){
            return 1;
        }
        return false;
    }
    int ret = 0;
    for(string b : adj[a]){
        ret += dfs(b, len+1, start, t or (b[0] == 't'));
    }
    return ret;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        string a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int res = 0;
    for(auto key : adj){
        string a = key.first;
        res += dfs(key.first, 0, key.first, (key.first[0] == 't'));
    }

    cout << res/6;

    return 0;
}
