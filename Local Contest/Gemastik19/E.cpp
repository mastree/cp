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
pii ar[10005];
int ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i=0;i<n;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int tm1=abs(a-c);
        int tm2=abs(b-d);

        ar[i]=mp(min(tm1,tm2),max(tm1,tm2));
    }

    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (ar[i].fi <= ar[j].fi && ar[i].se <= ar[j].se) ans++;
            else if (ar[i].se <= ar[j].fi && ar[i].fi <= ar[j].se) ans++;
            else if (ar[j].fi <= ar[i].fi && ar[j].se <= ar[i].se) ans++;
            else if (ar[j].se <= ar[i].fi && ar[j].fi <= ar[i].se) ans++;
        }
    }

    cout << n*(n-1)/2-ans << el;


    return 0;
}