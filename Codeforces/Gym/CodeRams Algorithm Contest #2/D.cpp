#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n, m, k;
vector<int> sclass[N];
vector<int> kelas[N];

int par[N], sz[N];
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
}
bool take[N];
bool corona[N];

void init(){
    for (int i=0;i<N;i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
        for (int j=1;j<=k;j++){
            int a;
            cin >> a;
            sclass[a].pb(i);
            kelas[i].pb(a);
        }
    }
    for (int i=1;i<=n;i++){
        int len = sclass[i].size();
        for (int j=0;j<len - 1;j++){
            make(sclass[i][j], sclass[i][j + 1]);
        }
    }
    int c;
    cin >> c;
    for (int i=1;i<=c;i++){
        int cor;
        cin >> cor;
        corona[cor] = 1;
        for (auto& x : sclass[cor]){
            take[find(x)] = 1;
        }
    }
    vector<bool> ans(n + 1, 0);
    for (int i=1;i<=m;i++){
        if (take[find(i)]){
            for (auto& x : kelas[i]){
                if (!corona[x]) ans[x] = 1;
            }
        }
    }
    int quar = 0;
    for (int i=1;i<=n;i++){
        if (ans[i]) quar++;
    }
    cout << quar << el;
    for (int i=1;i<=n;i++){
        if (ans[i]){
            cout << i << ' ';
        }
    }
    cout << el;

    return 0;
}