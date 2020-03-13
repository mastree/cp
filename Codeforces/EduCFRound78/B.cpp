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
// ll dif;

ll arit(ll a){
    return a*(a+1)/2;
}

ll binser(ll low, ll high, ll dif){
    while (low<high){
        ll mid = (low+high+1) / 2;

        ll tm = arit(mid);
        if (tm<=dif){
            low = mid;
        } else{
            high = mid-1;
        }
    }
    return low;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        ll a, b;
        cin >> a >> b;

        ll dif = abs(a-b);
        ll low = 0;
        ll high = 1e5;
        low = binser(low, high, dif);
        ll sisa;

        // cout << low << el;
        if (dif>arit(low)) low++;
        sisa = abs(dif-arit(low));
        if (sisa%2==0) cout << low << el;
        else {
            if (low%2==0){
                cout << low+1 << el;
            } else{
                cout << low+2 << el;
            }
        }
    }

    return 0;
}