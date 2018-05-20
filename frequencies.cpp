//
//  frequencies.cpp
//  PA1
//
//  Created by Yuhao Zhang on 4/16/18.
//  Copyright © 2018 Yuhao Zhang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>

class frequencies {
private:
    std::map<int, int> fTable;
    
public:
    frequencies() {}
    
    void addChar(char c) {
        fTable[int(c)]++;
    }
    
    void printTable() {
        for (std::map<int, int>::iterator i = fTable.begin(); i != fTable.end(); i++)
            std::cout << i->first << "  " << i->second << std::endl;
    }
};

int main(int argc, const char * argv[]) {
    frequencies f;
    char ch;
    while (std::cin.get(ch))
        f.addChar(ch);
    f.printTable();
    return 0;
}
