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

    pii ar[n+1];
    int tot=0;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi;
        ar[i].se=i;
        tot+=ar[i].fi;
    }

 //   sort(ar+2,ar+n+1);
    vector <int> ans;
    int now=ar[1].fi;
    for (int i=2;i<=n;i++){
        if (ar[i].fi*2<=ar[1].fi){
            ans.pb(ar[i].se);
            now+=ar[i].fi;
        }
    }

    if (now*2<=tot){
        cout << 0 << el;
        return 0;
    }
    else{
        cout << ans.size()+1 << el;
        cout << "1 ";
        for (auto x : ans) cout << x << " ";
        cout << el;
    }

    return 0;
}