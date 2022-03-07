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

set<int> setdah, ada; // mask state, sz
vector<vector<int>> dp(N);

const vector<pii> kanan = {{0, 0}, {0, 1}, {0, 2}};
const vector<pii> atas = {{0, 0}, {1, 0}, {2, 0}};
const vector<pii> kananatas = {{0, 0}, {1, 1}, {2, 2}};
const vector<pii> kiriatas = {{0, 0}, {1, -1}, {2, -2}};
vector<vector<pii>> dels = {kanan, atas, kananatas, kiriatas};

bool inrange(int a, int b, int c){
    return a <= b && b <= c;
}

int check(const vector<vector<int>>& board){
    for (int i=0;i<N;i++){
        for (int j=0;j<board[i].size();j++){
            for (auto& del : dels){
                vector<int> cnt(2, 0);
                for (int id=0;id<3;id++){
                    int ni = i + del[id].fi;
                    int nj = j + del[id].se;
                    if (inrange(0, ni, 3) && inrange(0, nj, (int)board[ni].size() - 1)){
                        cnt[board[ni][nj]]++;
                    }
                }
                for (int id=0;id<2;id++){
                    if (cnt[id] == 3) return id;
                }
            }
        }
    }
    return -1;
}
int get_mask(const vector<vector<int>>& dp){
    int mask = 0;
    for (int i=N - 1;i>=0;i--){
        mask <<= 4;
        for (int j=0;j<dp[i].size();j++){
            if (dp[i][j]) mask += (1 << j);
        }
    }
    return mask;
}
vector<vector<int>> demask(int mask, const vector<int>& sz){
    vector<vector<int>> ret(4);
    for (int i=0;i<N;i++){
        for (int j=0;j<sz[i];j++){
            if (mask & (1 << j)) ret[i].pb(1);
            else ret[i].pb(0);
        }
        mask >>= 4;
    }
    return ret;
}
void allposs(int dep){
    int res = check(dp);
    {
        int sz1 = setdah.size();
        int sz2 = ada.size();
        // vector<int> sz;
        // for (int i=0;i<N;i++) sz.pb(dp[i].size());
        int mask = get_mask(dp);
        if (res >= 0 && (dep & 1)){
            setdah.insert(mask);
            if (setdah.size() == sz1) return;
        } else{
            ada.insert(mask);
            if (ada.size() == sz2) return;
        }
    }
    for (int i=0;i<N;i++){
        if (dp[i].size() >= N) continue;
        dp[i].pb((dep & 1));
        allposs(dep + 1);
        dp[i].pop_back();
    }
}

int ans[N + 2][N + 2][N + 2]; // awal, akhir, akhir

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    allposs(0);
    for (auto& x : setdah){
        vector<vector<int>> board = demask(x, {4, 4, 4, 4});
        vector<int> mulai;
        vector<pii> akhir;
        for (int i=0;i<N;i++){
            assert(board[i].size() <= 4);
            if (board[i].size() && board[i][0] == 0) mulai.pb(i);
            if (board[i].size() && board[i].back() == 1){
                pii b = mp((int)board[i].size() - 1, i);
                int backup = board[b.se].back();
                board[b.se].pop_back();
                int ok = check(board);
                board[b.se].pb(backup);
                if (ok == -1) akhir.pb(b);
            }
        }
        for (auto& b : akhir){
            for (auto& a : mulai){
                if (b.fi == 0 && b.se == a) continue;
                ans[a + 1][b.fi + 1][b.se + 1]++;
            }
        }
    }
    cout << ans[2][2][3] << el;

    return 0;
}