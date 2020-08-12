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
const int INF = 2e9 + 10;

int n, t;
int ar[N];

int bit[N];

void upd(int x, int add){
    x++;
    while (x < N){
        bit[x] += add;
        x = x + (x & (-x));
    }
}
int ask(int a){
    int ret = 0;
    a = min(a + 1, N - 2);
    while (a){
        ret += bit[a];
        a = a - (a & (-a));
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    int sur = t - n - 1;
    int last = n;
    if (sur < 0){
        last = t - 1;
        sur = 0;
    }
    for (int i=1;i<=last;i++){
        ar[i] = max(ar[i] - sur - i, 0);
        upd(ar[i], 1);

    }
    int ans = 0;
    int qq = 0;
    for (int i=last;i>=1;i--){
        int temp = ask(qq);
        ans = max(ans, temp);
        upd(ar[i], -1);
        qq++;
    }
    cout << ans << el;

    return 0;
}