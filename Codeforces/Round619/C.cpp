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

int q;
ll n, m;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;
        ll kosong = n - m;
        ll ans = n * (n-1) / 2;
        ans += n;
        ll part = (n - m) / (m + 1);
        ll sisa = (n - m) % (m + 1);
        ans -= (part * (part - 1) / 2 + part) * (m + 1 - sisa);
        ans -= (part * (part + 1) / 2 + part + 1) * (sisa);
        cout << ans << el;
    }

    return 0;
}