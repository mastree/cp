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

const int N = 3e5 + 10;

int n;
pair<ll, ll> ar[N];
pair<ll, ll> cek[N];


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
    }

    bool bisa = 1;
    for (int i=1;i<=n;i++){
        if (i == n){
            cek[i].fi = ar[i].fi - ar[1].fi;
            cek[i].se = ar[i].se - ar[1].se;
            continue;
        }
        cek[i].fi = ar[i].fi - ar[i+1].fi;
        cek[i].se = ar[i].se - ar[i+1].se;
    }

    if (n&1){
        cout << "NO" << el;
        return 0;
    }
    for (int i=1;i<=n;i++){
        int j = i + n / 2;
        j %= n;
        if (j == 0) j = n;
        if (cek[i].fi * cek[j].se != cek[i].se * cek[j].fi || (cek[i].fi * cek[i].fi + cek[i].se * cek[i].se) != (cek[j].fi * cek[j].fi + cek[j].se * cek[j].se)){
            bisa = 0;
            break;
        }
    }
    if (bisa){
        cout << "YES" << el;
    } else{
        cout << "NO" << el;
    }

    return 0;
}