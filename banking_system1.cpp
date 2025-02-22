#include<iostream>
#include<vector>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    Transaction(string type, double amount) : type(type), amount(amount) {}
    
    void display() {
        cout << "Transaction: " << type << " | Amount: " << amount << endl;
    }
};

class Account {
public:
    int accountnumber;
    double balance;
    vector<Transaction> transactions;

    Account(int accnum, double bal) : accountnumber(accnum), balance(bal) {}

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactions.push_back(Transaction("Withdraw", amount));
            cout << "Withdraw: " << amount << " | New Balance: " << balance << endl;
            return true;
        } 
        else {
            cout << "Insufficient balance!" << endl;
            return false;
        }
    }

    void displayTransactions() {
        cout << "Transactions for Account " << accountnumber << ":\n";
        for (Transaction &t : transactions) {
            t.display();
        }
    }
};

class Customer {
public:
    string name;
    int customerID;
    vector<Account> accounts;

    Customer(string name, int id) : name(name), customerID(id) {}

    void addAccount(int accnum, double initialBalance) {
        accounts.push_back(Account(accnum, initialBalance));
    }

    Account* getAccount(int accnum) {
        for (auto &acc : accounts) {
            if (acc.accountnumber == accnum)
                return &acc;
        }
        return nullptr;
    }
};

int main() {
    Customer customer("John Doe", 1001);
    customer.addAccount(12345, 500.0);
    
    Account* acc = customer.getAccount(12345);
    
    if (acc) {
        acc->deposit(200);
        acc->withdraw(100);
        acc->displayTransactions();
    }
    
    return 0;
}

