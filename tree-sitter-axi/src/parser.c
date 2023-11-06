#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 26
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 19
#define ALIAS_COUNT 0
#define TOKEN_COUNT 11
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_from = 1,
  anon_sym_import = 2,
  anon_sym_SEMI = 3,
  anon_sym_SLASH = 4,
  aux_sym_packagePath_token1 = 5,
  sym_localPath = 6,
  anon_sym_COMMA = 7,
  anon_sym_STAR = 8,
  anon_sym_as = 9,
  sym_identifier = 10,
  sym_source_file = 11,
  sym_importStatement = 12,
  sym__module = 13,
  sym_packagePath = 14,
  sym_importsList = 15,
  sym_importAll = 16,
  aux_sym_source_file_repeat1 = 17,
  aux_sym_importsList_repeat1 = 18,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_from] = "from",
  [anon_sym_import] = "import",
  [anon_sym_SEMI] = ";",
  [anon_sym_SLASH] = "/",
  [aux_sym_packagePath_token1] = "packagePath_token1",
  [sym_localPath] = "localPath",
  [anon_sym_COMMA] = ",",
  [anon_sym_STAR] = "*",
  [anon_sym_as] = "as",
  [sym_identifier] = "identifier",
  [sym_source_file] = "source_file",
  [sym_importStatement] = "importStatement",
  [sym__module] = "_module",
  [sym_packagePath] = "packagePath",
  [sym_importsList] = "importsList",
  [sym_importAll] = "importAll",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_importsList_repeat1] = "importsList_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_from] = anon_sym_from,
  [anon_sym_import] = anon_sym_import,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [aux_sym_packagePath_token1] = aux_sym_packagePath_token1,
  [sym_localPath] = sym_localPath,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_as] = anon_sym_as,
  [sym_identifier] = sym_identifier,
  [sym_source_file] = sym_source_file,
  [sym_importStatement] = sym_importStatement,
  [sym__module] = sym__module,
  [sym_packagePath] = sym_packagePath,
  [sym_importsList] = sym_importsList,
  [sym_importAll] = sym_importAll,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_importsList_repeat1] = aux_sym_importsList_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_from] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_packagePath_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_localPath] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_as] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_importStatement] = {
    .visible = true,
    .named = true,
  },
  [sym__module] = {
    .visible = false,
    .named = true,
  },
  [sym_packagePath] = {
    .visible = true,
    .named = true,
  },
  [sym_importsList] = {
    .visible = true,
    .named = true,
  },
  [sym_importAll] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_importsList_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(15);
      if (lookahead == '*') ADVANCE(23);
      if (lookahead == ',') ADVANCE(22);
      if (lookahead == '.') ADVANCE(2);
      if (lookahead == '/') ADVANCE(19);
      if (lookahead == ';') ADVANCE(18);
      if (lookahead == 'a') ADVANCE(11);
      if (lookahead == 'f') ADVANCE(9);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '*') ADVANCE(23);
      if (lookahead == '.') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 2:
      if (lookahead == '.') ADVANCE(3);
      if (lookahead == '/') ADVANCE(14);
      END_STATE();
    case 3:
      if (lookahead == '/') ADVANCE(14);
      END_STATE();
    case 4:
      if (lookahead == 'm') ADVANCE(8);
      END_STATE();
    case 5:
      if (lookahead == 'm') ADVANCE(16);
      END_STATE();
    case 6:
      if (lookahead == 'o') ADVANCE(10);
      END_STATE();
    case 7:
      if (lookahead == 'o') ADVANCE(5);
      END_STATE();
    case 8:
      if (lookahead == 'p') ADVANCE(6);
      END_STATE();
    case 9:
      if (lookahead == 'r') ADVANCE(7);
      END_STATE();
    case 10:
      if (lookahead == 'r') ADVANCE(12);
      END_STATE();
    case 11:
      if (lookahead == 's') ADVANCE(24);
      END_STATE();
    case 12:
      if (lookahead == 't') ADVANCE(17);
      END_STATE();
    case 13:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(13)
      if (lookahead != 0) ADVANCE(20);
      END_STATE();
    case 14:
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(21);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_from);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(aux_sym_packagePath_token1);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_localPath);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(21);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_as);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 13},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_from] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [sym_localPath] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_as] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(18),
    [sym_importStatement] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_from] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(7), 1,
      sym_localPath,
    ACTIONS(9), 1,
      sym_identifier,
    STATE(23), 2,
      sym__module,
      sym_packagePath,
  [11] = 3,
    ACTIONS(5), 1,
      anon_sym_from,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
    STATE(4), 2,
      sym_importStatement,
      aux_sym_source_file_repeat1,
  [22] = 3,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
    ACTIONS(15), 1,
      anon_sym_from,
    STATE(4), 2,
      sym_importStatement,
      aux_sym_source_file_repeat1,
  [33] = 4,
    ACTIONS(18), 1,
      anon_sym_STAR,
    ACTIONS(20), 1,
      sym_identifier,
    STATE(15), 1,
      sym_importsList,
    STATE(16), 1,
      sym_importAll,
  [46] = 3,
    ACTIONS(22), 1,
      anon_sym_SEMI,
    ACTIONS(24), 1,
      anon_sym_COMMA,
    STATE(9), 1,
      aux_sym_importsList_repeat1,
  [56] = 3,
    ACTIONS(26), 1,
      anon_sym_SEMI,
    ACTIONS(28), 1,
      anon_sym_COMMA,
    STATE(7), 1,
      aux_sym_importsList_repeat1,
  [66] = 3,
    ACTIONS(18), 1,
      anon_sym_STAR,
    ACTIONS(31), 1,
      sym_identifier,
    STATE(24), 1,
      sym_importAll,
  [76] = 3,
    ACTIONS(33), 1,
      anon_sym_SEMI,
    ACTIONS(35), 1,
      anon_sym_COMMA,
    STATE(7), 1,
      aux_sym_importsList_repeat1,
  [86] = 3,
    ACTIONS(18), 1,
      anon_sym_STAR,
    ACTIONS(31), 1,
      sym_identifier,
    STATE(22), 1,
      sym_importAll,
  [96] = 1,
    ACTIONS(37), 2,
      ts_builtin_sym_end,
      anon_sym_from,
  [101] = 1,
    ACTIONS(26), 2,
      anon_sym_SEMI,
      anon_sym_COMMA,
  [106] = 2,
    ACTIONS(39), 1,
      anon_sym_import,
    ACTIONS(41), 1,
      anon_sym_SLASH,
  [113] = 1,
    ACTIONS(43), 1,
      anon_sym_as,
  [117] = 1,
    ACTIONS(45), 1,
      anon_sym_SEMI,
  [121] = 1,
    ACTIONS(22), 1,
      anon_sym_SEMI,
  [125] = 1,
    ACTIONS(47), 1,
      sym_identifier,
  [129] = 1,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
  [133] = 1,
    ACTIONS(51), 1,
      anon_sym_import,
  [137] = 1,
    ACTIONS(53), 1,
      aux_sym_packagePath_token1,
  [141] = 1,
    ACTIONS(55), 1,
      anon_sym_SEMI,
  [145] = 1,
    ACTIONS(57), 1,
      anon_sym_SEMI,
  [149] = 1,
    ACTIONS(59), 1,
      anon_sym_import,
  [153] = 1,
    ACTIONS(61), 1,
      anon_sym_SEMI,
  [157] = 1,
    ACTIONS(31), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 11,
  [SMALL_STATE(4)] = 22,
  [SMALL_STATE(5)] = 33,
  [SMALL_STATE(6)] = 46,
  [SMALL_STATE(7)] = 56,
  [SMALL_STATE(8)] = 66,
  [SMALL_STATE(9)] = 76,
  [SMALL_STATE(10)] = 86,
  [SMALL_STATE(11)] = 96,
  [SMALL_STATE(12)] = 101,
  [SMALL_STATE(13)] = 106,
  [SMALL_STATE(14)] = 113,
  [SMALL_STATE(15)] = 117,
  [SMALL_STATE(16)] = 121,
  [SMALL_STATE(17)] = 125,
  [SMALL_STATE(18)] = 129,
  [SMALL_STATE(19)] = 133,
  [SMALL_STATE(20)] = 137,
  [SMALL_STATE(21)] = 141,
  [SMALL_STATE(22)] = 145,
  [SMALL_STATE(23)] = 149,
  [SMALL_STATE(24)] = 153,
  [SMALL_STATE(25)] = 157,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [18] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [20] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [22] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_importsList, 1),
  [24] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_importsList_repeat1, 2),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_importsList_repeat1, 2), SHIFT_REPEAT(25),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_importsList, 2),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_importStatement, 5),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_packagePath, 1),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [49] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_packagePath, 3),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_importAll, 3),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_importsList, 3),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_importsList, 4),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_axi(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
