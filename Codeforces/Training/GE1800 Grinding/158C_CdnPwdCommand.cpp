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

int n;
string inp;
vector <string> st;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

  //  st.pb("/");
    cin >> n;

    while (n--){
        cin >> inp;
        if (inp[0]=='c'){
            cin >> inp;
            vector <string> token;
            
            stringstream ss(inp);
            string temp;

            while (getline(ss,temp,'/')){
                token.pb(temp);
            //    cout << temp << el;
            }
            if (token[0]==""){
                st.clear();
                st.shrink_to_fit();
                for (auto x : token){
                    if (x=="") continue;
                    if (x==".." && st.size()>0) st.pop_back();
                    else st.pb(x);
                }
            }
            else{    
                for (auto x : token){
                    if (x=="..") st.pop_back();
                    else st.pb(x);
                }
            }
        } else{
            for (auto x : st) cout << "/" << x;cout << "/" << el;
        }

    }

    return 0;
}