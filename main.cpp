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
        case 5:
            sortToFile();
            break;
        case 6:
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
    cout << "5 - leave from program\n";
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

/*void sortToFile()
{
    for (int i = 0; i < product_index; i++)
    {
        if (arr[i].cost > arr[i + 1].cost)
        {
            arr[i + 1] = arr[i];

            /*arr[i + 1].name = arr[i].name;
            arr[i + 1].cost = arr[i].cost;
            arr[i + 1].quantity = arr[i].quantity;
            arr[i + 1].date = arr[i].date;
        }
    }*/

    /*for (int i = 0; i < product_index; i++)
    {
        cout << i << "\t" << arr[i].name << "\t" << arr[i].cost << "\t" << arr[i].quantity << "\t" << arr[i].date << endl;
    }
    cout << "\n";*/

    /*ofstream fout;
    fout.open(fileName, ios::binary);
    fout.write((char*)arr, sizeof(sproduct) * product_index); // навіщо множиться на product_index
    fout.close();
    cout << "Data saved\n";*/
}
