#include "Board.hpp"

Action Board::landOn(uint8_t const square) const {
  auto finalSquare = [=] {
    auto it = portals.find(square);
    if (it != portals.end()) {
      return it->second.target;
    }
    return square;
  }();

  Action::Type type = Action::Type::Stay;
  if (finalSquare == size) {
    type = Action::Type::Win;
  } else if (finalSquare != square) {
    type = Action::Type::Move;
  }

  return {type, finalSquare};
}

const std::map<std::uint8_t, Portal> Board::portals = {
    {2, {Portal::Type::Ladder, 38}},  {4, {Portal::Type::Ladder, 14}},
    {8, {Portal::Type::Ladder, 31}},  {21, {Portal::Type::Ladder, 42}},
    {28, {Portal::Type::Ladder, 84}}, {36, {Portal::Type::Ladder, 44}},
    {47, {Portal::Type::Snake, 26}},  {49, {Portal::Type::Snake, 11}},
    {51, {Portal::Type::Ladder, 67}}, {56, {Portal::Type::Snake, 53}},
    {62, {Portal::Type::Snake, 18}},  {64, {Portal::Type::Snake, 60}},
    {71, {Portal::Type::Ladder, 91}}, {80, {Portal::Type::Ladder, 100}},
    {87, {Portal::Type::Snake, 24}},  {93, {Portal::Type::Snake, 73}},
    {95, {Portal::Type::Snake, 75}},  {98, {Portal::Type::Ladder, 78}}};
