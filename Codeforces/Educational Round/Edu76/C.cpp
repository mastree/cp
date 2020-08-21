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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while (q--){
        int n;
        cin >> n;

        vector <int> v;
        bool cek[n+5], bisa=0;
        int last[n+5];
        int ans=MOD;
        for (int i=0;i<n+5;i++){
            cek[i] = 0;
            last[i] = -MOD;
        }

        for (int i=0;i<n;i++){
            int a;
            cin >> a;
            v.pb(a);
            if (cek[a]) bisa=1; 
            cek[a]=1;

            ans = min(ans, i - last[a]);
            last[a] = i;
        }

        if (bisa){
            cout << ans+1 << el;
        } else{
            cout << -1 << el;
        }
    }

    return 0;
}