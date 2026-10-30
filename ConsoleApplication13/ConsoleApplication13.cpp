/****************************
* Платонова Софья           *
* Строки, векторы и словари *
* Вариант 22 (B)            *
****************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;

  cout << "Enter the number of elements ";

  if (!(cin >> n) || n < 0 || n > 100) {
    cout << "INVALID";
    return 0;
  }

  vector<int> a(n);

  cout << "Enter the element ";

  for (int& x : a) {
    if (!(cin >> x) || x < -1000 || x > 1000) {
      cout << "INVALID";
      return 0;
    }
  }

  sort(a.begin(), a.end());

  if (a.empty()) {
    cout << "EMPTY";
  }

  cout << "Result ";

  for (int i = 0; i < n; i++) {
    if (i > 0) cout << ' ';
    cout << a[i];
  }

  return 0;
}