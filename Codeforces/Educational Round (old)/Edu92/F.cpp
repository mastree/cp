#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;

piii mp3(const int& a, const int& b, const int& c){
    return mp(mp(a, b), c);
}

const int N = 2e5 + 10;

int n;
piii ar[N];
map<int, int> getid;

int dp[8 * N][2]; 
int lazy[8 * N][2]; // lazy addition

void push(int v){
    for (int i=0;i<2;i++){
        lazy[v * 2][i] += lazy[v][i];
        lazy[v * 2 + 1][i] += lazy[v][i];
        dp[v * 2][i] += lazy[v][i];
        dp[v * 2 + 1][i] += lazy[v][i];
        lazy[v][i] = 0;
    }
}

void merge(int v){
    for (int i=0;i<2;i++){
        dp[v][i] = max(dp[v * 2][i], dp[v * 2 + 1][i]);
    }
}

void update1(int v, int tl, int tr, int l, int r, bool tipe, int val){
    if (l > r || tr < l || r < tl) return;
    else if (l <= tl && tr <= r){
        dp[v][tipe] += val;
        lazy[v][tipe] += val;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update1(v * 2, tl, tm, l, r, tipe, val);
    update1(v * 2 + 1, tm + 1, tr, l, r, tipe, val);
    merge(v);
}

void update2(int v, int tl, int tr, int pos, bool tipe, int val){
    if (tr < pos || pos < tl) return;
    else if (tl == tr){
        dp[v][tipe] = max(dp[v][tipe], val);
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update2(v * 2, tl, tm, pos, tipe, val);
    update2(v * 2 + 1, tm + 1, tr, pos, tipe, val);
    merge(v);
}

int ask(int v, int tl, int tr, int l, int r, bool tipe){
    if (tr < l || r < tl) return 0;
    else if (l <= tl && tr <= r) return dp[v][tipe];
    push(v);
    int tm = (tl + tr) / 2;
    return max(ask(v * 2, tl, tm, l, r, tipe), ask(v * 2 + 1, tm + 1, tr, l, r, tipe));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i=1;i<=n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        c--;
        ar[i] = mp3(a, b, c);
        getid[a] = 1;
        getid[b] = 1;
    }
    int tempid = 0;
    for (auto& x : getid){
        x.se = ++tempid;
    }
    for (int i=1;i<=n;i++){
        ar[i].fi.fi = getid[ar[i].fi.fi];
        ar[i].fi.se = getid[ar[i].fi.se];
    }
    sort(ar + 1, ar + n + 1);
    int id = 1;
    for (int i=1;i<=tempid;i++){
        while (id <= n && ar[id].fi.fi < i){
            id++;
        }
        vector<piii> up;
        while (id <= n && ar[id].fi.fi == i){
            up.pb(ar[id]);
            id++;
        }
        for (auto x : up){
            int ri = x.fi.se;
            bool tipe = x.se;
            int temp = ask(1, 1, tempid, 1, x.fi.se, tipe);
            update2(1, 1, tempid, x.fi.se, tipe, temp + 1);
            update1(1, 1, tempid, x.fi.se + 1, tempid, tipe, 1);

            temp = ask(1, 1, tempid, 1, i - 1, !tipe);
            update2(1, 1, tempid, ri, tipe, temp + 1);
        }
        if (id > n) break;
    }
    int ans = max(ask(1, 1, tempid, 1, tempid, 0), ask(1, 1, tempid, 1, tempid, 1));
    cout << ans << el;

    return 0;
}