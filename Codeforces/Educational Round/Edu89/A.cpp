#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

int q;
ll a, b;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (a * 2 < b){
            cout << a << el;
            continue;
        }
        ll kur = b - a;
        ll ans = kur;
        a -= kur;
        b = a;
        ans += (a / 3) * 2;
        a %= 3;
        if (a >= 2) ans++;
        cout << ans << el;
    }

    return 0;
}