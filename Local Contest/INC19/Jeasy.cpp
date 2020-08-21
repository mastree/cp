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
string s[17];
int len[17];
pair<string, int> dp[17][(1 << 15) + 10];
int pc[(1 << 15) + 10];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> s[i];
        len[i]=s[i].length();
    }

    for (int i=1;i<(1 << len[0]);i++){
        string tm="";
        for (int j=0;j<len[0];j++){
            if (i&(1 << j)) tm.pb(s[0][j]);
        }
        dp[0][i]=mp(tm,tm.length());
    }

    
    sort(dp[0]+1, dp[0]+(1 << len[0]));
    for (int i=1;i<(1 << len[0]);i++){
        pc[i]=max(pc[i-1],dp[0][i].se);
    }


    for (int i=1;i<n;i++){
    //    cout << pc[(1 << len[i-1])-1] << el;
        for (int j=1;j<(1 << len[i]);j++){
            string tm="";
            for (int k=0;k<len[i];k++){
                if (j&(1 << k)) tm.pb(s[i][k]);
            }
            int panjang = tm.length();
            //auto it = lower_bound(dp[i-1]+1,dp[i-1]+(1 << len[i-1]),mp(tm, -1));

            int low=1, high=(1 << len[i-1])-1;
            while (low<high){
                int mid=(low+high)/2;
                string smid=dp[i-1][mid].fi;

                if (smid<tm){
                    low=mid+1;
                } else{
                    high=mid;
                }
            }

        //    it--;
            if (dp[i-1][high].fi<tm) high++;
            int id = high-1;//(int)(it-dp[i-1]);
            if (pc[id]==0) dp[i][j]=mp(tm,0);
            else dp[i][j]=mp(tm,pc[id]+panjang);
        }

        sort(dp[i]+1, dp[i]+(1 << len[i]));
        for (int j=1;j<(1 << len[i]);j++){
            pc[j]=max(pc[j-1],dp[i][j].se);
        }
    }

    int ans=pc[(1 << len[n-1])-1];

    if (ans) cout << ans << el;
    else cout << -1 << el;

    return 0;
}