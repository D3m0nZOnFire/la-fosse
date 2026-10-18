# La Fosse - Ivo Pereira Dantas

**Français** · [English](README.en.md)

## Description

**La Fosse** est un jeu de combat en mode texte (console Windows) développé en C++. Le joueur incarne un dresseur de bêtes mythologiques qui affronte des vagues ennemies de plus en plus puissantes dans une arène sans fin. L'objectif est de survivre le plus longtemps possible en recrutant de nouvelles bêtes après chaque combat.

---

## Téléchargement rapide

Pas envie de compiler ? Une version standalone (.exe) prête à jouer est disponible ici : [Télécharger La Fosse (dernière version)](https://github.com/D3m0nZOnFire/la-fosse/releases/latest) (fichier `.exe` dans les *Assets* de la release)

---

## Fonctionnalités

- **33 bêtes** issues de mythologies du monde entier (Japon, Grèce, Scandinavie, Afrique, etc.), réparties en 8 types : Feu, Eau, Nature, Foudre, Terre, Vent, Ombre, Céleste.
- **Système de types** avec triangle d'avantages (ex. Feu > Nature > Eau > Feu, Terre > Foudre, Ombre > Céleste). Multiplicateur ×1,5 / ×0,75 / ×1,0.
- **Sélection du starter** : 8 bêtes disponibles au départ, une par type.
- **Combat au tour par tour** : ordre de passage déterminé par la vitesse. Le joueur choisit sa cible ; les ennemis ciblent la bête avec le moins de PV.
- **Recrutement** : après chaque victoire, le joueur peut recruter une bête survivante ennemie (avec bonus de capture décroissant).
- **Régénération** : guérison partielle (75 % des PV manquants) entre chaque combat ; repos complet tous les 5 combats.
- **Scaling logarithmique** : les stats ennemies augmentent selon `1 + k × log(combat + 1)`, ce qui permet des runs longs sans mur de difficulté brutal.
- **Aide de type** : badges `[✦ Très efficace]` / `[↓ Peu efficace]` / `[Neutre]` affichés dans le menu de sélection de cible. Activable/désactivable dans les Options.
- **Bestiaire** : consultable depuis le menu principal avec pagination, stats complètes, texte de lore et origine folklorique.
- **Classement local** : les scores sont sauvegardés dans un fichier CSV et affichés en fin de partie.
- **Log de session** : chaque action est horodatée dans `lafosse.log`.

---

## Compiler depuis les sources

Le jeu tourne uniquement sous Windows (console, `conio.h`, `windows.h`).

1. Installer Visual Studio 2026 avec la charge de travail **Développement Desktop en C++** (toolset v145).
2. Cloner le dépôt :
   ```sh
   git clone https://github.com/D3m0nZOnFire/la-fosse.git
   ```
3. Ouvrir `La-Fosse/Projet-Fil-Rouge-Libre.slnx`, choisir **Release | x64**, puis **Générer → Générer la solution** (Ctrl+Maj+B).
4. Lancer avec **Ctrl+F5**, ou l'exécutable dans `La-Fosse/x64/Release/`.

---

## Exigences C++ satisfaites

Projet réalisé pour un cours de C++ à la HE-Arc. Voici où chaque exigence du cours est remplie.

<details>
<summary>Voir le tableau des exigences</summary>

| Exigence | Implémentation |
|---|---|
| Hiérarchie de classes abstraite | `Fighter` (`Fighter.h`) est abstraite avec `act()` virtuel pur ; `PlayerFighter` et `EnemyFighter` en héritent |
| Surcharge d'opérateur | `operator<<` sur `Fighter` — affiche `Nom [Type] HP cur/max` |
| Exception | `CombatException` → `EmptyPackException` (`CombatException.h`), levée par `runCombat()`, attrapée dans `Game.cpp` |
| Polymorphisme (redéfinition + pointeurs) | `act()` redéfinie dans chaque sous-classe ; dispatch via `vector<unique_ptr<Fighter>>` en combat |
| C++ moderne et STL | `unique_ptr`, `vector`, `sort` + lambda, designated initializers (C++20), singletons via static local |
| Fichier log | `Logger` singleton écrit dans `lafosse.log` avec horodatage et niveaux `[INFO]` / `[WARNING]` / `[ERROR]` |
| Programme fonctionnel | Jeu complet : menu, combat, recrutement, scaling, classement CSV, bestiaire, options |

</details>

---

## Avertissement légal

Ce projet n'est en aucun cas affilié à Nintendo, Game Freak ou The Pokemon Company. Les ressemblances avec un jeu où l'on capture des créatures dans une arène et où on les fait se battre sont purement... inexistantes. Totalement. On ne capture pas des Pokémon ici, on recrute des bêtes mythologiques issues de traditions folkloriques millénaires. C'est complètement différent. Merci de ne pas me poursuivre.
