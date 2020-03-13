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

int n;
vector <pii> point;
ll ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        point.pb(mp(a,b));
    }

    for (int i=0;i<n-2;i++){
        ll cnt=0;
        map <pii, ll> cek;
        for (int j=i+1;j<n;j++){
            int a=point[j].fi-point[i].fi, b=point[j].se-point[i].se;
            if (a==0 && b==0) continue;
            cnt++;
            int gcc=__gcd(a,b);
            a/=gcc;
            b/=gcc;
            cek[mp(a,b)]++;
        }
        ans+=((cnt-1)*cnt)/2;

        for (auto x : cek){
            ans-=((x.se-1)*x.se)/2;
        }
    }

    cout << ans << el;

    return 0;
}