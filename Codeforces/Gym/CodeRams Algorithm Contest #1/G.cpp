#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n;
int bit[N];

void upd(int x, int val){
    while (x < N){
        bit[x] += val;
        x += (x & (-x));
    }
}
int ask(int x){
    int ret = 0;
    while (x){
        ret += bit[x];
        x -= (x & (-x));
    }
    return ret;
}
int ask(int a, int b){
    return ask(b) - ask(a - 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<pii> vec; // deg, pos;
    for (int i=1;i<=n;i++){
        int temp;
        cin >> temp;
        int cur = 0;
        while ((temp & 1) == 0){
            cur++;
            temp >>= 1;
        }
        vec.pb(mp(cur, -i));
    }
    sort(vec.begin(), vec.end(), greater<pii>());
    ll ans = 0;
    for (auto& x : vec){
        int id = -x.se;
        ans += ask(id + 1, N - 1);
        upd(id, 1);
    }
    cout << ans << el;

    return 0;
}