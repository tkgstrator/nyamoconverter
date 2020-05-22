#include <iostream>
#include <fstream>
#include "byml/byml.h"

int main(){
    std::cout << "BYML CONVERTER" << std::endl;

    std::fstream file;
    file.open("0.bprm", std::ios::in | std::ios::binary);

    char buffer[0x14];
    file.read(buffer, sizeof(buffer));
    BymlFormat::Buffer mBuffer = BymlFormat::Buffer(buffer);
    BymlFormat::Reader mBymlReader = BymlFormat::Reader(mBuffer);
    return 0;
}