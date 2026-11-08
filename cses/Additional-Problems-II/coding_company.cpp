#include <iostream>
#include <vector>

using namespace std;

vector<int> skills;
vector<vector<std::vector<int>>> memo;

int main(int argc, char *argv[]) {
    int n, x;
    cin >> n >> x;

    // coder // penantly // team
    memo.resize(n + 1, vector<vector<int>>(x + 1, vector<int>(n + 1, -1)));

    skills.reserve(n);
    int s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        skills.push_back(s);
    }
}
