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
    while (x > 0){
        bit[x] = max(bit[x], val);
        x = x - (x & (-x));
    }
}
int ask(int x){
    int ret = 0;
    while (x < N){
        ret = max(ret, bit[x]);
        x = x + (x & (-x));
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        int temp = ask(a + 1);
        upd(a, temp + 1);
    }
    int ans = ask(1);
    cout << ans << el;

    return 0;
}