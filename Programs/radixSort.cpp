#include <iostream>


using namespace std;


int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}
// Function to measure the time taken by a sorting function
void measureTime(void (*sortFunc)(int[], int), int arr[], int n)
{
    clock_t start = clock(); // Start timer
    sortFunc(arr, n); // Call the sorting function
    clock_t end = clock(); // End timer

    // Calculate and print the time taken by the sorting function
    float timeTaken = (float)(end - start) / CLOCKS_PER_SEC;
    printf("%0.15lf",timeTaken);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int n = 10;
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand();


    // Measure time taken by bubble sort
    radixsort(arr, n);
    print(arr, n);


    return 0;
}