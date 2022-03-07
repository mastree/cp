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

int q;
int n, k, z;
int ar[2 * N];
int pre[2 * N];

void solve(){
    cin >> n >> k >> z;
    
    fill(ar, ar + 2 * n + 1, 0);
    fill(pre, pre + 2 * n + 1, 0);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        pre[i] = pre[i - 1] + ar[i];
    }
    
    int ans = 0;
    int tot = ar[1];
    for (int i=2;i<=min(n, k + 1);i++){
        tot += ar[i];
        int sisa = k + 1 - i;
        int tam = 0;
        int curz = z;
        if (sisa / 2 >= curz){
            tam += (ar[i - 1] + ar[i]) * curz;
            sisa -= curz * 2;
            tam += pre[i + sisa] - pre[i];
        } else{
            tam += (ar[i - 1] + ar[i]) * (sisa / 2);
            sisa %= 2;
            if (curz && sisa){
                tam += max(ar[i - 1], ar[i + 1]);
            }
        }

        ans = max(ans, tot + tam);
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