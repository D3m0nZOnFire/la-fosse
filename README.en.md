# La Fosse - Ivo Pereira Dantas

[Français](README.md) · **English**

## Description

**La Fosse** ("The Pit") is a text-based fighting game for the Windows console, written in C++. You play a tamer of mythological beasts facing ever stronger waves of enemies in an endless arena. The goal is to survive as long as possible by recruiting new beasts after each fight.

The game itself is in French.

---

## Quick download

Don't want to compile? A ready-to-play standalone build (.exe) is available here: [Download La Fosse (latest release)](https://github.com/D3m0nZOnFire/la-fosse/releases/latest) (the `.exe` file under the release's *Assets*)

---

## Features

- **33 beasts** from mythologies around the world (Japan, Greece, Scandinavia, Africa, etc.), split into 8 types: Fire, Water, Nature, Lightning, Earth, Wind, Shadow, Celestial.
- **Type system** with an advantage triangle (e.g. Fire > Nature > Water > Fire, Earth > Lightning, Shadow > Celestial). Multiplier ×1.5 / ×0.75 / ×1.0.
- **Starter selection**: 8 beasts to choose from at the start, one per type.
- **Turn-based combat**: turn order is decided by speed. The player picks a target; enemies target the beast with the lowest HP.
- **Recruitment**: after each win, the player can recruit one of the surviving enemy beasts (with a decreasing capture bonus).
- **Regeneration**: partial healing (75 % of missing HP) between fights; a full rest every 5 fights.
- **Logarithmic scaling**: enemy stats grow as `1 + k × log(fight + 1)`, which allows long runs without a sudden difficulty wall.
- **Type hints**: `[✦ Très efficace]` / `[↓ Peu efficace]` / `[Neutre]` badges (super effective / not very effective / neutral) in the target menu. Can be turned on or off in the Options.
- **Bestiary**: browsable from the main menu with pagination, full stats, lore and folkloric origin.
- **Local leaderboard**: scores are saved to a CSV file and shown at the end of a run.
- **Session log**: every action is timestamped in `lafosse.log`.

---

## Build from source

The game runs on Windows only (console, `conio.h`, `windows.h`).

1. Install Visual Studio 2026 with the **Desktop development with C++** workload (toolset v145).
2. Clone the repository:
   ```sh
   git clone https://github.com/D3m0nZOnFire/la-fosse.git
   ```
3. Open `La-Fosse/Projet-Fil-Rouge-Libre.slnx`, pick **Release | x64**, then **Build → Build Solution** (Ctrl+Shift+B).
4. Run it with **Ctrl+F5**, or start the executable in `La-Fosse/x64/Release/`.

---

## C++ requirements met

Built for a C++ course at HE-Arc. This shows where each course requirement is met.

<details>
<summary>Show the requirements table</summary>

| Requirement | Implementation |
|---|---|
| Abstract class hierarchy | `Fighter` (`Fighter.h`) is abstract with a pure virtual `act()`; `PlayerFighter` and `EnemyFighter` inherit from it |
| Operator overloading | `operator<<` on `Fighter`, prints `Name [Type] HP cur/max` |
| Exception | `CombatException` → `EmptyPackException` (`CombatException.h`), thrown by `runCombat()`, caught in `Game.cpp` |
| Polymorphism (overriding + pointers) | `act()` overridden in each subclass; dispatched through `vector<unique_ptr<Fighter>>` in combat |
| Modern C++ and STL | `unique_ptr`, `vector`, `sort` + lambda, designated initializers (C++20), singletons via function-local statics |
| Log file | `Logger` singleton writes to `lafosse.log` with timestamps and `[INFO]` / `[WARNING]` / `[ERROR]` levels |
| Working program | Complete game: menu, combat, recruitment, scaling, CSV leaderboard, bestiary, options |

</details>

---

## Legal disclaimer

This project is in no way affiliated with Nintendo, Game Freak or The Pokémon Company. Any resemblance to a game where you catch creatures and make them fight in an arena is purely... non-existent. Totally. We don't catch Pokémon here, we recruit mythological beasts from thousand-year-old folk traditions. Completely different. Please don't sue me.
