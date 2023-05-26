#include "Product.h"  // Include the header file for the Product class. This file should define the Product class with its properties and methods.

// This function swaps two Product objects. It's used in the sorting algorithm below.
void Swap(Product& a, Product& b) {
    Product temp = a;  // Create a temporary copy of the first product.
    a = b;  // Assign the second product to the first product's location.
    b = temp;  // Assign the temporary copy (original first product) to the second product's location.
}

// This function sorts a vector of Product objects using an enhanced bubble sort algorithm.
void EnhancedBubbleSort(std::vector<Product>& data, bool ascending) {
    bool sorted = false;  // Flag to indicate if the vector is sorted. It's initially set to false.
    int size = data.size();  // Get the size of the vector.

    // Outer loop iterates over each element in the vector.
    for (int i = 0; i < size; i++) {
        if (sorted) return;  // If the vector is sorted, exit the function.
        sorted = true;  // Assume the vector is sorted until proven otherwise.

        // Inner loop iterates over each unsorted element in the vector.
        for (int j = 0; j < (size - 1 - i); j++) {  // Adjusted loop condition to avoid unnecessary comparisons.

            // If the current element is greater than the next element in an ascending sort (or less in a descending sort), swap them.
            if ((ascending && data[j].price > data[j + 1].price) || (!ascending && data[j].price < data[j + 1].price)) {
                Swap(data[j], data[j + 1]);  // Swap the current element and the next element.
                sorted = false;  // Since a swap was made, the vector is not sorted.
            }
        }
    }
}