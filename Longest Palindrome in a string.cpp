/*
Given a string S, find the longest palindromic substring in S.
Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). 
Palindrome string: A string which reads the same backwards. 
More formally, S is palindrome if reverse(S) = S. 
Incase of conflict, return the substring which occurs first ( with the least starting index)

Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".

Input: 
S = "abc"
Output: a
Explanation: "a", "b" and "c" are the 
longest palindromes with same length.
The result is the one with the least
starting index.

*/





// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        // okay this is not so trivial 
        // but you will get it easily and swiftly as
        // i walk you through it
        // Lets Understand the Story of this problem
        
        // Now i believe you've read and digested the question right
        // at least you should have thought of how the brute force solution
        // will be right.... in Steps
        // scroll through all the substrings available -- step 1 
        // and check it they are equal to their reverse -- step 2
        
        // step one involve two pointer going in nested loop -- O(n^2)
        // step two will also be approcimately O(n)
        // i believe implementating this brute force would be a piece of cake
        // an extra knowledge to make code shorter 
        // is the use of the string method -- substr(start_index, end_index)
        
        // Now lets get to the real reason am here.....to show you a better approach
        // now take a look at two keywords in this question
        // ------ LONGEST and PALINDROME--------
        
        // the first question you should ask yourself is
        // What is a Palindrome and how can be Observed
        // look at examples of palindromes and what can you observe
        
        // ----peep---sees----level----rotor----stats
        // i belive you will observe that 
        // that you can clasify the behaviour of palindrome into
        // two groups EVEN PALIDROME and ODD PALINDROME
        
        // Even guys   pe.ep,  se.es
        // ODD guys    le-v-el, ro-t-or, st-a-ts
        
        // baseline observation is that as you move away from the mid-guy of a word
        // the letter below and the letter above must be the same
        // So we can say the palindromic property
        // depend on the mid-guy
        
        // Now knowing that we can move through each letter in a word
        // taking each letter as a mid-guy.
        // checking the longest palindrome that can be formed with that letter
        // Do you understand e.g aaaba
        // e.g for the first letter a----- longest palindrom is 1 letter
        // for the second letter a ----- longest palindrome is 3 letters
        // You grab right.....i believe you can implement also
        
        // But our Algorithm will not be complete because through out our checking
        // we are only checking for odd numbered Palindrome
        // think about it.... it would work for words like level
        // but will fail for words like deed.....try it
        
        // So our do we check for Even numbered words to
        // would be cool if there was like a dot in between all letters
        // remember that is only how we can check for even guys right
        // But that is the answer..... we change the string a little bit
        
        // instead of working with aaaba 
        // we will work with #a#a#a#b#a#
        // thus we can check for both even and odd
        
        // Wow that was a long Story....lets Implement
        
        
        
        // We tweak user given string into what we need
        string s2 = "#";
        for (char i:S){
            s2.push_back(i);
            s2.push_back('#');
        }
        
        
        // We create our array so that we store longest palindromic count 
        // for each letter as a mid-guy
        int mid_guys[s2.length()];
        
        
        
        // this keeps tabs on the longest numbered palindrome discovered
        int max_index = 0;
        
        
        
        // now lets check through each letter, taking them as mid-guys
        for (int i = 0; i < s2.length(); i++){
            int j = i-1;
            int k = i+1;
            int count = 0;
            
            while(s2[j] == s2[k]  &&  j>=0  &&  k<s2.length()){
                j--;
                k++;
                count++;
            }
            
            mid_guys[i] = count;
            if (mid_guys[i] > mid_guys[max_index]){
                max_index = i;
            }
            
        }
        
        
        
        
        
        /************for debugging****************
        for (int i = 0; i< s2.length(); i++){
            cout << mid_guys[i] << " ";
        }
        cout<< endl;
        cout << max_index;
        ******************************************/
        
        
        
        
        // Now that we know the index that makes the longest panlindrome
        // based on the array index element we know how letters that palindrome has
        // e.g for aaaba....#a#a#a#b#a..... we know it is   aaa.....#a#a#a
        // the mid_guy index is 3......length is 3
        // so the letters we need are the three forward letters and the three backward letters
        // thus implemetation becomes piece of cake
        string result ;
        int start = max_index - mid_guys[max_index];
        int end = max_index + mid_guys[max_index];
        for (int i = start; i<= end; i++){
            if (s2[i] != '#'){
                result.push_back(s2[i]);
            }
        }
        
        return result;
        
        
        
        
        
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends