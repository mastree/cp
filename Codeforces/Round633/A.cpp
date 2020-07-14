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

const int N = 1e5 + 10;
const ll INF = 1e12;

int q, n;
ll ar[N];

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

        ll mx = -INF;
        ll ans = 0;
        for (int i=1;i<=n;i++){
            if (i == 1){
                mx = ar[i];
                continue;
            }
            ans = max(ans, mx - ar[i]);
            mx = max(mx, ar[i]);
        }
        ll cur = 0;
        while (ans > 0){
            cur++;
            ans /= 2;
        }
        cout << cur << el;
    }

    return 0;
}