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

ll pow2[15];
ll dp[(1 << 15)][4];
bool udh[(1 << 15)][4];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (ll i=0;i<15;i++) pow2[i]=((ll)1 << i);

    int n,t;
    cin >> n >> t;

    pii ar[n];
    for (int i=0;i<n;i++){
        cin >> ar[i].fi >> ar[i].se;
    }


    queue <pii> qu; // bitmask,last-genre
    for (int i=0;i<n;i++){
        dp[pow2[i]][ar[i].se]=1;
        qu.push(mp(pow2[i],ar[i].se));
    }

    while (!qu.empty()){
        int bit=qu.front().fi,gen=qu.front().se;
        qu.pop();

        for (int i=0;i<n;i++){
            int tm=(bit|pow2[i]);
            if (tm>bit && gen!=ar[i].se){
                dp[tm][ar[i].se]=(dp[tm][ar[i].se]+dp[bit][gen])%MOD;
                if (!udh[tm][ar[i].se]){
                    qu.push(mp(tm,ar[i].se));
                    udh[tm][ar[i].se]=1;
                }
            }
        }
    }

    ll tot=0;
    for (int i=0;i<(1<<15);i++){
        for (int j=1;j<=3;j++){
            int time=0;
            for (int p=0;p<15;p++){
                if ((i&pow2[p])>0) time+=ar[p].fi;
            }
            if (time==t){
                tot=(tot+dp[i][j])%MOD;
            }
        }
    }

    cout << tot << el;

    return 0;
}