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

int n;
ll x;
ll ar[2 * N];
ll pc[2 * N], pchug[2 * N];

ll hitung(ll a){
    return (a + 1) * a / 2LL;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=n + 1;i<=n + n;i++){
        ar[i] = ar[i - n];
    }
    n *= 2;
    for (int i=1;i<=n;i++){
        pc[i] = pc[i - 1] + ar[i];
        pchug[i] = pchug[i - 1] + hitung(ar[i]);
    }
    ll ans = 0;
    for (int i=n / 2 + 1;i<=n;i++){
        int low = i - n / 2 + 1, high = i;
        while (low < high){
            int mid = (low + high) / 2;
            if (pc[i] - pc[mid - 1] <= x){
                high = mid;
            } else{
                low = mid + 1;
            }
        }
        if (low == i && ar[i] > x){
            ans = max(ans, hitung(ar[i]) - hitung(ar[i] - x));
            continue;
        }
        ll sisa = x - (pc[i] - pc[low - 1]);
        ans = max(ans, pchug[i] - pchug[low - 1] + hitung(ar[low - 1]) - hitung(ar[low - 1] - sisa));
    }
    cout << ans << el;

    return 0;
}