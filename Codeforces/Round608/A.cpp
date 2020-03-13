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

ll a, b, c, d;
ll e, f;

ll tot=0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c >> d;
    cin >> e >> f;

    for (ll i=0;i<=d;i++){
        tot=max(tot,min(i,a)*e + min(d-i, min(b,c))*f);
    }

    cout << tot << el;

    return 0;
}