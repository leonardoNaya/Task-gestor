#include <iostream>
#include <fstream>
using namespace std;
int menu(){
    system("cls");
    int response;
    cout << "----Menu----" << endl;
    cout << "1 - Add task to-do" << endl;
    cout << "2 - View pending tasks" << endl;
    cout << "3 - Delete pending tasks" << endl;
    cout << "4 - Exit" << endl;
    cin >> response;
    return response;
}
void Add(ofstream &ar){
    system("cls");
    string task;
    ar.open("task.txt", ios::app);
    cout << "Enter the task to perform: ";
    getline(cin.ignore(), task);
    ar << task << endl;
    ar.close();
}
void See(ifstream &lec){
    system("cls");
    string task;
    int i = 1;
    lec.open("task.txt", ios::in);
    cout << "------Task to do------\n";
    while (getline(lec, task)) {
        if (!task.empty()) {
            cout << "Task number " << i << ": " << task << endl;
            i++;
        }
    }
    lec.close();
    system("pause");
}
void Erase() {
    system("cls");
    string taskAux, task;
    ifstream read("task.txt", ios::in);
    ofstream write("aux.txt", ios::out);
    if (!read.is_open()) {
        cout << "Could not open the task file" << endl;
        return;
    }
    cout << "Enter the task to delete: ";
    cin >> taskAux;
    bool find = false;
    while (read >> task) {
        if (task == taskAux) {
            find = true;
        } else {
            write << task << endl;
        }
    }
    read.close();
    write.close();
    if (find) {
        remove("task.txt");
        rename("aux.txt", "task.txt");
        cout << "Task eliminated." << endl;
    } else {
        remove("aux.txt");
        cout << "Could not find the task." << endl;
    }
}
int main() {
    ofstream write;
    ifstream read;
    int option = 0;
    do
    {
        option = menu();
        switch (option){
            case 1:
                Add(write);
                break;
            case 2:
                See(read);
                break;
            case 3:
                Erase();
                break;
            default:
                break;
        }
    }while (option !=4);
    return 0;
}
