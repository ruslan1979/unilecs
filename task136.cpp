// UniLecs # 136
// custom implementation of indexOf and lastIndexOf functions
#include <iostream>
#include <string>

using namespace std;

pair<int, int> indexOf(string str, char ch) {
    int count = 0, first = -1, last = -1;
    for (int i = 0; i != str.length(); ++i) {
        if (str[i] == ch) {
            if (count == 0)
                first = i;

            last = i;
            count++;
        }
    }

    return make_pair(first, last);
}

// the function's usage
int main() {
    string str;
    char ch;
    cin >> str >> ch;
    pair<int, int> isfound = indexOf(str, ch);

    cout << isfound.first << " " << isfound.second << endl;
    return 0;
}