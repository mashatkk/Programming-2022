//.Створіть клас для банківського рахунку та  клас Клієнт. Клас Банківський рахунок повинен мати поля Клієн,
 //номера рахунку та баланс, повинен містити методи для додавання грошей на рахунок і знімання,
  //показ балансу та загальної інформації. Клас Клієнт повинен мати поля імʼяі клієнта, адреса та номер телефону. 
 //Ввести дані про 10 банківських рахунків, надати можливість пошуку рахунку за іменем клієнта та за адресою клієнта, 
// надати меню для додавання чи зняття грошей з вибраного рахунку#include<iostream>
#include<string>
#include <istream>
using namespace std;

class Client {
private:
    string name;
    string address;
    string phone;
public:
    Client() : name(""), address(""), phone("") {}
    Client( string _name, string _address, string _phone):  name(_name), address(_address), phone(_phone) {}
    friend istream& operator>>(istream& is, Client& data) {
        is >> data.name >> data.address >> data.phone;
        return is;
    }
    friend ostream& operator<<(ostream& os, Client& data1) {
        os << data1.name << " \t" << data1.address << " \t" << data1.tel;
        return os;
    };
    string get_address() {
        return address;
    }
    string get_name() {
        return name;
    }
    string get_phone() {
        return tel;
    }
    bool operator !=(const Client& other) {
        return !(this->tel == other.tel);
    }
    bool operator ==(const Client& other) {
        return (this->tel == other.tel);
    }
};
class Bank_account {
private:
    Client client;
    string number_of_card;
    int balance;
public:
    Bank_account() : balance(0), number_of_card(" ") { Client client(); }
    friend istream& operator>>(istream& is, Bank_account& data) {
        is >> data.client >> data.number_of_card >> data.balance;
        return is;
    }
    int addCash(int amount) {
        balance += amount;
        return balance;
    }
    int withdraw(int amount) {
        balance -= amount;
        return balance;
    };
    Client get_client() {
        return client;
    }
    string get_number_of_card() {
        return number_of_card;
    }
    void Balance() {
        cout << balance << endl;
    }
    void seeAllInformation() {
        cout << "Client:" << client << endl;
        cout << "Balance:" << balance;
        cout << "Number of card:" << number_of_card << endl;
    }
};
Bank_account Find_by_name(Bank_account array[10], string name) {
    bool flag = true;
    for (int i = 0; i < 10; i++) {
        if (array[i].get_client().get_name() == name) {
            cout << "Number of card:  " << array[i].get_number_of_card() << endl;
            flag = false;
            return array[i];
        }
    }
    if (flag) {
        cout << "There is no such card by this name" << endl;
    }
}
void Find_by_address(Bank_card array[2], string address) {
    bool flag = true;
    for (int i = 0; i < 2; i++) {
        if (array[i].get_client().get_address() == address) {
            cout << "Number of card : " << array[i].get_number_of_card() << endl;
            flag = false;
        }
    }
    if (flag) {
        cout << "There is no such card by this address" << endl;
    }
}
int main() {
    Bank_card list_of_cards[2];
    cout << "Enter 10 times data about 10 cards" << endl;
    for (int i = 0; i < 2; i++) {
        Bank_card object;
        cin >> object;
        list_of_cards[i] = object;
    }
    cout << "Now you can do some actions such as: add cash(enter add) or withdraw cash(enter withdraw)." << endl;
    string command;
    while (command != "end") {
        cout << "What do you want to do? TO end (enter end)" << endl;
        cin >> command;
        if (command == "add") {
            cout << "Choose name or address" << endl;
            string choice;
            cin >> choice;
            if (choice == "name") {
                cout << "Enter name" << endl;
                string name;
                cin >> name;
                Bank_card a = Find_by_name(list_of_cards, name);
                cout << "Enter amount" << endl;
                int amount;
                cin >> amount;
                a.addCash(amount);
                a.seeBalance();
            }
            else {
                cout << "Enter address" << endl;
                string address;
                cin >> address;
                Bank_card a = Find_by_name(_of_cards, address);
                cout << "Enter amount" << endl;
                int amount;
                cin >> amount;
                a.addCash(amount);
                a.seeBalance();
            }
        }
        if (command == "withdraw") {
            cout << "Choose name or address" << endl;
            string choice;
            cin >> choice;
            if (choice == "name") {
                cout << "Enter name" << endl;
                string name;
                cin >> name;
                Bank_card a = Find_by_name(list_of_cards, name);
                cout << "Enter amount" << endl;
                int amount;
                cin >> amount;
                a.withdrawCash(amount);
                a.seeBalance();
            }
            else {
                cout << "Enter address" << endl;
                string address;
                cin >> address;
                Bank_card a = Find_by_name(list_of_cards, address);
                cout << "Enter amount" << endl;
                int amount;
                cin >> amount;
                a.withdrawCash(amount);
                a.seeBalance();
            }
        }
    }
    return 0;
}