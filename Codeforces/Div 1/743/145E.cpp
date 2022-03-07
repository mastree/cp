#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 10;

int n, q;
bool ar[N];

vector<int> t[N * 4], cnt[N * 4];
bool lazy[N * 4];

pair<vector<int>, vector<int>> merge(const vector<int>& a, const vector<int>& b, const vector<int>& ca, const vector<int>& cb){
    vector<int> ret1(2, 0), ret2(2, 0);
    ret1[0] = max(a[0] + cb[1], ca[0] + b[0]);
    ret1[0] = max(a[1] + cb[0], ca[1] + b[1]);
    ret2[0] = ca[0] + cb[0];
    ret2[1] = ca[1] + cb[1];
    return {ret1, ret2};
}
pair<vector<int>, vector<int>> merge(const int& a, const int& b){
    return merge(t[a], t[b], cnt[a], cnt[b]);
}

void trev(const int& v){
    swap(t[v][0], t[v][1]);
    swap(cnt[v][0], cnt[v][1]);
}
void build(int v, int tl, int tr){
    t[v].resize(2, 0);
    cnt[v].resize(2, 0);
    if (tl == tr){
        t[v] = {1, 1};
        cnt[v][ar[tl]]++;
        cout << v << " " << t[v].fi << " " << cnt[v].fi << " " << cnt[v].se << el;
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    auto temp = merge(v * 2, v * 2 + 1);
    t[v].swap(temp.fi);
    cnt[v].swap(temp.se);
}
void push(int v){
    if (lazy[v]){
        trev(v * 2);
        trev(v * 2 + 1);
        lazy[v * 2] ^= 1;
        lazy[v * 2 + 1] ^= 1;
        lazy[v] = 0;
    }
}
void update(int v, int tl, int tr, int l, int r){
    if (l > r || r < tl || tr < l) return;
    if (l <= tl && tr <= r){
        trev(v);
        lazy[v] = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    push(v);
    update(v * 2, tl, tm, l, r);
    update(v * 2 + 1, tm + 1, tr, l, r);
    auto temp = merge(v * 2, v * 2 + 1);
    t[v].swap(temp.fi);
    cnt[v].swap(temp.se);
}
pair<vector<int>, vector<int>> ask(int v, int tl, int tr, int l, int r){
    if (l > r || r < tl || tr < l) return {{0, 0}, {0, 0}};
    if (l <= tl && tr <= r) return {t[v], cnt[v]};
    int tm = (tl + tr) / 2;
    push(v);
    auto t1 = ask(v * 2, tl, tm, l, r);
    auto t2 = ask(v * 2 + 1, tm + 1, tr, l, r);
    return merge(t1.fi, t2.fi, t1.se, t2.se);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        char c;
        cin >> c;
        ar[i] = c == '7';
    }
    build(1, 1, n);
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            cout << i << " " << j << " " << ask(1, 1, n, i, j).fi[0] << el;
        }
    }

    // while (q--){
    //     string tipe;
    //     cin >> tipe;
    //     if (tipe[0] == 's'){
    //         int l, r;
    //         cin >> l >> r;
    //         update(1, 1, n, l, r);
    //     } else{
    //         auto temp = ask(1, 1, n, 1, n);
    //         cout << temp.fi[0] << el;
    //     }
    // }

    return 0;
}