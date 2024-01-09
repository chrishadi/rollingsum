#include <catch2/catch_test_macros.hpp>
#include "rollingsum.h"

TEST_CASE( "One element is easy to test" ) {
    rollingsum r1 = rollingsum(1);
    REQUIRE( r1.size() == 0 );
    REQUIRE( r1.sum() == 0 );

    REQUIRE( r1.add(2) == 2 );
    REQUIRE( r1.size() == 1 );
    REQUIRE( r1.sum() == 2 );

    REQUIRE( r1.add(5) == 5 );
    REQUIRE( r1.size() == 1 );
    REQUIRE( r1.sum() == 5 );
}

TEST_CASE( "Three elements should have the latest sum" ) {
    rollingsum r3 = rollingsum(3);
    REQUIRE( (r3 << 2) == 2 );
    REQUIRE( r3.size() == 1 );
    REQUIRE( r3.sum() == 2 );

    REQUIRE( (r3 << 5) == 7);
    REQUIRE( r3.size() == 2 );
    REQUIRE( r3.sum() == 7 );

    REQUIRE( (r3 << 10) == 17);
    REQUIRE( r3.size() == 3 );
    REQUIRE( r3.sum() == 17 );

    REQUIRE( (r3 << 4) == 19 );
    REQUIRE( r3.size() == 3 );
    REQUIRE( r3.sum() == 19 );

    REQUIRE( (r3 << 9) == 23 );
    REQUIRE( r3.size() == 3 );
    REQUIRE( r3.sum() == 23 );

    REQUIRE( (r3 << 8) == 21 );
    REQUIRE( r3.size() == 3 );
    REQUIRE( r3.sum() == 21 );

    REQUIRE( (r3 << 203) == 220 );
    REQUIRE( r3.size() == 3 );
    REQUIRE( r3.sum() == 220 );
}
