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

const ll INF = 1e18;
const int N = 2e4 + 4;

int q;
ll ar[3];

vector <ll> fac[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    for (int i=1;i<N;i++){
        for (int j=1;j*j<=i;j++){
            if (i % j == 0){
                int temp = i / j;
                fac[i].pb(j);
                if (temp != j) fac[i].pb(temp);
            }
        }
        sort(fac[i].begin(), fac[i].end());
    }

    // for (int i=1;i<10;i++){
    //     for (auto x : fac[i]){
    //         cout << x << " ";
    //     }
    //     cout << el;
    // }

    while (q--){
        for (int i=0;i<3;i++){
            cin >> ar[i];
        }

        ll mn = INF;
        ll ans[3];
        for (ll i=1;i<=20000;i++){
            for (ll j : fac[i]){
                ll k;
                if (ar[0] >= j){
                    k = j;
                } else{
                    auto ita = upper_bound(fac[j].begin(), fac[j].end(), ar[0]);
                    if (ita == fac[j].begin()){
                        k = (*ita);
                    } else{
                        auto itb = ita--;
                        if (abs((*ita) - ar[0]) < abs((*itb) - ar[0])){
                            k = (*ita);
                        } else{
                            k = (*itb);
                        }
                    }
                }

                ll tot = abs(i - ar[2]) + abs(j - ar[1]) + abs(k - ar[0]);
                if (tot < mn){
                    mn = tot;
                    ans[0] = k;
                    ans[1] = j;
                    ans[2] = i;
                }
            }
        }

        cout << mn << el;
        cout << ans[0] << " " << ans[1] << " " << ans[2] << el;
    }

    return 0;
}