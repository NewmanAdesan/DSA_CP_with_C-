// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;


int minSwap(int *arr, int n, int k);

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends


int minSwap(int *arr, int n, int k) {
    // Complet the function
    // using sliding window technique
    // window size would be the how many
    // numbers are less than equal to k
    // 
    // then we move from one window to
    // another and look for  the minimum number 
    // of count of outliers in a window
    
    
    // lets find the window size
    int wsize = 0;
    for(int i = 0; i<n ; i++){
        if(arr[i] <= k){
            wsize++;
        }
    }
    
    if (wsize <= 1){
        return 0;
    }
    
    //note the idea is to do it in O(n)
    // thus no nested loop
    
    // lets check the first window
    int count = 0;
    for(int i = 0; i<wsize; i++){
        if (arr[i] > k){
            count++;
        }
    }
    
    
    // very key to note no nested loop 
    // is allowed and since this is sliding window
    // if we did nested loop, we will just be
    // repeating some counts

    int ans = count;
    for(int i = wsize; i<n; i++){
        if (arr[i-wsize] > k){
            count--;
        }
        
        if (arr[i] > k){
            count++;
        }
        
        ans = min(ans,count);
        
    }

    
    return ans;

   
}
