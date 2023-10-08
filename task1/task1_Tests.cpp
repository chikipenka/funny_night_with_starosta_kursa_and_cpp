#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "task1_MainFile.cpp"

TEST_CASE()
{
    BigInteger a("1234");
    BigInteger a_("1234");
    BigInteger minus_a("-1234");
    BigInteger b("4321");
    BigInteger x1("5555");
    BigInteger x2("5332114");
    BigInteger x3("3087");

    REQUIRE(a + b == x1);    
    REQUIRE(a * b == x2);  
    REQUIRE((a < b) == true);  
    REQUIRE((b > a) == true); 
    REQUIRE((a == a_) == true); 
    REQUIRE((a <= a_) == true); 
    REQUIRE((a >= a_) == true); 
    REQUIRE((a > a_) == false); 
    REQUIRE((a < a_) == false); 
    REQUIRE((a != b) == true);  
    REQUIRE((a == -minus_a) == true);  
    REQUIRE(b - a == x3); 
    REQUIRE(a - b == -x3);     
}
