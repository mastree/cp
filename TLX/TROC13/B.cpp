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

const int N = 3e2 + 10;

int n, m;
int ar[N][N];

int par[N * N], sz[N * N];
bool ada[N][N];

vector<pii> pos[N * N];

int pulau = 0;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int getid(int a, int b){
    return (a - 1) * m + b;
}
void init(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            par[getid(i, j)] = getid(i, j);
            sz[getid(i, j)] = 0;
        }
    }
}

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    pulau--;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    init();
    map<int, int> komp;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> ar[i][j];
            komp[ar[i][j]] = 1;
        }
    }
    int tempid = 0;
    for (auto x : komp){
        komp[x.fi] = ++tempid;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            ar[i][j] = komp[ar[i][j]];
            pos[ar[i][j]].pb(mp(i, j));
        }
    }
    int ans = 0;
    for (int h=n * m + 1;h>=1;h--){
        for (auto x : pos[h]){
            int i = x.fi, j = x.se;

            pulau++;
            ada[i][j] = 1;
            for (int k=0;k<4;k++){
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ada[ni][nj]){
                    make(getid(i, j), getid(ni, nj));
                }
            }
        }
        ans = max(ans, pulau);
    }
    cout << ans << el;

    return 0;
}