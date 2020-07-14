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

const ll MX = 1e6 + 10;

int q;
ll h, c, t;

long double hitung(ll a){
    ll b = a + 1;
    return ((long double)b * h + (long double)a * c) / (long double)(a + b);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> h >> c >> t;
        ll avg = (h + c) / 2;
        ll diff = h - c;
        ll post = t - c;
        if (t >= h){
            cout << 1 << el;
            continue;
        } else if (t <= avg){
            cout << 2 << el;
            continue;
        }
        ll cold = diff - post;
        ll hot = post;
        ll satu = hot - cold;
        ll b = cold / satu;
        if (abs(hitung(b) - (long double)t) < abs(hitung(b + 1) - (long double)t)){
            cout << b * 2 + 1 << el;
        } else{
            cout << b * 2 + 3 << el;
        }
    }

    return 0;
}