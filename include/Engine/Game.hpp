#include "Entities/Player.hpp"
#include "Opts.hpp"
#include "UI/Menu.hpp"
#include "UI/UI.hpp"
#include <cstddef>
#include <memory>
#include <raylib.h>

class Game {
  public:
  Game();

  private:
  // init methods
  bool load_opts();
  bool load_assets();
  bool unload_assets();

  // Draw Methods
  void Draw();
  void DrawEntities();
  void DrawUI();
  void DrawMenus();
  void DrawLevel();

  // Update Methods
  void Update();
  void UpdateEntities();
  void UpdateUI();
  void UpdateMenus();
  void UpdateLevel();

  void change_menu_flag() {
    if (IsKeyPressed(KEY_ENTER)) {
      switch (menu->get_menu_flag()) {
        case MENU::NONE:
          menu->set_flag(MENU::PAUSE);
          return;
        case MENU::MAIN:
          menu->set_flag(MENU::NONE);
          return;
        case MENU::PAUSE:
          menu->set_flag(MENU::NONE);
          return;
      }
    }
  }

  // Entity
  std::vector<Entity*> entities;

  Color background_color = RAYWHITE;
  std::shared_ptr<Player> player;
  std::shared_ptr<UI> ui;
  std::unique_ptr<Menu> menu;

  Opts opts;
};
