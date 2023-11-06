module.exports = grammar({
  name: "axi",

  rules: {
    source_file: ($) => repeat($.importStatement),
    importStatement: ($) =>
      seq("from", $._module, "import", $.importsList, ";"),
    _module: ($) => choice($.localPath, $.packagePath),
    packagePath: ($) =>
      seq($.identifier, optional(seq("/", /\S+/))),
    localPath: ($) =>
      token(seq(choice("./", "../"), /\S+/)),
    importsList: ($) =>
      choice(
        seq(
          $.identifier,
          repeat(seq(",", $.identifier)),
          optional(seq(",", $.importAll)),
        ),
        $.importAll,
      ),
    importAll: ($) => seq("*", "as", $.identifier),
    identifier: ($) => /[_a-zA-Z]\w*/,
  },
});
