#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
vector<int> ar;
vector<bool> udh;
vector<pii> disc; // min for max, percent, mx

const int N = 1e4 + 10;
vector<int> pos[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<N;i++){
        for (int j=0;j<16;j++){
            if (i & (1 << j)){
                pos[i].pb(j);
            }
        }
    }

    cin >> n >> m;
    ar.resize(n, 0);
    udh.resize(n, false);
    for (int i=0;i<n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=m;i++){
        int percent, mx;
        cin >> percent >> mx;
        disc.pb(mp(percent, mx)); // using rounding
    }
    pair<int, int> ans = mp(0, 0);

    for (int i=0;i<(1 << n);i++){
        if ((int)pos[i].size() > m) continue;
        for (int j=0;j<(1 << m);j++){
            if (pos[j].size() != pos[i].size()) continue;
            
            auto temp = pos[j];
            do{
                pair<int, int> cur = mp(0, 0);
                for (int k=0;k<temp.size();k++){
                    cur.fi += min(ar[pos[i][k]] * disc[temp[k]].fi, disc[temp[k]].se * 100);
                    cur.se -= ar[pos[i][k]];
                }
                ans = max(ans, cur);
            } while (next_permutation(temp.begin(), temp.end()));
        }
    }
    cout << (ans.fi + 50) / 100 << " " << -ans.se << el;

    return 0;
}