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

int n;
bool udh[N];
int ans = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        if (!udh[a]){
            ans++;
            udh[i] = 1;
        } else{
            udh[a] = 0;
            udh[i] = 1;
        }
    }
    cout << ans << el;

    return 0;
}