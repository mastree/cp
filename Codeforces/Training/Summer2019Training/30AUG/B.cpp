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
        for (int i=0;i<n;i++) cin >> ar[i];

        int cnt=0,mn=MOD;
        for (int i=n-1;i>=0;i--){
            if (mn<ar[i]) cnt++;
            if (ar[i]<mn) mn=ar[i];
        }

        cout << cnt << el;
    }

    return 0;
}