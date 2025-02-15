#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, vector<string>> adj;
map<string, string> op;

void dfs(string a, string op_path, string gate_path){
    op_path +=  op[a] + " ";
    gate_path += a + " ";
    if(a[0] == 'z' or op[a] == "OR"){
        cout << op_path << " ";
        if(op_path != " XOR XOR " and op_path != " XOR AND OR " and op_path != " AND OR "){
            cout << "NO NIE ";
        }
        cout << endl;
        cout << gate_path << endl;
        return;
    }

    for(string b : adj[a]){
        dfs(b, op_path, gate_path);
    }

}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string a, b, type, c;
        cin >> a >> type >> b >> c;
        adj[a].push_back(c);
        adj[b].push_back(c);
        op[c] = type;
    }
    
    for(int i = 1; i < 44; i++){
        cout << "----" << i << endl;
        string x = to_string(i);
        if(i < 10){
            x = "x0" + x;
        }
        else{
            x = "x" + x;
        }
        string y = to_string(i);
        if(i < 10){
            y = "y0" + y;
        }
        else{
            y = "y" + y;
        }

        cout << x << endl;
        dfs(x, "", "");
        cout << endl;
        cout << y << endl;
        dfs(y, "", "");
        cout << endl;
    }

}
