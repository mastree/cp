#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 8;
const int ALL = 42;

int ar[N][N];
pair<string, int> ans = mp("DRAW", -1);

int cek(){
    for (int i=1;i<=7;i++){
        int cur[3] = {0, 0, 0};
        for (int j=1;j<=6;j++){
            cur[ar[i][j]]++;
            if (j > 4) cur[ar[i][j - 4]]--;
            if (cur[1] == 4) return 1;
            else if (cur[2] == 4) return 2;
        }
    }
    for (int i=1;i<=6;i++){
        int cur[3] = {0, 0, 0};
        for (int j=1;j<=7;j++){
            cur[ar[j][i]]++;
            if (j > 4) cur[ar[j - 4][i]]--;
            if (cur[1] == 4) return 1;
            else if (cur[2] == 4) return 2;
        }
    }
    for (int i=1;i<=7;i++){
        for (int j=1;j<=6;j++){
            int cur[3] = {0, 0, 0};
            for (int k=0;k<4;k++){
                int ii = i + k;
                int jj = j + k;
                if (ii > 7 || jj > 6) break;
                cur[ar[ii][jj]]++;
            }
            if (cur[1] == 4) return 1;
            else if (cur[2] == 4) return 2;
        }
    }
    for (int i=1;i<=7;i++){
        for (int j=1;j<=6;j++){
            int cur[3] = {0, 0, 0};
            for (int k=0;k<4;k++){
                int ii = i + k;
                int jj = j - k;
                if (ii > 7 || jj <= 0) break;
                cur[ar[ii][jj]]++;
            }
            if (cur[1] == 4) return 1;
            else if (cur[2] == 4) return 2;
        }
    }

    return 0;
}
void printboard(){
    for (int i=1;i<=7;i++){
        for (int j=1;j<=6;j++){
            cout << ar[i][j] << " ";
        }
        cout << el;
    }
    cout << "=========================================" << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=1;i<=ALL;i++){
        int a;
        cin >> a;
        for (int j=1;j<=6;j++){
            if (ar[a][j] == 0){
                if (i & 1){
                    ar[a][j] = 1;
                } else{
                    ar[a][j] = 2;
                }
                break;
            }
        }
        if (ans.se == -1){
            int temp = cek();
            if (temp == 1){
                ans = mp("RED", i);
            } else if (temp == 2){
                ans = mp("YELLOW", i);
            }
        }
    }
    if (ans.se == -1){
        cout << ans.fi << el;
    } else{
        cout << ans.fi << " " << ans.se << el;
    }

    return 0;
}