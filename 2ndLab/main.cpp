#include "Six.hpp"

using namespace std;

int main() {
    Six a("111");
    Six b("222");
    Six c("112");
    Six d("113");
    cout << "========" << endl;
    Six q = a + b;
    cout << "========" << endl;

    Six r;
    r = c + d;
    cout << "========" << endl;

    cout << r;
    return 0;
}