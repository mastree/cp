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

    int d;
    cin >> d;

    

    for (int cas=1;cas<=d;cas++){
        int n,s;
        cin >> n >> s;
        int ans=-MOD;
        for (int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;

            if (b<=s) ans=max(ans,a);
            else ans=max(ans,a-(b-s));  
        }

        cout << "Case #" << cas << ": " << ans << el;
    }

    return 0;
}