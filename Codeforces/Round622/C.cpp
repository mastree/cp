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

int n;
ll ar[N];

ll mn[N][20];
ll le[N], ri[N];

ll minRange(ll a, ll b){
    ll res = INF;

    ll cur = a;
    for (ll i=19;i>=0;i--){
        if (cur + (1 << i) - 1 <= b){
            res = min(res, mn[cur][i]);
            cur += (1 << i);
        }
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    mn[0][0] = 0;
    mn[n+1][0] = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        mn[i][0] = ar[i];
    }

    for (int j=1;j<20;j++){
        for (int i=0;i<=n+1;i++){
            if (i + (1 << j) - 1 < N) mn[i][j] = min(mn[i][j-1], mn[i + (1 << (j - 1))][j-1]);
        }
    }

    le[1] = ar[1];
    for (ll i=2;i<=n;i++){
        ll low = 0, high = i-1;

        while (low < high){
            ll mid = (low + high + 1) / 2;
            if (minRange(mid, i-1) <= ar[i]){
                low = mid;
            } else{
                high = mid - 1;
            }
        }

        le[i] = (i - low) * ar[i] + le[low];
    }

    ri[n] = ar[n];
    for (ll i=n-1;i>=1;i--){
        ll low = i+1, high = n+1;

        while (low < high){
            ll mid = (low + high) / 2;
            if (minRange(i+1, mid) <= ar[i]){
                high = mid;
            } else{
                low = mid + 1;
            }
        }

        ri[i] = (high - i) * ar[i] + ri[high];
    }

    ll ans = -1, pos = -1;;
    for (int i=1;i<=n;i++){
        if (le[i] + ri[i] - ar[i] > ans){
            ans = le[i] + ri[i] - ar[i];
            pos = i;
        }
    }

    for (int i=pos+1;i<=n;i++){
        ar[i] = min(ar[i], ar[i-1]);
    }
    for (int i=pos-1;i>0;i--){
        ar[i] = min(ar[i], ar[i+1]);
    }
    for (int i=1;i<=n;i++){
        cout << ar[i] << " ";
    }
    cout << el;

    return 0;
}