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



bool cmp(pair<pii,int> a, pair<pii,int> b){
    return a.se<b.se;
}

bool valid(char c) {
  return !(c == '(' || c == ')' || c == '[' || c == ']' || c == ',' || c == ' ');
}

int main() {
  string s;
  getline(cin, s);
  vector<pair<int, int> > arr;
  int sz = s.size();
  for (int i = 1; i < sz - 1; i++) {
    if (!valid(s[i])) continue;
    string tmp = "";
    pair<int, int> cur;
    while (valid(s[i])) {
      tmp += s[i];
      i++;
      if (s[i] == ',') {
        cur.first = stoi(tmp);
        tmp = "";
        i++;
        if (s[i]==' ') i++;
      } else if (s[i] == ')') {
        cur.second = stoi(tmp);
        tmp = "";
      }
    }
    arr.push_back(cur);
  }

    vector <pair<pii,int>> va,vb;
    int inlen=arr.size();
    bool cek[inlen+2];

    for (int i=0;i<inlen;i++){
        cek[i]=0;
        int a=arr[i].fi,b=arr[i].se;
    //    cerr << a << " " << b << el;
        if (a<=b){
        //    cerr << i << "a ";
            va.pb(mp(mp(a,b),i));
        } else{
        //    cerr << i << "b ";
            vb.pb(mp(mp(a,b),i));
        }
    }

    int alen=va.size(),blen=vb.size();
    vector <pair<pii,int>> va2,vb2;
    int mk,curid;
    if (!va.empty()){
    mk=va[0].fi.se,curid=0;
    va2.pb(va[0]);
    for (int i=0;i<alen;i++){
        
        if (va[i].fi.fi<=mk){
            mk=max(mk,va[i].fi.se);
            va2[curid].fi.se=mk;
        } else{
            va2.pb(va[i]);
            curid++;
            mk=va[i].fi.se;
        }//cerr << va2[curid].fi.fi << " " << va2[curid].fi.se << el;
    }
    }

    if (!vb.empty()){
    reverse(vb.begin(),vb.end());
    mk=vb[0].fi.se,curid=0;
    vb2.pb(vb[0]);
    for (int i=0;i<blen;i++){
        
            mk=max(mk,vb[i].fi.se);
            vb2[curid].fi.se=mk;
        
    }

    
    for (auto it : va2){
      //  cerr << it.fi.fi << " " << vb2[0].fi.se << el;
        if (it.fi.fi<=vb2[0].fi.se){
            vb2[0].fi.se=max(it.fi.se,vb2[0].fi.se);
            cek[it.se]=1;
        }
    }

    reverse(va2.begin(),va2.end());
    for (auto it : va2){
      //  cerr << it.fi.fi << " " << vb2[0].fi.se << el;
        if (it.fi.se>=vb2[0].fi.fi && !cek[it.se]){
            vb2[0].fi.fi=min(it.fi.fi,vb2[0].fi.fi);
            cek[it.se]=1;
        }
    }

  //  cerr << vb2[0].fi.fi << " " << vb2[0].fi.se << el;

    }
    
    vector <pair<pii,int>> ans;
    for (auto x : va2){
        if (!cek[x.se]) ans.pb(x);
    }   

    for (auto x : vb2){
        ans.pb(x);
    }

    sort(ans.begin(),ans.end(),cmp);
    cout << "[";
    int lenn=ans.size(),cc=0;
    for (auto x : ans){
        cc++;
        if (cc!=lenn)
            cout << "(" << x.fi.fi << ", " << x.fi.se << "), ";
        else cout << "(" << x.fi.fi << ", " << x.fi.se << ")]";  
    }cout << el;

    return 0;
}