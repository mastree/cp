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

const int N = 5e5 + 10;

int n;
ll ar[N];

priority_queue <pair<pli, pii>> pq;
pii leri[N];

ll ans = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    ar[n+1] = 0;

    for (int i=1;i<=n;i++){
        pair<pli, pii> tm;
        tm.fi = mp(min(ar[i-1], ar[i+1]), i);
        tm.se = mp(i-1, i+1);
        leri[i] = mp(i-1, i+1);

        pq.push(tm);
    }

    while (!pq.empty()){
        auto x = pq.top();

        if (x.se != leri[x.fi.se]){
            x.se = leri[x.fi.se];
            x.fi.fi = min(ar[leri[x.fi.se].fi], ar[leri[x.fi.se].se]);
            pq.pop();
            pq.push(x);
            continue;
        }

        ans+=x.fi.fi;
        pq.pop();
        // cout << x.fi.se << " => " << x.se.fi << " => " << x.se.se << el;

        leri[x.se.fi].se = x.se.se;
        leri[x.se.se].fi = x.se.fi;
    }

    cout << ans << el;

    return 0;
}