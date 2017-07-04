#include <iostream>
#include <vector>
#include <string>

using namespace std;

// This is Chapter 5 drill. It is focused on getting the feel for various compiler errors.
// This code compiles, but it is useful to see how the compiler reacts to different errors

int main()
    try {
              int x = 4; double d = 5/(x-2); if (d==2*x+0.5) cout << "Success!\n";
              return 0;
    }
    catch (exception& e) {
              cerr << "error: " << e.what() << '\n';
              return 1;
    }
    catch (...) {
              cerr << "Oops: unknown exception!\n";
              return 2;
}
