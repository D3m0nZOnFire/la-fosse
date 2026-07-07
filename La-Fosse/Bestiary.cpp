#include "Bestiary.h"

// Attaques

#pragma region Fire
static const Attack A_SouffleArdent = {
    .name = "Souffle Ardent",
    .type = Type::Fire,
    .baseDamage = 10
};
static const Attack A_Explosion = {
    .name = "Explosion",
    .type = Type::Fire,
    .baseDamage = 16
};
static const Attack A_Brasier = {
    .name = "Brasier",
    .type = Type::Fire,
    .baseDamage = 12
};
static const Attack A_RayonDeBraise = {
    .name = "Rayon de Braise",
    .type = Type::Fire,
    .baseDamage = 11
};
static const Attack A_PluieDEpines = {
    .name = "Pluie d'Épines",
    .type = Type::Fire,
    .baseDamage = 13
};
#pragma endregion

#pragma region Water
static const Attack A_Saisie = {
    .name = "Saisie",
    .type = Type::Water,
    .baseDamage = 7
};
static const Attack A_MorsureAbyssale = {
    .name = "Morsure Abyssale",
    .type = Type::Water,
    .baseDamage = 13
};
static const Attack A_Torrent = {
    .name = "Torrent",
    .type = Type::Water,
    .baseDamage = 14
};
static const Attack A_Engloutissement = {
    .name = "Engloutissement",
    .type = Type::Water,
    .baseDamage = 14
};
static const Attack A_GriffeEau = {
    .name = "Griffe d'Eau",
    .type = Type::Water,
    .baseDamage = 12
};
#pragma endregion

#pragma region Nature
static const Attack A_SoinDePlume = {
    .name = "Serres de Plume",
    .type = Type::Nature,
    .baseDamage = 12
};
static const Attack A_Lianes = {
    .name = "Lianes",
    .type = Type::Nature,
    .baseDamage = 10
};
static const Attack A_MorsureVegetale = {
    .name = "Morsure Végétale",
    .type = Type::Nature,
    .baseDamage = 15
};
#pragma endregion

#pragma region Lightning
static const Attack A_ArcElectrique = {
    .name = "Arc Électrique",
    .type = Type::Lightning,
    .baseDamage = 10
};
static const Attack A_Surcharge = {
    .name = "Surcharge",
    .type = Type::Lightning,
    .baseDamage = 15
};
static const Attack A_Tonnerre = {
    .name = "Tonnerre",
    .type = Type::Lightning,
    .baseDamage = 13
};
#pragma endregion

#pragma region Earth
static const Attack A_Seisme = {
    .name = "Séisme",
    .type = Type::Earth,
    .baseDamage = 15
};
static const Attack A_ChargeBrute = {
    .name = "Charge Brute",
    .type = Type::Earth,
    .baseDamage = 15
};
static const Attack A_Ecrasement = {
    .name = "Écrasement",
    .type = Type::Earth,
    .baseDamage = 10
};
static const Attack A_LeurreOre = {
    .name = "Leurre Doré",
    .type = Type::Earth,
    .baseDamage = 10
};
#pragma endregion

#pragma region Wind
static const Attack A_Tourbillon = {
    .name = "Tourbillon",
    .type = Type::Wind,
    .baseDamage = 13
};
static const Attack A_Plongeon = {
    .name = "Plongeon",
    .type = Type::Wind,
    .baseDamage = 12
};
static const Attack A_ChargeAilee = {
    .name = "Charge Ailée",
    .type = Type::Wind,
    .baseDamage = 13
};
static const Attack A_TempeteDePlumes = {
    .name = "Tempête de Plumes",
    .type = Type::Wind,
    .baseDamage = 11
};
static const Attack A_GalopSpectral = {
    .name = "Galop Spectral",
    .type = Type::Wind,
    .baseDamage = 14
};
#pragma endregion

#pragma region Shadow
static const Attack A_Traque = {
    .name = "Traque",
    .type = Type::Shadow,
    .baseDamage = 13
};
static const Attack A_Famine = {
    .name = "Famine",
    .type = Type::Shadow,
    .baseDamage = 15
};
static const Attack A_Devoration = {
    .name = "Dévoration",
    .type = Type::Shadow,
    .baseDamage = 14
};
static const Attack A_DevorationDeReves = {
    .name = "Cauchemar",
    .type = Type::Shadow,
    .baseDamage = 13
};
#pragma endregion

