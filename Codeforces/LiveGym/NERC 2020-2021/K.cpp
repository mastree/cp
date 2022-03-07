#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e3 + 10;
const int INF = 1e9;

int n;
vector<int> vec;

void operasi1(vector<int>& vec){
    for (int i=0;i<n;i+=2){
        swap(vec[i], vec[i + 1]);
    }
}
void operasi2(vector<int>& vec){
    for (int i=0;i<n/2;i++){
        swap(vec[i], vec[n/2 + i]);
    }
}
bool is_sorted(vector<int>& vec){
    for (int i=0;i<n - 1;i++){
        if (vec[i] > vec[i + 1]) return 0;
    }
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    n = n + n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        vec.pb(a);
    }
    int ans = INF;
    {
        vector<int> temp = vec;
        int cur = 0;
        while (!is_sorted(temp) && cur < N + N){
            cur++;
            if (cur & 1){
                operasi1(temp);
            } else{
                operasi2(temp);
            }
        }
        if (cur != N + N){
            ans = min(ans, cur);
        }
    }
    {
        vector<int> temp = vec;
        int cur = 0;
        while (!is_sorted(temp) && cur < N + N){
            cur++;
            if (cur & 1 ^ 1){
                operasi1(temp);
            } else{
                operasi2(temp);
            }
        }
        if (cur != N + N){
            ans = min(ans, cur);
        }
    }
    if (ans == INF) ans = -1;
    cout << ans << el;

    return 0;
}