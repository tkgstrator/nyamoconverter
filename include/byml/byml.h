#pragma once

#include <cstdint>
#include <array>
#include <optional>

#include "byml/types.h"

namespace BymlFormat
{

    struct Header
    {
        std::array<char, 2> magic;
        u16 version;
        u32 hashKeyTableOffset;
        u32 stringTableOffset;
        u32 rootNodeOffset;
    };

    enum class NodeType : u8
    {
        STR_NODE_TYPE      = 0xA0,
        PATH_NODE_TYPE     = 0xA1,
        ARRAY_NODE_TYPE    = 0xC0,
        DICT_NODE_TYPE     = 0xC1,
        STR_TAB_NODE_TYPE  = 0xC2,
        PATH_TAB_NODE_TYPE = 0xC3,
        BOOL_NODE_TYPE     = 0xD0,
        INT_NODE_TYPE      = 0xD1,
        FLOAT_NODE_TYPE    = 0xD2,
    };

    class Buffer
    {
    public:
        Buffer(char *data)
        {
            mData = data;
            mSize = sizeof(data);
        }
        char* data() { return mData; }
        operator char*() {return data(); }
    private:
        char *mData;
        size_t mSize;
    };

    class Reader
    {
    public:
        Reader(Buffer buffer);
        // ~Reader();

        bool isValid() const;
        bool isSrray() const;
        bool isHash() const;
        u16 getVersion() const;
        // std::optional<Array> getArray() const;
        // std::optional<Hash> getHash() const;
        Buffer getBuffer() const { return mBuffer; }
        bool isBigEndian() const { return mBigEndian; };
        u32 getHashKeyTableOffset() const { return mHashKeyTableOffset; }
        u32 getStringValueTableOffset() const { return mStringValueTableOffset; }

    private:
        Buffer mBuffer;
        u32 mHashKeyTableOffset = 0;
        u32 mStringValueTableOffset = 0;
        u32 mRootNodeOffset = 0;
        bool mHasValidHeader = false;
        bool mBigEndian = false;
    };
} // namespace BymlFormat