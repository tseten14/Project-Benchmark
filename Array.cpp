#include <iostream>
#include <array>
#include <fstream>
#include <chrono>
#include <ctime>

// Append Function
int Append(int& length, std::array<int, 100>& arr) {
    if (length >= 100) {
        std::cerr << "Array is full, cannot append.\n";
        return -1;
    }
    int input;
    std::cout << "Enter an integer to append: ";
    std::cin >> input;

    auto start = std::chrono::high_resolution_clock::now();
    arr[length++] = input; // Append element
    auto stop = std::chrono::high_resolution_clock::now();

    auto runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    for (int i = 0; i < length; ++i) std::cout << arr[i] << " ";
    std::cout << "\nRuntime: " << runtime.count() << " nanoseconds\n";
    return runtime.count();
}

// Prepend Function
int Prepend(int& length, std::array<int, 100>& arr) {
    if (length >= 100) {
        std::cerr << "Array is full, cannot prepend.\n";
        return -1;
    }
    int input;
    std::cout << "Enter an integer to prepend: ";
    std::cin >> input;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = length; i > 0; --i) arr[i] = arr[i - 1];
    arr[0] = input;
    ++length;
    auto stop = std::chrono::high_resolution_clock::now();

    auto runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    for (int i = 0; i < length; ++i) std::cout << arr[i] << " ";
    std::cout << "\nRuntime: " << runtime.count() << " nanoseconds\n";
    return runtime.count();
}

// Remove from End Function
int Remove_from_end(int& length, std::array<int, 100>& arr) {
    if (length == 0) {
        std::cerr << "Array is empty, cannot remove from end.\n";
        return -1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    arr[--length] = 0; // Remove last element
    auto stop = std::chrono::high_resolution_clock::now();

    auto runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    for (int i = 0; i < length; ++i) std::cout << arr[i] << " ";
    std::cout << "\nRuntime: " << runtime.count() << " nanoseconds\n";
    return runtime.count();
}

// Remove from Beginning Function
int Remove_from_beginning(int& length, std::array<int, 100>& arr) {
    if (length == 0) {
        std::cerr << "Array is empty, cannot remove from beginning.\n";
        return -1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < length - 1; ++i) arr[i] = arr[i + 1];
    --length;
    auto stop = std::chrono::high_resolution_clock::now();

    auto runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    for (int i = 0; i < length; ++i) std::cout << arr[i] << " ";
    std::cout << "\nRuntime: " << runtime.count() << " nanoseconds\n";
    return runtime.count();
}

// Swap Function
int Swap(int length, std::array<int, 100>& arr) {
    int pos1, pos2;
    std::cout << "Enter two positions to swap: ";
    std::cin >> pos1 >> pos2;

    if (pos1 <= 0 || pos2 <= 0 || pos1 > length || pos2 > length) {
        std::cerr << "Invalid positions.\n";
        return -1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    std::swap(arr[pos1 - 1], arr[pos2 - 1]);
    auto stop = std::chrono::high_resolution_clock::now();

    auto runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    for (int i = 0; i < length; ++i) std::cout << arr[i] << " ";
    std::cout << "\nRuntime: " << runtime.count() << " nanoseconds\n";
    return runtime.count();
}

// Reverse Function
int Reverse(int length, std::array<int, 100>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < length / 2; ++i) std::swap(arr[i], arr[length - 1 - i]);
    auto stop = std::chrono::high_resolution_clock::now();

    auto runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    for (int i = 0; i < length; ++i) std::cout << arr[i] << " ";
    std::cout << "\nRuntime: " << runtime.count() << " nanoseconds\n";
    return runtime.count();
}

// Empty Function
int Empty(int& length, std::array<int, 100>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    arr.fill(0);
    length = 0;
    auto stop = std::chrono::high_resolution_clock::now();

    auto runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    for (int i = 0; i < length; ++i) std::cout << arr[i] << " ";
    std::cout << "\nRuntime: " << runtime.count() << " nanoseconds\n";
    return runtime.count();
}

// Main Function
int main() {
    std::array<int, 100> arr{};
    int length = 0;
    std::ofstream file("array_operations.csv");
    file << "Operation,Runtime (nanoseconds)\n";

    std::cout << "Append Operation:\n";
    file << "Append," << Append(length, arr) << "\n";

    std::cout << "Prepend Operation:\n";
    file << "Prepend," << Prepend(length, arr) << "\n";

    std::cout << "Remove from End Operation:\n";
    file << "Remove from End," << Remove_from_end(length, arr) << "\n";

    std::cout << "Remove from Beginning Operation:\n";
    file << "Remove from Beginning," << Remove_from_beginning(length, arr) << "\n";


    std::cout << "Append Operation:\n";
    file << "Append," << Append(length, arr) << "\n";
    std::cout << "Append Operation:\n";
    file << "Append," << Append(length, arr) << "\n";
    std::cout << "Append Operation:\n";
    file << "Append," << Append(length, arr) << "\n";
    
    std::cout << "Swap Operation:\n";
    file << "Swap," << Swap(length, arr) << "\n";


    std::cout << "Reverse Operation:\n";
    file << "Reverse," << Reverse(length, arr) << "\n";

    std::cout << "Empty Operation:\n";
    file << "Empty," << Empty(length, arr) << "\n";

    file.close();
    return 0;
}
