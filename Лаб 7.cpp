#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <windows.h>  

using namespace std;


vector<string> splitWords(const string& s) {
    vector<string> words;
    string word;
    for (char c : s) {
        if (isspace(static_cast<unsigned char>(c)) || ispunct(static_cast<unsigned char>(c))) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) words.push_back(word);
    return words;
}

string reverseStr(const string& s) {
    string r = s;
    reverse(r.begin(), r.end());
    return r;
}


void task1_char() {
    cout << "\n=== Задание 1 (тип char): удалить первую строку, содержащую 'a' ===\n";
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;


    char** matrix = new char* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new char[cols];

        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 'a' + rand() % 26;
        }
    }


    if (rows > 1 && cols > 0) matrix[1][0] = 'a';

    cout << "\nИсходная матрица (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << matrix[i][j];
        cout << '\n';
    }


    int delRow = -1;
    for (int i = 0; i < rows && delRow == -1; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 'a') {
                delRow = i;
                break;
            }
        }
    }

    if (delRow == -1) {
        cout << "\n→ Строка с символом 'a' не найдена.\n";
    }
    else {
        cout << "\n→ Удаляю строку номер " << delRow << "\n";

        for (int i = delRow; i < rows - 1; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = matrix[i + 1][j];
            }
        }
        --rows;

        cout << "\nПосле удаления (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << matrix[i][j];
            cout << '\n';
        }
    }

    for (int i = 0; i < rows + (delRow != -1 ? 1 : 0); ++i)
        delete[] matrix[i];
    delete[] matrix;
}


void task2_string() {
    cout << "\n=== Задание 2 (тип string): перевернуть каждое чётное слово ===\n";
    string input;
    cout << "Введите строку (слова через пробелы): ";
    getline(cin >> ws, input);

    auto words = splitWords(input);
    string result;
    for (size_t i = 0; i < words.size(); ++i) {
        if ((i + 1) % 2 == 0) {
            result += reverseStr(words[i]);
        }
        else {
            result += words[i];
        }
        if (i < words.size() - 1) result += " ";
    }

    cout << "\nИсходная строка: \"" << input << "\"\n";
    cout << "Результат:      \"" << result << "\"\n";
}


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    srand(static_cast<unsigned>(time(0)));

    int choice;
    do {
        cout << "\n=== ЛАБАРАТОРНАЯ РАБОТА №7, ВАРИАНТ 2 ===\n";
        cout << "1 — Задание 1 (двумерный массив char)\n";
        cout << "2 — Задание 2 (string: переворот чётных слов)\n";
        cout << "0 — Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: task1_char(); break;
        case 2: task2_string(); break;
        case 0: cout << "\nПрограмма завершена.\n"; break;
        default: cout << "\nОшибка: неверный выбор.\n";
        }
    } while (choice != 0);

    return 0;
}