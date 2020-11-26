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

int n, m;
int pos[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ans = 0;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        pos[a] = i;
    }
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        if (pos[a] > pos[b]) swap(a, b);
        int j1 = pos[b] - pos[a];
        int j2 = pos[a] - pos[b] + n;
        if (j1 % 2 == 0 || j2 % 2 == 0){
            ans++;
        }
    }
    cout << ans << el;

    return 0;
}