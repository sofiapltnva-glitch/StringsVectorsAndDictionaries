/****************************
* Платонова Софья           *
* Строки, векторы и словари *
* Вариант 22 (A)            *
****************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
  string imputUser, word, result;

  cout << "Enter a string ";

  if (!getline(cin, imputUser) || imputUser.size() > 200) {
    cout << "INVALID";
    return 0;
  }

  imputUser += ' ';

  for (const auto& element : imputUser) {
    if (element != ' ') {
      word += element;
    } else {
      if (!word.empty() && word[0] >= 'A' && word[0] <= 'Z') {
        if (!result.empty()) {
          result += ' ';
        }

        result += word;
      }

      word.clear();
    }
  }

  if (result.empty()) {
    cout << "EMPTY";
  } else {
    cout << "Result: " << result;
  }

  return 0;
}