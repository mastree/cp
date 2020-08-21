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

const int N = 2e5 + 10;
const ll INF = 1e18;

int q;
int n;
ll ar[N];
ll pre[2][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        for (int i=1;i<=n;i++){
            pre[0][i] = pre[0][i - 1];
            pre[1][i] = pre[1][i - 1];
            pre[i & 1][i] += ar[i];
        }
        ll base = pre[1][n], ans = base;
        ll mnod = 0, mnev = 0;
        for (int i=1;i<=n;i++){
            if (i == 1) continue;
            ll temp = pre[0][i] - pre[1][i];
            if (i & 1){
                temp += ar[1];
                mnod = min(mnod, temp);
                ans = max(ans, base + (temp - mnod));
            } else{
                mnev = min(mnev, temp);
                ans = max(ans, base + (temp - mnev));
            }
        }
        cout << ans << el;
    }

    return 0;
}