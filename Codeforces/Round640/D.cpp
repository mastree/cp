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

const int N = 1e3 + 10;

int q;
int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        deque <int> deq;
        for (int i=1;i<=n;i++){
            int temp;
            cin >> temp;
            deq.push_back(temp);
        }

        int a = 0, b = 0;
        int lasta = 0, lastb = 0;
        int turn;

        for (turn=1;;turn++){
            if (turn & 1){
                lasta = 0;
                while (lasta <= lastb){
                    lasta += deq.front();
                    deq.pop_front();
                    if (deq.empty()) break;
                }
                a += lasta;
                if (deq.empty()) break;
            } else{
                lastb = 0;
                while (lastb <= lasta){
                    lastb += deq.back();
                    deq.pop_back();
                    if (deq.empty()) break;
                }
                b += lastb;
                if (deq.empty()) break;
            }
        }

        cout << turn << " " << a << " " << b << el;
    }

    return 0;
}