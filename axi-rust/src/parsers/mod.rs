use std::fmt::Display;

pub type ParseResult<'a, Token, T> = Result<(&'a [Token], T), String>;

pub trait Parser<'a, Token, T> {
    fn parse(&self, input: &'a [Token]) -> ParseResult<'a, Token, T>;
}
pub fn of<'a, Token: 'a, T: Clone>(value: T) -> impl Parser<'a, Token, T> {
    move |input| Ok((input, value.clone()))
}

pub fn fail<'a, Token: 'a, T>(message: String) -> impl Parser<'a, Token, T> {
    move |_| Err(message.clone())
}
pub fn map<'a, F, Token: 'a, P, A, B>(parser: P, f: F) -> impl Parser<'a, Token, B>
where
    F: Fn(A) -> B,
    P: Parser<'a, Token, A>,
{
    move |input| match parser.parse(input) {
        Ok((state, a)) => Ok((state, f(a))),
        Err(err) => Err(err),
    }
}
pub fn just<'a, Token: PartialEq + Clone + Display + 'a>(
    token: Token,
) -> impl Parser<'a, Token, Token> + Clone {
    move |input: &'a [Token]| {
        let first = input.iter().next();
        let x = first.ok_or(String::from(format!(
            "Expected {token}, encountered end of stream."
        )));
        x.and_then(|first| {
            if *first == token {
                Ok((&input.iter().as_slice()[1..], token.clone()))
            } else {
                Err(String::from(format!(
                    "Expected '{token}', encountered '{first}'."
                )))
            }
        })
    }
}
pub fn pair<'a, Token: 'a, A, B, P1, P2>(parser1: P1, parser2: P2) -> impl Parser<'a, Token, (A, B)>
where
    P1: Parser<'a, Token, A>,
    P2: Parser<'a, Token, B>,
{
    move |input| {
        parser1
            .parse(input)
            .and_then(|(rest, a)| parser2.parse(rest).map(|(rest1, b)| (rest1, (a, b))))
    }
}

pub fn left<'a, Token: 'a, A, B, P1, P2>(parser1: P1, parser2: P2) -> impl Parser<'a, Token, A>
where
    P1: Parser<'a, Token, A>,
    P2: Parser<'a, Token, B>,
{
    map(pair(parser1, parser2), |(a, _)| a)
}

pub fn right<'a, Token: 'a, A, B, P1, P2>(parser1: P1, parser2: P2) -> impl Parser<'a, Token, B>
where
    P1: Parser<'a, Token, A>,
    P2: Parser<'a, Token, B>,
{
    map(pair(parser1, parser2), |(_, b)| b)
}

pub fn many1<'a, Token: 'a, P, A>(parser: P) -> impl Parser<'a, Token, Vec<A>>
where
    P: Parser<'a, Token, A>,
{
    move |input| {
        let mut result = Vec::new();
        let mut next_input = input;
        let first = parser.parse(next_input);
        match first {
            Err(err) => Err(err),
            Ok((next, a)) => {
                result.push(a);
                next_input = next;
                while let Ok((next, a)) = parser.parse(next_input) {
                    result.push(a);
                    next_input = next;
                }
                Ok((next_input, result))
            }
        }
    }
}
pub fn token_seq<'a, Token: PartialEq + Clone + Display + 'a>(
    tokens: Vec<Token>,
) -> impl Parser<'a, Token, Vec<Token>> + 'a {
    let parsers: Vec<_> = tokens
        .into_iter()
        .map(|token| just(token.clone()))
        .collect();
    seq(parsers)
}
pub fn seq<'a, Token: PartialEq + Clone + Display + 'a, T, P>(
    parsers: Vec<P>,
) -> impl Parser<'a, Token, Vec<T>> + 'a
where
    P: Parser<'a, Token, T> + Clone + 'a,
{
    move |input| {
        let mut next_input = input;
        let mut result = Vec::new();

        for p in parsers.clone() {
            let (next, a) = match p.parse(next_input) {
                Ok(s) => s,
                Err(e) => {
                    return Err(e);
                }
            };

            result.push(a);
            next_input = next;
        }

        Ok((next_input, result))
    }
}

pub fn choice<'a, Token: 'a, T>(
    parsers: Vec<impl Parser<'a, Token, T> + Clone>,
) -> impl Parser<'a, Token, T> {
    move |input| {
        for p in parsers.clone() {
            match p.parse(input) {
                Ok(state) => {
                    return Ok(state);
                }
                Err(e) => {
                    continue;
                }
            }
        }
        Err(format!("Expected a choice, got something else.").to_string())
    }
}

