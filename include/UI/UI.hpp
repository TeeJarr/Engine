#pragma once
#include "Entities/Characters/Player.hpp"

#include <memory>
class UI {
  public:
  UI(const std::shared_ptr<Player> a_player);
  void draw();
  void update();

  private:
  std::shared_ptr<Player> player;
};
