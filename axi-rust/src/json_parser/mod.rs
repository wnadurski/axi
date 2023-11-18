use crate::parsers;
use crate::parsers::{map, token_seq, ParseResult, Parser};
use std::collections::HashMap;

#[derive(Debug, Clone)]
pub enum Json {
    Null,
    Undefined,
    Number(i32),
    String(String),
    Array(Vec<Json>),
    Object(HashMap<String, Json>),
}
fn null<'a>() -> impl Parser<'a, char, Json> + Clone {
    map(parsers::str("null"), |_| Json::Null)
}
fn parser<'a>() -> impl Parser<'a, char, Json> {
    parsers::choice(vec![null()])
}

pub fn parse_json(str: &str) -> Result<Json, String> {
    let tokens: Vec<_> = str.chars().collect();
    let p = parser();

    let json = p.parse(tokens.as_slice());
    match json {
        Ok((rest, json)) => Ok(json),
        Err(err) => Err(err),
    }
}

#[cfg(test)]
mod tests {
    use crate::json_parser::parse_json;

    #[test]
    fn test_parse() {
        let x = parse_json("null");

        println!("{:?}", x)
    }
}
