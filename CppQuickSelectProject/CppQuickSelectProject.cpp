#include <iostream>

struct Range
{
    int left;
    int right;
};

void ArrayPrint(int* array, int size);
void ArraySortBubble(int* array, int size);
void Swap(int& a, int& b);
Range Partition(int* array, int begin, int end, int pivotIndex);

int QuickSelect(int* array, int begin, int end, int index);
void QuickSort(int* array, int begin, int end);


int main()
{
    srand(time(nullptr));

    int size{ 21 };
    int* array = new int[size];
    int* arraySort = new int[size];

    int item;
    for (int i{}; i < size; i++)
    {
        item = rand() % 100;
        array[i] = item;
        arraySort[i] = item;
    }
        
    ArrayPrint(array, size);

    QuickSort(array, 0, size - 1);

    ArrayPrint(array, size);

    /*std::cout << QuickSelect(array, 0, size - 1, size / 2) << "\n";

    ArraySortBubble(arraySort, size);
    ArrayPrint(arraySort, size);*/

    /*Range range = Partition(array, 0, size - 1, 10);
    std::cout << "left = " << range.left << "\n";
    std::cout << "right = " << range.right << "\n";

    ArrayPrint(array, size);*/

}

void ArrayPrint(int* array, int size)
{
    for (int i{}; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

void ArraySortBubble(int* array, int size)
{
    for (int i{}; i < size - 1; i++)
        for (int j{ size - 1 }; j > i; j--)
            if (array[j] < array[j - 1])
                Swap(array[j], array[j - 1]);
}

void Swap(int& a, int& b)
{
    int temp{ a };
    a = b;
    b = temp;
}

Range Partition(int* array, int begin, int end, int pivotIndex)
{
    int left{ begin };
    int right{ end };

    int pivot = array[pivotIndex];
    Swap(array[pivotIndex], array[begin]);

    int current{ begin };

    while (current <= right)
    {
        if (array[current] < pivot)
            Swap(array[current++], array[left++]);
        else if (array[current] > pivot)
            Swap(array[current], array[right--]);
        else
            current++;
    }

    return Range{ left, right };
}

int QuickSelect(int* array, int begin, int end, int index)
{
    if (begin == end)
        return array[begin];

    int indexRand = begin + rand() % (end - begin + 1);
    Range range = Partition(array, begin, end, indexRand);

    if (index >= range.left && index <= range.right)
        return array[index];
    if (index < range.left)
        return QuickSelect(array, begin, range.left - 1, index);
    if (index > range.right)
        return QuickSelect(array, range.right + 1, end, index);
}

void QuickSort(int* array, int begin, int end)
{
    int indexRand = begin + rand() % (end - begin + 1);
    Range range = Partition(array, begin, end, indexRand);

    if (begin < range.left)
        QuickSort(array, begin, range.left - 1);
    if (end > range.right)
        QuickSort(array, range.right + 1, end);
}
