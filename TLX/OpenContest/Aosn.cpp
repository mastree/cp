#include <bits/stdc++.h>

#define ppii pair<pii,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'


using namespace std;

ppii ar[200009];
int dp[200009],tonds[200009]; // Tony's ds

int ans[200009];

bool cmp(ppii a, ppii b){
    return a.fi<b.fi;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    for (int i=0;i<n;i++){
        cin >> ar[i].fi.fi >> ar[i].fi.se;
        ar[i].se=i;
    }

    sort(ar,ar+n,cmp);

    for (int i=0;i<n;i++){
        int b=ar[i].fi.se;
        
        int low=i,high=n-1,best=-1;
        while (low<=high){
            int mid=(low+high)/2;

            if (ar[mid].fi.fi<=b){
                best=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        if (best==-1) continue;
        dp[i]=best-i;
        tonds[i+1]++;
        tonds[best+1]--;
    }

    int cur=0;
    for (int i=0;i<n;i++){
        cur+=tonds[i];
        dp[i]+=cur;
    }

    for (int i=0;i<n;i++){
        ans[ar[i].se]=dp[i];
    }

    for (int i=0;i<n;i++) cout << ans[i] << el;

    return 0;
}