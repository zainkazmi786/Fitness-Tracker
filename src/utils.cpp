#include "../include/utils.h"
#include <iterator>  // for std::next

// Bubble Sort to sort recommendations based on the total calories burned (descending)
void bubbleSort(std::list<std::pair<std::string, int>>& recommendations) {
    bool swapped;
    
    // Traverse through all elements in the list
    do {
        swapped = false;
        auto it = recommendations.begin();
        auto nextIt = std::next(it);
        
        // Traverse the list and compare adjacent pairs
        while (nextIt != recommendations.end()) {
            // If the element is smaller than the next element, swap them
            if (it->second < nextIt->second) {
                std::swap(*it, *nextIt);
                swapped = true;
            }
            ++it;
            ++nextIt;
        }
    } while (swapped); // Continue the loop until no swaps are made
}
