#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void inpos(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void outpos(T n) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar('\n');
}

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

int q;
int n, k;
char ar[N];

int od[N][2], ev[N][2];


bool cek(int l, int r){
    int range = r - l + 1;
    if (range == 1) return 1;
    return (od[r][0] - od[l - 1][0] + ev[r][1] - ev[l - 1][1]) != range && (ev[r][0] - ev[l - 1][0] + od[r][1] - od[l - 1][1]) != range;
}
int t[4 * N];

void build(int v, int tl, int tr){
    if (tl == tr){
        if (tl == 0) t[v] = 0;
        else if (tl == 1) t[v] = 1;
        else t[v] = INF;
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}
void update(int v, int tl, int tr, int l, int r, int val){
    if (l > r || r < tl || tr < l) return;
    if (l <= tl && tr <= r){
        t[v] = min(t[v], val);
        return;
    }
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, r, val);
    update(v * 2 + 1, tm + 1, tr, l, r, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}
int ask(int v, int tl, int tr, int l, int r){
    if (l > r || r < tl || tr < l) return INF;
    if (l <= tl && tr <= r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
}

void solve(){
    inpos(n), inpos(k);
    for (int i=1;i<=n;i++){
        char c;
        scanf("%c", &c);
        ar[i] = c - '0';
    }
    if (k == 1){
        outpos(n - 1);
        return;
    }
    for (int i=0;i<=n + 2;i++){
        od[i][0] = od[i][1] = 0;
        ev[i][0] = ev[i][1] = 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<2;j++){
            od[i][j] = od[i - 1][j];
            ev[i][j] = ev[i - 1][j];
        }
        if (i & 1){
            od[i][ar[i]]++;
        } else{
            ev[i][ar[i]]++;
        }
    }
    build(1, 0, n);
    int last = 0, bef = 1;
    for (int i=2;i<=n;i++){
        if (ar[i] == ar[i - 1]) last = i - 1;
        int le = max(i - k + 1, 1);
        int cur;
        if (last >= le) cur = min(ask(1, 0, n, le - 1, last - 1), bef);
        else cur = bef;
        update(1, 0, n, i, i, cur + 1);
        bef = cur + 1;
    }
    outpos(bef - 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    inpos(q);
    while (q--){
        solve();
    }

    return 0;
}