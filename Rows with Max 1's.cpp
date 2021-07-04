/*
Given a boolean 2D array of n x m dimensions where each row is sorted. 
Find the 0-based index of the first row that has the maximum number of 1's

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing)

Input: 
N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1
Explanation: Row 1 contains 2 1's (0-based
indexing)

*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    	    // code here
	    // the first idea that should come to your mind
	    // is that you count the number of 1's pew row
	    // but because of the additional info that
	    // each row have been sorted
	    // all we need to know now
	    // is to know when a 1 start
	    
	    // Note how sorting makes it easier to come up
	    // with a solution.....Think about that
	    
	    // back to what i was saying, 
	    // we could skim through each column 
	    // trying to get where a 1 started but 
	    // that means O(n)
	    // we Need to search better.....
	    
	    // What pops to your Mind?
	    // BINARY SEARCH
	    // but why implement it yourselg when
	    // you have upper_boound and lower_bound function
	    // offered by STL
	    
	    // WE THAT SAID THE PROBLEM SLOWLY MOVED
	    // FROM MEDIUM TO EASY TO BASIC
	    
	    int maxi = 0;
	    int ind = -1;
	    
	    for (int i = 0; i<n; i++){
	        int num1 = arr[i].end() - lower_bound(arr[i].begin(), arr[i].end(), 1);
	        
	        if (num1>maxi){
	            maxi = num1;
	            ind = i;
	        }
	    }
	    
	    return ind;
	}
};



// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
