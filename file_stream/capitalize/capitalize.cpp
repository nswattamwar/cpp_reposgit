// JSON condenser example

// This example parses JSON from stdin with validation, 
// and re-output the JSON content to stdout with all string capitalized, and without whitespace.

#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/reader.h"
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/writer.h"
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/filereadstream.h"
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/filewritestream.h"
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/error/en.h"
#include <vector>
#include <cctype>
#include <gtest/gtest.h>
#include <sstream>
#include <string>

using namespace rapidjson;
using namespace std;

template<typename OutputHandler>
struct CapitalizeFilter {
    CapitalizeFilter(OutputHandler& out) : out_(out), buffer_() {}

    bool Null() { return out_.Null(); }
    bool Bool(bool b) { return out_.Bool(b); }
    bool Int(int i) { return out_.Int(i); }
    bool Uint(unsigned u) { return out_.Uint(u); }
    bool Int64(int64_t i) { return out_.Int64(i); }
    bool Uint64(uint64_t u) { return out_.Uint64(u); }
    bool Double(double d) { return out_.Double(d); }
    bool RawNumber(const char* str, SizeType length, bool copy) { return out_.RawNumber(str, length, copy); }
    bool String(const char* str, SizeType length, bool) {
        buffer_.clear();// clear the buffer
        for (SizeType i = 0; i < length; i++)//
            buffer_.push_back(static_cast<char>(std::toupper(str[i])));// convert to uppercase
        return out_.String(&buffer_.front(), length, true); // true = output handler need to copy the string
    }
    bool StartObject() { return out_.StartObject(); }
    bool Key(const char* str, SizeType length, bool copy) { return String(str, length, copy); }
    bool EndObject(SizeType memberCount) { return out_.EndObject(memberCount); }
    bool StartArray() { return out_.StartArray(); }
    bool EndArray(SizeType elementCount) { return out_.EndArray(elementCount); }

    OutputHandler& out_;
    std::vector<char> buffer_;
private:
    CapitalizeFilter(const CapitalizeFilter&);// // prevent copy 
    CapitalizeFilter& operator=(const CapitalizeFilter&);// // prevent copy
};

// int main(int, char*[]) {
//     // Prepare JSON reader and input stream.
//     Reader reader;
//     char readBuffer[65536];
//     FileReadStream is(stdin, readBuffer, sizeof(readBuffer));

//     // Prepare JSON writer and output stream.
//     char writeBuffer[65536];
//     FileWriteStream os(stdout, writeBuffer, sizeof(writeBuffer));
//     Writer<FileWriteStream> writer(os);

//     // JSON reader parse from the input stream and let writer generate the output.
//     CapitalizeFilter<Writer<FileWriteStream> > filter(writer);
//     if (!reader.Parse(is, filter)) {
//         fprintf(stderr, "\nError(%u): %s\n", static_cast<unsigned>(reader.GetErrorOffset()), GetParseError_En(reader.GetParseErrorCode()));
//         return 1;
//     }

//     return 0;
// }


