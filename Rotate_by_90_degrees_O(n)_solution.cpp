#include <stdio.h>


//User function Template for C
// meaning it was written for a
// C compiler but no worries
// The main code is the the function
// it will also work in C++
// all you need to do is 
// #include<bits/stdc++.h>
// using namespace std;


//Function to rotate matrix anticlockwise by 90 degrees.
void rotateby90(int n, int matrix[][n]) 
{
    // the key technique is just
    // simple recognition
    // simple reverse
    
    //creation of the extra space
    int matrix2[n][n];

    for (int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            matrix2[n-1-j][i] = matrix[i][j];
        }
    }
    
    for (int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            matrix[i][j] = matrix2[i][j];
        }
    }
    
    
    
    
} 

// { Driver Code Starts.

int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int n;
		scanf("%d", &n);
		int matrix[n][n];
	 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		
		rotateby90(n, matrix);
		for(int i = 0; i < n; i++)
		    for(int j=0; j<n; j++)
			    printf("%d ", matrix[i][j]);
		printf("\n");
	}
	return 0;
}  // } Driver Code Ends
