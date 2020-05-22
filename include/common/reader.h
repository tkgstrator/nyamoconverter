#pragma once

#include <cstring>

#include "byml/types.h"
#include "common/swap.h"

namespace BymlFormat
{
    namespace detail
    {
        inline bool isBigEndianPlatform()
        {
            return true;
        }
        template <typename T>
        T swapIfNeeded(T value, bool bigEndian)
        {
            if (isBigEndianPlatform() != bigEndian)
                value = SwapValue(value);
            return value;
        }
    } // namespace detail

    class BinaryReader
    {
    public:
        BinaryReader(char *data, bool bigEndian) : mData{data}, mBigEndian{bigEndian} {}
        bool isBigEndian() { return mBigEndian; }
        char *data() { return mData; }
        template <typename T>
        T read(size_t offset)
        {
            T value;
            std::memcpy(&value, &mData[offset], sizeof(T));
            return value;
        }

    private:
        char *mData = nullptr;
        bool mBigEndian = false;
    };
} // namespace BymlFormat