#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> nums[7];
ll total = 0;

int main(int argc, char *argv[]) {
    int p;
    cin >> p;
    cin.ignore(100, '\n');
    stringstream line_stream;
    for (int i = 0; i < p; i++) {
        string line;
        getline(cin, line);

        line_stream.clear();
        line_stream << line;
        ll a;
        while (line_stream >> a) {
            nums[i].push_back(a);
        }
        // cout << endl;
    }
    // cout << "read data" << endl;
    string line;
    getline(cin, line);
    line_stream.clear();
    line_stream << line;
    for (int k = 0; k < nums[0].size(); k++) {
        ll res;
        char op;
        line_stream >> op;
        line_stream.ignore(100, ' ');
        if (op == '+') {
            res = 0;
            for (int i = 0; i < p; i++) {
                cout << nums[i][k] << " ";
                res += nums[i][k];
            }
        } else {
            res = 1;
            for (int i = 0; i < p; i++) {
                cout << nums[i][k] << " ";
                res *= nums[i][k];
            }
        }
        cout << op << " = " << res << endl;
        total += res;
    }

    cout << total;

    return 0;
}
