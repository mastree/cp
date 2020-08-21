#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

const int N = 1e5 + 10;

ld convert(const pii& a){
    return ((ld)a.se) / ((ld)a.fi);
}

bool comp(const pii& a, const pii& b){
    ld vala = convert(a);
    ld valb = convert(b);
    return vala > valb;
}

int n;
ld m;
int mtemp;
pii ar[N];

ld ans = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> mtemp;
    m = (ld)mtemp;

    for (int i=1;i<=n;i++){
        cin >> ar[i].fi;
    }
    for (int i=1;i<=n;i++){
        cin >> ar[i].se;
    }
    sort(ar + 1, ar + n + 1, &comp);
    for (int i=1;i<=n && m > 0.0;i++){
        cout << ar[i].fi << " " << ar[i].se << el;
        if (m <= (ld)ar[i].fi){
            ans += m * convert(ar[i]);
            break;
        } else{
            ans += (ld)ar[i].se;
            m -= (ld)ar[i].fi;
        }
    }
    cout << fixed << setprecision(11) << ans << el;

    return 0;
}