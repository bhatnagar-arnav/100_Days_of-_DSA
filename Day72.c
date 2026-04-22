/*Problem Statement
Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

Input Format
A single string s.

Output Format
Print the first repeated character. If no character is repeated, print -1.

Sample Input
geeksforgeeks

Sample Output
e
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int seen[26] = {0};   // track occurrences of each character
    int firstRepeatIndex = -1;
    char result = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';
        if (seen[idx]) {  // already seen before
            firstRepeatIndex = i;
            result = s[i];
            break;        // stop at first repeated (second occurrence earliest)
        }
        seen[idx] = 1;
    }

    if (firstRepeatIndex == -1) printf("-1\n");
    else printf("%c\n", result);

    return 0;
}
