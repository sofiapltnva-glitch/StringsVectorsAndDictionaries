﻿﻿/****************************
* Платонова Софья           *
* Строки, векторы и словари *
* Вариант (C)               *
****************************/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  int n, x, threshold;
  string key;
  map<string, int> a, result;

  if (!(cin >> n) || n < 0 || n > 100) {
    cout << "INVALID";
    return 0;
  }

  for (int i = 0; i < n; i++) {
    if (!(cin >> key >> x) ||
      key.size() > 40 || x < -1000 || x > 1000) {
      cout << "INVALID";
      return 0;
    }

    for (unsigned char c : key) {
      if (c > 127) {
        cout << "INVALID";
        return 0;
      }
    }

    a[key] = x;
  }

  if (!(cin >> threshold) ||
    threshold < -1000 || threshold > 1000) {
    cout << "INVALID";
    return 0;
  }

  for (const auto& p : a) {
    if (p.second >= threshold) {
      result[p.first] = p.second;
    }
  }

  if (result.empty()) {
    cout << "EMPTY";
  }

  for (const auto& p : result) {
    cout << p.first << ' ' << p.second << '\n';
  }

  return 0;
}