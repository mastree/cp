#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define pll pair<long long, long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e5 + 4;

int n, m;
vector <pil> v[N*3];
pll ino[N]; // in-out
priority_queue<pli, vector<pli>, greater<pli>> in, out;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<m;i++){
        ll a, b, w;
        cin >> a >> b >> w;

        if (a==b) continue;
        ino[a].se+=w;
        ino[b].fi+=w;
    }

    for (int i=1;i<=n;i++){
        ll a = ino[i].fi;
        ll b = ino[i].se;

        ino[i].fi = max(a-b, (ll)0);
        ino[i].se = max(b-a, (ll)0);
    }

    for (int i=1;i<=n;i++){
        if (ino[i].fi){
            in.push(mp(ino[i].fi, i));
        }

        if (ino[i].se){
            out.push(mp(ino[i].se, i));
        }
    }

    while (!in.empty()){
        auto a = in.top(), b = out.top();
        in.pop();
        out.pop();

        ll c = min(a.fi, b.fi);
        a.fi-=c;
        b.fi-=c;
        v[b.se].pb(mp(a.se, c));

        if (a.fi){
            in.push(a);
        } 
        if (b.fi){
            out.push(b);
        }
    }

    int sz=0;
    for (int i=1;i<=n;i++){
        for (auto x : v[i]){
            sz++;
            // cout << i << " " << x.fi << " " << x.se << el;
        }
    }   

    cout << sz << el;
    for (int i=1;i<=n;i++){
        for (auto x : v[i]){
            // sz++;
            cout << i << " " << x.fi << " " << x.se << el;
        }
    }

    return 0;
}