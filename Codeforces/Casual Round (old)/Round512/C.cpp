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

typedef pair<ll, ll> pll;

const int N = 2e5 + 10;

int n, q;
pll ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi;
    }
    for (int i=1;i<=n;i++){
        cin >> ar[i].se;
    }
    while (q--){
        ll x, y;
        cin >> x >> y;
        if (x < 0){
            x = -x;

        } else{
            
        }
    }

    return 0;
}