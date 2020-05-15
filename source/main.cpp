#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Byaml
{
    public:
        std::fstream file;
        Byaml(std::string path)
        {
            file.open(path, std::ios::in | std::ios::binary);

        }
        int readU16(int);
        int readU24();
        int readU32();
    private:
};

int Byaml::readU16(int index) {
    char buf[16];
    std::stringstream ss;

    file.seekg(index, std::ios_base::cur);
    file.read(buf, sizeof(buf));
    cout << sizeof(buf) << endl;
    for (int i = 0; i < sizeof(buf); i++)
    {
        cout << buf << " to " << hex << uppercase << int(buf[i]) << endl;
        ss << std::hex << uppercase << int(buf[i]);
    }
    cout << ss.str() << endl;
    return 0;
}

int Byaml::readU24() {
    char buf[24];
    file.read(buf, sizeof(buf));

    return std::stoi(string(buf));
}

int Byaml::readU32() {
    char buf[32];
    file.read(buf, sizeof(buf));

    return std::stoi(string(buf));
}


int main()
{
    Byaml file = Byaml("0.byaml");
    cout << file.readU16(4) << endl;
    // if (!file.is_open())
    // {
    //     cout << "FILE OPEN ERROR" << endl;
    //     return EXIT_FAILURE;
    // }

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