#include <iostream>
#include <vector>

// Function to perform merge sort on the given vector
void mergeSort(std::vector<int>& vec)
{
    // Get the size of the vector
    int n = vec.size();

    // Base case: return if the vector has 0 or 1 elements
    if (n <= 1)
    {
        return;
    }

    // Divide the vector into two halves
    std::vector<int> left(vec.begin(), vec.begin() + n / 2);
    std::vector<int> right(vec.begin() + n / 2, vec.end());

    // Recursively sort the two halves
    mergeSort(left);
    mergeSort(right);

    // Merge the sorted halves
    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            vec[k] = left[i];
            i++;
        }
        else
        {
            vec[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of the left half, if any
    while (i < left.size())
    {
        vec[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of the right half, if any
    while (j < right.size())
    {
        vec[k] = right[j];
        j++;
        k++;
    }
}

// Function to print the elements of the given vector
void printVector(const std::vector<int>& vec)
{
    for (int elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Create a vector of integers
    std::vector<int> vec;

    // Generate 100 random numbers and add them to the vector
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(rand());
    }


    mergeSort(vec);

    printVector(vec);

    return 0;
}
