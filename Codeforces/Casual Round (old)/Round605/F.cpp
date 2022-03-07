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

const int N = 207;

string s, t;
int dp[N][N][N*4]; // i, j, surplus = used

int i, j, k;
char backt(){
    int ni, nj, nk;
    ni = i;
    nj = j;
    nk = k;

    nk--;
    if (nk>=0){
        if (dp[i][j][k] == dp[ni][nj][nk] + 1){
            i = ni;
            j = nj;
            k = nk;
            return '(';
        }
    }
    nk+=2;
    if (dp[i][j][k] == dp[ni][nj][nk] + 1){
        i = ni;
        j = nj;
        k = nk;
        return ')';
    }

    ni = i-1;nj = j;nk = k;
    if (s[i]=='(') nk--;
    else nk++;
    if (ni>=0 && nj>=0 && nk>=0){
        if (dp[i][j][k] == dp[ni][nj][nk] + 1){
            i = ni;
            j = nj;
            k = nk;
            return s[i+1];
        }
    }
    
    ni = i;nj = j-1;nk = k;
    if (t[j]=='(') nk--;
    else nk++;
    if (ni>=0 && nj>=0 && nk>=0){
        if (dp[i][j][k] == dp[ni][nj][nk] + 1){
            i = ni;
            j = nj;
            k = nk;
            return t[j+1];
        }
    }

    ni = i-1;nj = j-1;nk = k;
    if (s[i]=='(') nk--;
    else nk++;
    i = ni;
    j = nj;
    k = nk;
    return s[i+1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;

    int slen = s.length();
    int tlen = t.length();
    s = '*' + s;
    t = '*' + t;
    for (int i=0;i<=slen;i++){
        for (int j=0;j<=tlen;j++){
            for (int k=0;k<N*3;k++){
                dp[i][j][k] = MOD;
            }
        }
    }

    dp[0][0][0] = 0;
    for (int i=0;i<=slen;i++){
        for (int j=0;j<=tlen;j++){
            for (int k=0;k<N*3;k++){
                int ci, cj, ck;
                
                ci = i;cj = j;ck = k-1;
                if (ci>=0 && cj>=0 && ck>=0) dp[i][j][k] = min(dp[i][j][k], dp[ci][cj][ck] + 1);
                
                ci = i-1;cj = j;ck = k;
                if (s[i]=='(') ck--;
                else ck++;
                if (ci>=0 && cj>=0 && ck>=0){
                    dp[i][j][k] = min(dp[i][j][k], dp[ci][cj][ck] + 1);
                }
                
                ci = i;cj = j-1;ck = k;
                if (t[j]=='(') ck--;
                else ck++;
                if (ci>=0 && cj>=0 && ck>=0){
                    dp[i][j][k] = min(dp[i][j][k], dp[ci][cj][ck] + 1);
                }

                if (i>0 && j>0){
                    if (s[i]==t[j]){
                        ci = i-1;cj = j-1;ck = k;
                        if (s[i]=='(') ck--;
                        else ck++;
                        if (ck>=0){
                            dp[i][j][k] = min(dp[i][j][k], dp[ci][cj][ck] + 1);
                        }
                    }
                }
            }

            for (int k=N*3-2;k>=0;k--){
                dp[i][j][k] = min(dp[i][j][k], dp[i][j][k+1] + 1);
            }
        }
    }

    i = slen;
    j = tlen;
    k = 0;

    string ans = "";
    while (i!=0 || j !=0 || k!=0){
        ans.pb(backt());
    }

    reverse(ans.begin(), ans.end());
    cout << ans << el;

    return 0;
}