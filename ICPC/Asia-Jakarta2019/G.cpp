#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9;

int n, m, q;
int pos[N];
int ran;
vector <int> ubah[N];
pii cnt_ubah[N]; // lebih, kurang

int t[4 * N], lazy[4 * N];

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = pos[tl - 1] - (int)ubah[tl].size();
        // cout << tl << " " << t[v] << el;
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

void push(int v){
    lazy[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    t[v * 2] += lazy[v];
    t[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int add){
    if (l > r) return;
    else if (l == tl && tr == r){
        lazy[v] += add;
        t[v] += add;
        return;
    } 
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(tm, r), add);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int ask(int v, int tl, int tr, int l, int r){
    if (l > r) return INF;
    else if (l <= tl && tr <= r){
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    return min(ask(v * 2, tl, tm, l, min(tm, r)), ask(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    pos[0] = n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        if (i == 1) ran = a;
        else if (a > ran) pos[0]--;
    }
    for (int i=1;i<=m;i++){
        int len;
        cin >> len;
        for (int j=0;j<len;j++){
            int a;
            cin >> a;
            ubah[i].pb(a);
            if (a > ran){
                cnt_ubah[i].fi++;
            } else{
                cnt_ubah[i].se++;
            }
        }
        pos[i] = pos[i - 1] - cnt_ubah[i].fi;
    }
    build(1, 1, m);

    while (q--){
        int x, y, val;
        cin >> x >> y >> val;
        y--;
        if (ubah[x][y] > ran && val < ran){
            update(1, 1, m, x + 1, m, 1);
        } else if (ubah[x][y] < ran && val > ran){
            update(1, 1, m, x + 1, m, -1);
        }
        ubah[x][y] = val;
        cout << (ask(1, 1, m, 1, m) > 0) << el;
    }

    return 0;
}