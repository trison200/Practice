#include <iostream>
#include <functional>

using namespace std;

int func(int a){
    return a * a;
}

int main(){
    int x; cin >> x;
    int(*funcPtr)(int)  = func; 
    cout << funcPtr << endl;
    cout << funcPtr(x) << endl;
    return 0;
}