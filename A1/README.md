
## Q1: String and array Manipulation
Note: All these questions are to be done using character arrays and string datatype is
not allowed
Marks: 10
1. Given a paragraph as a character array, write a c++ program to remove a substring from
that paragraph. Your function should return the original array after removing the input
array.<br>
Function Prototype:
```
char* removeSentence(char* Para, char* input);
For Example:
Consider the following paragraph,
“I am currently studying OOP course. I hope to pass it. I might fail.”
Input: “I hope to pass it.”
Resulting paragraph will be as follows:
“I am currently studying OOP course. I might fail.”
```
Marks: 10
3. Given a char array, find if a subarray exists in that array. The array has to be treated as
circular. Your function should return a Boolean true or false.<br>
Function Prototype:<br>
bool FindSubString(char* Str, char* substr,int & start, int & end);<br>
For Example:<br>
```
Consider the following array,
“abcdab”
Input: “cda”
Output : return true , start =2 , end=4
Input: “dababc”
Output : return true , start =3 , end=2
Input: “bad”
Output : return false , start =-1 , end=-1
```
## Q3: Recursive Functions
Marks: 10
1. Given a number n, write a recursive function whether it is a perfect number or not. Your
function should return true or false. A perfect number is a positive integer that is equal to
the sum of its proper divisors.<br>
Example:<br>
6 is a perfect number, which is a sum of 1, 2 and 3 which are the divisors of 6.
Function Prototype: bool isperfectNumber(int n);<br>
Marks: 10<br>
2. Given a string, write a recursive function to find and return the total number of vowels.
Function Prototype: int findVowels(char* str);<br>
Marks: 10<br>
3. Write a C++ recursive program to compute the value of a given position in Pascal's
Triangle. Your function should return the value at that index in Pascal’s triangle. The entire<br>
implementation must be done recursively.<br>
Function Prototype: int pascal(int row,int col);<br>
```
Input : Row = 2, Col = 1
Output : 2
Input : Row = 4, Col = 2
Output : 6
```
Marks: 15<br>
4. Write a C++ recursive function to print following pattern. No loops allowed whatsoever,
and you can write other helping (recursive) functions. Your function prototype must be
as follows:<br>
void PrintPattern1(int start, int end);<br>
For example, calling your function with these argument PrintPattern1(1,10) should print
following pattern.<br>
<br>
Marks: 20<br>
5. Write a C++ code to recursively print a hollow diamond structure. No loops are allowed
whatsoever, and you can use helper functions. The function prototype is as follows:
void printHollowDiamond(int n);<br>
Here n is the number of stars.<br>
Example: printHollowDiamond(5) will give us the following output<br>

Marks: 15
6. Write a C++ recursive function PrintPattern2 to print following pattern using recursion.
No loops allowed whatsoever, and you can write other helping (recursive) functions
(other than main). Your function prototype must be as follows:
void PrintPattern2(int , int );<br>
Example 1: PrintPattern2(5,5);<br>

Example 2:<br>
PrintPattern2(6,6);<br>















