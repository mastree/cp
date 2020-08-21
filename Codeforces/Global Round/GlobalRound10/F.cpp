#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e6 + 10;
const ll INF = 1e18;

int n;
ll ar[N];
ll ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ll mn = INF, tot = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        tot += ar[i];
        mn = min(mn, ar[i] - i + 1);
    }   
    for (int i=1;i<=n;i++){
        ans[i] = mn + i - 1;
        tot -= ans[i];
    }
    ll base = tot / n;
    tot %= n;
    for (int i=1;i<=n;i++){
        ans[i] += base;
    }
    for (int i=1;i<=tot;i++){
        ans[i]++;
    }
    for (int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << el;

    return 0;
}