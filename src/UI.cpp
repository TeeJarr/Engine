#include "UI/UI.hpp"
#include <memory>

UI::UI(const std::shared_ptr<Player> a_player) {
  std::println("loading ui");
  auto temp = a_player;
  player = temp;
}

void UI::draw() {}
void UI::update() {}
