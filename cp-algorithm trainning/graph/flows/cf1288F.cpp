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

const int N = 300;

int n[3], m, r, b;
int color[3][N]

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n[1] >> n[2] >> m >> r >> b;
    for (int i=1;i<=2;i++){
        string s;
        cin >> s;
        for (int j=1;j<=n[i];j++){
            int col;
            if (s[j - 1] == 'U') col = 0;
            else if (s[j - 1] == 'R') col = 1;
            else col = 2;
            color[i][j] = col;
        }
    }
    

    return 0;
}