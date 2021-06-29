
/*
Given an array arr[] of N non-negative integers representing the height of blocks.
If width of each block is 1, compute how much water can be trapped 
between the blocks during the rainy season.

Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.

Input:
N = 3
arr[] = {6,9,9}
Output:
0
Explanation:
No water will be trapped.

*/









// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        // making two refrence array for 
        // left_bound and right_bound
        // note that water will only hold in a spot 
        // if it has a left bound and right bound
        // thus for each spot we want to know the 
        // maximum left bound and maximum rightbound
        // note also that water stored will only be
        // based on the minimum of the two bound
        
        // Making the Left_bound array
        int left_bound[n];
        int left = arr[0];
        
        for (int i = 0; i<n; i++){
            if (arr[i] == left){
                left_bound[i] = 0;
            }else if(arr[i] < left){
                left_bound[i] = left;
            }else if(arr[i] > left){
                left_bound[i] = 0;
                left = arr[i];
            }
        }
        
        
        /************************************************
        *a faster code will be to remove                *
        * the redundancy of the equal to equal          *
        * condition...and using a sort of               *
        * dynamic programing approach                   *
        * it just means bulding on calculated value     *
        * doing this left_bound array building will     *
        * be reduced to a line of code                  *
        *                                               *
        * left_bound[i] = max(left_bound[i-1], arr[i])  *
        * same way goes for building right_bound        *
        * anyways both code will work                   *
        * and execution time will be similar            *
        * just that the latter will be of shorter code  *
        * by physically looking at it but internal      *
        * implementation is just as long                *
        ************************************************/
        
        
        
        // Making right_bound array
        int right_bound[n];
        int right = arr[n-1];
        
        for (int i = n-1; i>=0; i--){
            
            if (arr[i] == right){
                right_bound[i] = 0;
            }else if(arr[i] < right){
                right_bound[i] = right;
            }else if(arr[i] > right){
                right_bound[i] = 0;
                right = arr[i];
            }
        }
        
        // having the bounds, we check for 
        // each spot how many water levels 
        // will be held
        
        int total = 0;
        
        for (int i = 0; i<n; i++){
            
            // to trap water in a spot there must
            // be bounds if no bounds, water will 
            // not be trappes
            if (left_bound[i] == 0 || right_bound[i] == 0){
                continue;
            }
            
            // if bounds exist, water will 
            // be trapped based on the 
            // minimum height of the two bounds
            // draw it and see for yourself
            int mini = min(left_bound[i],right_bound[i]);
            int water_stored = mini - arr[i];
            total = total + water_stored;
        }
        
        return total;
        
        
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends