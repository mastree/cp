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

const int N = 1e5 + 10;
const double PI = acos(-1);

int n;
pair<long double, int> ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        ar[i] = mp(atan2((long double)a, (long double)b), i);
    }
    sort(ar + 1, ar + n + 1);
    long double closest = ar[1].fi - ar[n].fi + 2 * PI;
    pii ans = mp(ar[1].se, ar[n].se);
    for (int i=1;i<n;i++){
        if (ar[i + 1].fi - ar[i].fi < closest){
            closest = ar[i + 1].fi - ar[i].fi;
            ans = mp(ar[i].se, ar[i + 1].se);
        }
    }
    cout << ans.fi << " " << ans.se << el;

    return 0;
}