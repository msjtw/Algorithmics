#include <iostream>

using namespace std;

string mmap[50];

bool can(int x, int y, int dir){
    if(mmap[y][x] == '@'){
        return can(x, y+dir, dir);
    }
    if(mmap[y][x] == '['){
        return can(x, y+dir, dir) and can(x+1,y+dir, dir);
    }
    if(mmap[y][x] == ']'){
        return can(x, y+dir, dir) and can(x-1,y+dir, dir);
    }
    if(mmap[y][x] == '.'){
        return true;
    }
    return false;
}

void move(int x, int y, int dir){
    if(mmap[y][x] == '@'){
        move(x, y+dir, dir);
        swap(mmap[y+dir][x], mmap[y][x]);
    }
    if(mmap[y][x] == '['){
        move(x, y+dir, dir);
        move(x+1,y+dir, dir);
        swap(mmap[y+dir][x], mmap[y][x]);
        swap(mmap[y+dir][x+1], mmap[y][x+1]);
    }
    if(mmap[y][x] == ']'){
        move(x, y+dir, dir);
        move(x-1,y+dir, dir);
        swap(mmap[y+dir][x], mmap[y][x]);
        swap(mmap[y+dir][x-1], mmap[y][x-1]);
    }
}

void print(int n){
    for(int i = 0; i < n; i++){
        cout << mmap[i] << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int x, y;
    for(int i = 0; i < n; i++){
        string line, wide_line;
        cin >> line;
        for(char c : line){
            if(c == '.'){
                wide_line += "..";
            }
            if(c == 'O'){
                wide_line += "[]";
            }
            if(c == '#'){
                wide_line += "##";
            }
            if(c == '@'){
                y = i;
                x = wide_line.size();
                wide_line += "@.";

            }
        }
        mmap[i] = wide_line;
    }

    /* print(n); */

    string moves;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        moves += s;
    }

    for(char m : moves){
        if(m == '^'){
            if(can(x,y,-1)){
                move(x,y,-1);
                y--;
            }
        }
        if(m == 'v'){
            if(can(x,y,1)){
                move(x,y,1);
                y++;
            }
        }
        if(m == '>'){
            int t = 1;
            while(mmap[y][x+t] == '[' or mmap[y][x+t] == ']'){
                t++;
            }
            if(mmap[y][x+t] == '.'){
                while(t > 0){
                    swap(mmap[y][x+t], mmap[y][x+t-1]);
                    t--;
                }
                x++;
            }
        }
        if(m == '<'){
            int t = 1;
            while(mmap[y][x-t] == '[' or mmap[y][x-t] == ']'){
                t++;
            }
            if(mmap[y][x-t] == '.'){
                while(t > 0){
                    swap(mmap[y][x-t], mmap[y][x-t+1]);
                    t--;
                }
                x--;
            }
        }
        /* print(n); */
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int k = 0; k < mmap[i].size(); k++){
            if(mmap[i][k] == '['){
                res += i*100+k;
            }
        }
    }
    cout << res;
}
