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
ll cur;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cur ^= ar[i];
    }
    cur = ((cur ^ ar[1]) ^ ar[2]);
    ll ans = 0;
    for (ll i=0;i<50;i++){
        ll bit = (1LL << i);
        if ((cur & bit) != ((ar[1] & bit) ^ (ar[2] & bit))){
            ll j;
            ll temp = (1LL << (i + 1)) - 1LL;
            ll res = (cur & temp);
            ll a = ar[1], b = ar[2];
            for (j=0;j<50;j++){
                ll bit2 = (1LL << j);
                if (a < bit2){
                    j = 50;
                    break;
                }
                if (res == (((a - bit2) ^ (b + bit2)) & temp)) break;
            }
            if (j >= 50){
                cout << -1 << el;
                return 0;
            }
            ll tambah = (1LL << j);
            ans += tambah;
            ar[1] -= tambah;
            ar[2] += tambah;
        }
        for (ll j=50;j>=0;j--){
            ll bit2 = (1LL << j);
            if (bit2 > ans) continue;
            if (cur == ((ar[1] + bit2) ^ (ar[2] - bit2))){
                ans -= bit2;
                ar[1] += bit2;
                ar[2] -= bit2;
            }
        }
    }
    if (ar[1] == 0){
        cout << -1 << el;
        return 0;
    }
    cout << ans << el;

    return 0;
}