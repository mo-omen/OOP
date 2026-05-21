#include <iostream>
#include <stdlib.h>

class BankAccount {
    private:
        int balance = 0;
        std::string h_name;

    public:
        void initAccount(void) {
               if(h_name != "") {
                    std::cout << "Error 401: Account Already initalized" << std::endl;
               } else {
                    std::cout << "Please enter Account holder Name: ";
                    getline(std::cin, h_name);
                    std::cout << "Account initialized\n" << std::endl;
               }
        }

        int getBalance(void) {
            return balance;
        }

        void deposit(int amount) {
            if(amount <= 0) {
                std::cout << "Invalid input";
            } else {
                balance += amount;
            }
        }

        void withdraw(int amount) {
            if(amount <= 0) {
                std::cout << "Invalid input";
            } else {
                balance -= amount;
            }
        }

        void printStatement() {
            std::cout << "######################################" << std::endl;
            std::cout << "Account Holder Name:\t" << h_name << std::endl;
            std::cout << "Balance: \t\t" << balance << std::endl;
            std::cout << "######################################" << std::endl;
        }

        };


void menu(void);
void actions(void);
void pheader(void);

int main(void) {
    BankAccount _25014926;
    BankAccount _26002384;
    BankAccount _24002388;

    do {
       menu();

    }while(1);

    return 0;
}

void pheader(void) {
    system("clear");
    std::cout << "############### Welcome to the Bank of Jewz ###############" << std::endl << std::endl;
}

void menu(void) {
    pheader();

    int choice;

    std::cout << "1. Intialize Account" << std::endl;
    std::cout << "2. Login to Account" << std::endl;
    std::cout << "3. Quit" << std::endl;

    std::cout << "\nPlease enter a choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:

        case 2:
            actions();

        case 3:
            exit(0);

        default:
            std::cout << "Invalid Input" << std::endl;
    }
}

void actions(void) {
    pheader();

    int choice;

    std::cout << "1. Print Details" << std::endl;
    std::cout << "2. Deposit" << std::endl;
    std::cout << "3. Withdraw" << std::endl;
    std::cout << "4. Transfer" << std::endl;
    std::cout << "5. Go Back" << std::endl;
    std::cout << "\nPlease enter a choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:

        case 2:
            actions();

        case 3:
            exit(0);

        case 4:

        case 5:
            menu();

        default:
            std::cout << "Invalid Input" << std::endl;
    }

}

void transfer(std::string Account1, std::string Account2, int amount) {

}
