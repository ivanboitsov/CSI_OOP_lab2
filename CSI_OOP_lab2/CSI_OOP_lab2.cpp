#include <iostream>
using namespace std;

class Array {
private:
    int* a; //Указатель на массив
    int n; // Число элементов в массиве
    int mem; // Память, выделенная под массив
    
    // Сдвиг влево, начиная с позиции pos + 1
    void ShiftLeft(int pos) {
        for (int i = 0; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--;
    }

public:
    // Конструктор с целым аргументом (м - число элементов в массиве) и по умолчанию
    // В зададнии есть разрешение на объединение этих конструкторов
    Array(int m = 1) {
        n = m;
        mem = m;
        a = new int[n];
    }
    // Конструктор с аргументом, m - число элементов в массиве b
    Array(int *b, int m) {
        n = m;
        mem = m;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = b[i];
        }
    }
    // Конструктор копирования
    Array(const Array& x) {
        n = x.n;
        mem = x.mem;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = x.a[i];
        }
    }
    // Операция присвоения
    Array& operator = (const Array& x) {
        if (this == &x) {
            return *this;
        }
        delete[] a;
        n = x.n;
        mem = x.mem;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = x.a[i];
        }
        return *this;
    }
    // Деконструктор
    ~Array() {
        delete[] a;
    }
    // Ввод массива из m чисел
    void Scan(int m) {
        n = m;
        mem = m;
        a = new int[n];
        for (int i = 0; i < 0; i++) {
            cin >> a[i];
        }
    }
    // Вывод массива
    void Print() {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    }
    // Считывание элемента по позиции
    int& operator[](int i) {
        return a[i];
    }
    // Поиск элемента key в массиве (возвращаем индекс key или -1)
    int FindKey(int key) {
        for (int i = 0; i < n; i++) {
            if (a[i] == key) {
                return i;
            }
        }
        return -1;
    }
    // Добавляем key в конец массива
    Array& operator += (int key) {
        if (n < mem) {
            a[n] = key;
            n++;
        }
        return *this;
    }
    // Формирование массива b = a + key (key добавляется в конец)
    Array& operator + (int key) {
        Array b(*this);
        if (n < mem) {
            b.a[n] = key;
            b.n++;
        }
        return b;
    }
    // Добавление массива в конец массива a
    Array& operator +=(Array x) {
        if (n + x.n < mem) {
            for (int i = 0; i < x.n; i++) {
                a[n + i] = x.a[i];
            }
            n += x.n;
        }
        return *this;
    }
    // Формирование массива y = a + x
    Array operator+(Array x) {
        Array y(n + x.n);
        for (int i = 0; i < n; i++) {
            y.a[i] = a[i];
        }
        for (int i = 0; i < x.n; i++) {
            y.a[n + i] = x.a[i];
        }
        y.n = n + x.n;
        return y;
    }
    // Удаление элемента key
    Array& operator -=(int key) {
        int pos = FindKey(key);
        if (pos != -1) {
            ShiftLeft(pos);
        }
        return *this;
    }
    // Формирование нового массива b = a - key
    Array operator - (int key) {
        Array b(*this);
        int pos = b.FindKey(key);
        if (pos != -1) {
            b.ShiftLeft(pos);
        }
        return *this;
    }
    // Удаление элемента с позиции pos
    Array& DelPosEq(int pos) {
        if (pos >= 0 && pos < n) {
            ShiftLeft(pos);
        }
        return *this;
    }
    // Формирование нового массива b, в котором удален элемент с позиции pos

    Array DelPosNew(int pos) {
        Array b(*this);
        if (pos >= 0 && pos < n) {
            b.ShiftLeft(pos);
        }
        return b;
    }
    // Проверка равенства массивов
    bool operator == (Array x) {
        if (n != x.n) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] != x.a[i])
                return false;
        }
        return true;
    }
    // Проверка неравенства массивов
    bool operator != (Array x) {
        return !(*this == x);
    }
    // Нахождение максимума в массиве, возвращает индекс максимального элемента
    int Max() {
        int maxVal = 0;
        int maxInd = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > maxVal) {
                maxVal = a[i];
                maxInd = i;
            }
        }
        return maxInd;
    }
    // Нахождение минимума в массиве
    int Min() {
        int minVal = a[0];
        int minInd = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < minVal) {
                minVal = a[i];
                minInd = i;
            }
        }
        return minInd;
    }
    // Сортировка пузырьком
    void Sorting() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }
    //
    friend ostream& operator << (ostream& r, Array& x);
    friend istream& operator >> (istream& r, Array& x);

    };

int main()
{
    return 0;
}