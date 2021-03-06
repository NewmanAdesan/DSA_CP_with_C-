/*

    Given an unsorted array arr[] of size N, 
    rotate it by D elements in the counter-clockwise direction.

    Technique : Simple Pattern Recognition
    
    Time complexity: O(n)
    Space complexity: 
    

    do you see how shifting can be achieve with reverse....Look at it

    Example 1
    Input:
    N = 5, D = 2
    arr[] = {1,2,3,4,5}
    Output: 3 4 5 1 2
    Explanation: 1 2 3 4 5  when rotated
    by 2 elements, it becomes 3 4 5 1 2.

    Example 2
    Input:
    N = 10, D = 3
    arr[] = {2,4,6,8,10,12,14,16,18,20}
    Output: 8 10 12 14 16 18 20 2 4 6
    Explanation: 2 4 6 8 10 12 14 16 18 20 
    when rotated by 3 elements, it becomes 
    8 10 12 14 16 18 20 2 4 6.

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        reverse(arr, arr+n);
        reverse(arr+(n-d), arr+n);
        reverse(arr, arr+(n-d));
    }
};

// { Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}  
