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

const int N = 1e6 + 9;

int n, k, l;
int a, b;

int dp[N];
int cnt[2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> l;
    int jarak = n-1;
    // dp[1] = 1;
    for (int i=1;i<=min(k, l);i++){
        dp[i] = 1;
        cnt[1]++;
    }
    for (int i=k+1;i<=jarak;i++){
        if (cnt[0]){
            dp[i] = 1;
            cnt[1]++;
        } else{
            dp[i] = 0;
            cnt[0]++;
        }

        cnt[dp[i-l+1]]--;
    }
    for (int i=1;i<=jarak;i++){
        cout << dp[i] << " ";
    }
    cout << el;
    if (dp[jarak]){
        cout << "A" << el;
    } else{
        cout << "B" << el;
    }

    return 0;
}