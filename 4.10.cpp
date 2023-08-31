#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    char charr[20];
    string str;

    cout << "length of string in charr before input:" << strlen(charr) << endl;
    cout << "length of string in str before input:" << str.size() << endl;
    cout << "enter a line of text:\n";
    cin.getline(charr, 20);
    cout << "you entered:" << charr << endl;
    cout << "enter another line of text:\n";
    getline(cin, str);
    cout << "you entered:" << str << endl;
    cout << strlen(charr) << " " << str.size() << endl;
}