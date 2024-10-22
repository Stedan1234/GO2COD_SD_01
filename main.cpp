#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //for std::transform
using namespace std;

//Structure to store contact info
struct Contact {
    string name;
    string phone;
    string email;
};

// Vector to store a list of contacts
vector<Contact> contacts;

//  Function to add new contact
void addContact () {
   Contact newContact;
   cout << "Enter Name: ";
   getline(cin, newContact.name);
   cout << "Enter Phone Number: ";
   getline(cin, newContact.phone);
   cout << "Enter Email: ";
   getline(cin, newContact.email);

   contacts.push_back(newContact);
   cout << "Contact '" << newContact.name << "' added successfully!\n\n";
}

//Function to view all contacts
void viewContacts() {
    if (contacts.empty()) {
        cout << "No contacts available.\n\n";
        return;
    }
    cout << "Contacts List:\n";
    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << i + 1 << ". Name: " << contacts[i].name
             << ", Phone: " << contacts[i].phone
             << ", Email: " << contacts[i].email << "\n";
    }
    cout << endl;
}

// function to edit an existing contact
void editContact() {
    string searchName;
    cout << "Enter the Name of the contact to edit: ";
    getline(cin, searchName);

    for (auto& contact : contacts) {
        if(contact.name == searchName) {
            cout << "Editing contact: " << contact.name << "\n";
            cout << "Enter new name: ";
            getline(cin, contact.name);
            cout << "Enter new phone number: ";
            getline(cin, contact.phone);
            cout << "Enter new email: ";
            getline(cin, contact.email);
            cout << "Contact updated successfully!\n\n";
            return;
        }
    }
    cout << "No contact found with the name '" << searchName << "'.\n\n";
}

// function to delete a contact
void deleteContact() {
    string searchName;
    cout << "Enter the name of the contact to delete: ";
    getline(cin, searchName);

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
       if (it->name == searchName) {
            contacts.erase(it);
            cout << "Contact '" << searchName << "' deleted successfully!\n\n";
            return;
        }
    }
    cout << "No contact found with the name '" << searchName << "'.\n\n";
}

// function to search for a contact by name or phone
void searchContact() {
    string query;
    cout << "Enter name or phone number to search: ";
    getline(cin, query);

    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.name.find(query) != string::npos || contact.phone.find(query) != string::npos) {
            cout << "Found: Name: " << contact.name
                 << ", Phone: " << contact.phone
                 << ", Email: " << contact.email << "\n";
            found = true;

        }
    }
    if (!found) {
        cout << "No contact found matching '" << query << "'.\n\n";
    } else {
        cout << endl;
    }
}

// function to display menu and handle all user inputs
void menu() {
    while (true) {
        cout << "\n--- Contact Management Menu ---\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Edit Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Search Contact\n";
        cout << "6. Exit\n";
        cout << " Choose an option (1-6): ";

        string choice;
        getline(cin, choice);

        if (choice == "1") {
            addContact();
        } else if (choice == "2") {
            viewContacts();
        } else if (choice == "3") {
            editContact();
        } else if (choice == "4") {
            deleteContact();
        } else if (choice == "5") {
            searchContact();
        } else if (choice == "6") {
            cout << "Exiting the program. Goodbye!\n";
            break;
        } else {
            cout << "Invalid option. Please choose a valid number from the menu.\n\n";
        }
    }
}

// main function
int main()
{
    menu();
    return 0;
}
