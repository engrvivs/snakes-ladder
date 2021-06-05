#include <catch2/catch.hpp>

#include "Board.hpp"

TEST_CASE(
    "GIVEN a board and a square WHEN no snake/ladder THEN no change in square",
    "[Board]") {
  Board board;
  REQUIRE(board.landOn(1) == Action{Action::Type::Stay, 1});
  REQUIRE(board.landOn(38) == Action{Action::Type::Stay, 38});
  REQUIRE(board.landOn(26) == Action{Action::Type::Stay, 26});
}

TEST_CASE("GIVEN a board WHEN on ladder THEN land on higher square",
          "[Board][Ladder]") {
  Board board;
  REQUIRE(board.landOn(2) == Action{Action::Type::Move, 38});
}

TEST_CASE("GIVEN a board WHEN on snake THEN land on lower square",
          "[Board][Snake]") {
  Board board;
  REQUIRE(board.landOn(47) == Action{Action::Type::Move, 26});
}

TEST_CASE("GIVEN a board WHEN on 100 THEN Win", "[Board][Win]") {
  Board board;
  REQUIRE(board.landOn(100) == Action{Action::Type::Win, 100});
}
