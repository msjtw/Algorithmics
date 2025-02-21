#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int res = 0;
    for(int dist = 1; dist < s.length(); dist++){
        int a, b ,c;
        for(b = 0; b < s.length(); b++){
            a = b-dist;
            c = b+dist;
            if(a < 0)
                continue;
            if(c >= s.length())
                break;
            
            if(s[a] == 'A' and s[b] == 'B' and s[c] == 'C')
                res++;
        }
    }
    cout << res;
}
