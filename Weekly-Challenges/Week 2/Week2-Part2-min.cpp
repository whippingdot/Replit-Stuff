#include <iostream>
using namespace std;void m(){cout<<"impossible";exit(0);}void I(string a){if(a!=""){m();}}string r(string l,string a){if(l == "BBB"){I(a);return "blue";}if(l=="RRR"){I(a);return "red";}return a;}int main(){string l;string n;string e;string a;int B=0;int R=0;cin>>l;cin>>n;cin>>e;a=r(l,a);a=r(n,a);a=r(e,a);for(int i=0;i<3;i++){if(l[i]!='.'||n[i]!='.'){if(n[i]=='.'||e[i]=='.'){m();}}for(char c:"BR"){if(l[i]==n[i]&&l[i]==e[i]&&e[i]==c){I(a);if(c=='B'){a="blue";}else{a="red";}}}l[i]=='B'?B+=1:B;l[i]=='R'?R+=1:R;n[i]=='B'?B+=1:B;n[i]=='R'?R+=1:R;e[i]=='B'?B+=1:B;e[i]=='R'?R+=1:R;}if(B!=R&&B+1!=R&&B-1!=R){m();}for(char c:"BR"){if(l[0]==n[1]&&l[0]==e[2]&&e[2]==c){I(a);if(c=='B'){a="blue";}else{a="red";}}if(l[2]==n[1]&&l[2]==e[0]&&e[0]==c){I(a);if(c=='B'){a="blue";}else{a="red";}}}if(a==""){cout<<"possible\ntie";exit(0);}cout<<"possible\n"<<a;}