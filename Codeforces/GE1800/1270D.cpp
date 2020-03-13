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

int n, k;
map <int, int> cek, elmt;
int tot;
vector <pii> ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=k+1;i++){
        cout << "? ";
        for (int j=1;j<=k+1;j++){
            if (j == i) continue;
            cout << j << " ";
        }
        cout << el << flush;
        int a, b;
        cin >> a >> b;
        // cout << a << " " << b << el;
        cek[a]++;
        elmt[a] = b;
    }
    if (k == 1){
        cout << "! 1" << endl;
        return 0;   
    }

    for (auto x : cek){
        ans.pb(mp(x.se, elmt[x.fi]));
    }
    sort(ans.begin(), ans.end(), greater<pii>());
    if (ans[0].se < ans[1].se) tot = ans[1].fi;
    else tot = ans[0].fi;

    cout << "! " << tot << endl;

    return 0;
}