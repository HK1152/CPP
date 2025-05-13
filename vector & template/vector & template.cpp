#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class MemoryCalculate {
private:
    vector<T> id;
    vector<string> name;

public:
    MemoryCalculate() {
        cout << "welcome";
    }

    void add() {
        T newid;
        string newname;
        cout << "\nEnter ID:";
        cin >> newid;
        cout << "\nEnter Name:";
        cin >> newname;
        id.push_back(newid);
        name.push_back(newname);
    }

    void display() const {
        cout << "Students List:" << endl;
        if (id.empty()) {
            cout << "No students in the list." << endl;
            return;
        }
        for (size_t i = 0; i < id.size(); ++i) {
            cout << "\nID: " << id[i] << ", Name: " << name[i] << endl;
        }
    }

    void remove(T searchId) {
        for (int i = 0; i < id.size(); i++) {
            if (id[i] == searchId) {
                id.erase(id.begin() + i);
                name.erase(name.begin() + i);
                cout << "Student with ID " << searchId << " removed." << endl;
                return;
            }
        }
        cout << "Student with ID " << searchId << " not found." << endl;
    }

    void search(T searchId) const {
        for (int i = 0; i < id.size(); i++) {
            if (id[i] == searchId) {
                cout << "Student found \n\n ID: " << id[i] << ", Name: " << name[i] << endl;
                return;
            }
        }
        cout << "Student with ID " << searchId << " not found." << endl;
    }
};

int main() {
    MemoryCalculate<int> studentList;
    int choice;

    while (1) {
        cout << "\nMenu:" << endl;
        cout << "1. Add students to a list." << endl;
        cout << "2. Display the list of students." << endl;
        cout << "3. Remove a student from the list by ID." << endl;
        cout << "4. Search for a student by ID." << endl;
        cout << "5. Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                studentList.add();
                break;
            case 2:
                studentList.display();
                break;
            case 3: {
                int removeId;
                cout << "Enter ID of the student to remove: ";
                cin >> removeId;
                studentList.remove(removeId);
                break;
            }
            case 4: {
                int searchId;
                cout << "Enter ID of the student to search: ";
                cin >> searchId;
                studentList.search(searchId);
                break;
            }
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
