#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int LEN = 10;

ll l, r;
vector<ll> vec; // all lucky numbers

void generate_lucky(){
    for (int len=1;len<=LEN;len++){
        for (int mask=0;mask<(1 << len);mask++){
            ll num = 0;
            for (int i=len - 1;i>=0;i--){
                if (mask & (1 << i)){
                    num = num * 10 + 7;
                } else{
                    num = num * 10 + 4;
                }
            }
            vec.pb(num);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> l >> r;
    vec.pb(0);
    generate_lucky();
    ll ans = 0;
    int len = vec.size();
    for (int i=1;i<len;i++){
        if (vec[i] < l || r <= vec[i - 1]) continue;
        ans += vec[i] * (min(vec[i], r) - max(vec[i - 1], l - 1));
    }
    cout << ans << el;

    return 0;
}