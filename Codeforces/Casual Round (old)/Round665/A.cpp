#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int q;
int n, k;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> k;
        int ans = 0;
        if (n < k){
            ans += k - n;
            n = k;
        } else{
            if ((k & 1) != (n & 1)) ans++;
        }
        cout << ans << el;
    }

    return 0;
}