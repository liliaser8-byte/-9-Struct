<img width="972" height="473" alt="image" src="https://github.com/user-attachments/assets/954ed8e4-fb23-4b67-a6d6-202514c0ca8d" />
Програма зчитує дані про 8 людей, включаючи ім’я, знак Зодіаку та дату народження, і зберігає їх у масиві структур Zodiak. Потім вона сортує масив за місяцем народження і виводить інформацію про людей, народжених у вказаний користувачем місяць, або повідомляє, якщо таких немає. Таким чином, користувач може швидко знайти людей за місяцем народження.


#include <iostream>
#include <string>
#include <windows.h> // для SetConsoleCP і SetConsoleOutputCP
using namespace std;

// Структура Zodiak
struct Zodiak {
    string fullname;   // Прізвище і ім'я
    string sign;       // Знак Зодіаку
    int birth[3];      // Дата народження: день, місяць, рік
};

// Функція для сортування масиву за місяцем народження
void sortByMonth(Zodiak arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i].birth[1] > arr[j].birth[1]) { // birth[1] - місяць
                Zodiak temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Функція для виведення людей за місяцем народження
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

    // Введення даних з клавіатури
    for (int i = 0; i < SIZE; i++) {
        cout << "Введіть дані для людини " << i + 1 << ":\n";
        cout << "Прізвище і ім'я: ";
        getline(cin, people[i].fullname);
        cout << "Знак Зодіаку: ";
        getline(cin, people[i].sign);
        cout << "Дата народження (день місяць рік через пробіл): ";
        cin >> people[i].birth[0] >> people[i].birth[1] >> people[i].birth[2];
        cin.ignore(); // очищаємо буфер після вводу чисел
    }

    // Сортування за місяцем народження
    sortByMonth(people, SIZE);

    // Введення місяця для пошуку
    int searchMonth;
    cout << "\nВведіть номер місяця для пошуку: ";
    cin >> searchMonth;

    // Виведення результату
    printByMonth(people, SIZE, searchMonth);

    return 0;
}
<img width="1777" height="924" alt="image" src="https://github.com/user-attachments/assets/a4da60a7-ff6d-40b1-8187-2f31f115616f" />


Чек-лист знань (`checklist.md`)
**Тема:** Структури (struct) у C++
### 🔹 Теоретичні знання
- [+] Знаю, що таке структура і для чого вона потрібна.  
- [+] Можу оголосити структуру та пояснити її поля.  
- [+] Знаю, як створити змінну структури та звертатися до її полів.  

### 🔹 Практичні навички
- [+] У коді є структура з кількома полями.  
- [+] Реалізовано введення і виведення даних.  
- [+] Програма обробляє масив структур (сортування, фільтрація тощо).  
- [+] Код має коментарі та працює без помилок.  

### 🔹 Робота з GitHub / Gist
- [+] Є файли `main.cpp` і `README.md`.  
- [+] README.md містить алгоритм, приклад виконання та висновок.  
- [+] Репозиторій / Gist має зрозумілу назву та структуровану організацію.  

### 🔹 Самооцінка
- [+] Можу пояснити роботу своєї структури.  
- [+] Розумію, як можна вдосконалити програму.  
- [+] Знаю, в яких задачах доцільно використовувати struct.
