#include<iostream>
#include<stack>
using namespace std;
int priority(int c){
    if(c=='^') return 3;
    else if( c == '/') return 2;
    else if(c=='*') return 2;
     else if( c == '+') return 1;
     else if(c =='-') return 1;
    else{
    return -1;
     }
       
}

int main(){
 string s="(a*b)+c/(d-e)";
 int i=0;
 stack<char> st;
 string ans="";

 while(i<s.length()){
      if((s[i]>='A' && s[i]<='Z' ) || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
             ans.push_back(s[i]);
      }
      else if(s[i]=='('){
              st.push(s[i]);
       }
       else if(s[i]==')'){
               while(!st.empty() && st.top()!='('){
                         ans.push_back(st.top());
                         st.pop();
                }
                st.pop();
       }
       else{
              while(!st.empty() &&  priority(s[i])<=priority(st.top())){
                  ans.push_back(st.top());
                  st.pop();
                  
             }
             st.push(s[i]);
             
       }
 i++;
 }
  
//All remaining char from stack should be added to ans and pop it from stack.
while(!st.empty()){
   ans.push_back(st.top());
  st.pop();
 }

  cout<<ans;
 
}
