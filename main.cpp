#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    float quantity1, cost1, quantity2, cost2;
    char num;
    string name1, date1, name2, date2;

    while (true)
    {
        cout << "vvedite chislo: ";
        cin >> num;

        switch (num)
        {
        case '1':
            cout << "vvedite dannue o produkte: " << endl;
            cout << "name: ";
            cin >> name1;
            cout << "cost: ";
            cin >> cost1;
            cout << "quantity: ";
            cin >> quantity1;
            cout << "date: ";
            cin >> date1;

            string path = "myFile.txt";

            ofstream fout;
            fout.open(path/*,ofstream::app */);


            if (!fout.is_open())
            {
                cout << "error with open file" << endl;
            }
            else
            {
                cout << "File open" << endl;
                fout << "\n" << name1 << "\n" << cost1 << "\n" << quantity1 << "\n" << date1 << "\n";
            }

            fout.close();

            ifstream fin;
            fin.open(path);

            if (!fin.is_open())
            {
                cout << "error with open file" << endl;
            }
            else
            {
                cout << "file open" << endl;
                char ch;
                while (fin.get(ch))
                {
                    cout << ch;
                }

                fin.close();

                break;

        case '2':

            cout << "vvedite dannue o produkte: " << endl;
            cout << "name: ";
            cin >> name2;
            cout << "cost: ";
            cin >> cost2;
            cout << "quantity: ";
            cin >> quantity2;
            cout << "date: ";
            cin >> date2;

            string path = "myFile.txt";

            ofstream fout;
            fout.open(path/*,ofstream::app */);


            if (!fout.is_open())
            {
                cout << "error with open file" << endl;
            }
            else
            {
                cout << "File open" << endl;
                fout << "\n" << name2 << "\n" << cost2 << "\n" << quantity2 << "\n" << date2 << "\n";
            }

            fout.close();

            ifstream fin;
            fin.open(path);

            if (!fin.is_open())
            {
                cout << "error with open file" << endl;
            }
            else
            {
                cout << "file open" << endl;
                char ch;
                while (fin.get(ch))
                {
                    cout << ch;
                }

                fin.close();

                break;
            }
            }
        }
    }
