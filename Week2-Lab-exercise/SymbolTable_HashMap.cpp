#include <bits/stdc++.h>
using namespace std;

class ST {
  string datatype;
  string key;
  string value;

public:
  ST(string d, string k, string v) {
    datatype = d;
    key = k;
    value = v;
  }
  // function to get key
  string getType() { return datatype; }
  string getKey() { return key; }
  // function to get value
  string getValue() { return value; }
};

// Hashmap
unordered_map<string, ST *> SymbolTable;

// Function to insert
void insert(string datatype, string key, string value) {
  if (SymbolTable.find(key) == SymbolTable.end())
    SymbolTable[key] = new ST(datatype, key, value);
}

// Function to get value for a given key
string get(string key) {
  if (SymbolTable.find(key) == SymbolTable.end())
    return "NULL";
  else
    cout << SymbolTable[key]->getType() << " " << SymbolTable[key]->getKey()
         << " " << SymbolTable[key]->getValue();
  return "True";
}

// Function to get key for a given value
string getKey(string value) {
  unordered_map<string, ST *>::iterator itr;
  for (itr = SymbolTable.begin(); itr != SymbolTable.end(); itr++) {
    if (itr->second->getValue() == value)
      return itr->second->getKey();
  }
}

// Driver code
int main() {
  insert("int", "A", "1");
  insert("char", "char1", "B");
  insert("string", "str1", "SRM University");
  insert("float", "D", "3.14");

  get("str1");
  cout << "\n";
  cout <<getKey("3.14")<< endl;

  return 0;
}