#pragma region Celestial
static const Attack A_VolSolaire = {
    .name = "Vol Solaire",
    .type = Type::Celestial,
    .baseDamage = 12
};
static const Attack A_Chatiment = {
    .name = "Châtiment",
    .type = Type::Celestial,
    .baseDamage = 15
};
static const Attack A_SerresDivines = {
    .name = "Serres Divines",
    .type = Type::Celestial,
    .baseDamage = 11
};
static const Attack A_SouffleSacre = {
    .name = "Souffle Sacré",
    .type = Type::Celestial,
    .baseDamage = 12
};
#pragma endregion

// Espèces

#pragma region Fire
static const Species E_Chimere = {
    .name = "Chimère",
    .type = Type::Fire,
    .hpBase = 90,
    .speedBase = 60,
    .attackBase = 18,
    .attack = &A_SouffleArdent,
    .origin = "Grèce antique",
    .lore = "Monstre hybride de la mythologie grecque, au corps de lion, à la tête de chèvre et à la queue de serpent. Son souffle ardent dévaste tout sur son passage."
};
static const Species E_Salamandre = {
    .name = "Salamandre",
    .type = Type::Fire,
    .hpBase = 70,
    .speedBase = 80,
    .attackBase = 20,
    .attack = &A_Explosion,
    .origin = "Europe médiévale",
    .lore = "Lézard de feu des légendes médiévales, réputé vivre au cœur des braises sans jamais se consumer. Son sang peut embraser une forêt entière."
};
static const Species E_Ifrit = {
    .name = "Ifrit",
    .type = Type::Fire,
    .hpBase = 110,
    .speedBase = 45,
    .attackBase = 22,
    .attack = &A_Brasier,
    .origin = "Monde arabe",
    .lore = "Djinn de feu des traditions arabes, né de flammes sans fumée. Rebelle et colossal, il dévaste les cités qui osent lui résister."
};
static const Species E_Carbuncle = {
    .name = "Carbuncle",
    .type = Type::Fire,
    .hpBase = 65,
    .speedBase = 90,
    .attackBase = 16,
    .attack = &A_RayonDeBraise,
    .origin = "Amérique du Sud",
    .lore = "Petite créature des folklores latino-américains, ornée d'un rubis étincelant sur le front. Son gemme concentre la chaleur solaire en un rayon dévastateur."
};
static const Species E_Manticore = {
    .name = "Manticore",
    .type = Type::Fire,
    .hpBase = 95,
    .speedBase = 55,
    .attackBase = 19,
    .attack = &A_PluieDEpines,
    .origin = "Perse",
    .lore = "Bête persane au visage d'homme, au corps de lion et à la queue hérissée d'épines empoisonnées. Elle traque ses proies avec une intelligence cruelle."
};
#pragma endregion

#pragma region Water
static const Species E_Kappa = {
    .name = "Kappa",
    .type = Type::Water,
    .hpBase = 85,
    .speedBase = 55,
    .attackBase = 16,
    .attack = &A_Saisie,
    .origin = "Japon",
    .lore = "Esprit aquatique japonais au crâne en forme de coupelle remplie d'eau. Poli mais dangereux, il saisit ses victimes depuis les rivières pour les entraîner au fond."
};
static const Species E_Nidhoggr = {
    .name = "Nidhoggr",
    .type = Type::Water,
    .hpBase = 130,
    .speedBase = 35,
    .attackBase = 20,
    .attack = &A_MorsureAbyssale,
    .origin = "Scandinavie",
    .lore = "Serpent titanesque de la mythologie nordique qui ronge les racines d'Yggdrasil depuis les abysses. Sa morsure corrosive peut dissoudre la roche."
};
static const Species E_Nixe = {
    .name = "Nixe",
    .type = Type::Water,
    .hpBase = 75,
    .speedBase = 70,
    .attackBase = 15,
    .attack = &A_Torrent,
    .origin = "Germanie",
    .lore = "Esprit des eaux germaniques capable de prendre forme humaine. Elle attire les voyageurs vers les profondeurs avec son chant envoûtant."
};
static const Species E_Bakunawa = {
    .name = "Bakunawa",
    .type = Type::Water,
    .hpBase = 110,
    .speedBase = 45,
    .attackBase = 19,
    .attack = &A_Engloutissement,
    .origin = "Philippines",
    .lore = "Serpent de mer des légendes philippines, assez grand pour avaler la lune entière. Il surgit des profondeurs pour engloutir ses proies d'un seul mouvement."
};
static const Species E_Ahuizotl = {
    .name = "Ahuizotl",
    .type = Type::Water,
    .hpBase = 80,
    .speedBase = 65,
    .attackBase = 17,
    .attack = &A_GriffeEau,
    .origin = "Mexique (Aztèque)",
    .lore = "Créature aquatique aztèque dotée d'une main préhensile au bout de la queue. Elle agrippe ses victimes depuis sous la surface et les noie sans pitié."
};
#pragma endregion

