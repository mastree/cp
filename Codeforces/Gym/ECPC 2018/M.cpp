#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using umap = unordered_map<int, int>;

const int N = 1e5 + 10;
const int RANGE = 1e9 + 10;

int q;
int n, m;

void upd(int x, int val, vector<int>& bit){
    while (x){
        bit[x] += val;
        x -= (x & (-x));
    }
}
int ask(int x, vector<int>& bit){
    int ret = 0;
    while (x < bit.size()){
        ret += bit[x];
        x += (x & (-x));
    }
    return ret;
}

void solve(){
    cin >> n >> m;
    vector<int> bit(n + m + 10, 0);
    vector<pii> ins, del;
    vector<int> compr;
    for (int i=1;i<=n;i++){
        int x, q, r;
        cin >> x >> q >> r;
        ins.pb(mp(x, q - x));
        del.pb(mp(x + r + 1, q - x));
        compr.pb(q - x);
    }
    sort(del.begin(), del.end());
    vector<pii> quers;
    for (int i=1;i<=m;i++){
        int pos, mn;
        cin >> pos >> mn;
        quers.pb(mp(pos, mn - pos));
        compr.pb(mn - pos);
    }
    sort(compr.begin(), compr.end());
    compr.resize(unique(compr.begin(), compr.end()) - compr.begin());
    {
        umap temp;
        int cur = 1;
        for (auto& x : compr){
            temp[x] = cur++;
        }
        for (auto& x : ins){
            x.se = temp[x.se];
        }
        for (auto& x : del){
            x.se = temp[x.se];
        }
        for (auto& x : quers){
            x.se = temp[x.se];
        }
    }
    reverse(ins.begin(), ins.end());
    reverse(del.begin(), del.end());
    for (int i=0;i<m;i++){
        while (ins.size() && ins.back().fi <= quers[i].fi){
            upd(ins.back().se, 1, bit);
            ins.pop_back();
        }
        while (del.size() && del.back().fi <= quers[i].fi){
            upd(del.back().se, -1, bit);
            del.pop_back();
        }
        cout << ask(quers[i].se, bit) << ' ';
    }
    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("business.in", "r", stdin);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}