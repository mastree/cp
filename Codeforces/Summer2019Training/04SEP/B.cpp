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

    ll ar[n],ganjil=0;
    ll ans=0;
    bool c0=0;

    for (int i=0;i<n;i++){
        cin >> ar[i];
        if (ar[i]==0) c0=1;
        if (ar[i]<0) ganjil++;
        ans+=abs(abs(ar[i])-1);
    }

    if (c0){
        cout << ans << el;
        return 0;
    }

    if (ganjil%2){
        cout << ans+2 << el;
    } else{
        cout << ans << el;
    }

    return 0;
}