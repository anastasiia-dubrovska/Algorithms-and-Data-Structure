
#include "MyString.h"
/*#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "x64/Debug/Алгоритм Маркова.tlog/doctest.h"



TEST_CASE("Test apply_rules() method") {
    MyString input_str, output_str;

    SUBCASE("Test empty string") {
        input_str = "";
        output_str = input_str.apply_rules();
        CHECK(string(output_str.get()) == "");
    }

    SUBCASE("Test string with no matches") {
        input_str = "xyz";
        output_str = input_str.apply_rules();
        CHECK(string(output_str.get()) == "xyz");
    }

    SUBCASE("Test string with single match at beginning") {
        input_str = "ab";
        output_str = input_str.apply_rules();
        CHECK(string(output_str.get()) == "bc");
    }

    SUBCASE("Test string with single match at end") {
        input_str = "cd";
        output_str = input_str.apply_rules();
        CHECK(string(output_str.get()) == "de");
    }

    SUBCASE("Test string with single match in middle") {
        input_str = "efg";
        output_str = input_str.apply_rules();
        CHECK(string(output_str.get()) == "ffg");
    }

    SUBCASE("Test string with multiple matches") {
        input_str = "ababcdefgab";
        output_str = input_str.apply_rules();
        CHECK(string(output_str.get()) == "bcbcdeffgbc");
    }

    SUBCASE("Test string with all possible matches") {
        input_str = "abcde";
        output_str = input_str.apply_rules();
        CHECK(string(output_str.get()) == "bcdef");
        output_str = output_str.apply_rules();
        CHECK(string(output_str.get()) == "cdeff");
        output_str = output_str.apply_rules();
        CHECK(string(output_str.get()) == "defff");
        output_str = output_str.apply_rules();
        CHECK(string(output_str.get()) == "effff");
        output_str = output_str.apply_rules();
        CHECK(string(output_str.get()) == "fffff");
    }
}*/

int main()
{
    MyString input_str, output_str;

    cout << "Enter string: ";
    char input[MAX_LEN];
    cin.getline(input, MAX_LEN);

    input_str.set(input);

    // перетворення рядка згідно з правилами
    output_str = input_str.apply_rules();

    cout << "Result: " << output_str.get() << endl;

    return 0;
}


