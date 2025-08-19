# Corozive ⚡️
**Modern C, with extra features. As simple as C**

## The goals 🎯
- Add a sugar syntax on top of C to allow sweet stuff like this:
    ```c
    typedef struct _foo {
        int value;
        Foo(int value) {
            return {
                value;
            }
        }

        int getValue(struct _foo* self) {
            return self.value;
        }
    } Foo;
    ```

    ```c
    Foo test = Foo(42);

    println("Value is : {}", test.getValue());
    ```

- Add RAII and operator overload

- A mutli-purpose cli (similar to npm) that will init, build, add package

- Optional LSP support for editors (Neovim, VSCode and more to come)

## How it works
Thanks to a transpiler that extends C features

## Pipeline overview
- src/*.c -> corozive sugar syntax
- cpm build -> transpile -> c99
- auto-generated makefile -> build -> executable
- Packages added via `cpm add <pkg>` (e.g, Raylib)
- Proxy LSP for autocompletion and diagnostics


## Quick start
```sh
cpm init

cpm add raylib

cpm build

cpm run
```

## Current status and roadmap
| Phase | Status | Description |
| ----- | ------ | ----------- |
| Transpiler | In Progress | Sugar syntax, RAII, operator overload |
| CLI | In Progress | `init`, `add`, `build`, `run` commands |
| Package manager (cpm) | Upcoming | Install packages from github / registry |
| Build system | Upcoming | Auto makefile generation & compilation |
| LSP Integation | Upcoming | Proxy LSP for Neovim and vscode |
| Examples and docs | Upcoming | Mini projects, tutorials, pipeline diagrams |

## Next steps
- Complete constructors, destructors, operator overload in transpiler
- Implement dynamic package handling in cpm add
- Multiplatform build workflow (Linux / MacOS / Windows)
- Create example projects demonstrating RAII & sugar syntax

## For purist
As you could understand, corozive generates pure C code under the hood, so if you prefer, you can disable sugar syntax handling in corozive.toml
And everything remains fully compatible with standard C.
```toml
[sugar]
enabled=true #default value
```
> Corozive isn't "C for babies"
> It's modern, readable, safe C, fully transpiled for performances
