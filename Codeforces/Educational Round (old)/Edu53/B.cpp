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

const int N = 2e5 + 10;

int n;
stack<int> st;
int ar[N];
bool ada[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    st.push(-1);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        ada[ar[i]] = 1;
    }
    for (int i=n;i>=1;i--){
        st.push(ar[i]);
    }
    for (int id=1;id<=n;id++){
        int a;
        cin >> a;
        int cur = 0;
        if (!ada[a]){
            cout << cur << " ";
            continue;
        }
        while (ada[a]){
            auto temp = st.top();
            cur++;
            st.pop();
            ada[temp] = 0;
        }
        cout << cur << " ";
    }
    cout << el;

    return 0;
}