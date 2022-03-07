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
string s;
vector<int> pos;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s;
    pos.pb(0);
    for (int i=1;i<=n;i++){
        if (s[i - 1] == 'b'){
            pos.pb(i);
        }
    }
    pos.pb(n + 1);
    int ans = 0;
    int len = pos.size();
    for (int i=0;i<len - 1;i++){
        int a = pos[i] + 1;
        int b = pos[i + 1] - 1;
        bool bisa = 0;
        for (int j=a;j<=b;j++){
            if (s[j - 1] == 'a') bisa = 1;
        }
        if (bisa) ans += b - a + 1;
    }
    cout << ans << el;

    return 0;
}