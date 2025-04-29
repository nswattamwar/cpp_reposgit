// filepath: /home/asd/cpp_reposgit/googletest/build/rapidjson/example/filterkey/test_filterkey.cpp
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/reader.h"
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/writer.h"
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/stringbuffer.h"
#include "/home/asd/cpp_reposgit/googletest/build/rapidjson/include/rapidjson/error/en.h"
#include "gtest/gtest.h"
#include "filterkeydom.cpp" // Include the implementation file

#include <sstream>
#include <string>
#include <stdexcept>

using namespace rapidjson;
using namespace std;

// Helper function to process JSON using FilterKeyHandler
std::string ProcessJson(const std::string& inputJson, const std::string& filterKey) {
    StringStream inputStream(inputJson.c_str());
    StringBuffer outputBuffer;
    Writer<StringBuffer> writer(outputBuffer);
    FilterKeyHandler<Writer<StringBuffer>> filter(writer, filterKey.c_str(), static_cast<SizeType>(filterKey.length()));

    Reader reader;
    if (!reader.Parse(inputStream, filter)) {
        throw std::runtime_error("JSON parsing failed");
    }

    return outputBuffer.GetString();
}

// Test cases
TEST(FilterKeyHandlerTest, FiltersSingleKey) {
    std::string input = R"({"key1":"value1", "key2":"value2"})";
    std::string expected = R"({"key1":"value1"})";
    EXPECT_EQ(ProcessJson(input, "key2"), expected);
}

TEST(FilterKeyHandlerTest, HandlesNestedObjects) {
    std::string input = R"({"outer": {"inner": "value"}, "key":"value"})";
    std::string expected = R"({"outer":{"inner":"value"}})";
    EXPECT_EQ(ProcessJson(input, "key"), expected);
}

TEST(FilterKeyHandlerTest, HandlesArraysWithFilteredKey) {// check if the key is filtered
    std::string input = R"({"array": [{"key2":"value"}, {"key2":"value2"}], "key":"value2"})";
    std::string expected = R"({"array":[{"key2":"value"},{"key2":"value2"}]})";
    EXPECT_EQ(ProcessJson(input, "key"), expected);// check if the key is filtered
}

TEST(FilterKeyHandlerTest, HandlesEmptyJson) {
    std::string input = R"({})";
    std::string expected = R"({})";
    EXPECT_EQ(ProcessJson(input, "key"), expected);
}

TEST(FilterKeyHandlerTest, HandlesNoMatchingKey) {
    std::string input = R"({"key1":"value1", "key2":"value2"})";
    std::string expected = R"({"key1":"value1","key2":"value2"})";
    EXPECT_EQ(ProcessJson(input, "key3"), expected);
}

TEST(FilterKeyHandlerTest, HandlesComplexNestedStructure) {
    std::string input = R"({"level1": {"level2": {"key":"value", "key2":"value2"}}, "key":"value"})";
    std::string expected = R"({"level1":{"level2":{"key2":"value2"}}})";
    EXPECT_EQ(ProcessJson(input, "key"), expected);
}

TEST(FilterKeyHandlerTest, HandlesSpecialCharactersInKey) {
    std::string input = R"({"special-key":"value", "key":"value"})";
    std::string expected = R"({"key":"value"})";
    EXPECT_EQ(ProcessJson(input, "special-key"), expected);
}

TEST(FilterKeyHandlerTest, HandlesEmptyArray) {
    std::string input = R"({"emptyArray": []})";
    std::string expected = R"({"emptyArray":[]})";
    EXPECT_EQ(ProcessJson(input, "key"), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}