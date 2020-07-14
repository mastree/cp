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

const int N = 21, M = 7, MAXX = 1e4 + 5;

int n, m;
int x, y, z;
int ar[N * M][4]; // pi, xi, yi, zi

pair<int, pii> dp[4][MAXX];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> x >> y >> z;
    int id = 1;
    for (int i=1;i<=n;i++){
        int temp[4];
        for (int j=0;j<4;j++){
            cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
        }
        for (int j=0;j<m;j++){  
            for (int k=0;k<4;k++) ar[id][k] = temp[k];
            id++;
        }
    }

    for (int item=1;item<=3;item++){
        for (int i=1;i<id;i++){
            
        }
    }

    return 0;
}