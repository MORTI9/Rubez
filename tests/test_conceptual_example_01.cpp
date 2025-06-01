#include <gtest/gtest.h>
#include "examples/ConceptualExample01.cpp"

using namespace ConceptualExample01;

TEST(ConceptualExample01Test, InitialStateIsConcreteStateA) {
    StateBase* initialState = new ConcreteStateA();
    Context context(initialState);

   
    EXPECT_NO_THROW(context.request());
}

TEST(ConceptualExample01Test, ToggleBetweenStates) {
    StateBase* initialState = new ConcreteStateA();
    Context context(initialState);

    
    context.request(); 
    context.request(); 
    context.request(); 
    context.request(); 

    
}
