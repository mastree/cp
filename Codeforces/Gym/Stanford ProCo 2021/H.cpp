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
const int INF = 1e9;

int n;
int ar[N];
int tar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        cin >> tar[i];
    }
    sort(ar + 1, ar + n + 1);
    sort(tar + 1, tar + n + 1);
    tar[n + 1] = INF;
    int last = 1;
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (ar[i] > tar[last]){
            ans++;
            last++;
        }
    }
    cout << ans << el;

    return 0;
}