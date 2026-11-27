#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> words;

        string current = "";
        int number = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                number = number * 10 + (ch - '0');
            }

            else if (ch == '[') {
                counts.push(number);
                words.push(current);

                number = 0;
                current = "";
            }

            else if (ch == ']') {
                int repeat = counts.top();
                counts.pop();

                string previous = words.top();
                words.pop();

                string temp = "";

                for (int i = 0; i < repeat; i++) {
                    temp += current;
                }

                current = previous + temp;
            }

            else {
                current += ch;
            }
        }

        return current;
    }
};