#pragma region Nature
static const Species E_Simurgh = {
    .name = "Simurgh",
    .type = Type::Nature,
    .hpBase = 95,
    .speedBase = 65,
    .attackBase = 14,
    .attack = &A_SoinDePlume,
    .origin = "Perse",
    .lore = "Oiseau bienveillant de la mythologie persane, assez grand pour porter un éléphant. Il niche au sommet de l'arbre de toute connaissance et soigne les blessures de ses serres."
};
static const Species E_Dryade = {
    .name = "Dryade",
    .type = Type::Nature,
    .hpBase = 80,
    .speedBase = 50,
    .attackBase = 16,
    .attack = &A_Lianes,
    .origin = "Grèce antique",
    .lore = "Nymphe grecque liée à un arbre spécifique dont elle partage le destin. Elle tisse des lianes à volonté pour immobiliser quiconque menace sa forêt."
};
static const Species E_Grootslang = {
    .name = "Grootslang",
    .type = Type::Nature,
    .hpBase = 120,
    .speedBase = 40,
    .attackBase = 19,
    .attack = &A_MorsureVegetale,
    .origin = "Afrique du Sud",
    .lore = "Créature sud-africaine mi-éléphant mi-serpent, erreur de création que les dieux tentèrent vainement de séparer. Elle garde jalousement les pierres précieuses de sa caverne."
};
#pragma endregion

#pragma region Lightning
static const Species E_Vouivre = {
    .name = "Vouivre",
    .type = Type::Lightning,
    .hpBase = 85,
    .speedBase = 75,
    .attackBase = 17,
    .attack = &A_ArcElectrique,
    .origin = "Franche-Comté (France)",
    .lore = "Dragon ailé du folklore franc-comtois, portant un escarboucle sur le front. Il sillonne les cieux orageux et foudroie quiconque convoite son trésor."
};
static const Species E_Raiju = {
    .name = "Raijū",
    .type = Type::Lightning,
    .hpBase = 70,
    .speedBase = 95,
    .attackBase = 19,
    .attack = &A_Surcharge,
    .origin = "Japon",
    .lore = "Bête de foudre japonaise qui voyage dans les éclairs sous forme de loup ou de belette. Elle se déplace si vite qu'on ne perçoit que l'éclair qu'elle laisse dans son sillage."
};
static const Species E_Thunderbird = {
    .name = "Thunderbird",
    .type = Type::Lightning,
    .hpBase = 100,
    .speedBase = 60,
    .attackBase = 18,
    .attack = &A_Tonnerre,
    .origin = "Amérique du Nord (peuples autochtones)",
    .lore = "Oiseau sacré des peuples amérindiens dont les battements d'ailes créent le tonnerre. Ses yeux lancent des éclairs et sa présence annonce les grandes tempêtes."
};
#pragma endregion

