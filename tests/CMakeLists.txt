project(tests)
add_executable(tests
    test_main.cpp
    test_vector.cpp
)
target_link_libraries(tests PRIVATE arrow)
