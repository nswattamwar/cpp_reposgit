// JSON filterkey example with SAX-style API.

// This example parses JSON text from stdin with validation.
// During parsing, specified key will be filtered using a SAX handler.
// It re-output the JSON content to stdout without whitespace.

#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/reader.h"
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/writer.h"
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/filereadstream.h"
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/filewritestream.h"
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/error/en.h"
#include <stack>

using namespace rapidjson;

// This handler forwards event into an output handler, with filtering the descendent events of specified key.
template <typename OutputHandler>
class FilterKeyHandler {
public:
    typedef char Ch;

    FilterKeyHandler(OutputHandler& outputHandler, const Ch* keyString, SizeType keyLength) : 
        outputHandler_(outputHandler), keyString_(keyString), keyLength_(keyLength), filterValueDepth_(), filteredKeyCount_()
    {}

    bool Null()             { return filterValueDepth_ > 0 ? EndValue() : outputHandler_.Null()    && EndValue(); }
    bool Bool(bool b)       { return filterValueDepth_ > 0 ? EndValue() : outputHandler_.Bool(b)   && EndValue(); }
    bool Int(int i)         { return filterValueDepth_ > 0 ? EndValue() : outputHandler_.Int(i)    && EndValue(); }
    bool Uint(unsigned u)   { return filterValueDepth_ > 0 ? EndValue() : outputHandler_.Uint(u)   && EndValue(); }
    bool Int64(int64_t i)   { return filterValueDepth_ > 0 ? EndValue() : outputHandler_.Int64(i)  && EndValue(); }
    bool Uint64(uint64_t u) { return filterValueDepth_ > 0 ? EndValue() : outputHandler_.Uint64(u) && EndValue(); }
    bool Double(double d)   { return filterValueDepth_ > 0 ? EndValue() : outputHandler_.Double(d) && EndValue(); }
    bool RawNumber(const Ch* str, SizeType len, bool copy) { return filterValueDepth_ > 0 ? EndValue() : outputHandler_.RawNumber(str, len, copy) && EndValue(); }
    bool String   (const Ch* str, SizeType len, bool copy) { return filterValueDepth_ > 0 ? EndValue() : outputHandler_.String   (str, len, copy) && EndValue(); }
    
    bool StartObject() { 
        if (filterValueDepth_ > 0) {    // if we are in the filtered value
            filterValueDepth_++;// increase the depth
            return true;// forward the event
        }
        else {
            filteredKeyCount_.push(0);// push the filtered key count
            return outputHandler_.StartObject();// forward the event
        }
    }
    
    bool Key(const Ch* str, SizeType len, bool copy) {// check if the key is filtered 
        if (filterValueDepth_ > 0) 
            return true;
        else if (len == keyLength_ && std::memcmp(str, keyString_, len) == 0) {// check if the key is filtered
            filterValueDepth_ = 1;// set the depth to 1
            return true;// forward the event
        }
        else {
            ++filteredKeyCount_.top();// increase the filtered key count
            // Check if the key is filtered
            return outputHandler_.Key(str, len, copy);// forward the key
        }
    }

    bool EndObject(SizeType) {// check if we are in the filtered value
        if (filterValueDepth_ > 0) {
            filterValueDepth_--;
            return EndValue();
        }
        else {
            // Use our own filtered memberCount
            SizeType memberCount = filteredKeyCount_.top();
            filteredKeyCount_.pop();
            return outputHandler_.EndObject(memberCount) && EndValue();
        }
    }

    bool StartArray() {// check if we are in the filtered value
        if (filterValueDepth_ > 0) {
            filterValueDepth_++;
            return true;
        }
        else
            return outputHandler_.StartArray();
    }

    bool EndArray(SizeType elementCount) {// check if we are in the filtered value
        if (filterValueDepth_ > 0) {
            filterValueDepth_--;
            return EndValue();
        }
        else
            return outputHandler_.EndArray(elementCount) && EndValue();
    }

private:
    FilterKeyHandler(const FilterKeyHandler&);// // prevent copy
    FilterKeyHandler& operator=(const FilterKeyHandler&);

    bool EndValue() {// check if we are in the filtered value
        if (filterValueDepth_ == 1) // Just at the end of value after filtered key
            filterValueDepth_ = 0;
        return true;
    }
    
    OutputHandler& outputHandler_;// // output handler
    const char* keyString_;
    const SizeType keyLength_;
    unsigned filterValueDepth_;
    std::stack<SizeType> filteredKeyCount_;
};

// int main(int argc, char* argv[]) {
//     if (argc != 2) {
//         fprintf(stderr, "filterkey key < input.json > output.json\n");
//         return 1;
//     }

//     // Prepare JSON reader and input stream.
//     Reader reader;
//     char readBuffer[65536];
//     FileReadStream is(stdin, readBuffer, sizeof(readBuffer));

//     // Prepare JSON writer and output stream.
//     char writeBuffer[65536];
//     FileWriteStream os(stdout, writeBuffer, sizeof(writeBuffer));
//     Writer<FileWriteStream> writer(os);

//     // Prepare Filter
//     FilterKeyHandler<Writer<FileWriteStream> > filter(writer, argv[1], static_cast<SizeType>(strlen(argv[1])));

//     // JSON reader parse from the input stream, filter handler filters the events, and forward to writer.
//     // i.e. the events flow is: reader -> filter -> writer
//     if (!reader.Parse(is, filter)) {
//         fprintf(stderr, "\nError(%u): %s\n", static_cast<unsigned>(reader.GetErrorOffset()), GetParseError_En(reader.GetParseErrorCode()));
//         return 1;
//     }

//     return 0;
// }
