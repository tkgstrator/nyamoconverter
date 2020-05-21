#include <cstddef>
#include <list>

namespace BymlFormat
{
    class Header
    {
    public:
        uint32_t ArrayOffset;
        uint32_t StringTableOffset;
        uint32_t DictionaryOffset;
        uint16_t Version;

        Header(std::byte data[])
        {
            if (int(data[0]) == 0x59)
            {
                std::cout << "BigEndian" << std::endl;
            }
            if (int(data[0]) == 0x42)
            {
                std::cout << "LittleEndian" << std::endl;
            }
        }
        Header(){

        }
    };

    class ArrayNode
    {
    public:
        ArrayNode()
        {
        }
    };

    class DictionaryNode
    {
    public:
        DictionaryNode()
        {
        }
    };

    class StringTableNode
    {
    public:
        StringTableNode()
        {
        }
    };

    class PathTableNode
    {
    public:
        PathTableNode()
        {
        }
    };

    class BinaryReader
    {
    public:
        BinaryReader()
        {
        }
    };

    class BymlFile
    {
    public:
        BymlFormat::Header header;
        BinaryReader bin;
        BymlFormat::ArrayNode ArrayNode;
        BymlFormat::StringTableNode StringTableNode;
        BymlFormat::DictionaryNode DictionaryNode;
        uint16_t Version;

        BymlFile(std::byte data[])
        {
            header = BymlFormat::Header(data);
            Version = header.Version;
        }

        BymlFile()
        {
            header = BymlFormat::Header();
            ArrayNode = BymlFormat::ArrayNode();
            StringTableNode = BymlFormat::StringTableNode();
            DictionaryNode = BymlFormat::DictionaryNode();
        }
    };
} // namespace BymlFormat