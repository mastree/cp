#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 4e2 + 10;


int q;
int n, m, mon;
int ar[N][N], pre[N][N];

int calc(int ra, int ca, int rb, int cb){
    return pre[rb][cb] - pre[ra - 1][cb] - pre[rb][ca - 1] + pre[ra - 1][ca - 1];
}

void solve(){
    cin >> n >> m >> mon;
    for (int i=1;i<=n;i++){
        int cur = 0;
        for (int j=1;j<=m;j++){
            cin >> ar[i][j];
            cur += ar[i][j];
            pre[i][j] = pre[i - 1][j] + cur;
        }
    }
    int ans = 0;
    for (int h=1;h<=n;h++){
        for (int i=1;i + h - 1<=n;i++){
            int le = 1;
            for (int ri=1;ri<=m;ri++){
                while (calc(i, le, i + h - 1, ri) > mon) le++;
                ans = max(ans, h * (ri - le + 1));
            }
        }
    }
    cout << ans << el;
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