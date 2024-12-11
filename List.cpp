#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
#include <chrono>

// Function to print list
void print_list(const std::list<int>& list_name) {
    for (const auto& val : list_name) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

// Append function
int Append(std::list<int>& list_name) {
    int input;
    std::cout << "Enter an integer to add at the end of the list: ";
    std::cin >> input;

    auto start = std::chrono::high_resolution_clock::now();
    list_name.push_back(input);
    auto stop = std::chrono::high_resolution_clock::now();

    print_list(list_name);
    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

// Prepend function
int Prepend(std::list<int>& list_name) {
    int input;
    std::cout << "Enter an integer to add at the beginning of the list: ";
    std::cin >> input;

    auto start = std::chrono::high_resolution_clock::now();
    list_name.push_front(input);
    auto stop = std::chrono::high_resolution_clock::now();

    print_list(list_name);
    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

// Remove from end
int Remove_from_end(std::list<int>& list_name) {
    auto start = std::chrono::high_resolution_clock::now();
    list_name.pop_back();
    auto stop = std::chrono::high_resolution_clock::now();

    print_list(list_name);
    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

// Remove from beginning
int Remove_from_beginning(std::list<int>& list_name) {
    auto start = std::chrono::high_resolution_clock::now();
    list_name.pop_front();
    auto stop = std::chrono::high_resolution_clock::now();

    print_list(list_name);
    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

// Swap elements
int Swap(std::list<int>& list_name) {
    if (list_name.size() < 2) {
        std::cout << "Not enough elements to swap.\n";
        return -1;
    }

    int pos1, pos2;
    std::cout << "Enter 2 positions to swap: ";
    std::cin >> pos1 >> pos2;

    auto it1 = std::next(list_name.begin(), pos1 - 1);
    auto it2 = std::next(list_name.begin(), pos2 - 1);

    auto start = std::chrono::high_resolution_clock::now();
    std::iter_swap(it1, it2);
    auto stop = std::chrono::high_resolution_clock::now();

    print_list(list_name);
    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

// Empty the list
int Empty(std::list<int>& list_name) {
    auto start = std::chrono::high_resolution_clock::now();
    list_name.clear();
    auto stop = std::chrono::high_resolution_clock::now();

    print_list(list_name);
    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

// Insert at position
int Insert(std::list<int>& list_name) {
    int pos, input;
    std::cout << "Enter the position to insert: ";
    std::cin >> pos;
    std::cout << "Enter the value to insert: ";
    std::cin >> input;

    auto it = std::next(list_name.begin(), pos - 1);

    auto start = std::chrono::high_resolution_clock::now();
    list_name.insert(it, input);
    auto stop = std::chrono::high_resolution_clock::now();

    print_list(list_name);
    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

// Remove duplicates
int Remove_duplicate(std::list<int>& list_name) {
    list_name.sort(); // Required for unique()
    auto start = std::chrono::high_resolution_clock::now();
    list_name.unique();
    auto stop = std::chrono::high_resolution_clock::now();

    print_list(list_name);
    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

// Reverse the list
int Reverse(std::list<int>& list_name) {
    auto start = std::chrono::high_resolution_clock::now();
    list_name.reverse();
    auto stop = std::chrono::high_resolution_clock::now();

    print_list(list_name);
    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

// Main function
int main() {
    std::list<int> sherpa_list;
    int var1 = 5;

    std::ofstream file_1("list.csv");
    file_1 << "Container Size,Append,Prepend,Remove from End,Remove from Beginning,Swap,Empty,Insert,Remove Duplicates,Reverse\n";

    for (int i = 0; i < 40; i += 5) {
        for (int j = i; j < i + 5; ++j) {
            sherpa_list.push_back(var1);
            var1 += 5;
        }

        file_1 << sherpa_list.size() << ","
               << Append(sherpa_list) << ","
               << Prepend(sherpa_list) << ","
               << Remove_from_end(sherpa_list) << ","
               << Remove_from_beginning(sherpa_list) << ","
               << Swap(sherpa_list) << ","
               << Empty(sherpa_list) << ","
               << Insert(sherpa_list) << ","
               << Remove_duplicate(sherpa_list) << ","
               << Reverse(sherpa_list) << "\n";
    }

    file_1.close();
    return 0;
}
