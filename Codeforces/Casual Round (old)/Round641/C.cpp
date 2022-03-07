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

const int N = 1e3 + 10;
const ll INF = 1e18 + 10;

int n, m, q;
int ar[N][N];

ll mul[N][N];

int _r[4] = {-1, 0, 1, 0};
int _c[4] = {0, -1, 0, 1};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    fill(ar[0], ar[0] + m + 2, 2);
    fill(ar[n + 1], ar[n + 1] + m + 2, 2);
    for (int i=0;i<=n+1;i++){
        ar[i][0] = 2;
        ar[i][m + 1] = 2;
    }
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        for (int j=1;j<=m;j++){
            ar[i][j] = (s[j-1] == '1');
        }
    }
    queue <pii> qu;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int cnt = 0;
            for (int k=0;k<4;k++){
                if (ar[i][j] == ar[i + _r[k]][j + _c[k]]) cnt++;
            }
            if (cnt){
                mul[i][j] = 0;
                // cout << i << " " << j << el;
                qu.push(mp(i, j));
            } else mul[i][j] = INF;
        }
    }

    // bfs
    while (!qu.empty()){
        auto temp = qu.front();
        qu.pop();

        ll awal = mul[temp.fi][temp.se];
        for (int i=0;i<4;i++){
            int nr = temp.fi + _r[i];
            int nc = temp.se + _c[i];
            if (mul[nr][nc] != INF) continue;
            mul[nr][nc] = awal + 1;
            qu.push(mp(nr, nc));
        }
    }

    while (q--){
        int x, y;
        ll p;
        cin >> x >> y >> p;

        ll awal = mul[x][y];
        ll dist = p - awal;
        // cout << awal << " => " << el;
        if (dist <= 0){
            cout << ar[x][y] << el;
        } else{
            if (dist & 1){
                cout << (ar[x][y] ^ 1) << el;
            } else{
                cout << ar[x][y] << el;
            }
        }
    }

    return 0;
}