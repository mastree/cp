#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int H = 1e3 + 10;

int q;

void solve() {
    string line;
    getline(cin, line);
    vector<int> vec;
    {
        stringstream ss(line);
        int inp;
        while (ss >> inp) {
            vec.push_back(inp);
        }
    }
    int n = vec.size();
    vector<set<int>> pos(H);
    set<int> ada;
    for (int i = n - 1; i >= 0; i--) {
        pos[vec[i]].insert(i);
        ada.insert(vec[i]);
    }

    int ans = 0;
    while (1) {
        int cur = -1;
        int lastpos = -1;

        vector<int> tobe_erased;
        for (auto it = ada.rbegin(); it != ada.rend(); it++) {
            int i = *it;
            if (pos[i].size()) {
                if (cur == -1) {
                    cur = i;
                    lastpos = *pos[i].begin();
                    pos[i].erase(pos[i].begin());
                } else if (cur == i + 1 && pos[i].upper_bound(lastpos) != pos[i].end()) {
                    cur = i;
                    int temp = *pos[i].upper_bound(lastpos);
                    pos[i].erase(pos[i].upper_bound(lastpos));
                    lastpos = temp;
                }
            }
            if (pos[i].empty()) {
                tobe_erased.push_back(i);
            }
        }
        for (auto& x : tobe_erased) ada.erase(x);
        if (cur == -1) break;
        ans++;
    }
    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    cin.ignore();
    for (int i = 1; i <= q; i++) {
        solve();
    }

    return 0;
}