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

ll a, b;
ll cnt[61];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    if (a == b && a == 0){
        cout << 0 << el;
        return 0;
    }

    bool bisa = 1;
    swap(a, b);

    ll cur = 0;
    ll last = 61;
    for (ll i=60;i>=0;i--){
        ll bit = (1LL << i);
        if (a & bit){
            cur++;
        }
        // if (i < 10) cout << cur << " ";
        if (b & bit){
            // cout << "ya ";
            if (cur == 0){
                if (last == 61){
                    bisa = 0;
                    break;
                } 
                // cnt[last]--;
                // cur = (1LL << (last - i));
                ll temp = 0;
                while (last > i){
                    // if (b & (1LL << last)){
                    if (cnt[last] <= 1){
                        bisa = 0;
                        break;
                    }
                    temp = 2;
                    cnt[last]-=2;
                    last--;
                    cnt[last] += temp * 2;
                }
                cur = cnt[last];
                cnt[last] = 0;
            }
            if (cur & 1){
                cnt[i] += cur;
                cur = 0;
                last = i;
            } else if (cur){
                cnt[i] += cur - 1;
                cur = 1;
                last = i;
            } else {
                bisa = 0;
                break;
            }
        } else{
            if (cur % 2 == 0){
                cnt[i] += cur;
                if (cur) last = i;
                cur = 0;
            } else{
                cnt[i] += cur - 1;
                cur = 1;
                last = i;
            }
        }
        cur = cur * 2;
    }
    // cout << el;
    if (cur > 0) bisa = 0;

    if (!bisa){
        cout << -1 << el;
        return 0;
    }
    for (int i=0;i<=4000;i++){
        for (int j=60;j>0;j--){
            if (cnt[j] >= 2 && cnt[j - 1] + 4 <= cnt[j]){
                cnt[j - 1] += 4;
                cnt[j] -= 2;
            }
        }
    }
    for (int i=0;i<=4000;i++){
        for (int j=0;j<60;j++){
            if (cnt[j] >= 4 && cnt[j + 1] + 2 <= cnt[j]){
                cnt[j + 1] += 2;
                cnt[j] -= 4;
            }
        }
    }
    // for (int i=9;i>=0;i--){
    //     cout << cnt[i] << " ";
    // }
    // cout << el;

    vector <ll> ans;
    ll tot = 0;
    for (ll i=0;i<=60;i++){
        if (cnt[i]){
            tot += (1LL << i);
            cnt[i]--;
        }
    }
    while (tot){
        ans.pb(tot);
        tot = 0;
        for (ll i=0;i<=60;i++){
            if (cnt[i]){
                tot += (1LL << i);
                cnt[i]--;
            }
        }
    }
    cout << ans.size() << el;
    for (auto x : ans){
        cout << x << " ";
    }
    cout << el;

    return 0;
}