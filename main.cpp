#include <iostream>
#include <vector>
#include <map>

void print_menu() {
    std::map<int, std::string> menu_options = {
        {1, "Print Pattern"},
        {2, "Rotate Array "},
        {3, " Help"},
        {4, "Exit"},
    };

    for (auto const& pair: menu_options) {
        std::cout << pair.first << " -- " << pair.second << std::endl;
    }
}

void option1() {
    int n;
    std::cout << "Enter the number of rows for the pattern: ";
    std::cin >> n;

    for (int i = n; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

void option2() {
    int n, k;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;
    std::cout << "Enter the number of rotations: ";
    std::cin >> k;

    std::vector<int> arr(n);
    std::cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::vector<int> temp(arr.begin() + n - k, arr.end());
    temp.insert(temp.end(), arr.begin(), arr.begin() + n - k);

    std::cout << "Rotated array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << temp[i] << " ";
    }
    std::cout << std::endl;
}

void option3() {
    std::cout << " --Help-- Option 1: Print a pattern with 'n' rows of decreasing asterisks.\n";
    std::cout << "Option 2: Rotate an array of 'n' elements of the right by 'k' steps.\n";
    std::cout << "Option 3: Display this help message.\n";
    std::cout << "Option 4: Exit the program.\n";
}

void option4() {
    std::cout << "Exiting the program. Goodbye!" << std::endl;
    exit(0);
}

int main() {
    while (true) {
        print_menu();
        int option;
        std::cout << "Enter your choice: ";
        std::cin >> option;

        switch (option) {
            case 1:
                option1();
                break;
            case 2:
                option2();
                break;
            case 3:
                option3();
                break;
            case 4:
                option4();
                break;
            default:
                std::cout << "Invalid option. Please enter a number between 1 and 4." << std::endl;
        }
    }

    return 0;
}
