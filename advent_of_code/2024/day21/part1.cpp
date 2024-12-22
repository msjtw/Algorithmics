#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<char, char> pcc;
typedef pair<int, int> pii;

char kp1[4][3] = {{'7','8','9'},{'4','5','6'},{'1','2','3'},{'x','0','A'}};
char kp2[2][3] = {{'x','^','A'},{'<','v','>'}};

map<pcc, string> r1;
map<pcc, string> r2;

void generate_dirs(){
    r1[{'A','A'}] = "A";
    r1[{'A','0'}] = "<A";
    r1[{'A','1'}] = "^<<A";
    r1[{'A','2'}] = "^<A";
    r1[{'A','3'}] = "^A";
    r1[{'A','4'}] = "^^<<A";
    r1[{'A','5'}] = "^^<A";
    r1[{'A','6'}] = "^^A";
    r1[{'A','7'}] = "^^^<<A";
    r1[{'A','8'}] = "^^^<A";
    r1[{'A','9'}] = "^^^A";

    r1[{'0','A'}] = ">A";
    r1[{'0','0'}] = "A";
    r1[{'0','1'}] = "^<A";
    r1[{'0','2'}] = "^A";
    r1[{'0','3'}] = "^>A";
    r1[{'0','4'}] = "^^<A";
    r1[{'0','5'}] = "^^A";
    r1[{'0','6'}] = "^^>A";
    r1[{'0','7'}] = "^^^<A";
    r1[{'0','8'}] = "^^^A";
    r1[{'0','9'}] = "^^^>A";

    r1[{'1','A'}] = ">>vA";
    r1[{'1','0'}] = ">vA";
    r1[{'1','1'}] = "A";
    r1[{'1','2'}] = ">A";
    r1[{'1','3'}] = ">>A";
    r1[{'1','4'}] = "^A";
    r1[{'1','5'}] = "^>A";
    r1[{'1','6'}] = "^>>A";
    r1[{'1','7'}] = "^^A";
    r1[{'1','8'}] = "^^>A";
    r1[{'1','9'}] = "^^>>A";

    r1[{'2','A'}] = ">vA";
    r1[{'2','0'}] = "vA";
    r1[{'2','1'}] = "<A";
    r1[{'2','2'}] = "A";
    r1[{'2','3'}] = ">A";
    r1[{'2','4'}] = "^<A";
    r1[{'2','5'}] = "^A";
    r1[{'2','6'}] = "^>A";
    r1[{'2','7'}] = "^^<A";
    r1[{'2','8'}] = "^^A";
    r1[{'2','9'}] = "^^>A";

    r1[{'3','A'}] = "vA";
    r1[{'3','0'}] = "v<A";
    r1[{'3','1'}] = "<<A";
    r1[{'3','2'}] = "<A";
    r1[{'3','3'}] = "A";
    r1[{'3','4'}] = "<<^A";
    r1[{'3','5'}] = "<^A";
    r1[{'3','6'}] = "^A";
    r1[{'3','7'}] = "<<^^A";
    r1[{'3','8'}] = "<^^A";
    r1[{'3','9'}] = "^^A";

    r1[{'4','A'}] = ">>vvA";
    r1[{'4','0'}] = ">vvA";
    r1[{'4','1'}] = "vA";
    r1[{'4','2'}] = ">vA";
    r1[{'4','3'}] = ">>vA";
    r1[{'4','4'}] = "A";
    r1[{'4','5'}] = ">A";
    r1[{'4','6'}] = ">>A";
    r1[{'4','7'}] = "^A";
    r1[{'4','8'}] = "^>A";
    r1[{'4','9'}] = "^>>A";

    r1[{'5','A'}] = ">vvA";
    r1[{'5','0'}] = "vvA";
    r1[{'5','1'}] = "<vA";
    r1[{'5','2'}] = "vA";
    r1[{'5','3'}] = ">vA";
    r1[{'5','4'}] = "<A";
    r1[{'5','5'}] = "A";
    r1[{'5','6'}] = ">A";
    r1[{'5','7'}] = "<^A";
    r1[{'5','8'}] = "^A";
    r1[{'5','9'}] = "^>A";

    r1[{'6','A'}] = "vvA";
    r1[{'6','0'}] = "vv<A";
    r1[{'6','1'}] = "v<<A";
    r1[{'6','2'}] = "v<A";
    r1[{'6','3'}] = "vA";
    r1[{'6','4'}] = "<<A";
    r1[{'6','5'}] = "<A";
    r1[{'6','6'}] = "A";
    r1[{'6','7'}] = "^<<A";
    r1[{'6','8'}] = "^<A";
    r1[{'6','9'}] = "^A";

    r1[{'7','A'}] = ">>vvvA";
    r1[{'7','0'}] = ">vvvA";
    r1[{'7','1'}] = "vvA";
    r1[{'7','2'}] = ">vvA";
    r1[{'7','3'}] = ">>vvA";
    r1[{'7','4'}] = "vA";
    r1[{'7','5'}] = ">vA";
    r1[{'7','6'}] = ">>vA";
    r1[{'7','7'}] = "A";
    r1[{'7','8'}] = ">A";
    r1[{'7','9'}] = ">>A";

    r1[{'8','A'}] = ">vvvA";
    r1[{'8','0'}] = "vvvA";
    r1[{'8','1'}] = "<vvA";
    r1[{'8','2'}] = "vvA";
    r1[{'8','3'}] = "vv>A";
    r1[{'8','4'}] = "v<A";
    r1[{'8','5'}] = "vA";
    r1[{'8','6'}] = "v>A";
    r1[{'8','7'}] = "<A";
    r1[{'8','8'}] = "A";
    r1[{'8','9'}] = ">A";

    r1[{'9','A'}] = "vvvA";
    r1[{'9','0'}] = "vvv<A";
    r1[{'9','1'}] = "vv<<A";
    r1[{'9','2'}] = "vv<A";
    r1[{'9','3'}] = "vvA";
    r1[{'9','4'}] = "v<<A";
    r1[{'9','5'}] = "v<A";
    r1[{'9','6'}] = "vA";
    r1[{'9','7'}] = "<<A";
    r1[{'9','8'}] = "<A";
    r1[{'9','9'}] = "A";

    r2[{'A','A'}] = "A";
    r2[{'A','^'}] = "<A";
    r2[{'A','<'}] = "v<<A";
    r2[{'A','>'}] = "vA";
    r2[{'A','v'}] = "v<A";

    r2[{'^','A'}] = ">A";
    r2[{'^','^'}] = "A";
    r2[{'^','<'}] = "v<A";
    r2[{'^','>'}] = "v>A";
    r2[{'^','v'}] = "vA";

    r2[{'<','A'}] = ">>^A";
    r2[{'<','^'}] = ">^A";
    r2[{'<','<'}] = "A";
    r2[{'<','>'}] = ">>A";
    r2[{'<','v'}] = ">A";

    r2[{'>','A'}] = "^A";
    r2[{'>','^'}] = "<^A";
    r2[{'>','<'}] = "<<A";
    r2[{'>','>'}] = "A";
    r2[{'>','v'}] = "<A";

    r2[{'v','A'}] = ">^A";
    r2[{'v','^'}] = "^A";
    r2[{'v','<'}] = "<A";
    r2[{'v','>'}] = ">A";
    r2[{'v','v'}] = "A";
}

