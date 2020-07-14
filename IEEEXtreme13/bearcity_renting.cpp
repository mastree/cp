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

const int N = 100007;

int n,m;
vector <pii> adl[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i=0;i<m;i++){
        int a, b, w;
        cin >> a >> b >> w;

        adl[a].pb(mp(w,b));
        adl[b].pb(mp(w,a));
    }

    for (int i=1;i<=n;i++){
        sort(adl[i].begin(),adl[i].end());
    }

    int ans=0;
    for (int i=1;i<=n;i++){
        if (adl[i].size() > 1){
            int cnt=0;
            for (auto x : adl[i]){
                if (x.fi==adl[i][0].fi) cnt++;
            }
            if (cnt>1) ans+=cnt;
        }
    }

    cout << n-ans << el;

    return 0;
}