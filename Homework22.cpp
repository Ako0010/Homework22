#include <iostream>
#include <cassert>
using namespace std;
#include "myString.h"

int main() {
    myString str1;
    cout << "str1: " << str1.print() << endl;
    cout << endl;

    myString str2("Hello, world!");
    cout << "str2: " << str2.print() << endl;
    cout << endl;

    myString str3(str2);
    cout << "str3 (str2-nin sureti): " << str3.print() << endl;
    cout << endl;

    str1.append("Hello");
    cout << "str1 appendlendikden sonra: " << str1.print() << endl;
    cout << endl;

    str1.append(", world!");
    cout << "str1 ikinci append edildikden sonra: " << str1.print() << endl;
    cout << endl;

    int comparison = str1.compare(str2);
    if (comparison == 0) {
        cout << "str1 ve str2 beraberdir!" << endl;
    }
    else if (comparison < 0) {
        cout << "str1, str2-den kiçikdir." << endl;
    }
    else {
        cout << "str1, str2-den boyukdur." << endl;
    }
    cout << endl;

    size_t index = str2.find('d');
    cout << "'d' herfi bu indexde tapildi: " << index << endl;
    cout << endl;

    myString subStr = str2.substr(7, 5);
    cout << "str2-nin 7-ci indexden 5 herf uzunlugunda alt stringi: " << subStr.print() << endl;
    cout << endl;

    size_t countO = str2.count('a');
    cout << "'a' herfinin str2-de nece defe tekrarlanmasi: " << countO << endl;
    cout << endl;

    bool containsChar = str2.contains('S');
    cout << "str2 'S' herfini ozunde saxlayir? " << (containsChar ? "Beli" : "Xeyr") << endl;
    cout << endl;

    char frontChar = str2.front();
    char backChar = str2.back();
    cout << "str2-nin ilk herfi: " << frontChar << endl;
    cout << "str2-nin son herfi: " << backChar << endl;
    cout << endl;

    str2.resize(5);
    cout << "str2 5 uzunluqda resize edildikden sonra: " << str2.print() << endl;
    cout << endl;

    str2.shrink_to_fit();
    cout << "str2 shrink_to_fit edildikden sonra: " << str2.print() << endl;
    cout << endl;

    str2.clear();
    cout << "str2 clear edildikden sonra: Ugurla Temizlendi :) " << str2.print() << endl;
    cout << endl;

    return 0;
}