char ptoc1(pii a){
 return kp1[a.first][a.second];
}

void generate_r1(){
    vector<pii> val_pos = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2},{3,1},{3,2}};
    vector<pii> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    for(auto start : val_pos){
        queue<pair<pii, string>> q;
        q.push({start,""});
        r1[{ptoc1(start),ptoc1(start)}] = "A";
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            pii pos = a.first;
            string hist = a.second;
            for(auto dir : dirs){
                pii new_pos = {pos.first + dir.first, pos.second + dir.second};
                if(find(val_pos.begin(), val_pos.end(), new_pos) == val_pos.end()){
                    continue;
                }
                if(r1.find({ptoc1(start),ptoc1(new_pos)}) != r1.end()){
                    continue;
                }
                if(dir == make_pair(-1,0)){
                    r1[{ptoc1(start),ptoc1(new_pos)}] = hist+"^A";
                    q.push({new_pos, hist+"^"});
                }
                if(dir == make_pair(1,0)){
                    r1[{ptoc1(start),ptoc1(new_pos)}] = hist+"vA";
                    q.push({new_pos, hist+"v"});
                }
                if(dir == make_pair(0,-1)){
                    r1[{ptoc1(start),ptoc1(new_pos)}] = hist+"<A";
                    q.push({new_pos, hist+"<"});
                }
                if(dir == make_pair(0,1)){
                    r1[{ptoc1(start),ptoc1(new_pos)}] = hist+">A";
                    q.push({new_pos, hist+">"});
                }
            }
        }
    }
    r2[{'A','A'}] = "A";
    r2[{'A','^'}] = "<A";
    r2[{'A','<'}] = "v<<A";
    r2[{'A','>'}] = "vA";
    r2[{'A','v'}] = "v<A";

    r2[{'^','A'}] = ">A";
    r2[{'^','^'}] = "A";
    r2[{'^','<'}] = "v<A";
    r2[{'^','>'}] = "v>A";
    r2[{'^','v'}] = "vA";

    r2[{'<','A'}] = ">>^A";
    r2[{'<','^'}] = ">^A";
    r2[{'<','<'}] = "A";
    r2[{'<','>'}] = ">>A";
    r2[{'<','v'}] = ">A";

    r2[{'>','A'}] = "^A";
    r2[{'>','^'}] = "<^A";
    r2[{'>','<'}] = "<<A";
    r2[{'>','>'}] = "A";
    r2[{'>','v'}] = "<A";

    r2[{'v','A'}] = ">^A";
    r2[{'v','^'}] = "^A";
    r2[{'v','<'}] = "<A";
    r2[{'v','>'}] = ">A";
    r2[{'v','v'}] = "A";
}

