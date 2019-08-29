#include <unordered_map>

using namespace std;

typedef struct TrieNode {
  unordered_map<char, TrieNode*> keys;
  bool endOfWord;
  int freq;
  TrieNode() : freq(0), endOfWord(false) {}
} TrieNode;