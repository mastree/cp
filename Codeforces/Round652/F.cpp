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

const int N = 1e6 + 10;

int q;
int n;
ll ar[N], br[N], pre[4 * N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        bool ok = 1;
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            pre[i + i] = -ar[i];
        }
        for (int i=1;i<=n;i++){
            cin >> br[i];
            int id = (i + i) % (n + n) + 1;
            pre[id] = br[i];
        }
        n = n + n;
        for (int i=1;i<=n;i++){
            pre[n + i] = pre[i];
        }
        for (int i=1;i<=n + n;i++){
            pre[i] = pre[i] + pre[i - 1];
        }
        if (pre[n] < 0){
            cout << "NO" << el;
            continue;
        }
        ll mx = 0;
        for (int i=0;i<=n + n;i++){
            if (i & 1){
                if (pre[i] - mx < 0){
                    ok = 0;
                    break;
                }
            } else{
                mx = max(mx, pre[i]);
            }
        }
        if (ok) cout << "YES" << el;
        else cout << "NO" << el;
    }

    return 0;
} 