#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<char, char> pcc;
typedef pair<int, int> pii;
typedef long long int ll;

const int LVL_MAX = 2;

char kp1_data[4][3] = {{'7','8','9'},{'4','5','6'},{'1','2','3'},{'x','0','A'}};
char kp2_data[2][3] = {{'x','^','A'},{'<','v','>'}};

int cache1[250][250] {};
int cache2[250][250][50] {};

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

int kp2(char a, char b, int lvl){
    cout << string((lvl+2)*3, ' ') <<  " " << a << b <<endl;
    if(cache2[a][b][lvl] > 0)
        return cache2[a][b][lvl];

    vector<pii> val_pos = {{0,1},{0,2},{1,0},{1,1},{1,2}};
    vector<pii> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    
    pii start = ctop2(a);
    vector<string> s_paths;
    queue<pair<pii,string>> q;
    q.push({start,""});
    while(!q.empty()){
        auto a = q.front();
        q.pop();
        pii pos = a.first;
        string hist = a.second;
        if(!s_paths.empty() and s_paths.front().size() < hist.size()){
            break;
        }
        if(ptoc2(pos) == b){
            s_paths.push_back(hist);
        }
        for(auto dir : dirs){
            pii new_pos = {pos.first + dir.first, pos.second + dir.second};
            if(find(val_pos.begin(), val_pos.end(), new_pos) == val_pos.end()){
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

    int ret = __INT_MAX__;
    if(lvl == LVL_MAX){
        cout << string((lvl+2)*3, ' ') <<  " " << s_paths[0] <<endl;
        ret =  s_paths[0].size();
    }
    else{
        for(auto p : s_paths){
            p = "A"+p+"A";
            cout << string((lvl+2)*3, ' ') <<  " " << p <<endl;
            int p_len = 0;
            for(int i = 0; i < p.size()-1; i++){
                p_len += kp2(p[i], p[i+1], lvl+1);
            }
            ret = min(ret, p_len);
        }
    }
    
    cache2[a][b][lvl] = ret;
    return ret;

}

int kp1(char a, char b){
    cout << "   " << a << b <<endl;
    if(cache1[a][b] > 0)
        return cache1[a][b];
    vector<pii> val_pos = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2},{3,1},{3,2}};
    vector<pii> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    pii start = ctop1(a);
    vector<string> s_paths;
    queue<pair<pii,string>> q;
    q.push({start,""});
    while(!q.empty()){
        auto a = q.front();
        q.pop();
        pii pos = a.first;
        string hist = a.second;
        if(!s_paths.empty() and s_paths.front().size() < hist.size()){
            break;
        }
        if(ptoc1(pos) == b){
            s_paths.push_back(hist);
        }
        for(auto dir : dirs){
            pii new_pos = {pos.first + dir.first, pos.second + dir.second};
            if(find(val_pos.begin(), val_pos.end(), new_pos) == val_pos.end()){
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
    int ret = __INT_MAX__;
    for(auto p : s_paths){
        p = "A"+p+"A";
        cout << "   " << p <<endl;
        int p_len = 0;
        for(int i = 0; i < p.size()-1; i++){
            p_len += kp2(p[i], p[i+1], 0);
        }
        ret = min(ret, p_len);
    }

    
    cache1[a][b] = ret;
    return ret;
}

int main(){
    int n;
    cin >> n;
    while(n --> 0){
        int len  = 0;
        string seq;
        cin >> seq;
        seq = "A"+seq;
        for(int i = 0; i < seq.size()-1; i++){
            len += kp1(seq[i], seq[i+1]);
        }
        cout << "-> " << len << endl;
    }
    return 0;
}
