#pragma once
#include <cereal/types/memory.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>
#include <cstdint>

struct Item {
  std::string name;
  uint8_t id;
  uint8_t effect;
  uint8_t type;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(name, id, effect, type);
  }
};

namespace item_type {
  enum TYPE {
    COLLECTABLE,
    MEDICINE,
    KEY_ITEM,
    WEAPON,
    ARMOR,
    AUGMENT,
  };
};
