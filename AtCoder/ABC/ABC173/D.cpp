#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int n;
ll ar[N];
ll ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1, greater<ll>());
    int sisa = n;
    for (int i=1;i<=n;i++){
        if (sisa){
            sisa--;
            ans += ar[i];
            if (sisa){
                sisa--;
                ans += ar[i];
            }
        }
        if (!sisa) break;
    }
    cout << ans - ar[1] << el;

    return 0;
}