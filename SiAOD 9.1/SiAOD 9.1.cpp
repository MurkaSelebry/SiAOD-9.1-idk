// SiAOD 9.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Table.h"
#include "Stopwatch.h"

//Задание 1. Разработать программу поиска записи по ключу в таблице записей с применение двух алгоритмов линейного поиска
//1.	Таблица содержит записи, структура которых определена вариантом.Ключи уникальны в пределах таблицы.
//2.	Разработать функцию линейного поиска(метод грубой силы).
//3.	Разработать функцию поиска с барьером.
//4.	Провести практическую оценку времени выполнения алгоритмов на таблицах объемом 100, 1000, 10 000 записей.
//5.	выСоставить таблицу с указанием : времени выполнения алгоритма, его фактическую и теоретическую вычислительную сложность.
//6.	Сделать выводы об эффективности алгоритмов.
//Регистрация земельного участка в СНТ: кадастровый номер – семизначное число, адрес СНТ
//Horticultural non-profit partnerships - Садоводческие некоммерческие товарищества (СНТ)


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    Table t;
    Stopwatch s;
    int answer1 = 100;
    while (answer1 != 0) {
        system("cls");
        cout << "Лабораторная работа №8 ИКБО-33-21 Резван М.Б. Вариант 21" << endl << endl;
        cout << "Задание 21" << endl;
        cout << "Условия задачи 1:\n\n\n.";
        cout << "Меню\n";
        cout << "1) Заполнить таблицу рандомными (случайными) значениями\n";
        cout << "2) Заполнить таблицу с клавиатуры\n";
        cout << "3) Brute force (линейный поиск (метод грубой силы)).\n";
        cout << "4) Barrier search (поиск с барьером).\n";
        cout << "5) Вывести таблицу\n";
        cout << "0) Выход\n";
        cout << "Ваш выбор: ";
        cin >> answer1;
        system("cls");
        cout << "Лабораторная работа №8 ИКБО-33-21 Резван М.Б. Вариант 21" << endl << endl;
        switch (answer1)
        {
        case 1:
            cout << "Введите размер таблицы: ";
            cin >> answer1;
            s.start_countdown();
            t.rand_init(answer1);
            cout << "Время работы: " << s.get_milliseconds() << '\n';
            system("pause");

            break;
        case 2:
            cout << "Введите размер таблицы: ";
            cin >> answer1;
            s.start_countdown();
            t.keyboard_init(answer1);
            cout << "Время работы: " << s.get_milliseconds() << '\n';
            system("pause");
        break;

        case 3:
            UI key;
            cout << "Введите ключ: ";
            cin >> key;
            s.start_countdown();
            cout << "Результат поиска (брут): " << t.brute_force(key) << "\n";
            cout << "Время работы: " << s.get_milliseconds() << '\n';
            system("pause");
            break;
        case 4:
        {
            UI key;
            cout << "Введите ключ: ";
            cin >> key;
            s.start_countdown();
            cout << "Результат поиска (барьер): " << t.barrier_search(key) << "\n";
            cout << "Время работы: " << s.get_milliseconds() << '\n';
        }
        system("pause");
        break;
        case 5:
            t.print_table();
            system("pause");
            break;
        }
    }

}
