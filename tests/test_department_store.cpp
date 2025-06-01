#include <gtest/gtest.h>
#include "examples/DepartmentStore.cpp"

using namespace DepartmentStoreExample;

TEST(DepartmentStoreTest, InitialState_Is_OutOfStock) {
    DepartmentStoreStateMachine fsm;
    EXPECT_NO_THROW(fsm.reportCurrentState());
}

TEST(DepartmentStoreTest, DeliveryArrived_AddsItems) {
    DepartmentStoreStateMachine fsm;
    fsm.processEvent(Events::DeliveryArrived{5});
    EXPECT_EQ(fsm.reportCurrentState(), "5 items available");
}

TEST(DepartmentStoreTest, Purchase_ReduceItems) {
    DepartmentStoreStateMachine fsm;
    fsm.processEvent(Events::DeliveryArrived{5});
    fsm.processEvent(Events::Purchased{2});
    EXPECT_EQ(fsm.reportCurrentState(), "3 items available");
}

TEST(DepartmentStoreTest, Discontinued_MarksAsNoLongerProduced) {
    DepartmentStoreStateMachine fsm;
    fsm.processEvent(Events::Discontinued{});
    EXPECT_EQ(fsm.reportCurrentState(), "Item is no more produced");
}
