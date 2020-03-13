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

const int N = 30;
const int L = 210;

int q;
string s;
int n;
int ar[L];

bool rel[N][N];
bool vis[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> s;
        n = s.length();
        for (int i=1;i<=n;i++){
            ar[i] = (s[i-1] - 'a');
        }
        for (int i=0;i<N;i++){
            fill(rel[i], rel[i] + N, 0);
            vis[i] = 0;
        }

        deque <int> deq;
        bool bisa = 1;
        for (int i=1;i<=n;i++){
            if (i == 1){
                deq.push_back(ar[i]);
                vis[ar[i]] = 1;
                continue;
            } 
            if (vis[ar[i]]){
                if (rel[ar[i]][ar[i-1]]) continue;
                else{
                    bisa = 0;
                    break;
                }
            } else{
                vis[ar[i]] = 1;
                if (deq.front() == ar[i-1]){
                    deq.push_front(ar[i]);
                } else if (deq.back() == ar[i-1]){
                    deq.push_back(ar[i]);
                } else{
                    bisa = 0;
                    break;
                }
                rel[ar[i]][ar[i-1]] = 1;
                rel[ar[i-1]][ar[i]] = 1;
            }
        }
        
        if (!bisa){
            cout << "NO" << el;
            continue;
        }

        cout << "YES" << el;
        for (auto x : deq){
            cout << char(x + (int)'a');
        }
        for (int i=0;i<26;i++){
            if (!vis[i]){
                cout << char(i + (int)'a');
            }
        }
        cout << el;
    }

    return 0;
}