#include "functions.h"


QByteArray parse(QString message)
{
    QStringList parts = message.left(message.length()-1).split("&");
    switch(parts.size()){
        case 3:
        {
            if (parts[0] == "sort")
            return pyramid_sort(parts[2], parts[1].toInt());
        };break;
    }
    return InvalidRequest();
}

QByteArray InvalidRequest()
{
    return QByteArray("Неверно введенная команда\n\r");
}

QByteArray pyramid_sort(QString array, int step)
{
    if (step < 0) return QByteArray("Шаг не может быть отрицательным!");
    QStringList parts = array.split(" ");
    QVector<int> arr;
    for (auto i:parts)
    {
        arr.append(i.toInt());
    }

    heapSort(arr, step);

    QString result = "";
    for (auto i:arr)
    {
        result += QString::number(i) + " ";
    }
    return QByteArray(result.toUtf8() + "\n\r");
}

void heapify_first(QVector<int>& arr, int n, int i) {
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1; // Левый потомок
    int right = 2 * i + 2; // Правый потомок

    // Если левый потомок больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый потомок больше, чем наибольший элемент на данный момент
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если наибольший элемент не является корнем
    if (largest != i)
    {
    arr.swapItemsAt(i, largest);
    // Применяем просеивание вниз рекурсивно для затронутой под-пирамиды
    heapify_first(arr, n, largest);
    }
}

// Просеивание элемента вниз для создания пирамиды
bool heapify(QVector<int>& arr, int n, int i, int& max_step) {
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1; // Левый потомок
    int right = 2 * i + 2; // Правый потомок

    // Если левый потомок больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый потомок больше, чем наибольший элемент на данный момент
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если наибольший элемент не является корнем
    if (largest != i)
    {
    arr.swapItemsAt(i, largest);
    if (max_step == 0 || --max_step == 0) return false;
    // Применяем просеивание вниз рекурсивно для затронутой под-пирамиды
    heapify(arr, n, largest, max_step);
    }
    return true;
}

// Основная функция для сортировки массива с использованием пирамиды
void heapSort(QVector<int>& arr, int& max_step) {
    // Построение пирамиды (перегруппировка массива)
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        heapify_first(arr, arr.size(), i);

    // Извлечение элементов из пирамиды по одному и перемещение их в конец
    for (int i = arr.size() - 1; i >= 0; i--) {
        arr.swapItemsAt(0, i); // Перемещаем текущий корень в конец
        if (max_step == 0 || --max_step == 0) return;
        if (!heapify(arr, i, 0, max_step)) return;
    }
}
