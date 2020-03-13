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

priority_queue<int,vector<int>,greater<int>> cnt[200005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin >> n >> k;

 //   int ar[n];
    for (int i=0;i<n;i++){
        int a,cur=0;
        cin >> a;
        cnt[a].push(0);
        //cerr << a << " " << cur << ", ";
        
        while (a){
            a/=2;
            cur++;
           // cerr << a << " " << cur << ", ";
            cnt[a].push(cur);
        }//cerr << el;
    }

    int ans=MOD+MOD;
    for (int i=0;i<200005;i++){
        if (cnt[i].empty()) continue;
        if (cnt[i].size()<k) continue;
       // cerr << i << el;

        int tm=0;
        for (int j=0;j<k;j++){
            tm+=cnt[i].top();
         //   int tmp=cnt[i].top();
            cnt[i].pop();
         //   cout << tmp << " ";
        }//cout << el;
        ans=min(ans,tm);
    }

    cout << ans << el;

    return 0;
}