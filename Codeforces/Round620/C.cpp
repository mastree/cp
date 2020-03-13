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

const int N = 110;

int q;
ll n, m;
pair<ll, pair<ll, ll>> ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;
        for (int i=1;i<=n;i++){
            cin >> ar[i].fi >> ar[i].se.fi >> ar[i].se.se;
        }

        bool bisa = 1;
        ll low = m, high = m;
        ll tnow = 0;
        for (int i=1;i<=n;i++){
            ll t = ar[i].fi;
            ll del = t - tnow;
            auto range = ar[i].se;

            if (high < range.fi){
                // cout << "tes" << el;
                if (range.fi - high > del){
                    bisa = 0;
                    break;
                } 
                high = min(range.se, high + del);
                low = range.fi;
            } else if (low > range.se){
                // cout << "tes1" << el;
                if (low - range.se > del){
                    bisa = 0;
                    break;
                } 
                low = max(range.fi, low - del);
                high = range.se;
            } else{
                // cout << "tes2" << el;
                if (low <= range.fi){
                    low = range.fi;
                }
                if (high >= range.se){
                    high = range.se;
                }
                low = max(range.fi, low - del);
                high = min(range.se, high + del);
            }
            // cout << low << " " << high << el;
            tnow = t;
        }
        
        if (bisa){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}