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

const int N = 3e2 + 10;

int n;
ll ar[N];
ll sumxor;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (i > 2) sumxor ^= ar[i];
    }
    ll a = ar[1], b = ar[2];
    if (sumxor > a + b){
        cout << -1 << el;
        return 0;
    }
    ll anb = (a + b - sumxor) / 2LL; // new a & b
    ll na = anb, nb = anb; // new a, new b
    if (na > a){
        cout << -1 << el;
        return 0;
    }
    for (ll i=50;i>=0;i--){
        ll bit = (1LL << i);
        if (sumxor & bit){
            if (na + bit < a) na += bit;
            else nb += bit;
        }
    }
    if (na == 0 || (na ^ nb) != sumxor || na + nb != a + b) cout << -1 << el;
    else cout << a - na << el;

    return 0;
}