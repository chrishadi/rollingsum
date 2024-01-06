#include <catch2/catch_test_macros.hpp>
#include "rollingsum.h"

TEST_CASE( "One element is easy to test" ) {
    rollingsum r1 = rollingsum(1);
    REQUIRE( r1.size() == 0 );
    REQUIRE( r1.sum() == 0 );

    r1.add(2);
    REQUIRE( r1.size() == 1 );
    REQUIRE( r1.sum() == 2 );

    r1.add(5);
    REQUIRE( r1.size() == 1 );
    REQUIRE( r1.sum() == 5 );
}

TEST_CASE( "Three elements should have the latest sum" ) {
    rollingsum r3 = rollingsum(3);
    r3.add(2);
    REQUIRE( r3.size() == 1 );
    REQUIRE( r3.sum() == 2 );

    r3.add(5);
    REQUIRE( r3.size() == 2 );
    REQUIRE( r3.sum() == 7 );

    r3.add(10);
    REQUIRE( r3.size() == 3 );
    REQUIRE( r3.sum() == 17 );

    r3.add(4);
    REQUIRE( r3.size() == 3 );
    REQUIRE( r3.sum() == 19 );

    r3.add(9);
    REQUIRE( r3.size() == 3 );
    REQUIRE( r3.sum() == 23 );

    r3.add(8);
    REQUIRE( r3.size() == 3 );
    REQUIRE( r3.sum() == 21 );

    r3.add(203);
    REQUIRE( r3.size() == 3 );
    REQUIRE( r3.sum() == 220 );
}
