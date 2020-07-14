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

int n,m;
int ar[2100],b[2100];
int mk[2100][2100];
ll dp[2100][2100]; // n,m

int binser1(int awal,int tar){
    int low=awal,high=n;

    while (high>low){
        int mid=(low+high)/2;

        if (mk[awal][mid]>tar) high=mid-1;
        else low=mid;
    }

    return low;
}

int binser2(int awal,int tar){
    int low=awal,high=n;

    while (high>low){
        int mid=(low+high+1)/2;

        if (mk[awal][mid]>=tar) high=mid;
        else low=mid+1;
    }

    return low;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> ar[i];
    for (int i=1;i<=m;i++) cin >> b[i];
    
    for (int i=1;i<=n;i++){
        int curmax=0;
        for (int j=i;j<=n;j++){
            curmax=max(curmax,ar[j]);
            mk[i][j]=curmax;
        }
    }

    dp[0][0]=1;
    for (int j=1;j<=m;j++){
        for (int i=1;i<=n;i++){
            int a=binser2(i,b[j]),b=binser1(i,b[j]);

            dp[b][j]=(ll)(b-a+1);
        }
    }

    for (int j=1;j<=m;j++){
        for (int i=1;i<=n;i++){
            ll tm=dp[i][j];
            dp[i+tm][j]*=tm;
            dp[i+tm][j]%=MOD;
        }
    }

    ans=
    for (int i=1;i<=n;i++){

    }

    return 0;
}