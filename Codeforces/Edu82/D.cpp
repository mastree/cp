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

const int N = 1e5 + 10;

int q;
ll n, m;
ll ar[N];

ll cnt[61];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;
        fill(cnt, cnt + 61, 0);
        ll tot = 0;
        for (int i=1;i<=m;i++){
            cin >> ar[i];
            tot += ar[i];
            ll p = log2(ar[i]);
            cnt[p]++;
        }
        if (n > tot){
            cout << -1 << el;
            continue;
        } else if (n == tot){
            cout << 0 << el;
            continue;
        }

        ll ans = 0;
        for (ll i=0;i<61;i++){ 
            if (i != 0){
                cnt[i] += cnt[i-1] / 2;
            }
            ll bit = (1LL << i);
            if (bit & n){
                if (cnt[i]){
                    cnt[i]--;
                    continue;
                }

                ll j;
                for (j=i+1;j<61;j++){
                    if (cnt[j]) break;
                }
                if (j == 61){
                    ans = -1;
                    break;
                }

                for (ll temp = j-1; temp >= i; temp--){
                    cnt[temp]++;
                }
                cnt[j]--;
                ans += j - i;
            } else{
                continue;
            }
        }

        cout << ans << el;

    }

    return 0;
}