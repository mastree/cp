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

const int N = 1e3 + 7;

int n;
int ar[N][N];
stack <int> st[4];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i=n*n - 1;i>=0;i--){
        st[i % 4].push(i);
    }  

    for (int i=0;i<n;i++){
        int ev, od;
        if (i%4 == 0){
            ev = 0;
            od = 1;
        } else if (i%4 == 1){
            ev = 2;
            od = 3;
        } else if (i%4 == 2){
            ev = 1;
            od = 0;
        } else{
            ev = 3;
            od = 2;
        }
        for (int j=0;j<n;j++){
            if (j&1){
                ar[i][j] = st[od].top();
                st[od].pop();
            } else{
                ar[i][j] = st[ev].top();
                st[ev].pop();
            }
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << ar[i][j] << " ";
        }
        cout << el;
    }

    return 0;
}