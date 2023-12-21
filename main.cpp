#include <iostream>
#include <ratio>
#include <vector>
#include <algorithm>
#include <chrono>

// Функция для разбиения массива и возврата индекса опорного элемента
template<typename T>
int partition(std::vector<T>& arr, int low, int high) {
    int pivot = arr[high]; // Выбираем последний элемент в качестве опорного
    int i = low - 1; // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Функция для нахождения k-го порядкового статистического элемента
template<typename T>
T dselect(std::vector<T>& arr, int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        // Находим индекс опорного элемента после разбиения
        int pivotIndex = partition(arr, low, high);

        // Если опорный элемент - искомый элемент
        if (pivotIndex - low == k - 1) {
            return arr[pivotIndex];
        }
        // Если k меньше, чем индекс опорного элемента, рекурсивно ищем в левой части
        if (pivotIndex - low > k - 1) {
            return dselect(arr, low, pivotIndex - 1, k);
        }
        // Иначе ищем в правой части
        return dselect(arr, pivotIndex + 1, high, k - pivotIndex + low - 1);
    }

    // В случае некорректного значения k
    return -1;
}

int main() {
    /* ---- Пример 1 ---- */
    std::vector<int> arr1 = {2148, 9058, 7742, 3153, 6324, 609, 7628, 5469, 7017, 504};
    int k1 = 4;

    auto start_time = std::chrono::high_resolution_clock::now();
    int result1 = dselect(arr1, 0, arr1.size() - 1, k1);
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<long double, std::milli> duration1 = end_time - start_time;

    /* ---- Пример 2 ---- */
    std::vector<int> arr2 = {
        2148, 9058, 7742, 3153, 6324, 609, 7628, 5469, 7017, 504, 4092, 
        1582, 9572, 1542, 5697, 2081, 4218, 3130, 7923, 9595, 6558, 
        3859, 9832, 3062, 6788, 7578, 7432, 479, 8439, 9079, 7173, 
        2667, 2770, 2655, 972, 4264, 2014, 3171, 4715, 345, 4388, 
        3816, 8887, 3915, 3490, 2327, 123, 4596, 4307, 8737, 4007, 
        6798, 6551, 1627, 1190, 4984, 2480, 3404, 2027, 4778, 2951, 
        2795, 5002, 8121, 8910, 9593, 5254, 448, 6237, 5565, 1816, 
        392, 8143, 9310, 9293, 3138, 4869, 6756, 872, 6183, 3517, 
        3513, 1676, 5498, 9172, 5739, 6108, 7538, 7671, 5780, 8666, 
        540, 9771, 6837, 9341, 1590, 5689, 1605, 1103, 5859
    };
    int k2 = 49;

    start_time = std::chrono::high_resolution_clock::now();
    int result2 = dselect(arr2, 0, arr2.size() - 1, k2);
    end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<long double, std::milli> duration2 = end_time - start_time;

    /* ---- Пример 3 ---- */
    std::vector<long> arr3 = {1415926535, 8979323846, 2643383279, 5028841971, 6939937510, 5820974944, 5923078164, 628620899, 8628034825, 3421170679};
    int k3 = 4;

    start_time = std::chrono::high_resolution_clock::now();
    long result3 = dselect(arr3, 0, arr3.size() - 1, k3);
    end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<long double, std::milli> duration3 = end_time - start_time;

    /* ---- Вывод результатов ---- */
    std::cout << "----==== Алгоритм 1 ====----\n"
            << "Результат при k = " << k1 << ": " << result1
            << "\nВремя: " << duration1.count() << " мс\n\n";
    
    std::cout << "----==== Алгоритм 2 ====----\n"
        << "Результат при k = " << k2 << ": " << result2
        << "\nВремя: " << duration2.count() << " мс\n\n";
    
    std::cout << "----==== Алгоритм 3 ====----\n"
        << "Результат при k = " << k3 << ": " << result3
        << "\nВремя: " << duration3.count() << " мс\n";

    return 0;
}