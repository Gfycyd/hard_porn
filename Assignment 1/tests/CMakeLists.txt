enable_testing()

find_package(Check REQUIRED)
find_package(Threads REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS})

include_directories(. ../src)

add_executable(test_binarize assignment0_1/test_binarize.c ../src/assignment0_1/binarize.c ../src/assignment2/stack.c ../src/assignment2/stack.h)
add_executable(test_task assignment0_1/test_task.c ../src/assignment0_1/task.c)
add_executable(test_stack assignment2/test_stack.c ../src/assignment2/stack.c)
add_executable(test_queue assignment2/test_queue.c ../src/assignment2/priority_queue.c)
add_executable(test_bitMap assignment3/test_bitMap.c ../src/assignment3/bitMap.c)
add_executable(tester assignment3/tester.c ../src/assignment3/bitMap.c)
add_executable(test_vector assignment4/test_vector.c ../src/assignment4/vector.c)
add_executable(test_vector_int assignment4/test_vector_int.c ../src/assignment4/vector_int.c)
add_executable(test_vector_qsort assignment4/test_vector_qsort.c ../src/assignment4/vector_int.c)



target_link_libraries(test_binarize ${CHECK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(test_task ${CHECK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(test_queue ${CHECK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(test_stack ${CHECK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(test_bitMap ${CHECK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(tester ${CHECK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(test_vector ${CHECK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(test_vector_int ${CHECK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(test_vector_qsort ${CHECK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})


add_test(test_binarize ${CMAKE_CURRENT_BINARY_DIR}/test_binarize)
add_test(test_queue ${CMAKE_CURRENT_BINARY_DIR}/test_queue)
add_test(test_stack ${CMAKE_CURRENT_BINARY_DIR}/test_stack)
add_test(test_bitMap ${CMAKE_CURRENT_BINARY_DIR}/test_bitMap)
add_test(test_vector ${CMAKE_CURRENT_BINARY_DIR}/test_vector)
add_test(test_vector_int ${CMAKE_CURRENT_BINARY_DIR}/test_vector_int)
add_test(test_vector_qsort ${CMAKE_CURRENT_BINARY_DIR}/test_vector_qsort)