#include "palindrome.h"

/**
 * is_palindrome - checks wheter or not
 * @n: number to be checked
 * Return: return 1 if n is a palindrome, and 0 otherwise
 */


int is_palindrome(unsigned long n) {
  unsigned long reversed = 0, original = n;
  while (n != 0) {
    reversed = reversed * 10 + n % 10;
    n /= 10;
  }
  return original == reversed;
}