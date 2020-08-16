#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e5 + 10;

int n;
ll ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }   
    ll ans = 0;
    ll cur = 0;
    for (int i=1;i<=n;i++){
        cur += ar[i];
        ans = max(ans, -cur);
    }
    cout << ans << el;

    return 0;
}