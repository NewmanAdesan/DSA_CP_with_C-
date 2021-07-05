// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        // Your code here
        // wow wow 
        // am sure Your first approach was kadanes Algorithm
        // you will find out that will yield O(n) Time complexity
        // am sure you tried it checking from back and front
        // the fact that this case is unsorted is a problem
        
        // THE Next Simplest Approach is the two pointer Method
        // Think about it well.....and you will see it works
        // am sure it crossed you Mind a bit... 
        // but you thought it would be O(n^2)
        // NO think of it again, its actually O(n + n)
        // dont just dismiss thoughts like that
        // quickly try it out on paper
        
        // the two pointer method is actually smart and basic
        // think about it 
        // you put pointer l at 0-index
        // you put pointer r at 1-index
        // and there is a reocurring sum.
        
        // if the updating sum from l to r is less than target
        //  Move r forward
        // if the updating sum from 1 to r is greater than target
        // Move l forward
        
        // if you tackled the question you will find out this
        // two pointer Method would Work
        // Think of it and check it on paper
        // one thing that would make you think of this
        // it to realise the question is asking for end points
        // One would have taught of Sliding window Technique
        // but in this case there is no constant size
        
        // Do Something for me keep in mind how two pointer work
        // and what it helps you do in this problem
        
        // it may come in handy for a tougher problem
        // but if you have a subset solution like this
        // things can flow nicely
        // this two pointer Method has O(n) time and O(1) space
        
        
        
        // I should have Ended this analysis chat
        // but there is also another Solution
        // using a refrence array(prefix array)
        // though this one is o(n) time and o(n) space
        
        // is quite Easy to think about, 
        // am sure if you werent focused on on O(1) space 
        // you would have easily found it
        
        // idea is basic but also keep how it works in mind
        // you make a sum prefix array
        // e.g for [1,2,3,7,5] --- [1,3,6,13,18]
        // thus your work is cut in half....i believe you can see
        // what to do next, you will need another array
        // the basic idea here is to find s
        // s = arr2[i] - [an element we would have already traversed though]
        // you see that we would need a set or mat so as to use 
        // the set.find() method
        // 
        
        
        
        // We are using the two pointer method
        
        int l = 0;  int r = 1;
        int sum = arr[0];
        // since question says we must return -1 
        // if s can not be brought out from array 
        vector <int> result = {-1};     
        
        while(l<n){
            
            //lets handle an hedge cases
            // if we have like [20,1,1,1], s = 20
            // or we could have just made r = 0 
            // and change sum += arr[r+1]
            // but we would go the long way
            // i want to just write the if statment 
            // to flag you tho think about hedge cases too
            
            if(arr[0] == s){
                result.clear();
                result.push_back(1);
                result.push_back(1);
                break;
            }
        
            
            if(sum < s){
                sum = sum + arr[r];
                r++;
            }else if(sum > s){
                sum = sum - arr[l];
                l++;
            }else{
                result.clear();
                result.push_back(l + 1);
                // because we add to sum before increase 
                //r is already +1 farther
                result.push_back( r );       
                break;
            }
            
        }
        
            
        return result;
        


    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;