pub fn str<'a>(str: &str) -> impl Parser<'a, char, String> + Clone {
    let tokens: Vec<_> = str.chars().collect();
    move |input| {
        let p = token_seq(tokens.clone());
        let p = map(p, |chars| {
            let s: String = chars.into_iter().collect();
            s
        });
        p.parse(input)
    }
}

impl<'a, Token: 'a, T, F> Parser<'a, Token, T> for F
where
    F: Fn(&'a [Token]) -> ParseResult<'a, Token, T>,
{
    fn parse(&self, input: &'a [Token]) -> ParseResult<'a, Token, T> {
        self(input)
    }
}

#[cfg(test)]
mod tests {
    use crate::parsers::{choice, just, many1, map, of, seq, str, token_seq, ParseResult, Parser};

    fn some_parser(string: &[char]) -> ParseResult<char, char> {
        let x = &string[1..];
        let first = *string.iter().next().unwrap();
        Ok((x, first))
    }

    #[derive(Debug, PartialOrd, PartialEq)]
    enum TestValue {
        First,
        Second,
        Def,
    }
    fn some_parser2(all: &[u32]) -> ParseResult<u32, TestValue> {
        let x = &all[1..];
        let first = *all.iter().next().unwrap();
        let output = if first == 1 {
            TestValue::First
        } else if first == 2 {
            TestValue::Second
        } else {
            TestValue::Def
        };
        Ok((x, output))
    }

    #[test]
    fn it_works() {
        let source = "Asdasasd";
        let x = source.chars().collect::<Vec<char>>();
        let result = some_parser.parse(x.as_slice());

        let vec = "sdasasd".chars().collect::<Vec<char>>();
        let expected = vec.as_slice();
        assert_eq!(result, Ok((expected, 'A')))
    }

    #[test]
    fn it_works_for_any_slice() {
        let xs = vec![1, 3, 2];
        let result = some_parser2.parse(xs.as_slice());

        assert_eq!(result, Ok((&xs[1..], TestValue::First)));

        let x = result.unwrap();
        let result2 = some_parser2.parse(x.0);

        assert_eq!(result2, Ok((&xs[2..], TestValue::Def)));
    }

    #[test]
    fn of_and_map() {
        let a = "asd".chars().collect::<Vec<char>>();
        let p1 = of(10);
        let result = p1.parse(a.as_slice());

        assert_eq!(result, Ok((a.as_slice(), 10)));

        let p2 = map(p1, |a| a + 20);
        let result = p2.parse(a.as_slice());

        assert_eq!(result, Ok((a.as_slice(), 30)));
    }

    #[test]
    fn just_test() {
        let a = "asd".chars().collect::<Vec<char>>();
        let p1 = just('a');
        let result = p1.parse(a.as_slice());

        assert_eq!(result, Ok((&a.as_slice()[1..], 'a')));

        let p2 = just('b');
        let result = p2.parse(a.as_slice());
        assert_eq!(result, Err(String::from("Expected 'b', encountered 'a'.")));
    }

    #[test]
    fn many1_test() {
        let input1 = "aaaabc".chars().collect::<Vec<char>>();
        let parser1 = many1(just('a'));
        let result = parser1.parse(input1.as_slice());

        assert_eq!(result, Ok((&input1[4..], vec!['a', 'a', 'a', 'a'])));

        let parser2 = many1(just('b'));
        let result = parser2.parse(input1.as_slice());

        assert_eq!(result, Err("Expected 'b', encountered 'a'.".to_string()));
    }

    #[test]
    fn seq_test() {
        let input1 = "abcxaz".chars().collect::<Vec<char>>();
        let parser1 = token_seq(vec!['a', 'b', 'c']);
        let result = parser1.parse(input1.as_slice());

        assert_eq!(result, Ok((&input1[3..], vec!['a', 'b', 'c'])));

        let parser2 = token_seq(vec!['a', 'a', 'c']);
        let result = parser2.parse(input1.as_slice());

        assert_eq!(result, Err("Expected 'a', encountered 'b'.".to_string()));
    }

    #[test]
    fn choice_test() {
        let input1 = "abcxaz".chars().collect::<Vec<char>>();
        let parser1 = choice(vec![just('b'), just('a')]);
        let result = parser1.parse(input1.as_slice());

        assert_eq!(result, Ok((&input1[1..], 'a')));

        let parser2 = choice(vec![just('c'), just('b')]);
        let result = parser2.parse(input1.as_slice());

        assert_eq!(
            result,
            Err("Expected a choice, got something else.".to_string())
        );
    }

    #[test]
    fn str_test() {
        let input1 = "abcxaz".chars().collect::<Vec<char>>();
        let parser1 = str("abc");
        let result = parser1.parse(input1.as_slice());

        assert_eq!(result, Ok((&input1[3..], "abc".to_string())));
    }
}
