#pragma once

struct Stats {
  int hp;
  int attack;
  int magic;
  int defense;
  int magic_defense;
  int agility;
  int speed;
  int luck;
  int fortitude;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(hp, attack, magic);
  }
};
