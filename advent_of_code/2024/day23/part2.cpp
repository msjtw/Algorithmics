#include <iostream>
#include <map>
#include <set>

using namespace std;

map<string, set<string>> adj;

map <pair<set<string>, set<string>>, set<string>> memo;

set<string> find_clique(set<string> clique, set<string> add){
    if(memo.find({clique, add}) != memo.end())
        return memo[{clique, add}];

    if(add.empty()){
        return clique;
    }
    set<string> ret;
    set<string> n_a = add;
    for(string a : add){
        n_a.erase(a);
        bool pop = false;
        for(string b : clique){
            if(adj[a].find(b) == adj[a].end()){
                pop = true;
            }
        }
        if(!pop){
            set<string> n_c = clique;
            n_c.insert(a);
            for(string x : adj[a]){
                if(clique.find(x) == clique.end())
                    add.insert(x);
            }
            auto tmp = find_clique(n_c, n_a);
            if(tmp.size() > ret.size()){
                ret = tmp;
            }
        }
    }

    memo[{clique, add}] = ret;
    return ret;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        string a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    set<string> res;
    int i = 0;
    for(auto key : adj){
        string a = key.first;
        auto tmp = find_clique({a}, adj[a]);
        if(tmp.size() > res.size()){
            res = tmp;
        }
        cout << (double)i / adj.size() * 100 << " %" << endl;
        i++;
    }

    for(string s : res){
        cout << s << ",";
    }

    return 0;
}
