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
        vector<ll> v;
        for (int i=1;i<=n;i++){
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            ll a = 0;
            for (int j=0;j<m;j++){
                if (s[j] == '1'){
                    a += (1LL << j);
                }
            }
            v.pb(a);
        }
        ll low = 0, high = (1LL << m) - 1LL;
        ll tar = (high - n) / 2;
        while (low < high){
            ll mid = (low + high) / 2;
            ll cur = mid;

            for (auto x : v){
                if (x <= mid) cur--;
            }
            if (cur >= tar){
                high = mid;
            } else{
                low = mid + 1;
            }
        }
        string ans;
        for (int i=0;i<m;i++){
            if (high & (1LL << i)) ans.pb('1');
            else ans.pb('0');
        }
        reverse(ans.begin(), ans.end());
        cout << ans << el;
    }

    return 0;
}