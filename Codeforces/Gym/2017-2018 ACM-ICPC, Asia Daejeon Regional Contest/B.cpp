#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 4;

int fmove;
pii last;
int ar[N][N];

// int ar[N + 1][N + 1][N + 1]
int bcnt[(1 << N)];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=1;i<(1 << N);i++) bcnt[i] = __builtin_popcount(i);

    cin >> fmove;
    cin >> last.fi >> last.se;
    vector<int> col;
    for (int i=1;i<=4;i++){
        if (last.se == i) continue;
        col.pb(i);
    }
    // 0 black, 1 white
    for (int i=0;i<=N;i++){
        int gapi = 1 + (col[0] == fmove);
        for (int maski=0;maski<(1 << i);maski+=gapi){
            for (int j=0;j<=N;j++){
                int gapj = 1 + (col[1] == fmove);
                for (int maskj=0;maskj<(1 << j);maskj+=gapj){
                    for (int k=0;k<=N;k++){
                        int gapk = 1 + (col[2] == fmove);
                        for (int maskk=0;maskk<(1 << k);maskk+=gapk){
                            if ((i + j + k + last.fi) ^ 1) continue;
                            int maskl = (1 << (last.fi - 1));
                            
                        }
                    }
                }
            }
        }
    }


    return 0;
}