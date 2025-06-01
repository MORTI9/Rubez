#include <gtest/gtest.h>
#include "examples/ConceptualExample03.cpp"

TEST(ConceptualExample03Test, TransitionBetweenStates) {

    ConceptualExample03::clientCode();


    EXPECT_NO_THROW(ConceptualExample03::clientCode());
}
