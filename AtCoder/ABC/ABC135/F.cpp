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

bool cek[5000100];

vector <int> prefix(string s){
    int n=s.length();
    vector <int> ans(n);

    int l=0;
    ans[0]=0;

    for (int r=1;r<n;r++){
        while (l!=0 && s[l]!=s[r]) l=ans[l-1];

        if (s[l]==s[r]){
            ans[r]=l+1;
            l++;
        }
        else ans[r]=0;
    }

    return ans;
}

int main()
{

    string s,t;
    cin >> s >> t;

    string st=s;

    while (s.length()<max(6*t.length(),6*st.length())){
        for (int i=0;i<st.length();i++){
            s.pb(st[i]);
        }
    }

    vector <int> pi_t,ans;
    pi_t=prefix(t);
    int n=s.length(),m=t.length();
    int ps=0,pt=0,cnt=0;
 //   cerr << n << " " << m << el;

    while (ps<n){
        while (pt!=0 && s[ps]!=t[pt]) pt=pi_t[pt-1];

        if (s[ps]==t[pt]) pt++;
        ps++;

        if (pt>=m){
        //    ans.push_back(ps-m+1);
            cek[ps-m]=1;
            cnt++;
        }
    }


    int res=0;
    bool infin=0;
    bool semua=1;
    for (int i=0;i<m;i++){
        int tm=0;
        bool bef=0;
        bool inf=1;
        for (int j=i;j<n-m+1;j+=m){
            inf=(inf&&cek[j]);
            semua=(semua&&cek[j]);
            if (bef){
                if (cek[j]){
                    tm++;
                } else{
                    tm=0;
                    bef=0;
                }
            } else{
                if (cek[j]){
                    tm=1;
                    bef=1;
                }
            }
            res=max(res,tm);
        }
        if (inf) infin=1;
    }

    if (semua||infin){
        cout << -1 << el;
        return 0;
    }
    cout << res << el;
    
}
