#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

const int N = 3e3 + 10;

int a[305][305];
bool f[305][305];
bool vis[305][305];
int n,m;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

int get(int x) {
    memset (f,0,sizeof(f));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i][j] >= x) f[i][j] = 1;
        }
    }
    int cnt = 0;
    memset (vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (vis[i][j]) continue;
            if (!f[i][j]) continue;
            vis[i][j] = 1;
            cnt++;
            stack<pii> s;
            s.push({i,j});
            while (!s.empty()) {
                pii cur = s.top();
                s.pop();
                for (int k=0;k<4;k++) {
                    pii next = {cur.fi+dx[k], cur.se+dy[k]};
                    if (next.fi>=1 && next.fi <= n && next.se >= 1 && next.se <= m && !vis[next.fi][next.se] && f[next.fi][next.se]) {
                        vis[next.fi][next.se] = 1;
                        s.push(next);
                    }
                }
            }
        }
    }
    return cnt;
}



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
    pulau = 0;
    for (int i=1;i<=n * m;i++) pos[i].clear();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            ada[i][j] = 0;
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

int solve2(){
    set<int> s;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            s.insert(a[i][j]);
        }
    }
    s.insert(0);
    vector<int> v;
    int ans = 0;
    for (auto x:s) {
        v.pb(x);
    }

    int l = 0, r = v.size()-1;
    while ((l + 10) <= r) {
        int m1 = (l*2+r) / 3;
        int m2 = (l+2*r) / 3;
        int x1 = get(v[m1]);
        int x2 = get(v[m2]);
        ans = max(x1, ans);
        ans = max(x2, ans);
        if (x1 > x2) {
            r = m2;
        } else if (x1 < x2) {
            l = m1;
        } else {
            l = m1;
            r = m2;
        }
    }
    for (int i=l;i<=r;i++) {
        ans = max(ans, get(v[i]));
    }
    return ans;
}

int solve1(){
    init();
    map<int, int> komp;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
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
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int inpp;
            cin >> inpp;
            ar[i][j] = a[i][j] = inpp;
        }
    }
    // n = m = 50;
    // srand (time(NULL));
    // for (int lup=1;lup<100000;lup++){
    //     for (int i=1;i<=n;i++){
    //         for (int j=1;j<=m;j++){
    //             ar[i][j] = a[i][j] = rand() % 100 + 1;
    //         }
    //     }
        int ans1 = solve1();
        int ans2 = solve2();
        cout << ans1 << " " << ans2 << "\n\n";
    //     if (ans1 != ans2){
    //         cout << n << " " << m << endl;
    //         for (int i=1;i<=n;i++){
    //             for (int j=1;j<=m;j++){
    //                 cout << a[i][j] << " ";
    //             }
    //             cout << endl;
    //         }
    //         return 0;
    //     }
    // }
    
    return 0;
}