#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <sstream> 
#include <stdlib.h> 
#include <utility> 
using namespace std;
int hellowindow(), autorizationstart(), earlyend();
void autorizationnext(), menu(), countcalories(), normalcal(), regestration();
string name, pass, user, uspass, line;
int startchoise, autorizchoice, autochoice, menuchoice, gr, countchoice, num, normalcalo, Age, Gender, koefA, counterror = 0;
float Weight, Height, Q, BMR, res = 0;
bool found = false;
string product[30] = { "Огурец","Арбуз","Мед","Говядина","Курица","Колбаса","Форель","Тунец","Семга","Креветки","Крабовые палочки","Морская капуста","Молоко","Рис","Хлеб","Печенье","Морковь","Яблоко","Укроп","Вишня","Клубника","Фисташки","Мармелад","Шоколад","Ирис","Арахис","Ежевика","Щавель","Персик","Лимон" };
int calproduct[30] = { 15, 30, 350,190, 160, 300, 100, 90, 200, 85, 200, 25, 50, 350, 300, 400, 30, 50, 40, 50, 30, 550, 300, 600, 40, 550, 30, 30, 40, 30 };


int hellowindow() {
    cout << " Приложение: Ваш подсчёт калорий " << endl;
    cout << " Версия: 1.1.1.0 " << endl;
    cout << endl;
    cout << " Разработали: " << endl << endl << " Рустам Багиев" << endl << " Степан Афанасьев" << endl << " Владимир Ломакин" << endl << " Алексей Ширяев" << endl << " Артём Герасимов" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Хотите ли вы начать подсчёт калорий?" << endl;
    cout << "(0) - Нет" << endl << "(1) - Да" << endl;
    do {
        cout << "Ваш выбор: ";
        cin >> startchoise;
    } while (startchoise != 1 && startchoise != 0);
    return startchoise;
}



int autorizationstart() {
    system("CLS");
    cout << "Вход" << endl << "Вы имеете учётную запись?" << endl;
    cout << "(0) - Нет" << endl << "(1) - Да" << endl;
    do {
        cout << "Ваш выбор: ";
        cin >> autorizchoice;
    } while (autorizchoice != 1 && autorizchoice != 0);
    return autorizchoice;
}

void regestration() {
    ofstream file("users.txt", ios::app);
    system("CLS");
    cout << "Регестрация" << endl;
    cout << "Введите никнейм (без пробелов): ";
    cin >> name;
    do {
        if (counterror != 0) cout << "Вы ввели некорректное значение! " << endl;
        cout << "Введите пароль (не менее 4 сиволов): ";
        cin >> pass;
        counterror++;
    } while (pass.size() <= 3);
    counterror = 0;
    file << name << " " << pass << endl;
    cout << "Регестрация завершена! Спасибо. " << endl;
    cout << "Ваш логин: " << name << endl;
    cout << "Ваш пароль: " << pass << endl;
    system("pause");
    menu();
}




int earlyend() {
    return 0;
}




void autorizationnext() {
    ifstream filename("users.txt");
    system("CLS");
    cout << "Введите никнейм (без пробелов): ";
    cin >> name;
    cout << "Введите пароль: ";
    cin >> pass;
    while (getline(filename, line)) {
        stringstream ss(line);
        ss >> user >> uspass;
        if (user == name && uspass == pass) {
            found = true;
            break;
        }
    }
    if (found == true) {
        menu();
    }
    else {
        cout << "Вы ввели неправильный пароль или никнейм!" << endl;
        cout << "Повторить ввод?" << endl;
        cout << "(0) - Перейти к регестрации" << endl;
        cout << "(1) - Да" << endl;
        cout << "(2) - Закончить программу" << endl;
        do {
            cout << "Ваш выбор: ";
            cin >> autochoice;
        } while (autochoice != 1 && autochoice != 0 && autochoice != 2);
        switch (autochoice) {
        case 0: regestration();
            break;
        case 1: autorizationnext();
            break;
        case 2: earlyend();
            break;
        }
    }
}




void menu() {
    system("CLS");
    cout << "Меню" << endl;
    cout << "(0) - Подсчет калорий" << endl;
    cout << "(1) - Посмотреть норму калорий" << endl;
    cout << "(2) - Закончить программу" << endl;
    do {
        cout << "Ваш выбор: ";
        cin >> menuchoice;
    } while (menuchoice != 1 && menuchoice != 0 && menuchoice != 2 && menuchoice != 3);
    switch (menuchoice) {
    case 0: countcalories();
        break;
    case 1: normalcal();
        break;
    case 2: earlyend();
        break;
    }
}



