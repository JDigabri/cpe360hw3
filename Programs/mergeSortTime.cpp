#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
// Function to merge two sorted arrays into a single sorted array
std::vector<int> merge(const std::vector<int>& a, const std::vector<int>& b)
{
    std::vector<int> result;
    result.reserve(a.size() + b.size());

    // Iterate over both arrays, adding the smaller of the two items at each step
    // to the result array, until one of the arrays is empty
    auto a_it = a.begin();
    auto b_it = b.begin();
    while (a_it != a.end() && b_it != b.end()) {
        if (*a_it < *b_it) {
            result.push_back(*a_it);
            a_it++;
        } else {
            result.push_back(*b_it);
            b_it++;
        }
    }

    // Add any remaining items from the non-empty array to the result array
    if (a_it != a.end()) {
        result.insert(result.end(), a_it, a.end());
    } else if (b_it != b.end()) {
        result.insert(result.end(), b_it, b.end());
    }

    return result;
}

// Recursive function to perform merge sort on a list of items
std::vector<int> merge_sort(const std::vector<int>& items)
{
    // If the list has only one item, it is already sorted, so return it
    if (items.size() == 1) {
        return items;
    }

    // Split the list into two approximately equal-sized sublists
    int mid = items.size() / 2;
    std::vector<int> a(items.begin(), items.begin() + mid);
    std::vector<int> b(items.begin() + mid, items.end());

    // Sort the two sublists using merge sort
    a = merge_sort(a);
    b = merge_sort(b);

    // Merge the two sorted sublists into a single sorted list
    return merge(a, b);
}
int partition( std::vector<int>& arr, int low, int high)
{
    // pivot element
    int pivot = arr[high];

    // index of the smaller element
    int i = low - 1;

    // run the loop from low to high-1
    for (int j = low; j <= high - 1; j++)
    {
        // if the current element is smaller than
        // the pivot element, increment the index
        // of the smaller element and swap the
        // current element with the element at
        // index i
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // swap the pivot element with the element
    // at index i + 1
    swap(arr[i + 1], arr[high]);

    // return the index of the pivot element
    return i + 1;
}

// Function to implement quick sort
// arr: vector to be sorted
// low: starting index of the vector
// high: ending index of the vector
void quickSort(vector<int>& arr, int low, int high)
{
    // if the starting index is less than the ending
    // index, we need to partition the array and
    // sort the sub-arrays recursively
    if (low < high)
    {
        // partition the array
        int pi = partition(arr, low, high);

        // sort the sub-array on the left of the pivot
        // element
        quickSort(arr, low, pi - 1);

        // sort the sub-array on the right of the pivot
        // element
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    // Generate a random list of integers to sort
    std::vector<int> items;
    for (int i = 0; i < 8000000; i++) {
        items.push_back(rand());
    }
    int n = items.size();

    quickSort(items, 0, n - 1);
    // Measure the time it takes to sort the list using merge sort
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> sorted_items = merge_sort(items);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Merge sort took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " milliseconds to sort " << items.size() << " items." << std::endl;

    return 0;
}
