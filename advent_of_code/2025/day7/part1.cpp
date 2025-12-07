#include <iostream>
#include <vector>

using namespace std;

int beam_pos[150] = {};
int splits = 0;

vector<int> find_all(string a, char c) {
    vector<int> pos;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == c) {
            pos.push_back(i);
        }
    }
    return pos;
}

int main(int argc, char *argv[]) {
    int p;
    cin >> p;
    string start;
    cin >> start;
    int s_pos = find_all(start, 'S')[0];
    beam_pos[s_pos] = 1;

    while (p-- > 0) {
        string line;
        cin >> line;
        auto spliters = find_all(line, '^');
        for(int pos : spliters){
            if(beam_pos[pos] == 1){
                splits++;
                beam_pos[pos-1] = 1;
                beam_pos[pos] = 0;
                beam_pos[pos+1] = 1;
            }
        }
    }

    cout << splits;

    return 0;
}
