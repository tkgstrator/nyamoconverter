#include <iostream>
#include <fstream>
#include <sstream>
#include "bymlformat.h"

using namespace std;

// std::string Byaml::readU16(int index)
// {
//     char buf[16];
//     std::stringstream ss;

//     file.seekg(index, std::ios_base::cur);
//     file.read(buf, sizeof(buf));
//     cout << sizeof(buf) << endl;
//     for (int i = 0; i < sizeof(buf); i++)
//     {
//         ss << std::hex << uppercase << int((std::byte)buf[i]);
//     }
//     cout << ss.str() << endl;
//     cout << __builtin_bswap16(stoi(ss.str())) << endl;
//     return "0";
// }

// std::string Byaml::readU24(int offset)
// {
//     char buf[24];
//     std::stringstream ss;

//     file.seekg(offset, std::ios_base::cur);
//     file.read(buf, sizeof(buf));
//     cout << sizeof(buf) << endl;
//     for (int i = 0; i < sizeof(buf); i++)
//     {
//         ss << std::hex << uppercase << int((std::byte)buf[i]);
//     }
//     return ss.str();
// }

// std::string Byaml::readU32(int offset)
// {
//     char buf[32];
//     std::stringstream ss;

//     file.seekg(offset, std::ios_base::cur);
//     file.read(buf, sizeof(buf));
//     cout << sizeof(buf) << endl;
//     for (int i = 0; i < sizeof(buf); i++)
//     {
//         ss << std::hex << uppercase << int((std::byte)buf[i]);
//     }
//     return ss.str();
// }

int main()
{

    // while (!file.eof())
    // {
    //     file.read(buf, sizeof(buf));
    //     for (int i = 0; i < sizeof(buf); i++)
    //     {
    //         cout << hex << uppercase << int(buf[i]);
    //     }
    //     cout << endl;
    //     cout << int(buf[7]) << endl;
    //     if ((string)buf != "BY")
    //     {
    //         return EXIT_FAILURE;
    //     }
    //     cout << "FILE SIZE : " << sizeof(file) <<  endl;
    //     cout << "ENCRYPT VERSION : " << hex << int(buf[3]) << endl;
    //     cout << "HASH OFFSET : " << hex << int(buf[4]) << endl;
    //     cout << "TABLE OFFSET : " << hex << int(buf[8]) << endl;

    //     break;
    //     for (int i = 0, size = file.gcount(); i < size; ++i)
    //     {
    //         cout << hex << uppercase << int(buf[i]) << std::flush;
    //     }
    //     cout << endl;
    // }

    // file.close();

    return 0;
}