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

    int q;
    cin >> q;

    while (q--){
        int n;
        cin >> n;

        int ar[n];
        for (int i=0;i<n;i++){
            cin >> ar[i];
        }

        sort(ar,ar+n,greater<int>());
        int ans=min(ar[1]-1,n-2);

        cout << ans << el;
    }

    return 0;
}