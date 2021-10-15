#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <stdexcept>

using namespace std;

char abc[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'  };

char abcbig[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

char nbr[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

char sym[8] = { '!', '@', '#', '$', '%', '^', '&', '*'};

int hex_value(unsigned char hex_digit) {
    static const signed char hex_values[256] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
         0,  1,  2,  3,  4,  5,  6,  7,  8,  9, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    };
    int value = hex_values[hex_digit];
    if (value == -1) throw std::invalid_argument("invalid hex digit");
    return value;
}

std::string hex_to_string(const std::string& input) {
    const auto len = input.length();
    if (len & 1) throw std::invalid_argument("odd length");

    std::string output;
    output.reserve(len / 2);
    for (auto it = input.begin(); it != input.end(); )
    {
        int hi = hex_value(*it++);
        int lo = hex_value(*it++);
        output.push_back(hi << 4 | lo);
    }
    return output;
}

string decToHexa(int n) {
    char hexaDeciNum[100];
    int i = 0;
    while (n != 0) {
        int temp = 0;
 
        temp = n % 16;
 
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
 
        n = n / 16;
    }
    string output = "";
    for (int j = i - 1; j >= 0; j--)
        output.push_back(hexaDeciNum[j]);

    return output;
}


void dekrypt(string input2){

    char* chr;
    string  resolved;
    string layer3_resolver;
    layer3_resolver = input2;
    int layer3_length = layer3_resolver.length();
        for(int i = 0; i<layer3_length; i++){
        if(!(layer3_resolver[i] == '!' || layer3_resolver[i] == '@'|| layer3_resolver[i] == '#'|| layer3_resolver[i] == '$' || layer3_resolver[i] == '%'|| layer3_resolver[i] =='^'|| layer3_resolver[i] =='&'|| layer3_resolver[i] == '*') ){
            resolved.push_back(layer3_resolver[i]);
        }
        else{
            break;
        }
    }
    string input = hex_to_string(resolved);

    string str_obj(input);
    chr = &str_obj[0];

    int length = input.length();

    int delta = 2 * pow(length - 1, 2);
    int s1, s2, s3;
    s1 = ((sqrt(delta) + length) * length) - (sqrt(length) * 2) + 1;
    s2 = ((sqrt(delta) - length) * length) + (sqrt(length) * 2) - 1;
    s3 = sqrt(pow(sqrt(s1 + s2), 3) + 1);

    while(s3 > 10){
        s3 -= (s3 / 2) + (s3 % 2);
    }

    int a = 0;

    for(int i = 1; i<=s3 * 2; i++){
        for(int i = 0; i<length; i++){
            for(int j = 0; j<26; j++){
                if(chr[i] == abc[j]){
                    a = j - s3;
                    if(a < 0){
                        a = 26 + a;
                    }
                    chr[i] = abc[a];
                    break;
                }
                else if(chr[i] == abcbig[j]){
                    a = j - s3;
                    if(a < 0){
                        a = 26 + a;
                    }
                    chr[i] = abcbig[a];
                    break;
                }
            }
        }
    }
    for(int i = 0; i<length; i++){
        for(int j = 0; j<10; j++){
            if(chr[i] == nbr[j]){
                a = j - s3;
                if(a < 0){
                    a = 10 + a;
                }
                chr[i] = nbr[a];
                break;
            }
        }
    }

    unsigned long long int encryptionkey = ((((length * 10 + s3) / length) * sqrt(s3)) + s3 * length + chr[0]) * pow(chr[1], 2) / sqrt(chr[0]);

    int symnbr;
    symnbr = encryptionkey;
    while(symnbr > 8){
        symnbr /= 8;
    }

    string layer3_resolved;
    for(int i = 0; i<length; i++){
        layer3_resolved += chr[i];
    }

    cout << layer3_resolved;
}

int main(){
    string test;
    cin >> test;
    dekrypt(test);
    cout << endl;
    system("pause");
}
