#include <bits/stdc++.h>
using namespace std;
void zigZag(int cols){
    for(int r=1; r<=3; r++){
        for(int c=1; c<=cols; c++){
            if((r==1 && c%4 == 3) || (r==2 && c%2 == 0) || (r==3 && c%4 == 1)){
                cout << "* ";
            }else{
                cout << "  ";
            }
        }cout << endl;
    }
}
int main() {
    zigZag(9);
    zigZag(13);
    return 0;

}
