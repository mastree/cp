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

int cnt[200005]={0};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    int ar[n];
    for (int i=0;i<n;i++){
        cin >> ar[i];
    }

    int ans=0;
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            cnt[ar[i]+ar[j]]++;
        }
    }
    for (int i=0;i<200005;i++) ans=max(ans,cnt[i]);

    cout << ans << el;

    return 0;
}