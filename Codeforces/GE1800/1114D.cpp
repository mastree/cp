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

const int N = 5e3 + 10;

int n;
vector <int> ar;
int dp[N][N];
// int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int bef;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        if (i == 1){
            bef = a;
        } else{
            if (a != bef){
                ar.pb(bef);
                bef = a;
            } 
        }
    }
    ar.pb(bef);
    n = ar.size();

    for (int i=1;i<=n;i++){
        for (int j=0;j+i<=n;j++){
            if (i == 1){
                continue;
            } 
            int l = j;
            int r = i + j -1;
            dp[l][r] = min(dp[l+1][r], dp[l][r-1]) + 1;
            if (ar[l] == ar[r]){
                dp[l][r] = min(dp[l][r], dp[l+1][r-1] + 1);
            }
        }
    }
    cout << dp[0][n-1] << el;

    return 0;
}