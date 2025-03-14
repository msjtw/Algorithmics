#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

typedef pair<int,int> pii;

const int BASE = 1<<19;

vector<pii> blocks;
int height[2*BASE] {};

void set(int p, int val){
    p += BASE;
    height[p] = val;
    while(p > 0){
        p >>= 1;
        height[p] = max(height[2*p], height[2*p+1]);
    }
}

int query(int p, int q){
    int ret = 0;
    p += BASE -1;
    q += BASE +1;
    while(p>>1 != q>>1){
        if(!(p&1)){
            ret = max(ret, height[p+1]);
        }
        if(q&1){
            ret = max(ret, height[q-1]);
        }
        p >>= 1;
        q >>= 1;
    }
    return ret;
}



bool cmp(pii l, pii r){
    return l.first > r.first;
}

int main(){
    int n, c;
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        int a, w;
        cin >> a >> w;
        blocks.push_back({a,w});
    }

    sort(blocks.begin(),blocks.end(),cmp);

    for(int i = 0; i < blocks.size(); i++){
        int a, w;
        tie(a, w) = blocks[i];
        int same = query(w,w);
        int diff = max(query(0,w-1),query(w+1,BASE));

        set(w, max(same + a, diff + a - c));

        // cout << a << " " << w << ": " << endl;
        // cout << same << " " << diff << endl;
        // cout << same + a << " " <<  diff + a - c << "; max " <<  max(same + a, diff + a - c) << endl;
        // cout << query(0,BASE) << endl << endl;
    }
    
    cout << query(0,BASE);

    return 0;
}
