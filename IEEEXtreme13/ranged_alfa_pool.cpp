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

const int N = 1000107;

ll dp[N];
int n;

int main() {
    cin >> n;
    
    dp[0]=1;
    
    for (int i=1;i<N;i++){
        for (int j=1;j<20;j++){
            int id=i-(1 << j)+1;
            if (id>=0){
                dp[i]+=dp[id];
                dp[i]%=MOD;
            }
        }
    }
    
    dp[0]=1;
    for (int i=1;i<N;i++){
        dp[i]+=dp[i-1]+dp[i];
        dp[i]%=MOD;
    }
    
    while (n--){
        int a, b;
        cin >> a >> b;
        
        ll ans;
        if (a==0) ans = dp[b];
        else ans = dp[b]-dp[a-1];
        if (ans<MOD) ans+=MOD;
        ans%=MOD;
        cout << ans << el;
    }
        
    return 0;
}