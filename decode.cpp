//
//  decode.cpp
//  PA1
//
//  Created by Yuhao Zhang on 4/24/18.
//  Copyright © 2018 Yuhao Zhang. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class decode {
private:
    map<string, int> codeMap;
    vector<char> byte;
    string binary;
    
public:
    void createCodeMap(const char *filename) {
        int ASC;
        string huffmanCode;
        ifstream is(filename);
        if (!is.is_open())
            cout << "Wrong file or file name" << endl;
        else {
            while (is >> ASC) {
                is >> huffmanCode;
                codeMap[huffmanCode] = ASC;
            }
        }
    }
    
    void getByte(char c) {
        byte.push_back(c);
    }
    
    void decodeByte() {
        for (int i = 0; i < byte.size(); i++)
            for (int j = 0; j < 8; j++)
                binary += to_string((byte[i] >> (7 - j)) & 1);
        
        string header = binary.substr(0, 8);
        int counter = 0;
        for (int i = 0; i < 8; i++)
            if (header[i] == '1')
                counter++;
        for (int i = 0; i < counter; i++)
            binary.pop_back();
        binary.erase(0,8);
    }
    
    void generateString() {
        string finder = "";
        for (int i = 0; i < binary.size(); i++) {
            finder += binary[i];
            if (codeMap.find(finder) != codeMap.end()) {
                string convertor;
                convertor = (char) codeMap[finder];
                cout << convertor;
                finder = "";
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    decode d;
    d.createCodeMap(argv[1]);
    char ch;
    while (cin.get(ch))
        d.getByte(ch);
    d.decodeByte();
    d.generateString();
    return 0;
}
