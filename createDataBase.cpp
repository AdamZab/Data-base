#include <fstream>
#include <iostream>
#include <string>

using namespace std;

char menu(int option){
    cout << endl << "Menu" << endl;
    cout << "[1] Check file" << endl;
    cout << "[2] Add random data to file" << endl;
    cout << "[3] Erase data" << endl;
    cout << "[4] End program" << endl;
    cin >> option;
    return option;
}
    
void openFile() {
    int data;
    ifstream dataBase;
    dataBase.open("dataBase", ios::binary);
    if(dataBase.fail())
    {
        cout << "File failed to open.\n";
        exit(1);
    }
    cout << "dataBase contains:" << endl;
    int lineNumber = 1;
    while (dataBase.read((char*)&data, sizeof(data))){
        cout << "[" << lineNumber << "]: " << data << endl;
        ++lineNumber;
    }
    dataBase.close();
}

int main(){
    while(1){
        int option = 0;
        option = menu(option);
        if (option == 1){
            openFile();
        }
        else if (option == 2){
            int data;
            ofstream dataBase;
            dataBase.open("dataBase", ios::binary | ios::app);
            for (int ii = 0; ii < 1000; ++ii){
                data = rand();
                dataBase.write((char*)&data, sizeof(data));
            }
            dataBase.close();
        }
        else if (option == 3){
            ofstream dataBase;
            dataBase.open("dataBase", std::ofstream::out | std::ofstream::trunc);
            dataBase.close();
        }
        else if (option == 4){
            return 0;
        }
    }
}
