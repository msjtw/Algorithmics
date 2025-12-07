#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

char arr[5][3750];

int main(int argc, char *argv[]) {
    int p;
    cin >> p;
    cin.ignore(100, '\n');
    int len;
    for (int i = 0; i < p; i++) {
        string s;
        getline(cin, s);
        s = " " + s;
        len = s.length();
        strcpy(arr[i], s.c_str());
    }

    stack<vector<int>> nums;
    nums.push({});
    for (int i = len - 1; i >= 0; i--) {
        bool num_break = true;
        int num = 0;
        for (int k = 0; k < p; k++) {
            if (arr[k][i] != ' ') {
                num_break = false;
                num *= 10;
                num += arr[k][i] - '0';
            }
        }
        if (num_break) {
            nums.push({});
        } else {
            nums.top().push_back(num);
        }
    }

    ll total = 0;
    nums.pop();
    while (!nums.empty()) {
        auto vec = nums.top();
        nums.pop();
        for (auto a : vec) {
            cout << a << " ";
        }
        char op;
        cin >> op;
        ll sum;
        if (op == '+') {
            sum = 0;
            for (auto a : vec) {
                sum += (ll)a;
            }
        } else {
            sum = 1;
            for (auto a : vec) {
                sum *= (ll)a;
            }
        }
        cout << op << " " << sum << endl;
        total += sum;
    }
    cout << total;

    return 0;
}
