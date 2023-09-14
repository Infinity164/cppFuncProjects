
#include <iostream>
using namespace std;

int main()
{

    short shortmin = -32768;
    short shortmax = 32767;
    
    int intmin = INT32_MIN;
    int intmax = INT32_MAX;

    long long llmax = LLONG_MAX;
    long long llmin = LLONG_MIN;

    unsigned short ushortmin = 0;
    unsigned short ushortmax = USHRT_MAX;

    unsigned int uintmax = UINT32_MAX;
    unsigned int uintmin = 0;

    unsigned long long ullmax = ULLONG_MAX;
    unsigned long long ullmin = 0;

    float floatmax = FLT_MAX;
    float floatmin = FLT_MIN;

    double dmax = DBL_MAX;
    double dmin = DBL_MIN;

    bool one = 1;
    bool zero = 0;

    char chmin = 0;
    char chmax = 255;


    cout << "|TYPE|\t\t|BYTE|\t\t|MIN|\t\t\t|MAX|" << endl;
    cout << "|SHORT|\t\t|" << sizeof(shortmin) << "\t\t|" << shortmin << "\t\t\t|" << shortmax << endl;
    cout << "|INT|\t\t|" << sizeof(INT32_MAX) << "\t\t|" << intmin << "\t\t|" << intmax << endl;
    cout << "|LONG LONG|\t|" << sizeof(LLONG_MAX) << "\t\t|" << llmin << "\t|" << llmax << endl;
    cout << "|ULLONG|\t|" << sizeof(ullmax) << "\t\t|" << ullmin << "\t\t\t|" << llmax << endl;
    cout << "|USHORT|\t|" << sizeof(ushortmax) << "\t\t|" << 0 << "\t\t\t|" << ushortmax << endl;
    cout << "|UINT|\t\t|" << sizeof(UINT32_MAX) << "\t\t|" << 0 << "\t\t\t|" << uintmax << endl;
    cout << "|FLOAT|\t\t|" << sizeof(FLT_MAX) << "\t\t|" << FLT_MIN << "\t\t|" << FLT_MAX << endl;
    cout << "|DOUBLE|\t|" << sizeof(dmax) << "\t\t|" << dmin << "\t\t|" << dmax << endl;
    cout << "|BOOL|\t\t|" << sizeof(one) << "\t\t|" << zero << "\t\t\t|" << one << endl;
    cout << "|CHAR|\t\t|" << sizeof(chmax) << "\t\t|" << 0 << "\t\t\t|" << 255 << endl;
} 