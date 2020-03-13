#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    int m;
    cin >> m;

    int pc[n+1][26];
    for (int i=0;i<26;i++) pc[0][i]=0;

    for (int i=1;i<=n;i++){
        for (int j=0;j<26;j++){
            pc[i][j]=pc[i-1][j];
        }
        pc[i][s[i-1]-'a']++;
    }

    while (m--){
        string q;
        cin >> q;

        int ar[26],len=q.length();
        for (int i=0;i<26;i++) ar[i]=0;
        for (int i=0;i<len;i++){
            ar[q[i]-'a']++;
        }

        int low=1,high=n;

        while (low<high){
            bool bisa=1;
            int mid=(low+high)/2;

            for (int i=0;i<26;i++){
            //    cerr << pc[mid][i] << " " << ar[i] << el;
                if (pc[mid][i]<ar[i]) bisa=0;
            }
            

            if (bisa) high=mid;
            else low=mid+1;
        }
        //cerr << el;
        cout << high << el;

    }

    return 0;
}