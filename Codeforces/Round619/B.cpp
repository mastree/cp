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
const ll INF = 1e18;

int q;
int n;
ll ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        vector <ll> v;
        ar[0] = -1;
        ar[n+1] = -1;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        for (int i=1;i<=n;i++){
            if (ar[i] == -1){
                if (ar[i-1] != -1){
                    v.pb(ar[i-1]);
                }
                if (ar[i+1] != -1){
                    v.pb(ar[i+1]);
                }
            }
        }
        int len = v.size();
        ll baru = 0;
        if (len){
            sort(v.begin(), v.end());
            baru = (v[0] + v[len - 1]) / 2;
            for (int i=1;i<=n;i++){
                if (ar[i] == -1) ar[i] = baru;
            }
        } 
        ll ans = 0;
        for (int i=1;i<n;i++){
            ans = max(ans, abs(ar[i+1] - ar[i]));
        }
        cout << ans << " " << baru << el;
    }

    return 0;
}