#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 30;
const int M = 1e3 + 10;

string s;

int ar[2][5];
int n, m;
int mat[N][N], nmat[N][N];

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    for (int i=0;i<5;i++){
        ar[0][i] = (s[i] == '1');
    }
    for (int i=6;i<11;i++){
        ar[1][i - 6] = (s[i] == '1');
    }
    cin >> n >> m;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            char c;
            cin >> c;
            mat[i][j] = int(c - '0');
        }
    }
    for (int lup=1;lup<=m;lup++){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                int cnt = 0;
                for (int k=0;k<4;k++){
                    int ni = (i + di[k] + n) % n;
                    int nj = (j + dj[k] + n) % n;
                    if (mat[ni][nj]) cnt++;
                }
                nmat[i][j] = ar[mat[i][j]][cnt];
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                mat[i][j] = nmat[i][j];
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << mat[i][j];
        }
        cout << el;
    }

    return 0;
}