#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piii = pair<int, pii>;

piii mp3(int a, int b, int c){
    return mp(a, mp(b, c));
}

const int N = 1e3 + 10;

int n, s[N];
int ar[N][N];
vector<piii> v;

int par[N], sz[N];
vector<int> out[N]; // ujung
vector<int> adj[N]; // edge

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}
void make(int a, int b){
    int ra = a, rb = b; // real a, real b;
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    if (out[a][0] == ra) out[a].pop_front();
    else out[a].pop_back();
    if (out[b][0] == rb) out[b].pop_front();
    else out[b].pop_back();
    for (auto x : out[b]) out[a].pb(x);
}

void init(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
        out[i].pb(i);
        out[i].pb(i);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> s[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> ar[i][j];
            v.pb(mp3(ar[i][j], i, j));
        }
    }
    sort(v.begin(), v.end());
    init();
    for (auto xx : v){
        int dist = xx.fi;
        int a = xx.se.fi;
        int b = xx.se.se;

        if (find(a) == find(b)) continue;
        
        int jara[2], jarb[2];
        for (int i=0;i<2;i++){
            jara[]
        }
    }

    return 0;
}