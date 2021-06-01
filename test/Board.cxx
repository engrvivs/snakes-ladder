#include <catch2/catch.hpp>

#include "Board.hpp"

TEST_CASE(
    "GIVEN a board and a square WHEN no snake/ladder THEN no change in square",
    "[Board]") {
  Board board;
  REQUIRE(1 == board.landOn(1).target);
  REQUIRE(38 == board.landOn(38).target);
  REQUIRE(26 == board.landOn(26).target);
}

TEST_CASE("GIVEN a board WHEN on ladder THEN land on higher square",
          "[Board][Ladder]") {
  Board board;
  REQUIRE(38 == board.landOn(2).target);
}

TEST_CASE("GIVEN a board WHEN on snake THEN land on lower square",
          "[Board][Snake]") {
  Board board;
  REQUIRE(26 == board.landOn(47).target);
}

TEST_CASE("GIVEN a board WHEN on 100 THEN Win", "[Board][Win]") {
  Board board;
  REQUIRE(Action::Type::Win == board.landOn(100).type);
}
