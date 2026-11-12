#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct range {
    int start, end;
    int idx;
};

vector<range> rangs;
vector<bool> contains_some;
vector<bool> contained_in;

int main() {
    int n;
    cin >> n;

    contains_some.assign(n, false);
    contained_in.assign(n, false);

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        rangs.push_back({x, y, i});
    }

    sort(rangs.begin(), rangs.end(), [](range l, range r) {
        if (l.start == r.start)
            return l.end > r.end;
        return l.start < r.start;
    });

    int min_end = __INT_MAX__;
    for (int i = rangs.size() - 1; i >= 0; i--) {
        auto r = &rangs[i];
        if (r->end >= min_end) {
            // this range starts earlier and ends later than some other so it
            // contains it
            contains_some[r->idx] = true;
        }
        min_end = min(min_end, r->end);
    }

    int max_end = 0;
    for (int i = 0; i < n; i++) {
        auto r = &rangs[i];
        if (r->end <= max_end) {
            // this range starts later and ends earlier so is contained
            contained_in[r->idx] = 1;
        }
        max_end = max(max_end, r->end);
    }

    for (int i = 0; i < n; i++) {
        cout << (int)contains_some[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << (int)contained_in[i] << " ";
    }

    return 0;
}
