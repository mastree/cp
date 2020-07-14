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
ll xa, ya, xb, yb;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> xa >> ya >> xb >> yb;

        if (xa == xb || ya == yb){
            cout << 1 << el;
            continue;
        }
        ll lv = xb - xa;
        cout << lv * (yb - ya) + 1LL << el;
    }

    return 0;
}