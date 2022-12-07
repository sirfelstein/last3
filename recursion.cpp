#include <cctype>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void pattern(int n, int col);

int main(){

        int stars;
        int spaces;
        cout << "Enter a number"<<endl;
        cin >> stars;
        cout << "Enter a second number"<<endl;
        cin >> spaces;
        cout<<endl;
        pattern(stars, spaces);
        cout<<endl;

return 0;
}

void pattern(int n, int col){

if (n == 0) return;

if (n == 1){

        for (int a = 0;a<2*col;a++){
                cout<<" ";  
        }
        cout<<"* ";
        cout<<endl;
return;
}

else{

        pattern(n-2, col+1);
        for (int a = 0; a < 2*col; a++){
                cout<<" ";
        }

        for (int b = 0; b < n; b++){
                cout<<"* ";
        }
 
        cout<<endl;

        pattern(n-2, 1+col);
 
 }
 }