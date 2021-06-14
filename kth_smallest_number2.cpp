
/***********************************************************************************************
 *   Problem :  Kth Smallest Number                                                            *
 *                                                                                             *
 *   Problem Solving Technique Used : Modulo Technique                                         *
 *                                                                                             *
 *   Info : Given an array arr[] and a number K where K is smaller than size of array,         *
 *          the task is to find the Kth smallest element in the given array.                   *
 *          It is given that all array elements are distinct.                                  *
 *                                                                                             *
 *   Example :  Input:                                                                         *
 *              N = 6                                                                          *
 *              arr[] = 7 10 4 3 20 15                                                         *
 *              K = 3                                                                          *
 *              Output : 7                                                                     *
 *              Explanation :                                                                  *
 *              3rd smallest element in the given                                              *
 *              array is 7.                                                                    *
 *                                                                                             *
 *   Time Complexity : O(n)                                                                    *
 *   Space Complexity : O(1)                                                                   *
 *                                                                                             *
 *                                                                                             *
 * ---------------------------------------------------------------------------------------------
 * ***********************************   MY PLAN   *********************************************
 * it actually simple i call this technique the Modulo Technique                               *
 * a technique that helps with consistent looping without                                      *
 * increasing the complexity.                                                                  *
 *                                                                                             *
 * For Instance: if given K = 2 --- 2nd smallest                                               *
 * what i do is loop through the array to look for the smallest element, when found            *
 * replace that element with the maximun element, then loop through the array again            *
 * to find the 2nd Smallest element.                                                           *
 * This is done with just one While loop......                                                 *
 *                                                                                             *
 * if 5 elements in array, i would actually loop ten times. i goes from 0 - 9                  *
 * but with the help of modulo(%) it will be 0-4 and another 0-4                               *
 * which micmicks looping twice all done with one loop                                         *
 *                                                                                             *
 * meaning if k= 3, n = 10.......while loop i goes from 0 - k*n                                *
 * modulo makes it  0-9, 0-9, 0-9                                                              *
 *                                                                                             *
 ***********************************************************************************************/




#include<stdio.h>

int kthSmallest(int arr[], int l, int n, int k)
    {
        int min, max, min_index, answer ;

        l = 0;                                          //my While loop Counter

        // get the max number of the array
        max = arr[0];
        for (int i= 1; i < n; i++){
            if (arr[i] > max ){
                max = arr[i];
            }
        }

        //search for the min in the array
        min = arr[0];
        while (l < (k * n)){
            int a = l % n;                              //The modulo Technique in use

            if (arr[a] < min){
                min = arr[a] ;
                min_index = a ;
            }else if (arr[a] == min && l>0){            // this chech incase there are multiple values
                arr[a] = max ;
            }

            if (a==(n-1)){                              // found a min value now it update answer
                answer = min;
                arr[min_index] = max;                   //update that min value in the array
                min = arr[min_index] ;                  //update the min checker value
            }

            l = l + 1 ;

        }

        return answer;
    }

// { Driver Code Starts.
 
int main()
{
    int test_case;
    scanf("%d",&test_case);
    while(test_case--)
    {
        int number_of_elements;
        scanf("%d", &number_of_elements);
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            scanf("%d", &a[i]);
            
        int k;
        scanf("%d",&k);
        printf("%d",kthSmallest(a, 0, number_of_elements, k));
        printf("\n");
    }
    return 0;
}  // } Driver Code Ends
