#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;

int n;
string s[N];
int di[8] = {0, 0, -1, 1, 1, -1, 1, -1};
int dj[8] = {-1, 1, 0, 0, 1, -1, -1, 1};

bool is_valid(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < n;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    pii kpos;
    for (int i=0;i<n;i++){
        cin >> s[i];
        for (int j=0;j<n;j++){
            if (s[i][j] == 'K') kpos = mp(i, j);
        }
    }
    for (int i=0;i<8;i++){
        int ci = kpos.fi + di[i];
        int cj = kpos.se + dj[i];
        if (is_valid(ci, cj)){
            s[ci][cj] = '-';
        }
    }
    int ans = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (s[i][j] == '*'){
                int ni, nj;
                ni = i + 1;
                nj = j - 1;
                if (is_valid(ni, nj) && s[ni][nj] == 'p') continue;
                ni = i + 1;
                nj = j + 1;
                if (is_valid(ni, nj) && s[ni][nj] == '-'){
                    ans++;
                    s[ni][nj] = 'p';
                    continue;
                } 
                ni = i + 1;
                nj = j - 1;
                if (is_valid(ni, nj) && s[ni][nj] == '-'){
                    ans++;
                    s[ni][nj] = 'p';
                    continue;
                }
                ans = -1;
                break;
            }
        }
        if (ans == -1) break;
    }
    cout << ans << el;

    return 0;
}