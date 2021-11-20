#include <iostream>

using namespace std;

unsigned short personHeight;

// Осуществляет ввод с клавиатуры возраста человека.
// Вывод через возвращаемое значение.
unsigned short ReadPersonAge() {
    unsigned short age;
    cout << "Возраст: ";
    cin >> age;
    return age;
}

// Осуществляет ввод с клавиатуры имени человека.
// Вывод через возвращаемое значение.
string ReadPersonName() {
    string name;
    cout << "Имя: ";
    cin >> name;
    return name;
}

// Осуществляет ввод с клавиатуры роста человека.
// Вывод через глобальные объекты.
void ReadPersonHeight() {
    cout << "Рост: ";
    cin >> personHeight;
}

// Осуществляет ввод с клавиатуры веса человека.
// Вывод через параметры по ссылке.
void ReadPersonWeight(unsigned short & weight) {
    cout << "Вес: ";
    cin >> weight;
}

// Осуществляет ввод с клавиатуры заработной платы человека.
// Вывод через параметры с помощью указателя.
void ReadPersonSalary(double * salary) {
    cout << "Заработная плата: ";
    cin >> * salary;
}

/*
Осуществляет ввод с клавиатуры имя,
возраст и заработную плату человека.
Для ввода использовать разработанные ранее функции.
Вывод через параметры по ссылке.
*/
void ReadPersonData(string & name, unsigned short & age, string & salary) {
    double doubleSalary;
    name = ReadPersonName();
    age = ReadPersonAge();
    ReadPersonSalary(&doubleSalary);
    salary = to_string(doubleSalary);
}

/*
Осуществляет ввод с клавиатуры имя,
возраст, рост и вес человека.
Для ввода использовать разработанные ранее функции.
Вывод через параметры по ссылке.
*/
void ReadPersonData(string& name, unsigned short& age, string& height, string& weight) {
    name = ReadPersonName();
    age = ReadPersonAge();
    ReadPersonHeight();
    height = to_string(personHeight);
    unsigned short personWeight;
    ReadPersonWeight(personWeight);
    weight = to_string(personWeight);
}

/*
Осуществляет вывод на экран имени,
возраста, роста, веса, заработной платы человека.
Ввод через параметры по значению
и через параметры по ссылке.
 */
void WritePersonData(unsigned short age, string name, const string & height = "", const string & weight = "", const string & salary = "") {
    if (!name.empty())
        cout << name << endl;
    cout << age << endl;
    if (!height.empty())
        cout << height << endl;
    if (!weight.empty())
        cout << weight << endl;
    if (!salary.empty())
        cout << salary << endl;
}

// Функция main.
int main() {
    string name, height, weight, salary;
    unsigned short age;
    ReadPersonData(name, age, salary);
    WritePersonData(age, name, "", "", salary);
    ReadPersonData(name, age, height, weight);
    WritePersonData(age, name, height, weight);
    return 0;
}