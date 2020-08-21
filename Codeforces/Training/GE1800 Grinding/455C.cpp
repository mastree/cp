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

const int N = 3e5 + 10;

int n, m, q;
int par[N], sz[N], path[N];
vector <int> adl[N];

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    int wc = (path[a] + 1) / 2 + (path[b] + 1) / 2 + 1;
    path[a] = max(max(path[a], path[b]), wc);
}

pii furthest(int node, int p, int dep){
    pii ret = mp(node, dep);
    for (auto x : adl[node]){
        if (x == p) continue;
        pii temp = furthest(x, node, dep + 1);
        if (temp.se > ret.se){
            ret = temp;
        }
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
        path[i] = 0;
    }
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
        make(a, b);
    }

    for (int i=1;i<=n;i++){
        if (par[i] == i){
            pii sidea = furthest(i, i, 0);
            pii sideb = furthest(sidea.fi, sidea.fi, 0);
            path[i] = sideb.se;
        }
    }

    while (q--){
        int tipe;
        cin >> tipe;
        if (tipe == 1){
            int x;
            cin >> x;
            cout << path[find(x)] << el;
        } else{
            int x, y;
            cin >> x >> y;
            make(x, y);
        }
    }

    return 0;
}