#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>

// Function to Print Vector
void print_vec(const std::vector<int>& vec) {
    for (auto it : vec) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

// Function for Append
int Append(std::vector<int>& vec, int input) {
    auto start = std::chrono::high_resolution_clock::now();
    vec.push_back(input);
    auto stop = std::chrono::high_resolution_clock::now();

    print_vec(vec);
    int runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cout << "The function takes " << runtime << " nanoseconds.\n";
    return runtime;
}

// Function for Prepend
int Prepend(std::vector<int>& vec, int input) {
    auto start = std::chrono::high_resolution_clock::now();
    vec.insert(vec.begin(), input);
    auto stop = std::chrono::high_resolution_clock::now();

    print_vec(vec);
    int runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cout << "The function takes " << runtime << " nanoseconds.\n";
    return runtime;
}

// Function for Remove from End
int Remove_from_end(std::vector<int>& vec) {
    if (vec.empty()) {
        std::cout << "Vector is empty. Cannot remove elements.\n";
        return -1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    vec.pop_back();
    auto stop = std::chrono::high_resolution_clock::now();

    print_vec(vec);
    int runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cout << "The function takes " << runtime << " nanoseconds.\n";
    return runtime;
}

// Function for Remove from Beginning
int Remove_from_beginning(std::vector<int>& vec) {
    if (vec.empty()) {
        std::cout << "Vector is empty. Cannot remove elements.\n";
        return -1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    vec.erase(vec.begin());
    auto stop = std::chrono::high_resolution_clock::now();

    print_vec(vec);
    int runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cout << "The function takes " << runtime << " nanoseconds.\n";
    return runtime;
}

// Function for Swap
int Swap(std::vector<int>& vec) {
    if (vec.size() < 2) {
        std::cout << "Not enough elements to swap.\n";
        return -1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    std::iter_swap(vec.begin(), vec.end() - 1);
    auto stop = std::chrono::high_resolution_clock::now();

    print_vec(vec);
    int runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cout << "The function takes " << runtime << " nanoseconds.\n";
    return runtime;
}

// Function for Remove Duplicates
int Remove_duplicate(std::vector<int>& vec) {
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    auto stop = std::chrono::high_resolution_clock::now();

    print_vec(vec);
    int runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cout << "The function takes " << runtime << " nanoseconds.\n";
    return runtime;
}

// Function for Reverse
int Reverse(std::vector<int>& vec) {
    auto start = std::chrono::high_resolution_clock::now();
    std::reverse(vec.begin(), vec.end());
    auto stop = std::chrono::high_resolution_clock::now();

    print_vec(vec);
    int runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cout << "The function takes " << runtime << " nanoseconds.\n";
    return runtime;
}

// Main Function
int main() {
    std::vector<int> vec1;
    int var1 = 5;
    int user_input;

    std::cout << "Enter a single integer for operations: ";
    std::cin >> user_input;

    std::ofstream file_1("vector.csv");
    file_1 << "Container Size, Append, Prepend, Remove from End, Remove from Beginning, Swap, Remove Duplicates, Reverse\n";

    for (int i = 0; i < 40; i += 5) {
        for (int j = i; j < i + 5; ++j) {
            vec1.push_back(var1);
            var1 += 5;
        }

        file_1 << vec1.size() << ", "
               << Append(vec1, user_input) << ", "
               << Prepend(vec1, user_input) << ", "
               << Remove_from_end(vec1) << ", "
               << Remove_from_beginning(vec1) << ", "
               << Swap(vec1) << ", "
               << Remove_duplicate(vec1) << ", "
               << Reverse(vec1) << "\n";
    }

    file_1.close();
    return 0;
}
