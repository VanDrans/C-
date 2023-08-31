#include<iostream>
int main()
{
    using namespace std;
    cout<<"what year was your house built?\n";
    int year;
    cin>>year;
    cin.get();
    cout << "你在那里?\n";
    char adress[80];
    cin.getline(adress, 80);
    cout<< "year built" << year << endl;
    cout << "Adress" << adress << endl;
    cout << "done!\n";
    return 0;
}
