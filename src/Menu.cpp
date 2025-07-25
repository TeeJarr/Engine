#include "UI/Menu.hpp"
#include "Engine/Flags.hpp"
#include "Engine/Opts.hpp"
#include "raylib.h"
#include <cstdint>
#include <print>

Menu::Menu() {
  set_flag(FLAGS::MENU::MAIN);
  std::println("{}", menu_flag);
}

void Menu::draw() {}

void Menu::update() {
  if (IsKeyPressed(KEY_TAB)) {
    change_window_size();
  }
}

bool Menu::set_flag(uint8_t menu_flag) {
  if (menu_flag > FLAGS::MENU::NONE || menu_flag < FLAGS::MENU::MAIN) {
    std::println("Error: invalid menu flag");
    return false;
  }
  this->menu_flag = menu_flag;
  return true;
}

uint8_t Menu::get_menu_flag() { return this->menu_flag; }

void Menu::draw_main() {
  ClearBackground(RED);
  // HACK: Make proper text and Add Actual background art
  Vector2 text_size = MeasureTextEx(GetFontDefault(), "Title Screen", 24, 1);
  DrawText("Title Screen", opts.screen.x / 2 - (text_size.x / 2), opts.screen.y / 2 - (text_size.x / 2), 24, BLACK);
}

void Menu::draw_pause() {
  ClearBackground(BLACK);
  // HACK: Make proper text and Add Actual background art
  Vector2 text_size = MeasureTextEx(GetFontDefault(), "Pause", 24, 1);
  DrawText("Pause", opts.screen.x / 2 - (text_size.x / 2), opts.screen.y / 2 - (text_size.y / 2), 24, WHITE);
}

void Menu::change_window_size() {
  Opts::screen.x = 1920;
  Opts::screen.y = 1080;
  SetWindowSize(opts.screen.x, opts.screen.y);
}
