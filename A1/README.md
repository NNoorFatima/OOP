
Q1: String and array Manipulation
Note: All these questions are to be done using character arrays and string datatype is
not allowed
Marks: 10
1. Given a paragraph as a character array, write a c++ program to remove a substring from
that paragraph. Your function should return the original array after removing the input
array.
Function Prototype:
char* removeSentence(char* Para, char* input);
For Example:
Consider the following paragraph,
“I am currently studying OOP course. I hope to pass it. I might fail.”
Input: “I hope to pass it.”
Resulting paragraph will be as follows:
“I am currently studying OOP course. I might fail.”
Marks: 10
2. Given a char array, find if a subarray exists in that array. The array has to be treated as
circular. Your function should return a Boolean true or false.
Function Prototype:
bool FindSubString(char* Str, char* substr,int & start, int & end);
For Example:
Consider the following array,
“abcdab”
Input: “cda”
Output : return true , start =2 , end=4
Input: “dababc”
Output : return true , start =3 , end=2
Input: “bad”
Output : return false , start =-1 , end=-1
