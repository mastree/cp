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

const int N = 3e3 + 10;

bool comp(const pii& a, const pii& b){
    if (a.se != b.se) return a.se < b.se;
    return a.fi > b.fi;
}

int q;
int n;
pii ar[N];

int bit[N + N][N + N];
int tempid;

void init(int nn){
    for (int i=0;i<=nn;i++) fill(bit[i], bit[i] + nn + 3, 0);
}
void upd(int le, int x, int val){
    while (x < tempid + 1){
        bit[le][x] = max(bit[le][x], val);
        x = x + (x & (-x));
    }
}
int ask(int le, int x){
    int ret = 0;
    while (x > 0){
        ret = max(ret, bit[le][x]);
        x = x - (x & (-x));
    }
    return ret;
}

void solve(){
    cin >> n;
    map<int, int> getid;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
        getid[ar[i].fi] = 1;
        getid[ar[i].se] = 1;
    }
    tempid = 0;
    for (auto& x : getid){
        x.se = ++tempid;
    }
    init(tempid);
    for (int i=1;i<=n;i++){
        ar[i].fi = getid[ar[i].fi];
        ar[i].se = getid[ar[i].se];
    }

    sort(ar + 1, ar + n + 1, &comp);
    int ans = 0;
    for (int i=1;i<=n;i++){
        int l = ar[i].fi, r = ar[i].se;
        int in = 0;
        for (int j=l;j<=r;j++){
            in = max(in, ask(j, r));
        }
        ans = max(ans, in + 1);
        upd(l, r, in + 1);
        for (int j=1;j<l;j++){
            int temp = ask(j, l - 1);
            ans = max(ans, temp + in + 1);
            upd(j, r, temp + in + 1);
        }
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}