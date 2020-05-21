#pragma once
#include <cstddef>
#include <list>
#include <algorithm>
namespace BymlFormat
{

    class Header
    {
    public:
        uint32_t NodeNamesOffset;
        uint32_t StringResOffset;
        uint32_t RootOffset;
        bool BigEndian = false;
        uint16_t Version = 1;

        Header(std::byte data[])
        {
            if (int(data[0]) == 0x59)
                std::cout << "BigEndian" << std::endl;
        }
        Header()
        {
        }
    };

    class StringTable
    {
    public:
        uint32_t *StringOffsets;
        std::list<std::string> strings = std::list<std::string>();
        bool IsNull = false;

        std::string JapChars(std::byte input)
        {
            return "JP";
        }

        StringTable(uint32_t offset, std::byte data, bool BigEndian)
        {
        }

        StringTable()
        {
        }

        StringTable(bool _isNull)
        {
            IsNull = _isNull;
        }

        std::string ReadNullTerminatedString()
        {
        }

        std::byte CreateNullTerminatedString(std::string str)
        {
            std::list<std::byte> res = std::list<std::byte>();
        }
    };

    class GenericNode
    {
    public:
        std::string Name;
        std::string StringValue;
        std::byte NodeType;
        std::byte *Value;
        uint32_t StringIndex = 0xFFFFFFFF;
        std::list<GenericNode> SubNodes = std::list<GenericNode>();

        static std::byte *StringToByteArray(std::string hex)
        {
        }

        static int GetHexVal(char hex)
        {
            int val = (int)hex;
            return val - (val < 58 ? 48 : 58);
        }

        bool Equals(GenericNode obj)
        {
            if (obj.StringIndex != StringIndex)
                return false;
            if (obj.NodeType != NodeType)
                return false;
            if (NodeType == std::byte(0xC0) || NodeType == std::byte(0xC1))
            {
                if (SubNodes.size() != obj.SubNodes.size())
                    return false;

                for (auto itr = SubNodes.begin(); itr != SubNodes.end(); ++itr)
                {
                    for (auto oitr = obj.SubNodes.begin(); oitr != SubNodes.end(); ++oitr)
                    {
                        if (!(*itr).Equals(*oitr))
                            return false;
                    }
                }
            }
            else
            {
                if (!obj.Value.SequenceEqual(Value)) // CSharp code
                    return false;
            }
            return true;
        }
        GenericNode()
        {
        }

        GenericNode(std::string _Name, std::string _StringValue, std::byte _type)
        {
            Name = _Name;
            StringValue = _StringValue;
            switch (static_cast<unsigned int>(_type))
            {
            case 0xC0:
                NodeType = std::byte(0xC0);
                break;
            case 0xC1:
                NodeType = std::byte(0xC1);
                break;
            case 0xA0:
                NodeType = std::byte(0xA0);
                break;
            case 0xA1:
                NodeType = std::byte(0xA1);
                break;
            case 0xD1:
                NodeType = std::byte(0xD0);
                break;
            case 0xD2:
                NodeType = std::byte(0xD2);
                break;
            case 0xD0:
                NodeType = std::byte(0xD0);
                break;
            }
        }
    };

    class DictionaryNode : GenericNode
    {
    public:
        DictionaryNode()
        {
        }
    };

    class BymlFile
    {
    public:
        Header header;
        StringTable NodeNames;
        StringTable StringRes;
        DictionaryNode RootNode;
        // GenericNode RootNode; // Reference code
        bool BigEndian = false;
        uint16_t Version = 1;

        BymlFile(std::byte data[])
        {
            header = Header(data);
            BigEndian = header.BigEndian;
            Version = header.Version;
        }

        BymlFile()
        {
            header = Header();
            NodeNames = StringTable();
            StringRes = StringTable();
            RootNode = DictionaryNode();
        }
    };

}; // namespace BymlFormat