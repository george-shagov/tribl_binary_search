#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <lib.hpp>
#include <iostream>

constexpr int a_size = 1'000'000;
static std::vector<int> s_integers;
static std::vector<std::string> s_strings;

TEST_CASE( "Test 1", "[main]" )
{
    s_integers.resize(a_size);
    for (auto i=0; i<a_size; ++i)
        s_integers.push_back(i);
    s_strings.resize(a_size);
    for (auto i=a_size; i<a_size*2; ++i)
        s_strings.push_back(std::to_string(i));

    SECTION("Integers")
    {
        REQUIRE(*tribl::lower_bound(s_integers.begin(), s_integers.end(), 1000) == 1000);
        REQUIRE(*tribl::lower_bound(s_integers.begin(), s_integers.end(), 0) == 0);
        REQUIRE(*tribl::lower_bound(s_integers.begin(), s_integers.end(), 100) == 100);
        REQUIRE(*tribl::lower_bound(s_integers.begin(), s_integers.end(), 999) == 999);
        REQUIRE(*tribl::lower_bound(s_integers.begin(), s_integers.end(), -1) == s_integers[0]);
    }

    SECTION("Strings")
    {
        REQUIRE(*tribl::lower_bound(s_strings.begin(), s_strings.end(), std::string("1000000")) == "1000000");
        REQUIRE(*tribl::lower_bound(s_strings.begin(), s_strings.end(), std::string("1000000")) == "1000000");
        REQUIRE(*tribl::lower_bound(s_strings.begin(), s_strings.end(), std::string("1003000")) == "1003000");
        REQUIRE(*tribl::lower_bound(s_strings.begin(), s_strings.end(), std::string("1000001")) == "1000001");
    }

}

