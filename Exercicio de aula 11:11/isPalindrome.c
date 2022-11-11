/*
  9. Palindrome Number
    Given an integer x, return true if x is a palindrome, and false otherwise.

  link: https://leetcode.com/problems/palindrome-number/description/
*/

bool isPalindrome(int x){
    if(x < 0){
        return false;
    } else if (x == 0){
        return true;
    }
    
    int inverse = 0, data = x;

    while(x != 0){
        inverse *= 10;
        inverse += data % 10;
        data /= 10;
    }

    if(inverse == x) {
        return true;
    } else {
        return false;
    }
}