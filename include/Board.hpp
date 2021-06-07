#pragma once
#include <cstdint>
#include <map>

struct Portal {
  enum class Type { Ladder, Snake };
  Type type;
  std::uint8_t target;
};

struct Action {
  enum class Type { Stay, Move, Win };
  Type type;
  std::uint8_t target;

  bool operator==(Action rhs) const {
    return std::tie(type, target) == std::tie(rhs.type, rhs.target);
  }
};

class Board {
private:
  static const int size = 100;
  static const std::map<std::uint8_t, Portal> portals;

public:
  Action landOn(uint8_t const square) const;
};
