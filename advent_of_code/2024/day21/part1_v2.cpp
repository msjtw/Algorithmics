#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<char, char> pcc;
typedef pair<int, int> pii;

char kp1[4][3] = {{'7','8','9'},{'4','5','6'},{'1','2','3'},{'x','0','A'}};
char kp2[2][3] = {{'x','^','A'},{'<','v','>'}};

vector<pii> val_pos_1 = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2},{3,1},{3,2}};
vector<pii> val_pos_2 = {{0,1},{0,2},{1,0},{1,1},{1,2}};


map<pcc, string> r;

char ptoc2(pii a){
 return kp2[a.first][a.second];

}
char ptoc1(pii a){
 return kp1[a.first][a.second];
}

string trans(pii start, string seq){
    // cout << "----" << endl << seq << endl;
    string seq0 = seq;
    vector<string> lvl0;
    while(!seq0.empty()){
        string pattern = "A";
        int pos = seq0.find(pattern)+1;
        lvl0.push_back(seq0.substr(0,pos));
        seq0.erase(0,pos);
    }
    string seq1;
    pii last = {0,2};
    for(auto s : lvl0){
        for(char c : s){
            if(find(val_pos_2.begin(),val_pos_2.end(), last) == val_pos_2.end()){
                return "out";
            }
            if(c == '^'){
                last.first--;
            }
            if(c == 'v'){
                last.first++;
            }
            if(c == '<'){
                last.second--;
            }
            if(c == '>'){
                last.second++;
            }
            if(c == 'A'){
                seq1 += ptoc2(last);
            }
        }
    }
    cout << seq1 << ", ";
    if(seq1.length() == 0 or seq1[seq1.length()-1] != 'A')
        return "";
    vector<string> lvl1;
    while(!seq1.empty()){
        string pattern = "A";
        int pos = seq1.find(pattern)+1;
        lvl1.push_back(seq1.substr(0,pos));
        seq1.erase(0,pos);
    }
    string seq2;
    last = {0,2};
    for(auto s : lvl1){
        for(char c : s){
            if(find(val_pos_2.begin(),val_pos_2.end(), last) == val_pos_2.end()){
                return "out";
            }
            if(c == '^'){
                last.first--;
            }
            if(c == 'v'){
                last.first++;
            }
            if(c == '<'){
                last.second--;
            }
            if(c == '>'){
                last.second++;
            }
            if(c == 'A'){
                seq2 += ptoc2(last);
            }
        }
    }
    cout << seq2 << ", ";
    if(seq2.length() == 0 or seq2[seq2.length()-1] != 'A')
        return "";
    vector<string> lvl2;
    while(!seq2.empty()){
        string pattern = "A";
        int pos = seq2.find(pattern)+1;
        lvl2.push_back(seq2.substr(0,pos));
        seq2.erase(0,pos);
    }
    string seq3;
    last = {3,2};
    for(auto s : lvl2){
        // cout << "--> "<< s << endl;
        for(char c : s){
            if(find(val_pos_1.begin(),val_pos_1.end(), last) == val_pos_1.end()){
                return "out";
            }
            if(c == '^'){
                last.first--;
            }
            if(c == 'v'){
                last.first++;
            }
            if(c == '<'){
                last.second--;
            }
            if(c == '>'){
                last.second++;
            }
            if(c == 'A'){
                seq3 += ptoc1(last);
            }
        }
    }
    cout << seq3 ;
    return seq3;
}

int main(){
    string s;
    int prev = 0;
    for(pii start : val_pos_1){
        queue<string> q;
        q.push("");
        while(!q.empty()){
            auto seq = q.front();
            q.pop();
            cout << "seq: " << seq << ": ";
            if(seq.length() > 0 and seq[seq.length()-1] == 'A'){
                string res = trans(start, seq);
                cout << res << " -> ";
                if(res == "out"){
                    cout << endl;
                    continue;
                }
                if(res.length() > 0 and r.find({ptoc1(start), res[0]}) == r.end()) {
                    r[{ptoc1(start), res[0]}] = seq;
                    cout << ptoc1(start) << " " <<  res[0] << ":  " << seq << endl;
                }
                if(r.size() - prev == 11){
                    prev = r.size();
                    break;
                }
            }
            cout << endl;
            q.push(seq+'^');
            q.push(seq+'>');
            q.push(seq+'v');
            q.push(seq+'<');
            q.push(seq+'A');
        }
    }
    return 0;
}
