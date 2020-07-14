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

ll r, c;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    // ll ans = 0;
    ll item, putih;
    item = ((r + 1) / 2) * ((c + 1) / 2) + (r / 2) * (c / 2);
    putih = r * c - item;
    
    if (r == 1 || c == 1) cout << 1 << el;
    else cout << item << el;

    return 0;
}