
#include <gtest/gtest.h>
#include "examples/ConceptualExample02.cpp"

using namespace ConceptualExample02;

TEST(ConceptualExample02Test, SharedPtrBasedStateMachine_ToggleStates) {
    auto initialState = std::make_shared<ConcreteStateA>();
    auto context = std::make_shared<Context>(initialState);

    context->request(); // A -> B
    context->request(); // B -> A
    context->request(); // A -> B
    context->request(); // B -> A

    
    EXPECT_NO_THROW(context->request());
}
