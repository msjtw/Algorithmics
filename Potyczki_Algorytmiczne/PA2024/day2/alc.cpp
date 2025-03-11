#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

typedef pair<int, int> pii;

const int MX = 30007;

vector<int> adj[MX][2];

set<pii> edg;
set<pii> add;
set<pii> rem;
queue<pii> rem2;

bool vis[MX][2];

vector<string> res;

void dfs1(int p){
    if(vis[p][0])
        return;
    vis[p][0] = true;

    vector<pii> r;
    
    if(p != 1 and edg.find({1, p}) == edg.end()){
        res.push_back("+ "+to_string(1)+" "+to_string(p));
        auto it = add.find({1, p});
        if(it == add.end()){
            rem.insert({1, p});
        }
        else{
            add.erase({it});
        }
    }

    for(int u : adj[p][0]){
        if(!vis[u][0])
            dfs1(u);
    }

}

void dfs2(int p){
    if(vis[p][1])
        return;
    vis[p][1] = true;

    for(int u : adj[p][1]){
        if(!vis[u][1])
            dfs2(u);
    }

    if(rem.find({1, p}) != rem.end()){
        rem2.push({1,p});
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int m1, m2;
    cin >> n;
    cin >> m1;
    for(int i = 0 ; i < m1; i++){
        int a, b;
        cin >> a >> b;
        adj[a][0].push_back(b);
        adj[b][0].push_back(a);
        if(a > b)
            swap(a, b);
        edg.insert({a, b});
    }
    cin >> m2;
    rem = edg;
    for(int i = 0 ; i < m2; i++){
        int a, b;
        cin >> a >> b;
        if(a > b)
            swap(a, b);
        adj[a][1].push_back(b);
        adj[b][1].push_back(a);
        if(edg.find({a, b}) == edg.end()){
            add.insert({a, b});
        }
        else{
            rem.erase({a, b});
        }
    }

    dfs1(1);
    dfs2(1);

    for(auto e : add){
        if(e.first != 1)
            res.push_back("+ "+to_string(e.first)+" "+to_string(e.second));
    }

    for(auto e : rem){
        if(e.first == 1){
            continue;
        }
        res.push_back("- "+to_string(e.first)+" "+to_string(e.second));
    }


    while(!rem2.empty()){
        auto e = rem2.front();
        rem2.pop();
        res.push_back("- "+to_string(e.first)+" "+to_string(e.second));
    }

    cout << res.size() << "\n";
    for(string s : res)
        cout << s << "\n";

    return 0;
}