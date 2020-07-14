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

const int N = 5e5 + 10;
const ll INF = 1e18;

int n, pos;
ll ar[N], pc[N], x;
ll mn_left[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    pos = (n + 1) / 2; 
    for (int i=1;i<=pos;i++){
        cin >> ar[i];
    }
    cin >> x;
    for (int i=pos;i>=1;i--){
        pc[i] = pc[i + 1] + ar[i];
    }
    for (int i=pos;i>=1;i--){
        pc[i] += x * ((ll)((n - pos) - (pos - i)));
    }
    mn_left[0] = INF;
    for (int i=1;i<=pos;i++){
        mn_left[i] = min(mn_left[i - 1], pc[i]);
    }
    int ans = n - pos;
    for (int i=pos;i>=1;i--){
        ans++;
        ll mn = mn_left[i];
        ll fac = (ll)(pos - i);
        // cout << i << " " << mn << " " << fac << el;
        if (mn + x * fac > 0){
            cout << ans << el;
            return 0;
        }
    }
    cout << -1 << el;

    return 0;
}