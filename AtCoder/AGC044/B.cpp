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

const int N = 510;

int n;
pii out[N * N];
bool ar[N][N];
int dp[N][N];

pii get_koor(int a){
    int r = (a - 1) / n + 1;
    int c = (a - 1) % n + 1;
    return mp(r, c);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n * n;i++){
        int temp;
        cin >> temp;
        out[i] = get_koor(temp);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            ar[i][j] = 1;
        }
    }
    

    return 0;
}