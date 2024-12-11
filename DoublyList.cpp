#include <iostream>
#include <forward_list>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <string>

void print_list(const std::forward_list<int>& list_name) { // Function for printing list
    for (const int& value : list_name) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int Append(std::forward_list<int>& list_name) {
    int input;
    std::cout << "Enter any integer to add at the end of the list: ";
    std::cin >> input;

    auto it = list_name.before_begin();
    for (auto iter = list_name.begin(); iter != list_name.end(); ++iter) {
        ++it;
    }

    auto start = std::chrono::high_resolution_clock::now();
    list_name.insert_after(it, input);
    auto stop = std::chrono::high_resolution_clock::now();

    std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    print_list(list_name);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds\n";

    return runtime.count();
}

int Prepend(std::forward_list<int>& list_name) {
    int input;
    std::cout << "Enter any integer to add at the beginning of the list: ";
    std::cin >> input;

    auto start = std::chrono::high_resolution_clock::now();
    list_name.push_front(input);
    auto stop = std::chrono::high_resolution_clock::now();

    std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    print_list(list_name);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds\n";

    return runtime.count();
}

int Remove_from_end(std::forward_list<int>& list_name) {
    if (list_name.empty()) {
        std::cout << "List is already empty.\n";
        return 0;
    }

    auto prev = list_name.before_begin();
    for (auto it = list_name.begin(); std::next(it) != list_name.end(); ++it) {
        ++prev;
    }

    auto start = std::chrono::high_resolution_clock::now();
    list_name.erase_after(prev);
    auto stop = std::chrono::high_resolution_clock::now();

    std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    print_list(list_name);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds\n";

    return runtime.count();
}

int Remove_from_beginning(std::forward_list<int>& list_name) {
    if (list_name.empty()) {
        std::cout << "List is already empty.\n";
        return 0;
    }

    auto start = std::chrono::high_resolution_clock::now();
    list_name.pop_front();
    auto stop = std::chrono::high_resolution_clock::now();

    std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    print_list(list_name);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds\n";

    return runtime.count();
}

int Swap(std::forward_list<int>& list_name) {
    int pos1, pos2;
    std::cout << "Enter 2 positions of integers you want swapped: ";
    std::cin >> pos1 >> pos2;

    if (pos1 <= 0 || pos2 <= 0 || pos1 == pos2) {
        std::cout << "Invalid positions.\n";
        return 0;
    }

    auto it1 = list_name.before_begin();
    auto it2 = list_name.before_begin();
    for (int i = 0; i < pos1 - 1; ++i) ++it1;
    for (int i = 0; i < pos2 - 1; ++i) ++it2;

    // Swap only if both positions are valid
    auto start = std::chrono::high_resolution_clock::now();
    std::swap(*std::next(it1), *std::next(it2));
    auto stop = std::chrono::high_resolution_clock::now();

    std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    print_list(list_name);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds\n";

    return runtime.count();
}

int Empty(std::forward_list<int>& list_name) {
    auto start = std::chrono::high_resolution_clock::now();
    list_name.clear();
    auto stop = std::chrono::high_resolution_clock::now();

    std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    print_list(list_name);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds\n";

    return runtime.count();
}

int Insert(std::forward_list<int>& list_name) {
    int pos, input;
    std::cout << "At what position would you like to add your integer? ";
    std::cin >> pos;
    std::cout << "Enter the integer to add at the given position: ";
    std::cin >> input;

    if (pos <= 0) {
        std::cout << "Invalid position.\n";
        return 0;
    }

    auto it = list_name.before_begin();
    for (int i = 0; i < pos - 1; ++i) ++it;

    auto start = std::chrono::high_resolution_clock::now();
    list_name.insert_after(it, input);
    auto stop = std::chrono::high_resolution_clock::now();

    std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    print_list(list_name);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds\n";

    return runtime.count();
}

int main() {
    std::forward_list<int> sherpa_list;
    int var1 = 5;

    std::ofstream file_1("forward_list.csv");
    file_1 << "Container Size, Append, Prepend, Remove from end, Remove from beginning, Swap, Empty, Insert\n";

    for (int i = 0; i < 40; i += 5) {
        for (int j = i; j < i + 5; ++j) {
            sherpa_list.push_front(var1);
            var1 += 5;
        }

        file_1 << i + 5 << ", " << Append(sherpa_list) << ", " << Prepend(sherpa_list) << ", "
               << Remove_from_end(sherpa_list) << ", " << Remove_from_beginning(sherpa_list) << ", "
               << Swap(sherpa_list) << ", " << Empty(sherpa_list) << ", " << Insert(sherpa_list) << "\n";
    }

    return 0;
}
