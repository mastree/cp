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

int q;
int n, k;
ll ar[N];
int w[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> k;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        sort(ar + 1, ar + n + 1);
        for (int i=1;i<=k;i++){
            cin >> w[i];
        }
        sort(w + 1, w + k + 1, greater<int>());
        ll ans = 0;
        int last = 1;
        int ii;
        for (ii=k;ii>0;ii--){
            if (w[ii] == 1){
                ans += ar[n] + ar[n];
                n--;
            } else if (w[ii] == 2){
                ans += ar[n] + ar[n - 1];
                n -= 2;
            } else{
                break;
            }
        }
        k = ii;
        for (int i=1;i<=k;i++){
            ll mn = MOD, mx = ar[n--];
            for (int j=last;j<last + w[i] - 1;j++){
                mn = min(mn, ar[j]);
            }
            last += w[i] - 1;
            ans += mn + mx;
        }
        cout << ans << el;
    }

    return 0;
}