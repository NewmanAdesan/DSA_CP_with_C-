
#include<bits/stdc++.h>
using namespace std;

   

int main(){


    string a = "6547232" ;
    string b = "546484" ;

  
    /************************************************************
    * First Step                                                *
    * make string a the smaller operand                         *
    * remember how we multiply right                            *
    * smaller opereand is below and bigger operand is above     *
    *************************************************************/
    if (a.length() > b.length()){
        string temp = a;
        a = b ;
        b = temp;
    }


    /************************************************************
    * Second Step                                               * 
    * let declare our integer array                             *
    * where we store and update our multiplication result       *
    * of course you also know it has to have length of          *
    * like twice the bigger operands length right?              *
    * "Flow with me here"                                       *
    ************************************************************/
    int N = 2*b.length() + 2;
    int arr[N]  = {0};


    /************************************************************
    * Third Step                                                *
    * The Main driver, our nested loop that does all the work   *
    * first we initiate where to start input value into our array
    *************************************************************/
    int start = N ;
    
    // next loop through the smaller operand from the back
    // remember that how we multiply             
    for (int l = a.length() - 1;  l >= 0;  l--){
        int i = a[l] - '0' ;                               // turn each element of operand to integers 
        int start1 = start - 1 ;                           // this helps put value in their right position in our array

        for (int m = b.length() - 1;  m >= 0; m-- ){       // for each loop through elements in bigger operand remeber thats how we multiply
            int j = b[m] - '0' ;
            int value = i * j + arr[start1] ;
            int rem = value % 10 ;
            int quot = value / 10 ;

            arr[start1] = rem ;
            arr[start1 - 1] +=quot ;
        
            start1-- ;  
        }
        start-- ;
    }

    /***********************************************************
    * last step                                                *
    * Now our array is filled with the right values            *
    * we convert our arr of integers to a string               *
    * we need a flag variable so as we loop through so         *
    * we would know when we should start adding numbers        *
    * to our string result                                     *
    *                                                          *
    ***********************************************************/ 
    string result = "" ;
    int flag = 0 ;
    for (int i = 0; i<N; i++){
        if (arr[i]!= 0){
            flag++;}
        if (flag>0){
            result.append( to_string(arr[i]) ) ;}
    }

    // then we return the string result
    cout << result ;

    return 0 ;

}


