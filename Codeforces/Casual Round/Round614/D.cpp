#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define pll pair<long long, long long>
#define ll long long
#define el '\n'

// typedef pair<ll, ll> pll;

using namespace std;

const ll INF = 1e18;

// ll x0, y0, ax, ay, bx, by;
pll awal, a, b, mul;
ll t;
pll ar[150];
ll pc[150];
int ans = 0;

ll jarak(pll in, pll out){
    return abs(in.fi - out.fi) + abs(in.se - out.se);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> awal.fi >> awal.se >> a.fi >> a.se >> b.fi >> b.se;
    cin >> mul.fi >> mul.se >> t;
    for (int i=0;i<150;i++){
        if (i==0){
            ar[i] = awal;
        } else if (((INF - b.fi) / a.fi > ar[i-1].fi) && ((INF - b.se) / a.se > ar[i-1].se)){
            ar[i] = mp(ar[i-1].fi * a.fi + b.fi, ar[i-1].se * a.se + b.se); 
        } else{
            ar[i] = mp(INF, INF);
        }
    }

    for (int i=1;i<150;i++){
        pc[i] = pc[i-1] + jarak(ar[i], ar[i-1]);
    }

    for (int i=0;i<150;i++){
        for (int start=0;start<=i;start++){
            ll temp = jarak(mul, ar[start]);
            if (temp > t) continue;
            // ll st;
            // if (i==0) st = 0;
            // else st = pc[i-1]; 
            if (temp + pc[i]-pc[start] <= t) ans = max(ans, i - start + 1);
        }
    }

    for (int i=0;i<150;i++){
        for (int start=149;start>=i;start--){
            ll temp = jarak(mul, ar[start]);
            if (temp > t) continue;
            // ll st;
            // if (i==0) st = 0;
            // else st = pc[i-1]; 
            if (temp + pc[start]-pc[i] <= t) ans = max(ans, start - i + 1);
        }
    }

    for (int start=0;start<150;start++){
        for (int last=start;last<150;last++){
            ll temp = pc[last] - pc[start];
            for (int mid=start;mid<=last;mid++){
                if (temp + jarak(mul, ar[mid]) + min(pc[mid] - pc[start], pc[last] - pc[mid]) <= t){
                    ans = max(ans, last - start + 1);
                }
            }
        }
    }
    cout << ans << el;

    return 0;
}