#pragma region Earth
static const Species E_Golem = {
    .name = "Golem",
    .type = Type::Earth,
    .hpBase = 140,
    .speedBase = 25,
    .attackBase = 21,
    .attack = &A_Seisme,
    .origin = "Judaïsme (Europe de l'Est)",
    .lore = "Colosse d'argile animé par la kabbale juive, obéissant à son créateur à la lettre. Sa masse titanesque fait trembler le sol à chaque pas."
};
static const Species E_Minotaure = {
    .name = "Minotaure",
    .type = Type::Earth,
    .hpBase = 115,
    .speedBase = 45,
    .attackBase = 23,
    .attack = &A_ChargeBrute,
    .origin = "Crète (Grèce antique)",
    .lore = "Fils maudit du roi Minos, enfermé au cœur du labyrinthe de Crète. Mi-homme mi-taureau, sa charge peut renverser des colonnes de marbre."
};
static const Species E_Tarasque = {
    .name = "Tarasque",
    .type = Type::Earth,
    .hpBase = 160,
    .speedBase = 20,
    .attackBase = 19,
    .attack = &A_Ecrasement,
    .origin = "Provence (France)",
    .lore = "Monstre provençal à la carapace de tortue et aux griffes de lion, terreur des bords du Rhône. Son écrasement laisse des cratères dans la roche."
};
static const Species E_Alicanto = {
    .name = "Alicanto",
    .type = Type::Earth,
    .hpBase = 105,
    .speedBase = 40,
    .attackBase = 20,
    .attack = &A_LeurreOre,
    .origin = "Chili",
    .lore = "Oiseau nocturne chilien qui se nourrit de minerais précieux. Son plumage luit de l'or et de l'argent qu'il a ingérés, attirant les mineurs vers des falaises mortelles."
};
#pragma endregion

#pragma region Wind
static const Species E_Sylphe = {
    .name = "Sylphe",
    .type = Type::Wind,
    .hpBase = 60,
    .speedBase = 100,
    .attackBase = 14,
    .attack = &A_Tourbillon,
    .origin = "Europe (alchimie)",
    .lore = "Esprit aérien de la philosophie alchimiste, invisible et insaisissable. Il tourbillonne à travers les armures sans jamais ralentir."
};
static const Species E_Roc = {
    .name = "Roc",
    .type = Type::Wind,
    .hpBase = 105,
    .speedBase = 55,
    .attackBase = 17,
    .attack = &A_Plongeon,
    .origin = "Monde arabe / Océan Indien",
    .lore = "Oiseau géant des légendes arabes, assez puissant pour emporter un éléphant dans ses serres. Son envergure obscurcit le soleil sur des lieues à la ronde."
};
static const Species E_Peryton = {
    .name = "Peryton",
    .type = Type::Wind,
    .hpBase = 90,
    .speedBase = 75,
    .attackBase = 16,
    .attack = &A_ChargeAilee,
    .origin = "Atlantide (légende)",
    .lore = "Cerf ailé des légendes de l'Atlantide, dont l'ombre prend curieusement forme humaine. Il chasse en piqué avec une précision chirurgicale."
};
static const Species E_Ziz = {
    .name = "Ziz",
    .type = Type::Wind,
    .hpBase = 120,
    .speedBase = 50,
    .attackBase = 18,
    .attack = &A_TempeteDePlumes,
    .origin = "Hébraïque",
    .lore = "Oiseau colossal de la mythologie hébraïque, pendant céleste du Léviathan et du Béhémoth. Ses plumes, projetées comme des lances, percent les cuirasses."
};
static const Species E_Sleipnir = {
    .name = "Sleipnir",
    .type = Type::Wind,
    .hpBase = 80,
    .speedBase = 110,
    .attackBase = 15,
    .attack = &A_GalopSpectral,
    .origin = "Scandinavie",
    .lore = "Cheval à huit pattes d'Odin, la monture la plus rapide des neuf mondes nordiques. Il peut galoper sur l'eau, dans les airs et jusqu'au royaume des morts."
};
#pragma endregion

