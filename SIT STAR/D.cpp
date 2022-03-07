#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;

int n, a, b;
bool ar[N];
vector<pii> vec;
vector<pii> ansa;
vector<int> ansb;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    {
        char c;
        for (int i=1;i<=n;i++){
            cin >> c;
            ar[i] = (c == '1');
        }
        ar[n + 1] = 1;
    }
    {
        int bef = 1;
        int cnt = 0;
        for (int i=1;i<=n + 1;i++){
            if (ar[i] == bef){
                cnt++;
            } else{
                if (bef == 0){
                    vec.pb(mp(i - cnt, i - 1));
                }
                bef = ar[i];
                cnt = 1;
            }
        }
    }
    // a = large, b = small
    for (auto& x : vec){
        if (a == 0) break;
        while ((x.se - x.fi + 1) >= 2 && a){
            ansa.pb(mp(x.se - 1, x.se));
            x.se -= 2;
            a--;
        }
    }
    for (auto& x : vec){
        if (b == 0) break;
        while ((x.se - x.fi + 1) > 0 && b){
            ansb.pb(x.se);
            x.se--;
            b--;
        }
    }
    if (a || b){
        cout << "NO" << el;
        return 0;
    }
    cout << "YES" << el;
    for (auto x : ansa){
        cout << x.fi << " " << x.se << el;
    }
    for (auto x : ansb){
        cout << x << el;
    }

    return 0;
}