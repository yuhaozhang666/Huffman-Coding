//
//  encode.cpp
//  PA1
//
//  Created by Yuhao Zhang on 4/23/18.
//  Copyright © 2018 Yuhao Zhang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

class encode {
private:
    map<int, string> codeMap;
    string encryption;
    vector<bool> bit;
    
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
                codeMap[ASC] = huffmanCode;
            }
        }
    }
    
    void encrypt(char c) {
        encryption += codeMap[int(c)];
    }
    
    void convert() {
        for (int i = 0; i < encryption.size(); i++) {
            if (encryption[i] == '0')
                bit.push_back(0);
            else
                bit.push_back(1);
        }
        
        int more = 8 - (bit.size() % 8);
        unsigned char header = 0x00;
        if (more != 8) {
            for (int i = 0; i < more; i++) {
                header = header << 1;
                header = header | 1;
            }
        }
        cout << header;
        
        while (bit.size() % 8 != 0)
            bit.push_back(0);
        
        for (int i = 0; i < bit.size(); i += 8) {
            unsigned char x = 0x00;
            for (int j = i; j < i + 8; j++) {
                x = x << 1;
                x = bit[j] | x;
            }
            cout << x;
        }
    }
};

int main(int argc, const char * argv[]) {
    encode s;
    s.createCodeMap(argv[1]);
    char ch;
    while (cin.get(ch))
        s.encrypt(ch);
    s.convert();
    return 0;
}
