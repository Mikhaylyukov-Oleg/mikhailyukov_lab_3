﻿#include <iostream>
#include <cstdlib>
#include <ctime>
#define elements_count 20
using namespace std;

int int_rand_in_segment(const int left_border, const int right_border);
void fill_array_randomly(int* arr, const int amount);
void print_array(int* arr, const int amount);
int find_index_of_max_element(int* arr, const int amount);

int main()
{
    setlocale(LC_ALL, "rus");

    int arr[elements_count];

    srand(time(NULL));
    fill_array_randomly(arr, elements_count);

    print_array(arr, elements_count);

    const int index_of_max_element = find_index_of_max_element(arr, elements_count);

    cout << "\nНаибольший элемент массива: ";
    cout << "arr[" << index_of_max_element << "] = " << arr[index_of_max_element] << "\n";
    return 0;
}

void fill_array_randomly(int* arr, const int amount)
{
    for (int i = 0; i < amount; i++) {
        arr[i] = int_rand_in_segment(-10000, 10000);
    }
}

int int_rand_in_segment(const int left_border, const int right_border)
{
    const double rand_0_1 = rand() / (RAND_MAX + 1.0);
    const int count_of_posible_numbers = right_border - left_border + 1;
    const int res = left_border + (int) (rand_0_1 * count_of_posible_numbers);
    return res;
}

void print_array(int* arr, const int amount)
{
    cout << "Массив случайных чисел:\n";
    for (int i = 0; i < amount; i++) {
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    }
}

int find_index_of_max_element(int* arr, const int amount)
{
    int index_of_max_element = 0;
    for (int i = 0 + 1; i < amount; i++) {
        if (arr[i] > arr[index_of_max_element]) {
            index_of_max_element = i;
        }
    }
    return index_of_max_element;
}