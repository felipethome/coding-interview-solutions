#include <iostream>
#include <vector>

#include "trie.h"

using namespace std;

void insertWord(TrieNode **root, string str) {
  if (*root == NULL) *root = new TrieNode();

  TrieNode *curr = *root;

  for (int i = 0; i < str.length(); i++) {
    curr->freq++;

    if (curr->keys.find(str[i]) != curr->keys.end()) {
      curr = (curr->keys.find(str[i]))->second;
    }
    else {
      curr->keys[str[i]] = new TrieNode();
      curr = curr->keys[str[i]];

      if (i == str.length() - 1) curr->endOfWord = true;
    }
  }
}

vector<string> findUniquePrefixes(vector<string> &a) {
  vector<string> ans;

  if (a.size() == 0) return ans;

  TrieNode *root = NULL;

  for (int i = 0; i < a.size(); i++) {
    insertWord(&root, a[i]);
  }

  for (int i = 0; i < a.size(); i++) {
    string temp = "";
    TrieNode *curr = root;

    for (int j = 0; j < a[i].size(); j++) {
      temp += a[i][j];
      curr = (curr->keys.find(a[i][j]))->second;
      if (curr->freq <= 1) {
        ans.push_back(temp);
        break;
      }
    }
  }

  return ans;
}

int main() {
  vector<string> a = {"zebra", "dog", "duck", "dove"};

  vector<string> r = findUniquePrefixes(a);

  for(int i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
  }
  cout << endl;

  return 0;
}