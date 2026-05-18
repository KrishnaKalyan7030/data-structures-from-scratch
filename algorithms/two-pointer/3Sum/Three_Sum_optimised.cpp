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


vector<vector<int>> st;
sort(arr.begin(),arr.end());
for(int k=0;k<n-2;k++){
  if(k>0 && arr[k]==arr[k-1]) continue;
 int i=k+1,j=n-1;
 int num=target-arr[k];
 while(i<j){
   int sum=arr[i]+arr[j];
    if(sum<num){
    i++;
    }
    else if(sum>num){
      j--;
   }
   else{
    st.push_back({arr[k],arr[i],arr[j]});
    while(i<j && arr[i]==arr[i+1]) i++;
    while(i<j && arr[j]==arr[j-1]) j--;
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



# Here used vector<vector<int>> as while inserting in set TC was O(logn) which leads to O(n^2logn) but without set it is o(n^2) only.
