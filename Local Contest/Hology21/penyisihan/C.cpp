#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e3 + 10;

int n, m;
pii par[N][N];
int sz[N][N];
int raja[N][N]; 

void init(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            par[i][j] = mp(i, j);
        }
    }
}
pii find(pii a){
    if (par[a.fi][a.se] == a) return a;
    return par[a.fi][a.se] = find(par[a.fi][a.se]);
}
void make(pii a, pii b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a.fi][a.se] < par[b.fi][b.se]) swap(a, b);
    par[b.fi][b.se] = a;
    raja[a.fi][a.se] |= raja[b.fi][b.se];
    sz[a.fi][a.se] += sz[b.fi][b.se];
}
bool alpha(char c){
    
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<vector<char>> mat(n + 2, vector<char>(m + 2, '#'));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> mat[i][j];
        }
    }
    init();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (mat[i][j] == )
        }
    }

    return 0;
}