#include <iostream>
#include <iomanip>
#include <string>
#include "dictionary.h"

int main() {
  int array_length = 8;
  std::string words[] = {"Camel", "Dog", "Fish", "Horse",
                         "Lion", "Monkey", "Panda", "Zebra"};

  std::cout << "Minimum word length: " 
            << MinWordLength(words, array_length) << std::endl;

  std::cout << "Maximum word length: " 
            << MaxWordLength(words, array_length) << std::endl;

  std::cout << "Word length Range: " 
            << WordLengthRange(words, array_length) << std::endl;

  std::cout << "Average word length: " << std::fixed << std::setprecision(2) 
            << AverageWordLength(words, array_length) << std::endl;

  std::cout << "Most common word length: " 
            << MostCommonWordLength(words, array_length) << std::endl;

  return 0;
}