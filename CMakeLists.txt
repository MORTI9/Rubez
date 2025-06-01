cmake_minimum_required(VERSION 3.10)
project(StatePattern)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fconcepts")


include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/src/state_pattern
    ${PROJECT_SOURCE_DIR}/FiniteStateMachine_LightSwitch
)


set(STATE_PATTERN_SRC
    src/state_pattern/Light.cpp
    src/state_pattern/LightState.cpp
    src/state_pattern/ConcreteLightStates.cpp
)

set(STATE_PATTERN_HDR
    src/state_pattern/Light.h
    src/state_pattern/LightState.h
    src/state_pattern/ConcreteLightStates.h
)


add_library(StatePatternLib STATIC ${STATE_PATTERN_SRC} ${STATE_PATTERN_HDR})


add_executable(StatePatternApp
    examples/Program.cpp
    FiniteStateMachine_LightSwitch/LightSwitchMain.cpp
    examples/ConceptualExample01.cpp
    examples/ConceptualExample02.cpp
    examples/ConceptualExample03.cpp
    examples/JobApplication.cpp
    examples/DepartmentStore.cpp
)

target_link_libraries(StatePatternApp PRIVATE StatePatternLib)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)

    add_executable(runTests
        tests/test_light.cpp
        tests/test_light_state.cpp
        tests/test_concrete_states.cpp
        tests/test_department_store.cpp
        tests/test_conceptual_example_01.cpp
        tests/test_conceptual_example_02.cpp
        tests/test_conceptual_example_03.cpp
        tests/test_job_application.cpp
    )

    target_link_libraries(runTests
        PRIVATE GTest::GTest GTest::Main StatePatternLib
    )

    add_test(NAME AllTests COMMAND runTests)
endif()


set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_NAME "StatePatternApp")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-Linux")
include(CPack)
