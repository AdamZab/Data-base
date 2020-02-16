#include <time.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

#define NUMBEROFDATA 10
#define MAXNUMBER 10000

class Data
{
    int ID;
    char name[10];
public:
    void set_data()
    {
        ID = rand() %8999 + 1000;
        int random_number;
        for(int ii = 0; ii < 10; ++ii){
            random_number = rand() % 26;
            name[ii] = 'a' + random_number;
        }

    }
    
    void print_data(){
        std::cout << ID << ": " << name << std::endl;
    }
    
};

int menu(int option){
    std::cout << std::endl << "Menu" << std::endl;
    std::cout << "[1] Read file" << std::endl;
    std::cout << "[2] Add random data to file" << std::endl;
    std::cout << "[3] Erase data" << std::endl;
    std::cout << "[4] End program" << std::endl;
    std::cin >> option;
    return option;
}
    
void open_file() {
    std::ifstream data_base;
    data_base.open("data_base.dat", std::ios::binary);
    if(data_base.fail())
    {
        std::cout << "File failed to open.\n";
        exit(1);
    }
    Data line;
    std::cout << "data_base contains:" << std::endl;

    while (data_base.read((char*)&line, sizeof(line)))
        line.print_data();
    data_base.close();    
}

void erase_file(){
    std::ofstream data_base;
    data_base.open("data_base.dat", std::ofstream::out | std::ofstream::trunc);
    data_base.close();
}

void save_file(){
    std::ofstream data_base;
    data_base.open("data_base.dat", std::ios::binary | std::ios::app);
    Data line;
    line.set_data();
    data_base.write((char*)&line, sizeof(line)); 

    data_base.close();
}


int main(){
    srand (time(NULL));
    while(1){
        int option = menu(option);
        switch (option){
            
            case 1:{
            open_file();
            break;
            }

            case 2:{
                Data line;
                for (int ii; ii <= 100; ++ii)
                    save_file(); 
                line.print_data();
                break;
            }
        
            case 3:{
            erase_file();
            break;
            }
        
            case 4:
            return 0;
        }
    }
}
