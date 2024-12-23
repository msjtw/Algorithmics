#include <csignal>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <signal.h>

using namespace std;

typedef pair<int,int> pii;

struct node{
    pii pos;
    int len;
    pii dir;
    vector<pii> hist;

    struct Compare {
        bool operator()(const node& a, const node& b) const {
            return a.len > b.len ; // Min-heap behavior
        }
    };
};

const int MX = 150;

string mmap[150];
int seat[150][150];
map<pii, int> dist[150][150];

priority_queue<node, vector<node>, node::Compare> q;
int n;

void sigint_handler(int sig){
    cout << endl;
    cout << q.size() << endl;
    int count = 0;
    while(!q.empty()){
        node a = q.top();
        q.pop();
        if(mmap[a.pos.second][a.pos.first] != 'O'){
            count++;
        }
        mmap[a.pos.second][a.pos.first] = 'O';
    }
    for(int i = 0; i < n; i++){
        cout << mmap[i] << endl;
    }
    cout << count << endl;
    exit(0);
}

int main(){
    for(int i = 0; i < 150; i++){
        for(int k = 0; k < 150; k++){
            dist[i][k][{-1,0}] = __INT_MAX__;
            dist[i][k][{1,0}] = __INT_MAX__;
            dist[i][k][{0,-1}] = __INT_MAX__;
            dist[i][k][{0,1}] = __INT_MAX__;
        }
    }

    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    

    int s_x, s_y;
    pii end;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> mmap[i];
        for(int k = 0; k < n; k++){
            if(mmap[i][k] == 'S'){
                s_x = k;
                s_y = i;
            }
            if(mmap[i][k] == 'E'){
                end.first = k;
                end.second = i;
            }
        }
    }

    vector<pii> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    vector<vector<pii>> paths;
    int min_len;
    q.push({.pos={s_x,s_y}, .len=0, .dir={0,1}, .hist={{s_x,s_y}}});
    dist[s_y][s_x][{-1,0}] = 0;
    dist[s_y][s_x][{1,0}] = 0;
    dist[s_y][s_x][{0,-1}] = 0;
    dist[s_y][s_x][{0,1}] = 0;
    while(!q.empty()){
        node a = q.top();
        q.pop();
        if(dist[a.pos.second][a.pos.first][a.dir] < a.len){
            continue;
        }
        dist[a.pos.second][a.pos.first][a.dir] = a.len;
        while(q.size() > 0 and q.top().len == a.len and q.top().pos == a.pos and q.top().dir == a.dir){
            a.hist.insert(a.hist.end(), q.top().hist.begin(), q.top().hist.end());
            q.pop();
        } 
        if(paths.size() > 0 and a.len > min_len){
            break;
        }
        if(mmap[a.pos.second][a.pos.first] == 'E'){
            cout << a.len << endl;
            if(paths.empty()){
                min_len = a.len;
            }
            paths.push_back(a.hist);
        }
        for(pii dir : dirs){
            pii n_pos = {a.pos.first + dir.first, a.pos.second + dir.second};
            auto n_hist = a.hist;
            n_hist.push_back(n_pos);
            if(mmap[n_pos.second][n_pos.first] == '#'){
                continue;
            }
            if(find(a.hist.begin(), a.hist.end(), n_pos) != a.hist.end()){
                continue;
            }
            if(dir == a.dir){
                q.push((node){.pos = n_pos, .len = a.len+1, .dir = dir, .hist = n_hist});
            }
            else{
                q.push((node){.pos = n_pos, .len = a.len+1001, .dir = dir, .hist = n_hist});
            }
        }
    }

    for(auto path : paths){
        for(auto pos : path){
            seat[pos.second][pos.first] = 1;
        }
    }

    int res= 0;
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            res += seat[i][k];
        }
    }

    cout << res;
        
    return 0;
}
