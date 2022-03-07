#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e4 + 10;
const int COMP = 6;
const int INF = 1e9;

int q;
int n;

void solve(){
    cin >> n;
    vector<vector<int>> rank(n + 1, vector<int>(5));
    for (int i=1;i<=n;i++){
        for (int j=0;j<5;j++){
            cin >> rank[i][j];
        }
    }
    int sz = min(n, (int)sqrt(n) + 1);
    int part = (n + sz - 1) / sz;
    vector<int> winner(part, 0);
    for (int pp=0;pp<part;pp++){
        int a = 1 + pp * sz;
        int b = min(a + sz, n + 1);
        for (int i=a;i<b;i++){
            bool bisa = 1;
            for (int j=a;j<b;j++){
                if (i == j) continue;
                int cnt = 0;
                for (int k=0;k<5;k++){
                    if (rank[i][k] < rank[j][k]) cnt++;
                }
                if (cnt < 3){
                    bisa = 0;
                    break;
                }
            }
            if (bisa){
                winner[pp] = i;
                break;
            }
        }
    }
    int ans = -1;
    for (auto& i : winner){
        if (i == 0) continue;
        bool bisa = 1;
        for (int j=1;j<=n;j++){
            if (i == j) continue;
            int cnt = 0;
            for (int k=0;k<5;k++){
                if (rank[i][k] < rank[j][k]) cnt++;
            }
            if (cnt < 3){
                bisa = 0;
                break;
            }
        }
        if (bisa){
            ans = i;
            break;
        }
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}