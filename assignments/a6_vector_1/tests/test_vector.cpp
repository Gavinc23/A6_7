// test_vector.cpp
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "vector.hpp"
#include <stdexcept>

TEST_CASE("Default constructor creates empty vector") {
    dsa::Vector<int> v;
    bool ok{true};
    REQUIRE(ok);
}


TEST_CASE("basic functions") { //capacity, size, empty, operator, front, back, (const and noraml), AND push_back
   dsa::Vector<int> v; //normal, not const

   REQUIRE(v.capacity() == 0);
   REQUIRE(v.size() == 0);
   REQUIRE(v.empty() == true);
   
   v.push_back(1);
   v.push_back(2);
   v.push_back(3);

   REQUIRE(v.size() == 3);
   REQUIRE(v.empty() == false);

   REQUIRE(v[0] == 1);
   REQUIRE(v.at(1) == 2);

   REQUIRE(v.front() == 1);
   REQUIRE(v.back() == 3);

   const dsa::Vector<int> const_v = v;

   REQUIRE(const_v.front() == 1);
   REQUIRE(const_v.back() == 3);
   REQUIRE(const_v.at(2) == 3);
   REQUIRE(const_v[2] == 3);
   REQUIRE_THROWS_AS(const_v.at(5), std::out_of_range);

}


TEST_CASE("insert add elem, shifts") {
    dsa::Vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.insert(1,2);
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);

}

TEST_CASE("erase erases") {
    dsa::Vector<int> v;
   
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    v.erase(1);

    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 3);

}

TEST_CASE("pop_back removes last data") {
    dsa::Vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.pop_back();
    REQUIRE(v.size() == 2);
    REQUIRE(v.back() == 2);
}

TEST_CASE("reserve reserves") {
    dsa::Vector<int> v;
   
    v.reserve(5);
    REQUIRE(v.capacity() == 5);
    REQUIRE(v.size() == 0);
    v.push_back(1);
    REQUIRE(v[0] == 1);
}