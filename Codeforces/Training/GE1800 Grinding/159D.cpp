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

const int N = 2e3 + 10;

string s;
bool pal[N][N];
int n;

ll le[N], ri[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();
    s = "*" + s;
    for (int len=1;len<=n;len++){
        if (len == 1){
            for (int i=1;i+len-1<=n;i++){
                pal[i][i+len-1] = 1;
            }
        } else if (len == 2){
            for (int i=1;i+len-1<=n;i++){
                pal[i][i+len-1] = (s[i] == s[i+len-1]);
            }
        } else{
            for (int i=1;i+len-1<=n;i++){
                int j = i+len-1;
                pal[i][j] = (pal[i+1][j-1] && s[i] == s[j]); 
            }
        }
    }

    ll ans = 0;
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            ll temp = (ll)pal[i][j];
            le[j] += temp;
            ri[i] += temp;
        }
    }

    for (int i=2;i<=n;i++){
        le[i] += le[i-1];
    }
    for (int i=n;i>1;i--){
        ans += ri[i] * le[i-1];
    }
    cout << ans << el;

    return 0;
}