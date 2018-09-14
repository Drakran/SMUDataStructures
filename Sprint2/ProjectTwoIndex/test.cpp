#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "DSvector.hpp"
#include <string>


using namespace std;

TEST_CASE("Testing dsvectrs", "[dsvectors]")
{
    SECTION("Int Tests")
    {
        DSvector<int> testInt(0);
        DSvector<int> testInt2(5);
    }

    SECTION("String tests")
    {
        DSvector<string> testString(0);
    }

    SECTION("at Tests")
    {
        DSvector<std::string> testAt(3);
        REQUIRE_THROWS_AS(testAt.at(4), logic_error);
    }

}
