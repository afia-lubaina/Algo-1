#include <bits/stdc++.h>
using namespace std;
#define ff first 
#define ss second
#define debug(x) cerr << (#x) << ' ' << x << endl;
typedef long long ll;

int main(){

    int n; cin>>n; 
    int arr[n]; 
    for (size_t i = 0; i < n; i++)
    {cin>>arr[i];
    }
    
    vector<int>temp; 
    temp.push_back(arr[0]); 

    for (int i = 1; i < n; i++)
    {
        if(arr[i]>temp.back())
            temp.push_back(arr[i]);
        else 
        {
            int ind= lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[ind] = arr[i];
        }
    }
    

    cout<<temp.size()<<"\n";

    for (size_t i = 0; i < temp.size(); i++)
    {
       cout<<temp[i]<<" ";
    }
    
    

}