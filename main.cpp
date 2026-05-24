#include <iostream>
#include <limits>
#include "AVLTree.hpp"



void printMenu() {
    std::cout << '\n';
    std::cout << "=== AVL Tree Menu ===" << '\n';
    std::cout << "1. Insert element manually" << '\n';
    std::cout << "2. Load predefined array of numbers (10 elements)" << '\n';
    std::cout << "3. Display tree" << '\n';
    std::cout << "0. Exit" << '\n';
    std::cout << "Select an option: ";
}

int main() {
    std::cout << "Welcome to the AVL tree!" << '\n';

    AVLTree tree;
    int choice;

    do {
        printMenu();

        // Dummy check
        if (!(std::cin >> choice)) {
            std::cout << "Error: Please enter a number!" << '\n';
            std::cin.clear(); // ресет
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1; // костиль для продовження циклу
            continue;
        }

        switch (choice) {
            case 1: {
                int val;
                std::cout << "Enter a number to insert: ";


                if ((std::cin >> val) && (std::cin.peek() == '\n' || std::cin.peek() == ' ')) {
                    tree.insert(val);
                    std::cout << "Element " << val << " successfully inserted." << '\n';
                } else {
                    std::cout << "Invalid number input. Strictly integers only!" << '\n';
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // клінер рядка
                }
                break;
            }
            case 2: {
                int arr[10] = {50, 30, 70, 20, 40, 60, 80, 10, 35, 45};
                std::cout << "Loading array: ";
                for (int i = 0; i < 10; ++i) {
                    std::cout << arr[i] << " ";
                    tree.insert(arr[i]);
                }
                std::cout << '\n';
                std::cout << "Array successfully loaded into the tree!" << '\n';
                break;
            }
            case 3:
                std::cout << '\n';
                std::cout << "Current AVL Tree structure:" << '\n';
                tree.display();
                break;
            case 0:
                std::cout << "Exiting program. Goodbye!" << '\n';
                break;
            default:
                std::cout << "Invalid option. Please choose a number from 0 to 3." << '\n';
                break;
        }

    } while (choice != 0);

    return 0;
}