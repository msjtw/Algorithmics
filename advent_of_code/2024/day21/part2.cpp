#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef pair<char, char> pcc;
typedef pair<int, int> pii;
typedef long long int ll;

const int LVL_MAX = 24;

char kp1_data[4][3] = {{'7','8','9'},{'4','5','6'},{'1','2','3'},{'x','0','A'}};
char kp2_data[2][3] = {{'x','^','A'},{'<','v','>'}};

map<pcc, vector<string>> r1;
map<pcc, vector<string>> r2;

ll memo[250][250][50] {};

pii ctop1(char c){
    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 3; k++){
            if(kp1_data[i][k] == c)
                return {i,k};
        }
    }
    return {-1,-1};
}

pii ctop2(char c){
    for(int i = 0; i < 2; i++){
        for(int k = 0; k < 3; k++){
            if(kp2_data[i][k] == c)
                return {i,k};
        }
    }
    return {-1,-1};
}

char ptoc1(pii a){
    return kp1_data[a.first][a.second];
}

char ptoc2(pii a){
    return kp2_data[a.first][a.second];
}

void generate(){
    vector<pii> val_pos = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2},{3,1},{3,2}};
    vector<pii> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    for(auto start : val_pos){
        queue<pair<pii, string>> q;
        q.push({start,"A"});
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            pii pos = a.first;
            string hist = a.second;
            if( r1[{ptoc1(start), ptoc1(pos)}].empty() or 
                (r1[{ptoc1(start), ptoc1(pos)}].size() > 0 and 
                r1[{ptoc1(start), ptoc1(pos)}][0].size() == hist.size()+1))
            {
                r1[{ptoc1(start), ptoc1(pos)}].push_back(hist+"A");
            }
            for(auto dir : dirs){
                pii new_pos = {pos.first + dir.first, pos.second + dir.second};
                if(find(val_pos.begin(), val_pos.end(), new_pos) == val_pos.end()){
                    continue;
                }
                if(r1.find({ptoc1(start),ptoc1(new_pos)}) != r1.end()){
                    continue;
                }
                if(dir == make_pair(-1,0)){
                    q.push({new_pos, hist+"^"});
                }
                if(dir == make_pair(1,0)){
                    q.push({new_pos, hist+"v"});
                }
                if(dir == make_pair(0,-1)){
                    q.push({new_pos, hist+"<"});
                }
                if(dir == make_pair(0,1)){
                    q.push({new_pos, hist+">"});
                }
            }
        }
    }
    val_pos = {{0,1},{0,2},{1,0},{1,1},{1,2}};
    for(auto start : val_pos){
        queue<pair<pii, string>> q;
        q.push({start,"A"});
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            pii pos = a.first;
            string hist = a.second;
            if( r2[{ptoc2(start), ptoc2(pos)}].empty() or 
                (r2[{ptoc2(start), ptoc2(pos)}].size() > 0 and 
                r2[{ptoc2(start), ptoc2(pos)}][0].size() == hist.size()+1))
            {
                r2[{ptoc2(start), ptoc2(pos)}].push_back(hist+"A");
            }
            for(auto dir : dirs){
                pii new_pos = {pos.first + dir.first, pos.second + dir.second};
                if(find(val_pos.begin(), val_pos.end(), new_pos) == val_pos.end()){
                    continue;
                }
                if(r2.find({ptoc2(start),ptoc2(new_pos)}) != r2.end()){
                    continue;
                }
                if(dir == make_pair(-1,0)){
                    q.push({new_pos, hist+"^"});
                }
                if(dir == make_pair(1,0)){
                    q.push({new_pos, hist+"v"});
                }
                if(dir == make_pair(0,-1)){
                    q.push({new_pos, hist+"<"});
                }
                if(dir == make_pair(0,1)){
                    q.push({new_pos, hist+">"});
                }
            }
        }
    }
}

void zero(){
    for(int i = 0; i < 250; i++){
        for(int k = 0; k < 250; k++){
            for(int l = 0; l < 50; l++){
                memo[i][k][l] = -1;
            }
        }
    }
}

ll kp2(char a, char b, int level){
    if(level == LVL_MAX){
        return r2[{a,b}][0].size()-1;
    }
    if(memo[a][b][level] != -1)
        return memo[a][b][level];
    ll ret = __INT64_MAX__;
    for(string path : r2[{a,b}]){
        ll r = 0;
        for(int i = 0; i < path.size()-1; i++){
            r += kp2(path[i], path[i+1], level+1);
        }
        ret = min(ret, r);
    }
    memo[a][b][level] = ret;
    return ret;
}

ll kp1(char a, char b){
    ll ret = __INT64_MAX__;
    for(string path : r1[{a,b}]){
        ll r = 0;
        for(int i = 0; i < path.size()-1; i++){
            r += kp2(path[i], path[i+1], 0);
        }
        ret = min(ret, r);
    }
    return ret;
}

int main(){
    zero();
    generate();
    int n;
    cin >> n;
    ll res = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        s = "A"+s;
        ll r = 0;
        for(int k = 0; k < s.size()-1; k++){
            r += kp1(s[k], s[k+1]);
        }
        res += r * stoi(s.substr(1,3));
    }
    cout << res;
    return 0;
}

