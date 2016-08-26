// A dynamic programming solution for longest palindr.
// This code is adopted from following link
// http://www.leetcode.com/2011/11/longest-palindromic-substring-part-i.html

#include <stdio.h>
#include <string.h>

// A utility function to print a substring str[low..high]
void printSubStr(char* str, int low, int high) {
  int i;
  for (i = low; i <= high; ++i)
    printf("%c", str[i]);
}

// This function prints the longest palindrome substring
// of str[].
// It also returns the length of the longest palindrome
int longestPalSubstr(char *str) {

	int n = strlen(str); // get length of input string

  printf("string length: %d\n", n);

  int i;
  // table[i][j] will be false if substring str[i..j]
  // is not palindrome.
  // Else table[i][j] will be true
  int table[n][n];
  memset(table, 0, sizeof(table));

  // All substrings of length 1 are palindromes
  int maxLength = 1;
  for (i = 0; i < n; ++i)
    table[i][i] = 1;

  // check for sub-string of length 2.
  int start = 0;
  for (i = 0; i < n - 1; ++i) {
    if (str[i] == str[i + 1]) {
      table[i][i + 1] = 1;
      start = i;
      maxLength = 2;
    }
  }

  // Check for lengths greater than 2. k is length
  // of substring
  int k;
  for (k = 3; k <= n; ++k) {
    // Fix the starting index
    for (i = 0; i < n - k + 1; ++i) {
      // Get the ending index of substring from
      // starting index i and length k
      int j = i + k - 1;

      // checking for sub-string from ith index to
      // jth index iff str[i+1] to str[j-1] is a
      // palindrome
      if (table[i + 1][j - 1] && str[i] == str[j]) {
        table[i][j] = 1;

        if (k > maxLength) {
          start = i;
          maxLength = k;
        }
      }
    }
  }

  printf("Longest palindrome substring is: ");
  printSubStr(str, start, start + maxLength - 1);

  return maxLength; // return length of LPS
}

// Driver program to test above functions
int main(int argc, char **argv) {

  char str2[1000];

  char *arquivo = "sampleinput.txt";

  if(argc > 1)
    arquivo = argv[1];

  memset(str2, ' ', sizeof(str2));
  str2[999] = '\0';

  FILE *f = fopen(arquivo, "r");
  fread(str2, 999, sizeof(char), f);

  int n = strlen(str2); // get length of input string

  printf("\nLength is: %d\n", longestPalSubstr(str2));

  return 0;
}
