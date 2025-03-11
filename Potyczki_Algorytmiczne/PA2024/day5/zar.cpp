#include<iostream>
#include<vector>
#include<bitset>
#include<unordered_map>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

bitset<200007> start;
vector<pii> swi;
unordered_map<bitset<200007>, bool> res;

void search(bitset<200007> state){
    if(res[state])
        return;
    res[state] = true;
    for(auto s : swi){
        int a = s.first;
        int b = s.second;
        if(state[a] == state[b]){
            bitset<200007> cpy = state;
            cpy.flip(a);
            cpy.flip(b);
            search(cpy);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        bool a;
        cin >> a;
        start.set(i, a) ;
    }
    for(int i = 0 ; i < m; i++){
        int a, b;
        cin >> a >> b;
        swi.push_back({a, b});
    }

    search(start);

    cout << res.size();

    return 0;
}