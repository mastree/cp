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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        ll n;
        cin >> n;
        vector <ll> ans;
        map <ll, bool> cek;

        for (ll i=1;i*i<=n;i++){
            ll tm = n/i;
            if (n/tm == i){
                ans.pb(i);
                cek[i]=1;
                if (!cek[tm]){
                    ans.pb(tm);
                    cek[tm]=1;
                }
            }
        }

        ans.pb(0);
        sort(ans.begin(), ans.end());
        cout << ans.size() << el;
        for (auto x : ans){
            cout << x << " ";
        }
        cout << el;
    }

    return 0;
}