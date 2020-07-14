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

const int N = 2e3 + 10;

int q;
int n;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        vector<int> od, ev;
        for (int i=1;i<=n + n;i++){
            cin >> ar[i];
            if (ar[i] & 1){
                od.pb(i);
            } else{
                ev.pb(i);
            }
        }
        int len = od.size();
        vector<pii> ans;
        for (int i=0;i<len - 1;i+=2){
            // cout << od[i] << " " << od[i + 1] << el;
            ans.pb(mp(od[i], od[i + 1]));
        }
        len = ev.size();
        for (int i=1;i<len - 1;i+=2){
            // cout << ev[i] << " " << ev[i + 1] << el;
            ans.pb(mp(ev[i], ev[i + 1]));
        }
        for (int i=0;i<n - 1;i++){
            cout << ans[i].fi << " " << ans[i].se << el; 
        }
    }    

    return 0;
}