void countcalories() {
    system("CLS");
    cout << "Подсчет калорий" << endl << endl;
    for (int i = 0; i < 30; i++) {
        cout << i << ") " << product[i] << endl;
    };
    cout << "Какие продукты вы съели за это день?" << endl;
    cout << "Введите номер продукта. Чтобы завершить, наберите -1." << endl;
    do {
        cout << "Номер продукта: ";
        cin >> num;
        if (num >= 0 && num < 30) {
            cout << "Количество грамм: ";
            cin >> gr;
            res += calproduct[num] * (gr / 100);
        }
        else {
            if (num != -1)
                cout << "Такого значения нет!" << endl;
        }
    } while (num != -1);


    cout << "Сумма калорий введенных продуктов: " << res << endl;
    system("pause");
    system("CLS");
    cout << "(0) - Назад в меню" << endl;
    cout << "(1) - Повторить ввод" << endl;
    cout << "(2) - Закончить программу" << endl;
    do {
        cout << "Ваш выбор: ";
        cin >> countchoice;
    } while (countchoice != 1 && countchoice != 0 && countchoice != 2);
    switch (countchoice) {
    case 0: menu();
        break;
    case 1: countcalories();
        break;
    case 2: earlyend();
        break;
    }

}




void normalcal() {
    system("CLS");
    cout << "Расчёт дневных калорий для мужчин и женщин.\n" << endl;
    cout << "1 - Сидячий образ жизни (1.2)\n";
    cout << "2 - Легкие упражнения (1-3 раза в неделю) (1.375)\n";
    cout << "3 - Умеренные упражнения (3-5 дней в неделю) (1.55)\n";
    cout << "4 - Интенсивные упражнения (6-7 дней в неделю) (1.725)\n";
    cout << "5 - Профессиональный спорт (более 1 раза в день) (1.9)\n\n";


    counterror = 0;
    do {
        if (counterror > 0)
            cout << "Вы ввели неверное значение! " << endl;
        cout << "Введите свою активность: ";
        cin >> koefA;
        counterror++;
    } while (koefA < 1 || koefA > 5);
    switch (koefA) {
    case 1:
        koefA = 1.2;
        break;
    case 2:
        koefA = 1.375;
        break;
    case 3:
        koefA = 1.55;
        break;
    case 4:
        koefA = 1.725;
        break;
    case 5:
        koefA = 1.9;
        break;

    }


    counterror = 0;
    system("CLS");
    cout << "Введите возраст (в годах):" << endl;
    do {
        if (counterror > 0)
            cout << "Вы ввели неверное значение! " << endl;
        cout << "Ваш выбор: ";
        cin >> Age;
        counterror++;
    } while (Age < 1);


    counterror = 0;
    system("CLS");
    cout << "Выберите пол (М-1, Ж-2):" << endl;
    do {
        if (counterror > 0)
            cout << "Вы ввели неверное значение! " << endl;
        cout << "Ваш выбор: ";
        cin >> Gender;
        counterror++;
    } while (Gender != 2 && Gender != 1);


    counterror = 0;
    system("CLS");
    cout << "Введите вес (в кг):" << endl;
    do {
        if (counterror > 0)
            cout << "Вы ввели неверное значение! " << endl;
        cout << "Ваш выбор: ";
        cin >> Weight;
        counterror++;
    } while (Weight < 1);


    counterror = 0;
    system("CLS");
    cout << "Введите рост (в см):" << endl;
    do {
        if (counterror > 0)
            cout << "Вы ввели неверное значение! " << endl;
        cout << "Ваш выбор: ";
        cin >> Height;
        counterror++;
    } while (Height < 1);


    counterror = 0;
    system("CLS");
    if (Gender == 1) {
        BMR = (10 * Weight) + (6.25 * Height) - (5 * Age) + 5;
    }
    else {
        BMR = (10 * Weight) + (6.25 * Height) - (5 * Age) - 161;
    }
    Q = BMR * koefA;

    cout << "Расчёт калорий для поддержания веса: " << Q << endl;
    cout << "Для оптимального похудения: " << Q * 0.85 << endl;
    cout << "Для набора массы: " << Weight * 30 + 500 << endl;



    cout << "(0) - Назад в меню" << endl;
    cout << "(1) - Повторить ввод" << endl;
    cout << "(2) - Закончить программу" << endl;
    do {
        cout << "Ваш выбор: ";
        cin >> normalcalo;
    } while (normalcalo != 1 && normalcalo != 0 && normalcalo != 2);
    switch (normalcalo) {
    case 0: menu();
        break;
    case 1: normalcal();
        break;
    case 2: earlyend();
        break;
    }

}


int main() {
    setlocale(LC_ALL, "RU");
    fstream file("users.txt");
    int res = hellowindow();
    if (res == 0) {
        return 0;
    }
    else {
        res = autorizationstart();
    }
    if (res == 0) {
        regestration();
    }
    else {
        autorizationnext();
    }
    file.close();
}