pii btop(pii start, string a){
    pii tmp = start;
    for(char c : a){
        if(c == '^'){
            tmp.first--;
        }
        if(c == 'v'){
            tmp.first++;
        }
        if(c == '<'){
            tmp.second--;
        }
        if(c == '>'){
            tmp.second++;
        }
    }
    return start;
}

char ptoc2(pii a){
 return kp2[a.first][a.second];
}

void generate_r2(){
    vector<pii> val_pos = {{0,1},{0,2},{1,0},{1,1},{1,2}};
    for(auto start : val_pos){
        queue<string> q;
        q.push("");
        r2[{ptoc2(start),ptoc2(start)}] = "A";

    }
}


char trans(string seq){
    vector<string> lvl1;
    while(!seq.empty()){
        int pos = seq.find('A');
        lvl1.push_back(seq.substr(0,pos));
        seq.erase(0,pos);
    }
    for(auto s : lvl1){
        cout << s << endl;
    }
    return 'C';
}

int main(){
    generate_r1();
    generate_r2();
    for(int i = 0; i < 10; i++){
        for(int k = 0; k < 10; k++){
            cout << i << " " << k << ": "<< r1[{'0'+i, '0'+k}] << endl;
        }
        cout << endl;
    }
    int n;
    int res = 0;
    cin >> n;
    while(n --> 0){
        string seq, next_seq = "";
        cin >> seq;
        int val = stoi(seq.substr(0,3));
        seq = "A"+seq;
        cout << seq << endl;
        for(int i = 0; i < seq.size()-1; i++){
            next_seq += r1[{seq[i],seq[i+1]}];
        }
        seq = "A"+next_seq;
        cout << seq << endl;
        next_seq = "";
        for(int i = 0; i < seq.size()-1; i++){
            next_seq += r2[{seq[i],seq[i+1]}];
        }
        seq = "A"+next_seq;
        cout << seq << endl;
        next_seq = "";
        for(int i = 0; i < seq.size()-1; i++){
            next_seq += r2[{seq[i],seq[i+1]}];
        }
        seq = next_seq;
        cout << seq << endl;
        cout << seq.length() << " " << val << endl;
        res += seq.length()*val;
    }
    cout << res;
}
