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
const int R = 1e6 + 10;

int n;
int _ton[2 * R];
int * ton = _ton + R;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int ay = R, by = -R;
        for (int j=0;j<6;j++){
            int a;
            cin >> a;
            if (j & 1){
                ay = min(ay, a);
                by = max(by, a);
            }
        }
        ton[ay]++;
        ton[by + 1]--;
    }
    int ans = 0;
    for (int i=-R + 3;i<R - 2;i++){
        ton[i] += ton[i - 1];
        ans = max(ans, ton[i]);
    }
    cout << ans << el;

    return 0;
}