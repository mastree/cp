#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int n, k;
int cnt0;
vector<ll> pos, neg;

ll hitung(const vector<ll>& v){
    ll ret = 1;
    for (auto x : v){
        ret = ret * (x + MOD) % MOD;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        ll a;
        cin >> a;
        if (a == 0){
            cnt0++;
            continue;
        }
        if (a > 0){
            pos.pb(a);
        } else{
            neg.pb(a);
        }
    }
    if (n - cnt0 < k){
        cout << 0 << el;
        return 0;
    } else if (n - cnt0 == k && (((int)neg.size()) & 1)){
        if (cnt0) cout << 0 << el;
        else{
            for (auto x : neg){
                pos.pb(x);
            }
            cout << hitung(pos) << el;
        }
        return 0;
    }
    // while ((int)pos.size() + (int)neg.size() < k){
    //     cnt0--;
    //     pos.pb(0);
    // }
    if ((int)pos.size() < k){
        sort(neg.begin(), neg.end(), greater<ll>());
        sort(pos.begin(), pos.end(), greater<ll>());

        vector<ll> temp;
        while ((int)pos.size() + (int)temp.size() < k){
            int len = (int)pos.size() + (int)temp.size();
            if (k - len >= 2){
                temp.pb(neg.back());
                neg.pop_back();
                temp.pb(neg.back());
                neg.pop_back();
            } else{
                if (pos.size()){
                    pos.pop_back();
                    temp.pb(neg.back());
                    neg.pop_back();
                    temp.pb(neg.back());
                    neg.pop_back();
                } else{
                    if (cnt0){
                        cout << 0 << el;
                        return 0;
                    } else{
                        while ((int)neg.size() < k){
                            neg.pb(temp.back());
                            temp.pop_back();
                        }
                        while ((int)neg.size() > k) neg.pop_back();
                        cout << hitung(neg) << el;
                        return 0;
                    }
                    return 0;
                }

            }
        }
        while (1){
            if (neg.size() < 2 || pos.size() < 2) break;

            int lneg = neg.size();
            int lpos = pos.size();

            if (neg[lneg - 1] * neg[lneg - 2] > pos[lpos - 1] * pos[lpos - 2]){
                pos.pop_back();
                pos.pop_back();
                temp.pb(neg.back());
                neg.pop_back();
                temp.pb(neg.back());
                neg.pop_back();
            } else break;
        }
        for (auto x : temp) pos.pb(x);
        cout << hitung(pos) << el;
        return 0;
    } else{
        sort(pos.begin(), pos.end(), greater<ll>());
        sort(neg.begin(), neg.end(), greater<ll>());
        while ((int)pos.size() > k){
            pos.pop_back();
        }

        vector<ll> temp;
        while (1){
            if (neg.size() < 2 || pos.size() < 2) break;

            int lneg = neg.size();
            int lpos = pos.size();

            if (neg[lneg - 1] * neg[lneg - 2] > pos[lpos - 1] * pos[lpos - 2]){
                pos.pop_back();
                pos.pop_back();
                temp.pb(neg.back());
                neg.pop_back();
                temp.pb(neg.back());
                neg.pop_back();
            } else break;
        }
        for (auto x : temp) pos.pb(x);
        cout << hitung(pos) << el;
        return 0;
    }


    return 0;
}