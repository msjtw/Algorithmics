#include <iostream>

using namespace std;

int res = 0;

int main (int argc, char *argv[]) {
    int p;
    cin >> p;
    while (p --> 0) {
        string s;
        cin >> s;
        int maxi = 0;
        for( int i = s.length()-2; i >= 0; i--){
            for(int k = s.length()-1; k > i; k --){
                int a = s[i] - '0';
                int b = s[k] - '0';
                maxi = max(maxi, a*10+b);
            }
        }
        res += maxi;
    }
    cout << res << endl;
    return 0;
}
