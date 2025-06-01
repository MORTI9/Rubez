// ===========================================================================
// JobApplication.cpp
// ===========================================================================

#include <iostream>
#include <memory>

namespace JobApplicationExample {

    class State
    {
    public:
        virtual ~State() {}

        virtual void inform() = 0;             // inform applicant
        virtual void process() = 0;            // process job application
        virtual std::string to_string() = 0;   // print current state
    };

    // Конкретные реализации состояний (упрощённые)

    class Refused : public State
    {
    public:
        void inform() override {}
        void process() override {}
        std::string to_string() override { return "Refused"; }
    };

    class Received : public State
    {
    public:
        void inform() override {}
        void process() override {}
        std::string to_string() override { return "Received"; }
    };

    class Invited : public State
    {
    public:
        void inform() override {}
        void process() override {}
        std::string to_string() override { return "Invited"; }
    };

    class Hired : public State
    {
    public:
        void inform() override {}
        void process() override {}
        std::string to_string() override { return "Hired"; }
    };

    class Interviewed : public State
    {
    public:
        void inform() override {}
        void process() override {}
        std::string to_string() override { return "Interviewed"; }
    };

    class Talentpool : public State
    {
    public:
        void inform() override {}
        void process() override {}
        std::string to_string() override { return "Talentpool"; }
    };

    class Incomplete : public State
    {
    public:
        void inform() override {}
        void process() override {}
        std::string to_string() override { return "Incomplete"; }
    };

    // =======================================================================

    class JobApplication
    {
    private:
        std::shared_ptr<State> m_state;

    public:
        JobApplication()
        {
            m_state = std::make_shared<Received>();
        }

        std::shared_ptr<State> getState()
        {
            return m_state;
        }

        void setState(std::shared_ptr<State> nextState)
        {
            if (nextState.get() == m_state.get()) return;

            if (!isStateAccepted(nextState)) {
                std::cout << "State " << nextState->to_string() << " not allowed here!" << std::endl;
                return;
            }

            m_state = nextState;
        }

        void inform()
        {
            m_state->inform();
        }

        void process()
        {
            m_state->process();
        }

        void print()
        {
            std::cout << m_state->to_string() << std::endl;
        }

    private:
        bool isStateAccepted(std::shared_ptr<State> nextState)
        {
            if (dynamic_cast<Received*>(m_state.get())) {
                return dynamic_cast<Incomplete*>(nextState.get()) || dynamic_cast<Interviewed*>(nextState.get());
            }

            if (dynamic_cast<Incomplete*>(m_state.get())) {
                return dynamic_cast<Refused*>(nextState.get()) || dynamic_cast<Received*>(nextState.get());
            }

            if (dynamic_cast<Interviewed*>(m_state.get())) {
                return dynamic_cast<Refused*>(nextState.get()) || dynamic_cast<Invited*>(nextState.get());
            }

            if (dynamic_cast<Refused*>(m_state.get())) {
                return false;
            }

            if (dynamic_cast<Invited*>(m_state.get())) {
                return dynamic_cast<Talentpool*>(nextState.get()) || dynamic_cast<Hired*>(nextState.get()) || dynamic_cast<Refused*>(nextState.get());
            }

            if (dynamic_cast<Talentpool*>(m_state.get())) {
                return false;
            }

            if (dynamic_cast<Hired*>(m_state.get())) {
                return false;
            }

            return false;
        }
    };

    static void clientCode()
    {
        JobApplication b;
        b.print();

        b.setState(std::make_shared<Hired>());         // не разрешено
        b.setState(std::make_shared<Interviewed>());  // разрешено
        b.print();
        b.inform();
        b.process();

        b.setState(std::make_shared<Talentpool>());   // не разрешено
        b.setState(std::make_shared<Invited>());      // разрешено
        b.print();

        b.setState(std::make_shared<Received>());     // не разрешено
        b.setState(std::make_shared<Hired>());        // разрешено
        b.print();
    }
}

void test_jobapplication_example() {
    JobApplicationExample::clientCode();
}
