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
const int INF = 2e9;

int n;
int ar[N];
unordered_map<int, ll> cnt;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int mn = INF, mx = -INF;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cnt[ar[i]]++;
        mn = min(mn, ar[i]);
        mx = max(mx, ar[i]);
    }
    ll ans;
    if (mn != mx) ans = cnt[mn] * cnt[mx];
    else{
        ans = cnt[mn];
        ans = ans * (ans - 1) / 2;
    }
    cout << mx - mn << " " << ans << el;

    return 0;
}