#include <iostream>
using namespace std;
class Bool {
    int x;
public: Bool();
    void get();
    void show();
    Bool operator || (const Bool & );
    Bool operator * (const Bool & );
    Bool operator ^ (const Bool & );
    Bool operator || (const int);
    Bool operator * (const int);
    Bool operator ^ (const int);
    friend bool operator == (Bool, Bool);
    friend bool operator != (Bool, Bool);
};
Bool::Bool()
{
    x = 0;
}
void Bool::get()
{
    int n;
    cin >> n;
    if (n == 0)
        x = 0;
    else if (n == 1)
        x = 1;
    else if (n != 0)
        x = 1;
}
void Bool::show()
{
    cout << x << endl;
}
// surpascreire la ||
Bool Bool::operator || (const Bool & obj)
{
    Bool * sum = new Bool();
    if ((x == obj.x) && (obj.x == 0))
        sum -> x = 0;
    else if ((x == 1) || (obj.x == 1))
        sum -> x = 1;
    return *sum;
}
Bool Bool::operator || (const int a)
{
    Bool * sum = new Bool();
    if ((x == a) && (a == 0))
        sum -> x = 0;
    else if ((x == 1) || (a == 1))
        sum -> x = 1;
    return *sum;
}
Bool Bool::operator * (const Bool & obj)
{
    Bool * prod = new Bool();
    if ((x == obj.x) && (obj.x == 1))
        prod -> x = 1;
    else if ((x == 0) || (obj.x == 0))
        prod -> x = 0;
    return *prod;
}
Bool Bool::operator * (const int a)
{
    Bool * prod = new Bool();
    if ((x == a) && (a == 1))
        prod -> x = 1;
    else if ((x == 0) || (a == 0))
        prod -> x = 0;
    return *prod;
}
Bool Bool::operator ^ (const Bool & obj)
{
    Bool * sum = new Bool();
    if ((x == obj.x) && ((obj.x == 1) || (obj.x == 0)))
        sum -> x = 0;
    else if ((x == 1) || (obj.x == 1))
        sum -> x = 1;
    return *sum;
}
Bool Bool::operator ^ (const int a)
{
    Bool * sum = new Bool();
    if ((x == a) && ((a == 1) || (a == 0)))
        sum -> x = 0;
    else if ((x == 1) || (a == 1))
        sum -> x = 1;
    return *sum;
}
bool operator != (Bool A, Bool B) {
    bool n;
    if (A.x != B.x)
        n = true;
    else
        n = false;
    return n;
}
bool operator == (Bool A, Bool B)
{
    bool n;
    if (A.x == B.x)
        n = true;
    else
        n = false;
    return n;
}
int main()
{
    Bool A, B;
    Bool * t = new Bool();
    int op;
    while (1)
    {
        cout << "\nMeniu" << endl;
        cout << "[1] Introducerea variabelelor logice" << endl;
        cout << "[2] Afisarea variabelelor logice" << endl;
        cout << "[3] Operatiunea OR" << endl;
        cout << "[4] Operatiunea AND" << endl;
        cout << "[5] Operatirunea XOR" << endl;
        cout << "[6] Verifica pentru egalitate" << endl;
        cout << "[0] Iesire" << endl;
        cin >> op;
        switch (op)
        {
            case 1:
                cout << "Introduceti prima variabila" << endl;
                A.get();
                cout << "Introduceti adoua variabila" << endl;
                B.get();
                cout << "Introducerea a avut loc cu succes!" << endl;
                break;
            case 2:
                cout << "Variabilele logice:\n";
                A.show();
                B.show();
                break;
            case 3:
                * t = A || B;
                cout << " A + B = ";
                t -> show();
                cout << "\n";
                break;
            case 4:
                * t = A * B;
                cout << " A * B = ";
                t -> show();
                cout << "\n";
                break;
            case 5:
                * t = A ^ B;
                cout << " A ^ B = ";
                t -> show();
                cout << "\n";
                break;
            case 6:
                if (A == B)
                    cout << "Variabilele sunt egale" << endl;
                else if (A != B)
                    cout <<"Variabilele nu sunt egale" << endl;
                break;
            case 0:
                exit(0);

        }
    }
    return 0;
}


