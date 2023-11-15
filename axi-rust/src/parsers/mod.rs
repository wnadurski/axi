pub type ParseResult<'a, Token, T> = Result<(&'a [Token], T), String>;

pub trait Parser<'a, Token, T> {
    fn parse(&self, input: &'a [Token]) -> ParseResult<'a, Token, T>;
}
impl<'a, F, Token: 'a, T> Parser<'a, Token, T> for F
where
    F: Fn(&'a [Token]) -> ParseResult<'a, Token, T>,
{
    fn parse(&self, input: &'a [Token]) -> ParseResult<'a, Token, T> {
        self(input)
    }
}

#[cfg(test)]
mod tests {
    use crate::parsers::{ParseResult, Parser};

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
}
