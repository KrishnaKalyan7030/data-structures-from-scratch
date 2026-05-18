#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(){
int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++){
cin>>arr[i];
}

int target;
cout<<"Enter target num: ";
cin>>target;


set<vector<int>> st;
sort(arr.begin(),arr.end());
for(int k=0;k<n;k++){
 int i=k+1,j=n-1;
 int num=target-arr[k];
 while(i<j && j>=0){
   int sum=arr[i]+arr[j];
    if(sum<num){
    i++;
    }
    else if(sum>num){
      j--;
   }
   else{
    vector<int> v(3);
    v[0]=arr[k];
     v[1]=arr[i];
     v[2]=arr[j];
     st.insert(v);
i++;
j--;
   
    }

 }
}
for(auto it=st.begin();it!=st.end();it++){
  for(auto x:*it){
  cout<<x<<" ";
  }
 cout<<endl;
}

}