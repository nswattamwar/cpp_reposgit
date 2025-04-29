// filepath: /home/asd/cpp_reposgit/googletest/build/rapidjson/example/capitalize/test_capitalize.cpp
//#include "cap.h"
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/reader.h"
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/writer.h"
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/stringbuffer.h"
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/error/en.h"
#include "gtest/gtest.h"
#include "capitalize.cpp" // Include the implementation file
 // Include the header file

#include <sstream>
#include <string>
#include <stdexcept>

using namespace rapidjson;
using namespace std;


// Helper function to process JSON using CapitalizeFilter
std::string ProcessJson(const std::string& inputJson) {//
    StringStream inputStream(inputJson.c_str());//
    StringBuffer outputBuffer;//
    Writer<StringBuffer> writer(outputBuffer);// 
    CapitalizeFilter<Writer<StringBuffer>> filter(writer);

    Reader reader;
    if (!reader.Parse(inputStream, filter)) {
        throw std::runtime_error("JSON parsing failed");
    }

    return outputBuffer.GetString();
}

// Test cases
TEST(CapitalizeFilterTest, CapitalizesSimpleString) {
    std::string input = R"({"key":"value"})";
    std::string expected = R"({"KEY":"VALUE"})";
    EXPECT_EQ(ProcessJson(input), expected);
}

TEST(CapitalizeFilterTest, HandlesNestedObjects) {
    std::string input = R"({"outer": {"inner": "text"}})";
    std::string expected = R"({"OUTER":{"INNER":"TEXT"}})";
    EXPECT_EQ(ProcessJson(input), expected);
}

TEST(CapitalizeFilterTest, HandlesArrays) {
    std::string input = R"({"array": ["one", "two", "three"]})";
    std::string expected = R"({"ARRAY":["ONE","TWO","THREE"]})";
    EXPECT_EQ(ProcessJson(input), expected);
}

TEST(CapitalizeFilterTest, HandlesMixedTypes) {
    std::string input = R"({"string": "text", "number": 123, "bool": true})";
    std::string expected = R"({"STRING":"TEXT","NUMBER":123,"BOOL":true})";
    EXPECT_EQ(ProcessJson(input), expected);
}

TEST(CapitalizeFilterTest, HandlesEmptyObject) {
    std::string input = R"({})";
    std::string expected = R"({})";
    EXPECT_EQ(ProcessJson(input), expected);
}

TEST(CapitalizeFilterTest, HandlesEmptyArray) {
    std::string input = R"({"emptyArray": []})";
    std::string expected = R"({"EMPTYARRAY":[]})";
    EXPECT_EQ(ProcessJson(input), expected);
}

TEST(CapitalizeFilterTest, HandlesSpecialCharacters) {
    std::string input = R"({"special": "hello-world_123"})";
    std::string expected = R"({"SPECIAL":"HELLO-WORLD_123"})";
    EXPECT_EQ(ProcessJson(input), expected);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}