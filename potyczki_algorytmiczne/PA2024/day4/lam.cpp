#include <iostream>
#include <map>
#include <stack>

using namespace std;

const int MX = 2007;

map<char, int> row[MX];
map<char, int> col[MX];

char arr[MX][MX];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        for(int k = 0 ; k < m; k++){
            cin >> arr[i][k];
            row[i][arr[i][k]]++;
            col[k][arr[i][k]]++;
        }
    }

    stack<string> res;
    int old;
    do{
        old = res.size();
        for(int i = 0 ; i < n; i ++){
            if(row[i].size() == 1){
                string s = "R " + to_string(i+1) + " " + row[i].begin()->first;
                res.push(s);
                for(int k = 0 ; k < m; k++){
                    if(arr[i][k] == 0)
                        continue;
                    col[k][arr[i][k]]--;
                    row[i][arr[i][k]]--;
                    if(row[i][arr[i][k]] == 0)
                        row[i].erase(arr[i][k]);
                    if(col[k][arr[i][k]] == 0)
                        col[k].erase(arr[i][k]);
                    arr[i][k] = 0;
                }
            }
        }
        for(int k = 0 ; k < m; k ++){
            if(col[k].size() == 1){
                string s = "K " + to_string(k+1) + " " + col[k].begin()->first;
                res.push(s);
                for(int i = 0 ; i < n; i++){
                    if(arr[i][k] == 0)
                        continue;
                    row[i][arr[i][k]]--;
                    col[k][arr[i][k]]--;
                    if(col[k][arr[i][k]] == 0)
                        col[k].erase(arr[i][k]);
                    if(row[i][arr[i][k]] == 0)
                        row[i].erase(arr[i][k]);
                    arr[i][k] = 0;
                }
            }
        }
    }while(old != res.size());

    cout << res.size() << "\n";
    while(!res.empty()){
        cout << res.top() << "\n";
        res.pop();
    }

}