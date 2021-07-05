/*
Given a matrix of size r*c. Traverse the matrix in clock-wise spiral form.

Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation:

       ---------------
        __________   
       |    |     |  |
       |    |_____|  |
       |             |
       ---------------

Input:
r = 3, c = 4  
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7
Explanation:
Applying same technique as shown above, 
output for the 2nd testcase will be 
1 2 3 4 8 12 11 10 9 5 6 7.

*/





// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        // Hmmm,  Hmmm , i love this
        // you should understand how indexing works for each element
        // in an array built matrix
        
        // let me show you a view
        // Realise we have to simulate 
        // a sort of box that is closing in
        // a spiral.
        // Thus it will make sense to have
        // four pointers i, j, k, l around the block
        // then they start to close in
        // meaning i comes down, j move left
        // k moves up, l moves right
        
        //           0   1   2   3    4
        //
        //        i ____________________ j
        //  0      `|1   2   3   4    5|      0
        //          ____             ____
        //  1       |6 | 7   8   9   |10|     1    after a loop      7    8   9
        //  2       |11| 12  13  14  |15|     2   --------------->   12   12   14  ---> 13
        //  3       |16| 17  18  19  |20|     3                      17   18   19
        //          _______________
        //  4       |21  22  23  24| |25|     4
        //         l                     k
        //
        //           0   1   2    3    4
        
        // if you read the question well
        // this approach works well because 
        // of a sort of  index symmetricity 
        // that goes on when we define a matrix
        
        //
        // you would be nodding your head by now
        
        // So basically we have the Upper wall
        // we have the LEFT wall, LOWER wall
        // and the RIGHt wall 
        // and after a loop, this wall start 
        // coming closer
        
        // so the idea is to first add element in Upper wall
        // then we add in elements in left wall
        // then we add in elements in lower wall
        // then we add in elements in right wall
        
        // now here this, this is where the indexing 
        // makes implementation easy and work
        // after taking the left wall
        // that is a for loop from i ---> j at row i
        // then after, i increases by  1.
        // which denotes a start from when j should begin
        
        // Thus for the Right wall we have
        // a for loop from j ---- k starting from i at column j
        //  think about it
        
        // OKay ENOUGH TAlK LET ME SHOW YOU IMPLEMENTATION
        // before that i want to ask you aomething
        // when do you think the loop will stop
        // it will stop, when our answer vector size is r*c 
        
        vector<int> v;
        int i,j,k,l;
        i = 0;
        j = c - 1;
        k = r - 1;
        l = 0;
        
        while( v.size() < r*c){
            // left wall
            for(int p = i; p<=j; p++){
                v.push_back(matrix[i][p]);
            }
            i++;            // i moves down...as it is done with that wall
            
            
            
            if (v.size() == r*c){
                break;
            }
            
            
            // Right wall
            for(int p = i; p<=k; p++){
                v.push_back(matrix[p][j]);
            }
            j--;            // j moves back......as it is done with that wall
            
            
            if (v.size() == r*c){
                break;
            }
            
            
            
            // Lower Wall
            for(int p = j; p>=l; p--){
                v.push_back(matrix[k][p]);
            }
            k--;            // k moves up......as it is done with that wall 
            
            
            if (v.size() == r*c){
                break;
            }
            
            // Left Wall
            for(int p = k; p>=i; p--){
                v.push_back(matrix[p][l]);
            }
            l++;            // l moves forward ......as it is done with that wall
            
            
            // Are you still with Me
            // Are you seeing what is happening here
            // Draw it on your paper and 
            // work with the flow yourself
            // You would Observe, the pointers
            // the pointers aremoving in 
            // anti-clock wise circles
            // Quite Pretty and Ironic
            // since you are moving in clock wise spiral
        }
        
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends