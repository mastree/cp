#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 10;

int pre[N];
int sieve[N];

int q;
void solve(){
    int n;
    cin >> n;
    int gcc = __gcd(n, pre[n]);
    cout << pre[n] / gcc << "/" << n / gcc << el;
}
void init(){
    fill(sieve, sieve + N, 1);
    for (int i=2;i * i<N;i++){
        if (!sieve[i]) continue;
        for (int j=i * i;j<N;j+=i){
            sieve[j] = 0;
        }
    }
    fill(pre, pre + N, 1);
    for (int i=2;i<N;i++){
        if (sieve[i]) continue;
        for (int j=i + i;j<N;j+=i){
            pre[j] = 0;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    pre[0] = 0;
    for (int i=1;i<N;i++){
        // if (i <= 100 && pre[i]){
        //     cout << i << el;
        // }
        pre[i] += pre[i - 1];
    }
    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}