#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e3 + 10;

int n;
int pre[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        pre[a]++;
        pre[b + 1]--;
    }
    for (int i=1;i<N;i++){
        pre[i] += pre[i - 1];
    }
    bool ok = 1;
    for (int i=1;i<N;i++){
        pre[i] += pre[i - 1];
        if (pre[i] - pre[max(0, i - 180)] > 90){
            ok = 0;
            break;
        }
    }
    if (ok) cout << "YES" << el;
    else cout << "NO" << el;

    return 0;
}