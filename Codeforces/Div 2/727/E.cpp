#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

struct StreeMin{
    vector<int> stree;
    int n;
    StreeMin(){}
    void build(int v, int tl, int tr, vector<int>& vec){
        if (tl == tr){
            stree[v] = vec[tl - 1];
            return; 
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, vec);
        build(v * 2 + 1, tm + 1, tr, vec);
        stree[v] = min(stree[v * 2], stree[v * 2 + 1]);
    }
    void create(vector<int>& vec){
        n = vec.size();
        stree.resize(n * 4);
        build(1, 1, n, vec);
    }
    int ask(int v, int tl, int tr, int l, int r){
        if (l > r || tr < l || r < tl) return INF;
        if (l <= tl && tr <= r){
            return stree[v];
        }
        int tm = (tl + tr) / 2;
        return min(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r);
    }
};
struct StreeMax{
    vector<int> stree;
    int n;
    StreeMax(){}
    void build(int v, int tl, int tr, vector<int>& vec){
        if (tl == tr){
            stree[v] = vec[tl - 1];
            return; 
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, vec);
        build(v * 2 + 1, tm + 1, tr, vec);
        stree[v] = max(stree[v * 2], stree[v * 2 + 1]);
    }
    void create(vector<int>& vec){
        n = vec.size();
        stree.resize(n * 4);
        build(1, 1, n, vec);
    }
    int ask(int v, int tl, int tr, int l, int r){
        if (l > r || tr < l || r < tl) return -INF;
        if (l <= tl && tr <= r){
            return stree[v];
        }
        int tm = (tl + tr) / 2;
        return max(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r);
    }
};
struct Data{
    int val;
    // int ran[2][2];
    int al, ar;
    int bl, br;
};

int n, m;
Data ar[N];

StreeMax sal, sbl;
StreeMin sar, sbr;

int checka(int pos, int val){
    int l = pos, r = n;
    int ret = pos - 1;
    while (l <= r){
        int m = (l + r) / 2;
        int atas = sar.ask(1, 1, n, pos, m);
        int bawah = ret;
        if (atas >= val) bawah = sal.ask(1, 1, n, pos, m);
        if (bawah <= val && val <= atas){
            ret = m;
            l = m + 1;
        } else{
            r = m - 1;
        }
    }
    return ret - (pos - 1);
}

int checkb(int pos, int val){
    int l = pos, r = n;
    int ret = pos - 1;
    while (l <= r){
        int m = (l + r) / 2;
        int atas = sbr.ask(1, 1, n, pos, m);
        int bawah = ret;
        if (atas >= val) bawah = sbl.ask(1, 1, n, pos, m);
        if (bawah <= val && val <= atas){
            ret = m;
            l = m + 1;
        } else{
            r = m - 1;
        }
    }
    return ret - (pos - 1);
}

int dp[N][2];
pii last[2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    {
        vector<int> tal, tar, tbl, tbr;
        for (int i=1;i<=n;i++){
            cin >> ar[i].val;
            // for (int j=0;j<2;j++){
            //     for (int k=0;k<2;k++){
            //         cin >> ar[i].ran[j][k];
            //     }
            // }
            cin >> ar[i].al >> ar[i].ar;
            cin >> ar[i].bl >> ar[i].br;
            tal.pb(ar[i].al);
            tar.pb(ar[i].ar);
            tbl.pb(ar[i].bl);
            tbr.pb(ar[i].br);
        }
        sal.create(tal);
        sar.create(tar);
        sbl.create(tbl);
        sbr.create(tbr);
    }
    for (int i=1;i<N;i++){
        dp[i][0] = dp[i][1] = -1;
    }
    last[0] = last[1] = {checka(1, 0), checkb(1, 0)};
    for (int i=1;i<=n;i++){
        last[0].fi--;
        last[1].fi--;
        last[0].se--;
        last[1].se--;

        pii nlast[2];
        nlast[0] = last[0];
        nlast[1] = last[1];

        pii baru = {checka(i, ar[i].val), checkb(i, ar[i].val)};
        if (last[0].fi >= 0 && last[0].se >= 0){
            if (nlast[1].se < baru.se){
                nlast[1] = {last[0].fi, baru.se};
                dp[i][1] = 1;
            }
            if (nlast[0].fi < baru.fi){
                nlast[0] = {baru.fi, last[1].se};
                dp[i][0] = 0;
            }
        } else{

        }
    }

    return 0;
}