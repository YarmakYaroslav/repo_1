#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

const int MAXLEN = 255;

struct sproduct
{
    char name[MAXLEN];
    int cost;
    int quantity;
    int date;
};

sproduct arr[MAXLEN];

int product_index = 0;

int menu();
void readFromFile(const char* fileName);
void saveToFile(const char* fileName);
void addNew();
void del();
void sortToFile();
void changeToFile();

int main()
{
    while (true)
    {
        switch (menu())
        {
        case 1:
            readFromFile("file.dat");
            break;
        case 2:
            saveToFile("file.dat");
            break;
        case 3:
            addNew();
            break;
        case 4:
            del();
            break;
        case 5:
            sortToFile();
            break;
        case 6:
            changeToFile();
            break;
        case 7:
            return 0;
        default:
            cout << "Wrong choice" << endl;
        }
    }
}

int menu()
{
    cout << "\n";
    int ans;
    cout << "make choice\n";
    cout << "1 - reading file\n";
    cout << "2 - write file\n";
    cout << "3 - adding an entry\n";
    cout << "4 - deleting an entry\n";
    cout << "5 - sort file\n";
    cout << "6 - change file\n";
    cout << "7 - leave from program\n";
    cin >> ans;
    return ans;
}
void readFromFile(const char* fileName)
{
    ifstream fin;
    fin.open(fileName, ios::binary);
    if (!fin)
    {
        cout << "File not found";
    }
    else
    {
        sproduct product;
        product_index = 0;
        while (true)
        {
            fin.read((char*)&product, sizeof(product));
            if (fin.eof())
                break;
            arr[product_index] = product;
            product_index++; // тобто ми переходимо у кінець файлу і читаємо те що знаходиться у кінці
        }
        fin.close();
        cout << "Data read from file\n";
        for (int i = 0; i < product_index; i++)
        {
            cout << i + 1 << "\t" << arr[i].name << "\t" << arr[i].cost << "\t" << arr[i].quantity << "\t" << arr[i].date << endl;
        } // тобто ми переходимо у кінець файлу і читаємо те що знаходиться у кінці
    }
}

void saveToFile(const char* fileName) //функція, що записує дані у бінарний файл
{
    ofstream fout;
    fout.open(fileName, ios::binary);
    fout.write((char*)arr, sizeof(sproduct) * product_index); // навіщо множиться на product_index
    fout.close();
    cout << "Data saved\n";
}

void addNew()//функція, що додає(створює) новий запис
{
    cout << "Adding a new entry\n\n";
    cout << "Writing down the number " << product_index + 1 << "\n";
    //cin.ignore(); //Эта строка игнорирует символ новой строки, который может остаться во входном потоке после предыдущей операции ввода.
    cout << "Nazva productu:  ";
    cin >> arr[product_index].name, MAXLEN; // cin.getline(arr[product_index].name, MAXLEN);
    cout << "Vvedit vartist:  ";
    cin >> arr[product_index].cost;
    cout << "Vvedite kilkist:  ";
    cin >> arr[product_index].quantity;
    cout << "Vvedite datu:  ";
    cin >> arr[product_index].date;

    product_index++;
    cout << "\n";
    for (int i = 0; i < product_index; i++)
    {
        cout << i + 1 << "\t" << arr[i].name << "\t" << arr[i].cost << "\t" << arr[i].quantity << "\t" << arr[i].date << endl;
    }
    cout << "\n";
}

void del()//функція, що видаляє запис
{
    int d;
    cout << "Select the entry number to be deleted ";
    cin >> d;
    for (int i = d - 1; i < product_index; i++)
    {
        arr[i] = arr[i + 1];// :)
    }
    product_index--;

    cout << "\n";
    for (int i = 0; i < product_index; i++)
    {
        cout << i + 1 << "\t" << arr[i].name << "\t" << arr[i].cost << "\t" << arr[i].quantity << "\t" << arr[i].date << endl;
    }
    cout << "\n";
}

void sortToFile()
{
    char changeChar;
    int changeInt;
    for (int j = 0; j < product_index; j++)
    {
        for (int i = 0; i < product_index - 1; i++)
        {
            if (arr[i].cost > arr[i + 1].cost)
            {
                /*change = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = change;*/

                swap(arr[i].name, arr[i + 1].name);
                swap(arr[i].cost, arr[i + 1].cost);
                swap(arr[i].quantity, arr[i + 1].quantity);
                swap(arr[i].date, arr[i + 1].date);

                /*changeChar = arr[i + 1].name;
                arr[i + 1].name = arr[i].name;
                arr[i].name = changeChar;*/

                /*changeInt = arr[i + 1].cost;
                arr[i + 1].cost = arr[i].cost;
                arr[i].cost = changeInt;

                changeInt = arr[i + 1].quantity;
                arr[i + 1].quantity = arr[i].quantity;
                arr[i].quantity = changeInt;

                changeInt = arr[i + 1].date;
                arr[i + 1].date = arr[i].date;
                arr[i].date = changeInt;*/
            }
        }
    }

    for (int i = 0; i < product_index; i++)
    {
        cout << i + 1 << "\t" << arr[i].name << "\t" << arr[i].cost << "\t" << arr[i].quantity << "\t" << arr[i].date << endl;
    }
    cout << "\n";

    /*ofstream fout;
    fout.open(fileName, ios::binary);
    fout.write((char*)arr, sizeof(sproduct) * product_index); // навіщо множиться на product_index
    fout.close();
    cout << "Data saved\n";*/
}

void changeToFile()
{
    int c;
    cout << "Select the entry number to be change ";
    cin >> c;

    cout << "Change entry\n\n";
    cout << "Writing down the number " << c << "\n";
    cout << "Nazva productu:  ";
    cin >> arr[c - 1].name, MAXLEN; // cin.getline(arr[product_index].name, MAXLEN);
    cout << "Vvedit vartist:  ";
    cin >> arr[c - 1].cost;
    cout << "Vvedite kilkist:  ";
    cin >> arr[c - 1].quantity;
    cout << "Vvedite datu:  ";
    cin >> arr[c - 1].date;

    cout << "\n";
    for (int i = 0; i < product_index; i++)
    {
        cout << i + 1 << "\t" << arr[i].name << "\t" << arr[i].cost << "\t" << arr[i].quantity << "\t" << arr[i].date << endl;
    }
    cout << "\n";
}
