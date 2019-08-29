/**
 * Pretty print a JSON object using proper indentation. Your solution should
 * return a list of strings, where each entry corresponds to a single line. The
 * strings should not have “\n” character in them.
 * 
 * 1. Every inner brace should increase one indentation to the following lines.
 * 2. Every close brace should decrease one indentation to the same line and the
 * following lines.
 * 3. The indents can be increased with an additional ‘\t’
 * 4. [] and {} are only acceptable braces in this case.
 * 
 * Assume for this problem that space characters can be done away with.
 *
 * Example:
 * 
 * Given {A:"B",C:{D:"E",F:{G:"H",I:"J"}}}
 * Output, 
 * { 
 *     A:"B",
 *     C: 
 *     { 
 *         D:"E",
 *         F: 
 *         { 
 *             G:"H",
 *             I:"J"
 *         } 
 *     }     
 * }
 *
 * Given ["foo", {"bar":["baz",null,1.0,2]}]
 * Output, 
 * [
 *     "foo", 
 *     {
 *         "bar":
 *         [
 *             "baz", 
 *             null, 
 *             1.0, 
 *             2
 *         ]
 *     }
 * ]
 *
 * Time complexity: O(N), where N is the length of the given string.
 * Space complexity: O(N).
 *
 * Explanation: nothing much to talk about here, just take care with some
 * possible cases:
 * 
 * 1. Ignore spaces, the exercise ask you for doing that, so don't forget.
 * 2. Add/remove indentation.
 * 3. Properly add commas that can come after closing braces.
 * 4. Remove one indentation before inserting a closing brace.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<string> prettyJSON(string a) {
  vector<string> ans;
  int i = 0, level = 0;

  while (i < a.size()) {
    // Ignore white spaces
    if (a[i] == ' ') {
      i++;
      continue;
    }

    string line = "";
    // Insert the proper indentation.
    for (int i = 0; i < level; i++) line.push_back('\t');

    // For opening braces we increment the indentation and add it to the answer.
    if (a[i] == '{' || a[i] == '[') {
      line.push_back(a[i] == '{' ? '{' : '[');
      level++;
      i++;
    }
    // For closing braces we decrement the indentation and add it to the answer.
    // Remove one indentation because the closing braces come one indentation
    // before the previous content.
    else if (a[i] == '}' || a[i] == ']') {
      line.pop_back();
      line.push_back(a[i] == '}' ? '}' : ']');
      level--;
      i++;
    }
    else {
      // Insert everything that we can into our line and increment i. Here, we
      // also need to ignore spaces.
      while (i < a.size() && a[i] != ',' && a[i] != '}' && a[i] != ']' &&
        a[i] != '{' && a[i] != '[') {
        if (a[i] != ' ') line.push_back(a[i]);
        i++;
      }
    }

    // Commas can come after a value or after a closing brace, in both ways
    // they are part of the current line, so we check for it here instead of
    // inside the "else" above.
    if (i < a.size() && a[i] == ',') {
      line.push_back(',');
      i++;
    }

    ans.push_back(line);
  }

  return ans;
}

int main() {
  // string a = "{A:\"B\",C:{D:\"E\",F:{G:\"H\",I:\"J\"}}}";
  string a = "[\"foo\", {\"bar\":[\"baz\",null,1.0,2]}]";

  vector<string> r = prettyJSON(a);

  for (string e : r) {
    cout << e << endl;
  }
  cout << endl;

  return 0;
}