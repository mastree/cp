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

const int N = 1e5 + 7;

int n;
int ar[4*N];
int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        vector <pii> v; // score, cnt;
        for (int i=0;i<n;i++){
            cin >> ar[i];
        }

        sort(ar, ar + n, greater<int>());
        int len = 0;
        for (int i=0;i<n;i++){
            if (len==0){
                v.pb(mp(ar[i],1));
                // cout << ar[i] << " ";
                len++;
                continue;
            }

            if (v[len-1].fi == ar[i]){
                v[len-1].se++;
            } else{
                // cout << ar[i] << " ";
                v.pb(mp(ar[i],1));
                len++;
            }
        }

        int ans[3]={0,0,0};
        int cur=0;
        if (len<3){
            cout << "0 0 0" << el;
            continue;
        }

        int picked=v[0].se+v[1].se;
        ans[0]=v[0].se;
        ans[1]=v[1].se;
        cur=1;
        // cout << "vector => ";
        // for (auto x : v){
        //     cout << x.se << " ";
        // } cout << el;
        for (int i=2;i<len;i++){
            if (cur==1){
                if (ans[1]>ans[0]){
                    cur=2;
                } else{
                    picked+=v[i].se;
                    ans[1]+=v[i].se;
                }
            }
            if (cur==2){
                if (picked+v[i].se<=n/2){
                    picked+=v[i].se;
                    ans[2]+=v[i].se;
                } else{
                    break;
                }
            }
            // cout << "cur : " << cur << " => " << v[i].se << el;
        }

        if (picked>n/2 || ans[2]==0 || (ans[0]>=ans[2] || ans[0]>=ans[1])){
            cout << "0 0 0" << el;
            continue;
        }

        for (int i=0;i<3;i++) cout << ans[i] << " ";
        cout << el;
    }

    return 0;
}