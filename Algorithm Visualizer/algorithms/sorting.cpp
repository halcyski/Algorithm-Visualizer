#include "sorting.h"


// bubbleSort : [Vector Int]& -> Void
// Purpose: Takes the address of an array of int elements and sorts
// the array numerically in ascending order using a bubble sort algorithm.
void bubbleSort(sf::RenderWindow& window, std::vector<int>& array)
{
    // Assign an int variable equal to the size of the array, n.
    int elems = array.size();

    // Initialize a boolean flag that is set to false each pass each pass of the algorithm.
    // It represents if a swap occurs in a pass of the algorithm If it is false for an entire 
    // pass that means the array is sorted (no swaps occured) and the algorithm can exit.
    bool swappedFlag; 

    for (int i = 0; i < elems - 1; i++)
    {
        // Each pass the flag is set to false. 
        swappedFlag = false;
        for (int j = 0; j < elems - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                // If array[j] is greater than array[j + 1] then they are swapped
                // using a placeholder value.  
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
                // A swap has occured
                swappedFlag = true;
                drawBars(window, array);
                delay(0);
            }
        }
        // If no swaps occured (array is already sorted) then break out of the algorithm
        if(!swappedFlag)
            break;
    }
}


// merge : [Vector Int]& Int Int Int -> Void
// Purpose: merges two subarrays of the main array[]
// The first array is array[left, mid] and the second is array[mid, right]
// left, mid, and right are the indices of the specified arrays to merge.
void merge(sf::RenderWindow& window, std::vector<int>& array, int left, int mid, int right)
{
    int leftSize = mid - left + 1; // size of left side of array (left->mid)
    int rightSize = right - mid; // size of right side of array (mid->right)

    // Creating temporary vectors / arrays and assigning array[left, mid] and
    // array[mid, right] to their respective left and right arrays.
    std::vector<int> leftArray(leftSize), rightArray(rightSize);

    for (int i = 0; i < leftSize; i++)
    {
        leftArray[i] = array[left + i];
    }
    for (int i = 0; i < rightSize; i++)
    {
        rightArray[i] = array[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    // Merge both temporary arrays back into array[]
    while (i < leftSize && j < rightSize)
    {   
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;   
        } else 
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    } 

    // Copy any potential remaining values in leftArray[] into array[]
    while (i < leftSize)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy any potential remaining values in rightArray[] into array[]
    while (j < rightSize)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

// mergeSort : [Vector Int]& Int Int -> Void
// Purpose: divides an array into subarrays until they can no longer be divided
// and merges them back together in a numerically sorted order.
void mergeSort(sf::RenderWindow& window, std::vector<int>& array, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    // Sort left size
    mergeSort(window, array, left, mid);
    // Sort right side
    mergeSort(window, array, mid + 1, right);
    // Merge all
    merge(window, array, left, mid, right);
}



// partition : [Vector Int]& Int Int -> Int
// Purpose: returns a new pivot position from an array 
int partition(sf::RenderWindow& window, std::vector<int>& array, int low, int high)
{
    // Choose the pivot
    // Some methods of choosing the pivot include:
    // - Picking the first (or last) element as the pivot
    // - Picking a random element as the pivot
    // - Pick the median as the pivot (can occur in linear time)
    int pivot = array[high];

    // Indice of smaller element and indicates
    // the right position of the pivot found so far
    int i = low - 1;


    // Traverse the array from low to high and move all smaller 
    // elements (< pivot) to the left side. Elements from low to i
    // are smaller after every iteration.
    for (int j = 0; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }

    // Move pivot to after the smaller elements 
    // return its position.
    std::swap(array[i + 1], array[high]);
    return i + 1;
}

// quickSort : [Vector Int]& Int Int -> Void
// Purpose: QuickSort algorithm that takes an array of data, a low and a high and sorts
// the array using quickSort math.
void quickSort(sf::RenderWindow& window, std::vector<int>& array, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(window, array, low, high);

        // Recursion calls for smaller elements
        // and greater or equal elements
        quickSort(window, array, low, partitionIndex - 1);
        quickSort(window, array, partitionIndex + 1, high);
    }
}

// maxElement : [Vector Int] -> Int
// returns the largest element in a list of integers
int maxElement(std::vector<int> array)
{
    int largest = std::numeric_limits<int>::min();

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] > largest)
        {
            largest = array[i];
        }      
    }
    return largest;
}

// randArray : Int -> [Vector Int] 
// takes an int representing a number of elements and returns an
// array of integers with random values.
std::vector<int> randArray(int numElements)
{
    std::vector<int> array = std::vector<int>(numElements);
    srand(time(0)); // generate random seed for rand()

    for (int i = 0; i < numElements; i++)
    {
        array[i] = rand() % 500; // 1000 as a default max value
    }

    return array;
}