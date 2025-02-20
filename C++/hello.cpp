# include <iostream>
# include <cmath>
using namespace std;


int main() {
    int age ;
    cout << "Enter your age :";
    cin >> age;
    if(age<18){
        cout << "You are eligible for Minor PAN card\n";
    }else if (age>=18){
        cout << "You are eligible for Major PAN card\n";
    }else{
        cout << "Inavlid Input";
    }
    return 0;
}