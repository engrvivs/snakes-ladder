#include <iostream>
using std::cin;
using std::cout;
#include "Board.hpp"

int main(int, char **) {
  std::uint8_t box = 0;
  cout << "Enter box #: ";
  cin >> box;

  Board board;
  Action act = board.landOn(box);
  cout << static_cast<std::int16_t>(act.target) << "\n" << std::endl;

  return 0;
}
