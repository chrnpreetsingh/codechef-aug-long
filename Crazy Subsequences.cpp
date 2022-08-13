#include<bits/stdc++.h> //CRASUB
#define int long long
using namespace std;
string del0(string a) {
  string b;
  if(a.size()>=3&&a[a.size()-1]=='1'&&a[a.size()-2]=='1') {
    a[a.size()-1]='$';
    for(int i=0;i<(int)a.size();++i)
      if(a[i]=='0') {
        a[i]='$';
        break;
      }
    for(int i=0;i<(int)a.size();++i)
      if(a[i]!='$') b+=a[i];
    return b;
  } else return a;
}
int calc(string s) {
  vector<int> T;
  for(int i=0;i<s.size();++i)
    if(s[i]=='0') T.push_back(i);
  if(T.size()==1) return 1;
  if(T[T.size()-1]==T[T.size()-2]) return 1;
  for(int i=T[0];i<T[T.size()-2];++i)
    if(s[i]=='1') return 1;
  return 2;
}
void solve() {
 string s,a;
 int t=0,p=0;
 cin >> s;
 for(int i=(int)s.size()-1;i>=0;--i)
   if(s[i]=='1') {
     for(int j=0;j<=i;++j)
       a+=s[j];
     break;
   } else t++;
 if(t==(int)s.size()) {
   cout << s << "\n";
   return;
 }
 s=a;
 for(int i=0;i<(int)s.size();++i)
   if(s[i]=='0') p++;
 if(p==0) {
   cout << s;
   for(int i=0;i<t;++i) putchar('0');
   putchar('\n');
   return;
 }
 if(p%2==0) {
   int l=2147483647,r=-2147483648;
   for(int i=0;i<(int)s.size();++i)
     if(s[i]=='0') {
       l=min(l,i);
       r=max(r,i);
     }
   for(int i=l;i<=r;++i)
     if(s[i]=='1') {
       for(int j=0;j<(int)s.size();++j)
         if(s[j]=='1') putchar('1');
       for(int i=0;i<t;++i) putchar('0');
       putchar('\n');
       return;
     }
   if(t>=2) {
     for(int i=0;i<(int)s.size();++i)
       if(s[i]=='1') putchar('1');
     for(int i=0;i<t-2;++i) putchar('0');
     putchar('\n');
     return;
   }
   if(t==1) {
     a="";
     for(int i=(int)s.size()-1;i>=0;--i)
       if(s[i]=='0') {
         s[i]='$';break;
       }
     for(int i=0;i<(int)s.size();++i)
       if(s[i]=='$') a+='0'; else
       if(s[i]=='1') a+='1';
     s=a;
     cout << del0(s) << "\n";
     return;
   }
   if(t==0) {
     int _=0;a="";
     for(int i=(int)s.size()-1;i>=0;--i)
       if(s[i]=='0') {
         s[i]='$';
         _++;
         if(_==2)
           break;
       }
     for(int i=0;i<(int)s.size();++i)
       if(s[i]=='$') a+='0'; else
       if(s[i]=='1') a+='1';
     s=a;
     cout << del0(del0(s)) << "\n";
     return;
   }
 }
 int T=0,L=calc(s);a="";
 for(int i=s.size()-1;i>=0;--i)
   if(s[i]=='0') {
     T++;
     if(T==L) s[i]='$';
   }
 for(int i=0;i<(int)s.size();++i)
   if(s[i]=='1') a+='1';
   else if(s[i]=='$') a+='0';
 s=a;
 if(t!=0) {
   for(int i=0;i<(int)s.size();++i)
     if(s[i]=='1') putchar('1');
   for(int i=0;i<t-1;++i)
     putchar('0');
   putchar('\n');
   return;
 }
 cout << del0(a) << "\n";
}
signed main() {
 int T;
 cin >> T;
 for(int i=0;i<=T;++i) {
   // cout << i << ":";
   solve();
 }
}
