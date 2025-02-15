#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> values;
map<string, string> type;

map<string, vector<string>> adj;
map<string, vector<string>> Tadj;

map<string, int> vis;
vector<string> order;

void topo(string a){
    if(vis [a] == 2){
        return;
    }
    vis[a] = 1;
    for(string b : adj[a]){
        topo(b);
    }
    vis[a] = 2;
    order.push_back(a);
}

int main(){
    int n;
    cin >> n;
    set<string> start;
    for(int i = 0; i < n; i++){
        string a;
        int val;
        cin >> a >> val;
        values[a] = val;
        start.insert(a);
    }
    int m;
    cin >> m;
    vector<string> out;
    for(int i = 0; i < m; i++){
        string a, op, b, c;
        cin >> a >> op >> b >> c;
        adj[a].push_back(c);
        adj[b].push_back(c);
        type[c] = op;
        Tadj[c].push_back(a);
        Tadj[c].push_back(b);
        if(c[0] == 'z'){
            out.push_back(c);
        }
    }

    for(string s : start){
        if(vis[s] == 0)
            topo(s);
    }
    reverse(order.begin(),order.end());
    for(string a : order){
        if(values.find(a) != values.end()){
            continue;
        }
        int v1 = values[Tadj[a][0]];
        int v2 = values[Tadj[a][1]];
        if(type[a] == "AND"){
            values[a] = v1 and v2;
        }
        if(type[a] == "XOR"){
            values[a] = v1 xor v2;
        }
        if(type[a] == "OR"){
            values[a] = v1 or v2;
        }
    }

    sort(out.begin(), out.end());

    unsigned long long int res= 0;
    for(int i = out.size()-1; i >= 0; i--){
        cout << values[out[i]];
        res <<= 1;
        res += values[out[i]];
    }

    cout << endl;
    cout << res;
}
