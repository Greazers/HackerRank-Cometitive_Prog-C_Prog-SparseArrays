# HackerRank-Cometitive_Prog-C_Prog-SparseArrays
Hacker Rank Problem


Sparse Arrays
There is a collection of input strings and a collection of query strings. For each query string, determine
how many times it occurs in the list of input strings. Return an array of the results.
Example
There are instances of ' , of ' ' and of ' '. For each query, add an element to the return array,
.
Function Description
Complete the function matchingStrings in the editor below. The function must return an array of integers
representing the frequency of occurrence of each query string in strings.
matchingStrings has the following parameters:
string strings[n] - an array of strings to search
string queries[q] - an array of query strings
Returns
int[q]: an array of results for each query
Input Format
The first line contains and integer , the size of .
Each of the next lines contains a string .
The next line contains , the size of .
Each of the next lines contains a string .
Constraints
.
Sample Input
4
aba
baba
aba
xzxb
3
aba
xzxb
ab
2/2
Sample Output
210
Explanation
Here, "aba" occurs twice, in the first and third string. The string "xzxb" occurs once in the fourth string,
and "ab" does not occur at all.


Note: Check Only Implemented Functions:  
        1. bStringCmp() , 
        2. u8StringLen() and
        3. matchingStrings()

