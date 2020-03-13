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

ll n,m;

ll fast(ll a, ll b){
    if (b==0) return 1;

    ll tm=fast(a,b/2);
    tm=(tm*tm)%MOD;

    if (b&1){
        tm=(tm*a)%MOD;
    }

    return tm;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    ll tm=fast(2,m)-1;
    if (tm<0) tm+=MOD;

    cout << fast(tm,n) << el;

    return 0;
}