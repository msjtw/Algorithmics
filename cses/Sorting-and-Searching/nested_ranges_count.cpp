#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

struct range {
    int begin, end;
    int idx;
};

set<int> vals_rmap;
unordered_map<int, int> vals_map;
vector<int> contains;
vector<int> is_contained;

vector<range> rangs;

const int BASE = 1 << 19;
vector<int> range_ends;

void add(int p, int v, vector<int> &tree) {
    p += BASE;
    tree[p] += v;
    while (p > 0) {
        p >>= 1;
        tree[p] = tree[2 * p] + tree[2 * p + 1];
    }
}

int query(int p, int q, vector<int> &tree) {
    int ret = 0;
    p += BASE - 1;
    q += BASE + 1;
    while (p >> 1 != q >> 1) {
        if (not(p & 1)) {
            ret += tree[p + 1];
        }
        if (q & 1) {
            ret += tree[q - 1];
        }
        p >>= 1;
        q >>= 1;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;

    contains.assign(n, 0);
    is_contained.assign(n, 0);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vals_rmap.insert(a);
        vals_rmap.insert(b);
        rangs.push_back(range{a, b, i});
    }

    int m = vals_rmap.size();
    for (int v : vals_rmap) {
        static int i = 0;
        vals_map[v] = i;
        i++;
    }

    for (auto &r : rangs) {
        r.begin = vals_map[r.begin];
        r.end = vals_map[r.end];
    }

    sort(rangs.begin(), rangs.end(), [](range l, range r) {
        if (l.begin == r.begin)
            return l.end > r.end;
        return l.begin < r.begin;
    });

    range_ends.assign(2 * BASE, 0);
    for (int i = 0; i < n; i++) {
        auto r = &rangs[i];
        // tree only contains ranges that began earlier
        // so the ones that end after this rang contain it
        int count = query(r->end, m, range_ends);
        is_contained[r->idx] = count;

        add(r->end, 1, range_ends);
    }

    range_ends.assign(2 * BASE, 0);
    for (int i = n - 1; i >= 0; i--) {
        auto r = &rangs[i];
        // now tree only contains ends of ranges that begin later
        // so the ones that end before this are contained be this
        int count = query(r->begin, r->end, range_ends);
        contains[r->idx] = count;

        add(r->end, 1, range_ends);
    }

    for (int i = 0; i < n; i++) {
        cout << contains[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << is_contained[i] << " ";
    }

    return 0;
}
