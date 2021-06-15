
/***************************************************************************************************
 *   Problem :  Count More than n/k Occurences                                                     *                   
 *                                                                                                 *
 *   Problem Solving Technique : Using Array indexing for Refrencing                               *                                                          
 *                                                                                                 *
 *   Info : Given an array arr[] of size N and an element k.                                       *
 *          The task is to find all elements in array                                              *
 *          that appear more than n/k times.                                                       *
 *                                                                                                 *
 *   Example :  Input:                                                                             *
 *              N = 8                                                                              *
 *              arr[] = {3,1,2,2,1,2,3,3}                                                          *
 *              K = 4                                                                              *
 *              Output : 2                                                                         *
 *              Explanation :                                                                      *
 *                            In the given array, 3 and 2                                          *
 *                            are the only elements that appears                                   * 
 *                            more than n/k times.                                                 *
 *                                                                                                 *
 *                                                                                                 *
 *   Time Complexity : O(n)                                                                        *
 *   Space Complexity : O(n)                                                                       *
 *                                                                                                 *
 *                                                                                                 *
 * -------------------------------------------------------------------------------------------------
 * ***********************************   MY PLAN   *************************************************
 * it actually simple.                                                                             * 
 * I know, I know the name is not as brilliant as i would have hoped it to be.                     *
 * okay what of REFRENCING WITH ARRAY INDEXING "how about that?" i think thats beter               *
 * anyways lets get to the plan                                                                    *
 * basically its about utiliizing HOW the array data structure tranverses.                         *
 * whereby arrays have index numbers like ID that we can use to access values assigned to them.    *
 *                                                                                                 *
 *                                                                                                 *
 * Let See What Happened :      (Now follow me, follow me closely)                                 *
 * we make a separate array whereby every unique element in our input array                        *
 * is an index in that separate array. Now of course you know arrays                               *
 * assign index automatically from 0 to a given number                                             *
 *                                                                                                 *
 *                                                                                                 *
 * Thus all we have to do (You think) is this ---  int frequency[ (max of input array) + 1] = {0}  *
 * Think about it and you'll see it sure enough works.                                             *
 * Of course we have to make it all zeros, i mean a zero array                                     *
 * because what we are going to be storing in there are count values                               *
 * of unique element in our input index                                                            *
 *                                                                                                 *
 *                                                                                                 *
 * So we loop Through our input array and constantly and simultaneously                            *
 * count each unique element and update the count value in                                         *
 * our refrence array using the unique element as index in that array for updating                 *
 * unique elements count value                                                                     *
 *                                                                                                 *
 *                                                                                                 *
 * For Example: input array = {1,4,2,4,4}                                                          *
 *              refrence array =  |0|1|2|3|4|   ----- index(unique element as key)                 *
 *                                 0 1 1 0 3    ----- count values                                 *
 *                                                                                                 *
 *                                                                                                 *
 * Then lastly all we have to do is loop to refrence array                                         * 
 * and look for indexes whose count values are more than n/k.                                      *
 *                                                                                                 *
 *                            This is My Game Plan :)                                              *
 ***************************************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    int countOccurence(int arr[], int n, int k) {

        
        //get the max of array to implement
        //array index refrencing technique
        int maxi = arr[0];
        for (int i = 1; i<n; i++){
            maxi = max(arr[i],maxi);}
    

        //now we make our refrence advantageous array fill it initially with zero
        int freq[maxi+1] = {0};
        

        //fill our array 
        for (int i = 0; i<n; i++ ){
            freq[ arr[i] ] ++;}
            

        //now we check for the n/k condition
        int count = 0;                      //how many elements fulfill this condition
        for (int i = 0; i< maxi+1; i++){
            if (freq[i] > n/k){
                count++;}}
                
        return count;
        
    }
};



// { Driver Code Starts.
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends
