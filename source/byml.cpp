#include "byml/byml.h"
#include "byml/bymlformat.h"
#include "common/reader.h"
#include <iostream>

namespace BymlFormat {
    Reader::Reader(BymlFormat::Buffer buffer) : mBuffer{buffer} {
        const bool isBigEndian = buffer[0] == 'B' && buffer[1] == 'Y';
        mBigEndian = isBigEndian;
    }
}