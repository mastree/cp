#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 26;
const int INF = 1e9 + 7;

int q;
string s;
int m;
int dist[N][N];

void solve(){
    cin >> s;
    cin >> m;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    for (int i=1;i<=m;i++){
        char ca, cb;
        cin >> ca >> cb;
        int a = ca - 'A';
        int b = cb - 'A';
        dist[a][b] = 1;
    }
    for (int k=0;k<N;k++){
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll ans = INF;
    for (int i=0;i<N;i++){
        ll cur = 0;
        for (auto& x : s){
            cur += dist[x - 'A'][i];
        }
        ans = min(ans, cur);
    }
    if (ans >= INF) cout << -1 << el;
    else cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}