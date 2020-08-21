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

const int N = 2e5 + 10;

int n, m;
int ar[N];
int lv[N];
vector <int> app;
vector <int> adl[N];

vector <pair<int, int>> vec[N]; // val, turn

int t[4 * N];
bool vis[N];
vector <pii> jawab;

void dfs_lv(int node, int p){
    app.pb(node);
    if (node != p) lv[node] = lv[p] + 1;
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs_lv(x, node);
    }
    app.pb(node);
}

void update(int v, int tl, int tr, int pos, int add){
    if (tr < pos || tl > pos) return;
    else if (tr == tl){
        t[v] += add;
        return;
    }
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, pos, add);
    update(v * 2 + 1, tm + 1, tr, pos, add);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

int query(int v, int tl, int tr, int l, int r){
    if (l > r) return 0;
    else if (l <= tl && tr <= r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(tm, r)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    dfs_lv(1, 1);

    for (int i=1;i<=m;i++){
        int tipe;
        cin >> tipe;
        if (tipe == 1){
            int x, val;
            cin >> x >> val;
            vec[x].pb(mp(val, i));
        } else{
            int x;
            cin >> x;
            vec[x].pb(mp(-1, i));
        }
    }

    for (auto node : app){
        if (!vis[node]){
            vis[node] = 1;
            for (auto qq : vec[node]){
                int val = qq.fi;
                int turn = qq.se;
                if (val > 0){
                    if (lv[node]&1) val = -val;
                    update(1, 1, m, turn, val);
                } else{
                    int temp = query(1, 1, m, 1, turn);
                    if (lv[node]&1) temp = -temp;
                    jawab.pb(mp(turn, temp + ar[node]));
                }
            }
        } else{
            for (auto qq : vec[node]){
                int val = qq.fi;
                int turn = qq.se;
                if (val > 0){
                    if (lv[node]&1) val = -val;
                    update(1, 1, m, turn, -val);
                } 
            }
        }
    }
    sort(jawab.begin(), jawab.end());
    for (auto x : jawab){
        cout << x.se << el;
    }

    return 0;
}