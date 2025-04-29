// filepath: /home/asd/cpp_reposgit/googletest/build/rapidjson/example/pretty/test_pretty.cpp

#include"pretty.cpp"
#include "gtest/gtest.h"
#include <sstream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <cstdio>
#include <cstdlib>

// Helper function to execute the pretty.cpp program and capture its output
std::string RunPrettyFormatter(const std::string& inputJson) {
    // Write input JSON to a temporary file
    const char* inputFileName = "temp_input.json";
    const char* outputFileName = "temp_output.json";
    std::ofstream inputFile(inputFileName);
    inputFile << inputJson;
    inputFile.close();

    // Run the pretty.cpp program
    std::string command = "./pretty < " + std::string(inputFileName) + " > " + std::string(outputFileName) + " 2>/dev/null";
    int result = std::system(command.c_str());
    if (result != 0) {
        throw std::runtime_error("Failed to execute pretty formatter");
    }

    // Read the output JSON from the temporary file
    std::ifstream outputFile(outputFileName);
    std::stringstream outputBuffer;
    outputBuffer << outputFile.rdbuf();
    outputFile.close();

    // Clean up temporary files
    std::remove(inputFileName);
    std::remove(outputFileName);

    return outputBuffer.str();
}

// Test cases
TEST(PrettyFormatterTest, FormatsValidJson) {
    std::string input = R"({"key":"value","array":[1,2,3]})";
    std::string expected = R"({
    "key": "value",
    "array": [
        1,
        2,
        3
    ]
}
)";
    EXPECT_EQ(RunPrettyFormatter(input), expected);
}

TEST(PrettyFormatterTest, HandlesEmptyJson) {
    std::string input = R"({})";
    std::string expected = R"({
}
)";
    EXPECT_EQ(RunPrettyFormatter(input), expected);
}

TEST(PrettyFormatterTest, HandlesNestedJson) {
    std::string input = R"({"outer":{"inner":{"key":"value"}}})";
    std::string expected = R"({
    "outer": {
        "inner": {
            "key": "value"
        }
    }
}
)";
    EXPECT_EQ(RunPrettyFormatter(input), expected);
}

TEST(PrettyFormatterTest, HandlesJsonArray) {
    std::string input = R"([{"key1":"value1"},{"key2":"value2"}])";
    std::string expected = R"([
    {
        "key1": "value1"
    },
    {
        "key2": "value2"
    }
]
)";
    EXPECT_EQ(RunPrettyFormatter(input), expected);
}

TEST(PrettyFormatterTest, HandlesInvalidJson) {
    std::string input = R"({"key": "value",)";
    EXPECT_THROW(RunPrettyFormatter(input), std::runtime_error);
}

TEST(PrettyFormatterTest, HandlesLargeJson) {
    std::string input = R"({"key1":"value1","key2":"value2","key3":{"nestedKey":"nestedValue"},"array":[1,2,3,4,5]})";
    std::string expected = R"({
    "key1": "value1",
    "key2": "value2",
    "key3": {
        "nestedKey": "nestedValue"
    },
    "array": [
        1,
        2,
        3,
        4,
        5
    ]
}
)";
    EXPECT_EQ(RunPrettyFormatter(input), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}