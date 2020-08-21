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

const int N = 2e5 + 9;

int q;
ll n, t, a, b;
pair<ll,ll> ar[N]; // ti, hard

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> t >> a >> b;

        map <ll, bool> cek;
        ll s0 = 0, s1 = 0;
        for (int i=1;i<=n;i++){
            cin >> ar[i].se;
            if (ar[i].se) s1++;
            else s0++;
        }
        for (int i=1;i<=n;i++){
            cin >> ar[i].fi;
            cek[ar[i].fi] = 1;
        }

        sort(ar + 1, ar + n + 1);
        ll ans = 0;
        ll id = 1;
        ll tot = 0;
        for (auto x : cek){
            ll ti = x.fi;

            // cout << ti << el;
            if (tot <= ti-1){
                ll kosong = (ti-1) - tot;
                ll plus = 0;

                if (kosong < s0 * a){
                    plus += kosong / a;
                } else{
                    plus += s0;
                    kosong -= s0 * a;
                    if (kosong < s1 * b){
                        plus += kosong / b;
                    } else{
                        plus += s1;
                    }
                }

                ans = max(ans, id-1 + plus);
            }
            while (ar[id].fi == ti){
                if (ar[id].se){
                    s1--;
                    tot += b;
                }
                else{
                    s0--;
                    tot += a;
                }
                // cout << id << "=> " << tot << el;
                id++;
                if (id==n+1) break;
            }
        }
        if (tot <= t){
            ans = id-1;
        }

        cout << ans << el;

    }

    return 0;
}