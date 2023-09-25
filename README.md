Awascript
=========

*awawawawa*

Awascript is a small esoteric programming language that transpiles to brainfuck. In awascript, each of Brainfuck's 8 command characters are represented by an "awa" with varying capitalization. All other characters are ignored as whitespace.

|awa|character|
|---|---------|
|awa|        >|
|awA|        <|
|aWa|        +|
|aWA|        -|
|Awa|        .|
|AwA|        ,|
|AWa|        [|
|AWA|        ]|

As an example,

```sh
$cat example/hello.awa
aWA AWa aWA aWA aWA aWA aWA aWA aWA awa aWa awA AWA awa aWA Awa
aWA AWa aWA awa aWa aWa aWa aWa aWa awA AWA awa aWa aWa Awa aWa
aWa aWa aWa aWa aWa aWa Awa Awa aWa aWa aWa Awa AWa aWA aWA aWA
awa aWa awA AWA awa aWA aWA aWA aWA aWA Awa aWA aWA aWA AWa aWA
awa aWa aWa aWa awA AWA awa Awa aWA AWa aWA aWA aWA awa aWa awA
AWA awa aWA aWA aWA Awa aWa aWa aWa Awa aWA aWA aWA aWA aWA aWA
Awa aWA aWA aWA aWA aWA aWA aWA aWA Awa
$cat example/hello.awa | awascript | bf
Hello World
```

##Install
```sh
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
sudo cmake --install build
```
