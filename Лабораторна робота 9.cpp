#include <iostream>
#include <string>
#include <windows.h> 
using namespace std;

// Структура Zodiak
struct Zodiak {
    string fullname;   // Прізвище і ім'я
    string sign;       // Знак Зодіаку
    int birth[3];      // Дата народження: день, місяць, рік
};

void sortByMonth(Zodiak arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i].birth[1] > arr[j].birth[1]) { 
                Zodiak temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printByMonth(Zodiak arr[], int size, int month) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i].birth[1] == month) {
            cout << "Ім'я: " << arr[i].fullname
                << ", Знак: " << arr[i].sign
                << ", Дата народження: "
                << arr[i].birth[0] << "."
                << arr[i].birth[1] << "."
                << arr[i].birth[2] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Людей, народжених у цьому місяці, немає." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 8;
    Zodiak people[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cout << "Введіть дані для людини " << i + 1 << ":\n";
        cout << "Прізвище і ім'я: ";
        getline(cin, people[i].fullname);
        cout << "Знак Зодіаку: ";
        getline(cin, people[i].sign);
        cout << "Дата народження (день місяць рік через пробіл): ";
        cin >> people[i].birth[0] >> people[i].birth[1] >> people[i].birth[2];
        cin.ignore();
    }

    sortByMonth(people, SIZE);

    int searchMonth;
    cout << "\nВведіть номер місяця для пошуку: ";
    cin >> searchMonth;

    printByMonth(people, SIZE, searchMonth);

    return 0;
}