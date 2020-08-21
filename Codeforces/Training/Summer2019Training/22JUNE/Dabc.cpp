#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    pair<ll,ll> ar[n];  // dedline,worktime;
    for (int i=0;i<n;i++){
        cin >> ar[i].se >> ar[i].fi;
    }

    sort(ar,ar+n);
    ll tot=0;
    for (int i=0;i<n;i++){
        tot+=ar[i].se;
        if (tot<=ar[i].fi) continue;

        cout << "No" << el;
        return 0;
    }

    cout << "Yes" << el;

    return 0;
}