#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> data = {1,1,1,1,1,1,1,1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5};

    // Find the maximum element in the dataset
    int maxElement = *std::max_element(data.begin(), data.end());

    // Create a frequency array to count occurrences of each element
    std::vector<int> frequency(maxElement + 1, 0);
    for (int num : data) {
        frequency[num]++;
    }

    // Display the histogram
    for (int i = 1; i <= maxElement; i++) {
        std::cout << i << " | ";
        for (int j = 0; j < frequency[i]; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}
