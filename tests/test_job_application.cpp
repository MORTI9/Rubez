#include <gtest/gtest.h>
#include "examples/JobApplication.cpp"

using namespace JobApplicationExample;


TEST(JobApplicationTest, InitialStateIsReceived) {
    JobApplication app;
    EXPECT_EQ(app.getState()->to_string(), "Received");
}


TEST(JobApplicationTest, Received_AllowedTransitions) {
    JobApplication app;
    EXPECT_EQ(app.getState()->to_string(), "Received");

   
    app.setState(std::make_shared<Incomplete>());
    EXPECT_EQ(app.getState()->to_string(), "Incomplete");


    JobApplication app2;
    app2.setState(std::make_shared<Interviewed>());
    EXPECT_EQ(app2.getState()->to_string(), "Interviewed");
}


TEST(JobApplicationTest, Interviewed_Transitions) {
    JobApplication app;
    app.setState(std::make_shared<Interviewed>());
    EXPECT_EQ(app.getState()->to_string(), "Interviewed");

    app.setState(std::make_shared<Refused>());
    EXPECT_EQ(app.getState()->to_string(), "Refused");

  
    app.setState(std::make_shared<Interviewed>());
    EXPECT_EQ(app.getState()->to_string(), "Refused"); 
}


TEST(JobApplicationTest, Invited_Transitions) {
    
    {
        JobApplication app;
        app.setState(std::make_shared<Interviewed>());
        app.setState(std::make_shared<Invited>());
        app.setState(std::make_shared<Talentpool>());
        EXPECT_EQ(app.getState()->to_string(), "Talentpool");
    }

    
    {
        JobApplication app;
        app.setState(std::make_shared<Interviewed>());
        app.setState(std::make_shared<Invited>());
        app.setState(std::make_shared<Hired>());
        EXPECT_EQ(app.getState()->to_string(), "Hired");
    }

    
    {
        JobApplication app;
        app.setState(std::make_shared<Interviewed>());
        app.setState(std::make_shared<Invited>());
        app.setState(std::make_shared<Refused>());
        EXPECT_EQ(app.getState()->to_string(), "Refused");
    }
}

TEST(JobApplicationTest, Refused_NoTransitionsAllowed) {
    JobApplication app;
    
    
    app.setState(std::make_shared<Interviewed>());
    app.setState(std::make_shared<Invited>());
    app.setState(std::make_shared<Refused>());
    EXPECT_EQ(app.getState()->to_string(), "Refused");

    
    auto prevState = app.getState(); 
    
    app.setState(std::make_shared<Invited>());
    EXPECT_EQ(app.getState()->to_string(), "Refused");
    EXPECT_EQ(app.getState().get(), prevState.get()); 

    app.setState(std::make_shared<Interviewed>());
    EXPECT_EQ(app.getState()->to_string(), "Refused");
    EXPECT_EQ(app.getState().get(), prevState.get());

    app.setState(std::make_shared<Talentpool>());
    EXPECT_EQ(app.getState()->to_string(), "Refused");
    EXPECT_EQ(app.getState().get(), prevState.get());

    app.setState(std::make_shared<Received>());
    EXPECT_EQ(app.getState()->to_string(), "Refused");
    EXPECT_EQ(app.getState().get(), prevState.get());
}
