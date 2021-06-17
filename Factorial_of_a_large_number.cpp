
#include<bits/stdc++.h>
using namespace std;

   

int main(){


    string a = "100" ;
    string b = "23" ;

    // First Step 
    // make a the smaller operand
    // remember how we multiply right
    // smaller opereand id below and bigger operand is above
    // we chose a = smallest and b = biggest
    if (a.length() > b.length()){
        string temp = a;
        a = b ;
        b = temp;}


    // Second Step 
    // let declare our integer array
    // where we store and update our multiplication result
    // of course you also know it has to have length of
    // like twice the operands length right? "Flow with me here"
    // it has to be bigger
    //
    int arr[2*3 + 2]  = {0};
    int N = 2*3 + 2;


    // Third Step
    // The Main driver, our nested loop that does all the work
    // first we initiate where to start input value into our array
    int start = N ;
    
    // next loop through the smaller operand from the back
    // remember that how we multiply             
    for (int l = a.length() - 1;  l >= 0;  l--){
        int i = a[l] - '0' ;                           // turn each element of operand to integers 
        int start1 = start - 1 ;                           // this helps put value in their right position in our array

        for (int m = b.length() - 1;  m >= 0; m-- ){     // for each loop through elements in bigger operand remeber thats how we multiply
            int j = b[m] - '0' ;
            int value = i * j ;
            int rem = value % 10 ;
            int quot = value / 10 ;

            arr[start1] = arr[start1] + rem ;
            arr[start1 - 1] = arr[start1 -1] + quot ;


            // now thats not all because remebmer during
            // that multiplication we would add right
            // add when we add if we get a two value integer
            // like 26, we put 6 (remainder) in that box position
            // and carry 2 (quotient) to the preceeding box
            // you remember right? thats what am dong with this if block  
            if (arr[start1] > 9){                       
                int value2 = arr[start1] ;
                int rem2 = value2 % 10 ;
                int quot2 = value2 / 10 ;

                arr[start1] = rem2 ;
                arr[start1 - 1]  = arr[start1 - 1] + quot2 ;
            }

            start1-- ;  
        }
        start-- ;
         
    }


    
    // last step
    // Now our array is filled with the right values
    // we convert our arr of integers to a string 
    string result = "" ;
    for (int i = N-1; i>0; i--){
        if (arr[i]!= 0){
            int j=i;
        }
        result.append( to_string(arr[i]) ) ;
    }
    result.pop_back();
    reverse(result.begin(),result.end());


    // then we return the string result
    
    cout << result ;

    return 0 ;

}


