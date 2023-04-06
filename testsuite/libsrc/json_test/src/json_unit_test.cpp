#include <gtest/gtest.h>
#include <iostream>
#include "json_parser/json_parser.hpp"

class TestFoo : public ::testing::Test
{
protected:
    void SetUp() {}
    void TearDown() {}
};


//Проверка на простой словарь
TEST(TestUtils, simple_json_testing)
{
    testing::internal::CaptureStdout();
    std::string s = "{a:123}";
    json_parser(s);
    std::string output = testing::internal::GetCapturedStdout();
//    std::cout<<output<<std::endl;
    ASSERT_TRUE(output=="123 - INT\n");
}

//Проверка на сложный словарь
TEST(TestUtils, difficult_json_testing)
{
testing::internal::CaptureStdout();
std::string s = "{a:123, b:\"string_check\", c:{q:123, j:\"string_check2\"}}";
json_parser(s);
std::string output = testing::internal::GetCapturedStdout();
ASSERT_TRUE(output=="123 - INT\n"
"\"string_check\" - STRING\n"
"{q:123,j:\"string_check2\"} - DICT\n"
"123 - INT\n"
"\"string_check2\" - STRING\n");
}

//Проверка на список
TEST(TestUtils, array_testing)
{
testing::internal::CaptureStdout();
std::string s = "[123, \"456\", 1234, \"check_string\"]";
array_parser(s);
std::string output = testing::internal::GetCapturedStdout();
ASSERT_TRUE(output=="123 - INT\n"
"\"456\" - STRING\n"
"1234 - INT\n"
"\"check_string\" - STRING\n");
}





int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}