#pragma region Shadow
static const Species E_Fenrir = {
    .name = "Fenrir",
    .type = Type::Shadow,
    .hpBase = 100,
    .speedBase = 70,
    .attackBase = 20,
    .attack = &A_Traque,
    .origin = "Scandinavie",
    .lore = "Loup titanesque de la mythologie nordique, fils de Loki, enchaîné par les dieux jusqu'au Ragnarök. Sa gueule ouverte s'étend de la terre au ciel."
};
static const Species E_Wendigo = {
    .name = "Wendigo",
    .type = Type::Shadow,
    .hpBase = 90,
    .speedBase = 60,
    .attackBase = 18,
    .attack = &A_Famine,
    .origin = "Amérique du Nord (Algonquin)",
    .lore = "Esprit algonquin de la famine, né d'un homme contraint au cannibalisme. Plus il dévore, plus sa faim s'intensifie — il ne peut jamais être rassasié."
};
static const Species E_Ammit = {
    .name = "Ammit",
    .type = Type::Shadow,
    .hpBase = 95,
    .speedBase = 50,
    .attackBase = 21,
    .attack = &A_Devoration,
    .origin = "Égypte antique",
    .lore = "Dévoreur d'âmes égyptien, mi-lion mi-crocodile mi-hippopotame. Il attend le jugement des morts pour engloutir les cœurs trop lourds de péchés."
};
static const Species E_Baku = {
    .name = "Baku",
    .type = Type::Shadow,
    .hpBase = 85,
    .speedBase = 60,
    .attackBase = 18,
    .attack = &A_DevorationDeReves,
    .origin = "Japon",
    .lore = "Tapir chimérique du folklore japonais, assemblé des restes de la création divine. Il dévore les cauchemars — et parfois, les rêves trop beaux aussi."
};
#pragma endregion

#pragma region Celestial
static const Species E_Yatagarasu = {
    .name = "Yatagarasu",
    .type = Type::Celestial,
    .hpBase = 80,
    .speedBase = 85,
    .attackBase = 16,
    .attack = &A_VolSolaire,
    .origin = "Japon",
    .lore = "Corbeau à trois pattes messager du soleil dans la mythologie japonaise. Il guidait l'empereur Jimmu à travers les terres obscures vers la lumière divine."
};
static const Species E_AngeDechu = {
    .name = "Ange Déchu",
    .type = Type::Celestial,
    .hpBase = 90,
    .speedBase = 65,
    .attackBase = 18,
    .attack = &A_Chatiment,
    .origin = "Tradition abrahamique",
    .lore = "Être céleste banni des sphères supérieures, dont la gloire passée se retourne en puissance destructrice. Ses ailes noircies portent encore la marque du divin."
};
static const Species E_Garuda = {
    .name = "Garuda",
    .type = Type::Celestial,
    .hpBase = 100,
    .speedBase = 75,
    .attackBase = 17,
    .attack = &A_SerresDivines,
    .origin = "Inde / Asie du Sud-Est",
    .lore = "Oiseau divin de la mythologie hindoue et bouddhiste, monture de Vishnu. Ennemi éternel des serpents, ses serres sacrées brisent les enchantements."
};
static const Species E_Qilin = {
    .name = "Qilin",
    .type = Type::Celestial,
    .hpBase = 100,
    .speedBase = 70,
    .attackBase = 17,
    .attack = &A_SouffleSacre,
    .origin = "Chine",
    .lore = "Licorne chimère de la mythologie chinoise, présage de l'avènement d'un sage. Si pur qu'il ne foule pas l'herbe — son souffle sacré purifie autant qu'il brûle."
};
#pragma endregion

const std::vector<const Species*>& getStarterBestiary() {
    static const std::vector<const Species*> starters = {
        &E_Chimere,     // Feu
        &E_Kappa,       // Eau
        &E_Simurgh,     // Nature
        &E_Vouivre,     // Foudre
        &E_Golem,       // Terre
        &E_Sylphe,      // Vent
        &E_Fenrir,      // Ombre
        &E_Yatagarasu,  // Céleste
    };
    return starters;
}

const std::vector<const Species*>& getBestiary() {
    static const std::vector<const Species*> bestiary = {
        &E_Chimere, &E_Salamandre, &E_Ifrit, &E_Carbuncle, &E_Manticore,
        &E_Kappa, &E_Nidhoggr, &E_Nixe, &E_Bakunawa, &E_Ahuizotl,
        &E_Simurgh, &E_Dryade, &E_Grootslang,
        &E_Vouivre, &E_Raiju, &E_Thunderbird,
        &E_Golem, &E_Minotaure, &E_Tarasque, &E_Alicanto,
        &E_Sylphe, &E_Roc, &E_Peryton, &E_Ziz, &E_Sleipnir,
        &E_Fenrir, &E_Wendigo, &E_Ammit, &E_Baku,
        &E_Yatagarasu, &E_AngeDechu, &E_Garuda, &E_Qilin,
    };
    return bestiary;
}
