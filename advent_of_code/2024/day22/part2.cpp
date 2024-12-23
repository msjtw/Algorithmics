#include <iostream>
#include <locale>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef tuple <int,int,int,int> seq;

const int ITER = 2000;
const int MOD = 16777216;
const int MX = 2000;

vector<int> monkeys[MX];
map<seq, int> values;
set<seq> sequences;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        uint a;
        cin >> a;
        for (int _i = 0; _i < ITER; _i++){
            uint tmp = a*64;
            a = tmp^a;
            a = a%MOD;
            tmp = a/32;
            a = tmp^a;
            a = a%MOD;
            tmp= a*2048;
            a = tmp^a;
            a = a%MOD;
            monkeys[i].push_back(a%10);
        }
    }

    for(int i = 0; i < n; i++){
        set<seq> mon_seq;
        int a = monkeys[i][1] - monkeys[i][0];
        int b = monkeys[i][2] - monkeys[i][1];
        int c = monkeys[i][3] - monkeys[i][2];
        int d = monkeys[i][4] - monkeys[i][3];
        values[{a,b,c,d}] += monkeys[i][4];
        mon_seq.insert({a,b,c,d});
        sequences.insert({a,b,c,d});
        for(int k = 5; k < monkeys[i].size(); k++){
            a=b;
            b=c;
            c=d;
            d=monkeys[i][k] - monkeys[i][k-1];
            if(mon_seq.find({a,b,c,d}) == mon_seq.end()){
                values[{a,b,c,d}] += monkeys[i][k];
                sequences.insert({a,b,c,d});
                mon_seq.insert({a,b,c,d});
            }
        }
    }

    cout << sequences.size() << endl;

    int res = 0;
    for(auto s : sequences){
        res= max(res, values[s]);
    }

    cout << res;

    return 0;
}
