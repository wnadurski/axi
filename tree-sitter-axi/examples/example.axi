from http import createServer, response, * as http;
from IO import IO, * as io;
from utils/http/tests import testing;
from ./utils/testing import test;

hostname = '127.0.0.1'
port = 3000

export main: IO<Unit> = do {
    server <- createServer((req) -> response.do {
      response.writeHead(200, { 'Content-Type': 'text/plain' })
      response.end('Hello World\n')
    })

    server.listen(port, hostname, console.log('Server running at http://${hostname}:${port}/'))
}

main: IO<Unit> = createServer((req) ->
    response.writeHead(200, { 'Content-Type': 'text/plain' })
    *> response.end('Hello World\n')
  )
  >> io.flatMap(server -> server.listen(port, hostName, ...))

export type Person = {
    name: String,
    age: Int
}

export type Functor = <F: * => *> => {
    map: <a, b> => (a -> b) -> F<a> -> F<b>
}

export enum IO<a> = IO(a)
type IO = <a> => {tag: 'IO', value: a}
export enum Either<a, b> = Left(a) | Right(b)
enum Unit = unit
export newtype PLN = hidden PLN(Float)

functorIO: Functor<IO> = {
    map: (f, io) -> match(io) {
        IO(a) -> IO(f(a))
        else -> IO(unit)
    }
}

type Increase = <F> => (Functor<F>, F<Int>) -> F<Int>
increase: Increase = (functor, f) -> f >> functor.map((x) -> x + 1)
increase: <F> => (Functor<F>, F<Int>) -> F<Int> = functor -> functor.map((x) -> x + 1)

someArr: Array<Int> = [1,2,3]

functorArr: Functor<Array> = {
    map: (f, arr) -> match(arr) {
        [] -> [],
        [x, ...xs] -> [f(x), ...functorArr.map(f, xs)]
    }
}

increased = increase(functorArr, someArr)

type Monad<M> = Functor<M> & {
    flatMap: <a, b> => (a -> M<a>) -> M<a> -> M<b>
    (>>=): <a, b> => (M<a>, a -> M<b>) -> M<b>
}
repeat: <M: Type => Type> => (Monad<M>, M<Int>) -> M<Int> = (monad, m) -> do(monad) {
    x <- m
    y <- m
    z = 10
    x + y + z
}

repeat = (monad, m) -> do(monad) {
    x <- m
    y <- m
    z = 10
    x + y + z
}


repeated = repeat(monadArr, [1, 2])) == [1,2] >> m.flatMap(x => [1,2].map(y => x + y))

functorEither = {
    map: (f, either) -> match(either) {
        Left(a) -> Left(a),
        Right(b) -> Right(f(b))
    }
}

monadEither = {
    ...functorEither,
    flatMap: (f, either) -> match(either) {
        Left(a) -> Left(a),
        Right(b) -> f(b)
    }
}
export (>>=): <e, a, b> => (Either<e, a>, a -> Either<e, b>) -> Either<e, b> = flip(monadEither.flatMap)
export (<$>): <e, a, b> => (a -> b, Either<e, a>) -> Either<e, b> = functorEither.map


(x -> x + 1) <$> [1, 2, 3] == [2, 3, 4]
[1, 2, 3] >>= (x -> [x + 1]) == [2, 3, 4]
[1,2,3] `Arr.(>>=) (x -> [x + 1]) == [2, 3, 4]
