# CMake generated Testfile for 
# Source directory: C:/Users/gavin/Fall253514/A6.7/A6_7/assignments/a6_vector_1
# Build directory: C:/Users/gavin/Fall253514/A6.7/A6_7/assignments/a6_vector_1/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(my_test "C:/Users/gavin/Fall253514/A6.7/A6_7/assignments/a6_vector_1/build/Debug/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/gavin/Fall253514/A6.7/A6_7/assignments/a6_vector_1/CMakeLists.txt;20;add_test;C:/Users/gavin/Fall253514/A6.7/A6_7/assignments/a6_vector_1/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(my_test "C:/Users/gavin/Fall253514/A6.7/A6_7/assignments/a6_vector_1/build/Release/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/gavin/Fall253514/A6.7/A6_7/assignments/a6_vector_1/CMakeLists.txt;20;add_test;C:/Users/gavin/Fall253514/A6.7/A6_7/assignments/a6_vector_1/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(my_test "C:/Users/gavin/Fall253514/A6.7/A6_7/assignments/a6_vector_1/build/MinSizeRel/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/gavin/Fall253514/A6.7/A6_7/assignments/a6_vector_1/CMakeLists.txt;20;add_test;C:/Users/gavin/Fall253514/A6.7/A6_7/assignments/a6_vector_1/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(my_test "C:/Users/gavin/Fall253514/A6.7/A6_7/assignments/a6_vector_1/build/RelWithDebInfo/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/gavin/Fall253514/A6.7/A6_7/assignments/a6_vector_1/CMakeLists.txt;20;add_test;C:/Users/gavin/Fall253514/A6.7/A6_7/assignments/a6_vector_1/CMakeLists.txt;0;")
else()
  add_test(my_test NOT_AVAILABLE)
endif()
