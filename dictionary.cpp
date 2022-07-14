#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

/**
* FUNCTION I: MaxWordLength
*
* for (0 <= i < length of the array that stores the words)
*   reset letter count to zero
*     while individual character is not a null terminator
*       increase count by one for the letters in current word being checked
*       go to next character
*     if current word is longer than the current longest word
*       set the max amount of letters equal to the current word's letter count
* return longest word length
**/
int MaxWordLength(string words[], int length) {
  int max_word_length = 0;

  for (int i = 0; i < length; i++)
    if (words[i].size() > max_word_length)
      max_word_length = words[i].size();

  return max_word_length;
}

/** Function II: MinWordLength
*
* for (0 <= i < length of the array that stores the words)
*   reset letter count to zero
*     while individual character is not a null terminator
*       increase count by one for the letters in current word being checked
*       go to next character
*     if current word is shorter than the current shortest word
*       set the minimum amount of letters equal to the current word's letter-
*       - count
* return shortest word length
**/
int MinWordLength(string words[], int length) {
  int min_word_length = MaxWordLength(words, length);

  for (int i = 0; i < length; i++)
    if (words[i].size() < min_word_length)
      min_word_length = words[i].size();

  return min_word_length;
}

/** Function III: WordLengthRange
*
* return (the maximum word length - the minimum word length) by calling
* the find maximum word length and the find minimum word length functions-
* - respectivly
**/
int WordLengthRange(string words[], int length) {
  return MaxWordLength(words, length) - MinWordLength(words, length);
}

/** Function IV: AverageWordLength
*
* for (0 <= i < length of the array that stores the words)
*   reset letter count to zero
*     while individual character is not a null terminator
*       increase count by one for the letters in current word being checked
*       go to next character
*     Replace the previous total number of characters with the new total-
*     - including the current word's letter count
* return total letter count / the amount of words
**/
float AverageWordLength(string words[], int length) {
  float running_total = 0; // The sum of all word lengths

  for (int i = 0; i < length; i++) 
    running_total += (float)words[i].size();

  float return_val = running_total / length;
  //cout << setprecision(2) << return_val;
  return return_val;
}

/** Function V: MostCommonWordLength
*
* for (0 <= i < length of the array that stores the words)
*   reset letter count to zero
*     while individual character is not a null terminator
*       increase count by one for the letters in current word being checked
*       store the word lengths in a matrix, so they can be compared later
*       go to next character
* for (0 <= i < length of the array that stores the words)
*   reset current word length to zero
*   for (0 <= j < length of the array that stores the words)
*     if word length i is equal to word length j
*       increase word length frequency counter by one
*     if current length frequency is greater than the current mode's frequency
*       the mode freq should be set equal to the current word lengths freq
*       set the mode equal to the current word length
* return mode
**/
int MostCommonWordLength(string words[], int length) {
  int word_lengths[length],
      mode = 0,
      mode_freq = 0,
      current_word_length_freq = 0;

  for (int i = 0; i < length; i++) 
    word_lengths[i] = words[i].size();

  for (int i = 0; i < length; i++) {
    current_word_length_freq = 0;

    for (int j = 0; j < length; j++)
      if (word_lengths[i] == word_lengths[j])
        current_word_length_freq++;

    if (current_word_length_freq > mode_freq) {
      mode_freq = current_word_length_freq;
      mode = word_lengths[i];
    }
  }

  return mode;
}
