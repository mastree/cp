#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int q;
int n;
ll p;
ll ar[N];

ll bates[N];

ll fpow(ll a, ll b){
    if (b == 0) return 1LL;
    ll temp = fpow(a, b / 2);
    temp = temp * temp % MOD;
    if (b & 1) temp = temp * a % MOD;
    return temp;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bates[1] = INF;
    for (ll i=2;i<N;i++){
        if (i > 1000){
            bates[i] = 2;
            continue;
        }
        ll temp = i;
        ll bat = 1;
        while (temp <= N){
            temp *= i;
            bat++;
        }
        bates[i] = bat;
    }

    cin >> q;
    while (q--){
        cin >> n >> p;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        sort(ar + 1, ar + n + 1, greater<ll>());
        ll last = ar[1];
        ll cnt = 1;
        ll ans1 = 0, ans2 = 0;
        ll lebih = 0;
        for (int i=2;i<=n;i++){
            if (ar[i] != last){
                ll temp = fpow(p, last);
                if (lebih == 0){
                    ll hh = cnt / 2;
                    for (int i=1;i<=hh;i++){
                        ans1 = (ans1 + temp) % MOD;
                        ans2 = (ans2 + temp) % MOD;
                    }
                    if (cnt & 1){
                        ans1 = (ans1 + temp) % MOD;
                        lebih++;
                    }
                } else{
                    if (lebih >= N){
                        for (int i=1;i<=cnt;i++){
                            ans2 = (ans2 + temp) % MOD;
                        }
                    } else{
                        while (cnt && lebih){
                            cnt--;
                            lebih--;
                            ans2 = (ans2 + temp) % MOD;
                        }
                        if (cnt){
                            ll hh = cnt / 2;
                            for (int i=1;i<=hh;i++){
                                ans1 = (ans1 + temp) % MOD;
                                ans2 = (ans2 + temp) % MOD;
                            }
                            if (cnt & 1){
                                ans1 = (ans1 + temp) % MOD;
                                lebih++;
                            }
                        }
                    }
                }

                if (lebih <= N && lebih){
                    ll pang = last - ar[i];
                    if (bates[p] <= pang){
                        lebih = N + 10;
                    } else{
                        lebih = lebih * fpow(p, pang);
                    }
                }
                cnt = 1;
                last = ar[i];
            } else{
                cnt++;
            }
        }
        ll temp = fpow(p, last);
        if (lebih == 0){
            ll hh = cnt / 2;
            for (int i=1;i<=hh;i++){
                ans1 = (ans1 + temp) % MOD;
                ans2 = (ans2 + temp) % MOD;
            }
            if (cnt & 1){
                ans1 = (ans1 + temp) % MOD;
                lebih++;
            }
        } else{
            if (lebih > N){
                for (int i=1;i<=cnt;i++){
                    ans2 = (ans2 + temp) % MOD;
                }
            } else{
                while (cnt && lebih){
                    cnt--;
                    lebih--;
                    ans2 = (ans2 + temp) % MOD;
                }
                if (cnt){
                    ll hh = cnt / 2;
                    for (int i=1;i<=hh;i++){
                        ans1 = (ans1 + temp) % MOD;
                        ans2 = (ans2 + temp) % MOD;
                    }
                    if (cnt & 1){
                        ans1 = (ans1 + temp) % MOD;
                        lebih++;
                    }
                }
            }
        }
        cout << (ans1 - ans2 + MOD) % MOD << el;
    }

    return 0;
}