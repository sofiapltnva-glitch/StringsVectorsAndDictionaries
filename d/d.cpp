﻿﻿/****************************
* Платонова Софья           *
* Строки, векторы и словари *
* Вариант (D)               *
****************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>

using namespace std;

int main() {
  int n;

  if (!(cin >> n) || n < 0 || n > 100) {
    cout << "INVALID";
    return 0;
  }

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<map<string, string>> records;
  vector<string> result;

  for (int i = 0; i < n; i++) {
    string sender, text;

    if (!getline(cin, sender) || !getline(cin, text)) {
      cout << "INVALID";
      return 0;
    }

    records.push_back({
        { "sender", sender },
        { "text", text }
    });
  }

  for (const auto& record : records) {
    for (string key : {"sender", "text"}) {
      auto field = record.find(key);

      if (field == record.end()) {
        cout << "INVALID";
        return 0;
      }

      const string& s = field->second;

      if (s.empty() || s.size() > 200 ||
        s.front() == ' ' || s.back() == ' ') {
        cout << "INVALID";
        return 0;
      }

      for (unsigned char c : s) {
        if (c > 127) {
          cout << "INVALID";
          return 0;
        }
      }
    }
  }

  for (const auto& record : records) {
    if (record.at("text").size() > 20) {
      result.push_back(
        record.at("sender") + " " +
        to_string(record.at("text").size())
      );
    }
  }

  if (result.empty()) {
    cout << "EMPTY";
  }

  for (const string& s : result) {
    cout << s << '\n';
  }

  return 0;
}