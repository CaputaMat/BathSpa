# S2 — Utility App
**Language:** C++

A console-based **Vending Machine** application that demonstrates the more advanced techniques covered in the module — functions, error checking, and object-oriented programming — built on top of the fundamentals from [S1](../CodeLab(AS1)/).

The machine is modelled as a **rectangular grid of slots** identified by a column letter and a row number (e.g. `A1`, `B3`). Each slot may hold a single `Product` or be empty. The grid is rendered as an ASCII table centred on the terminal width.

---

## Project Layout

| Path | Description |
| --- | --- |
| [CMakeLists.txt](CMakeLists.txt) | CMake build configuration — C++17, project name `vending_machine`, strict compiler warnings. |
| [src/main.cpp](src/main.cpp) | Entry point — constructs a `VendingMachine`, stocks slots with products, and renders the grid to `stdout`. |
| [include/VendingMachine.h](include/VendingMachine.h) | `VendingMachine` class — owns a labelled grid of `GridSlot` objects keyed by slot label (e.g. `"A1"`). |
| [src/VendingMachine.cpp](src/VendingMachine.cpp) | `VendingMachine` implementation — grid construction, `stock()` placement, ASCII `render()` (with UTF-8 aware width calculation). |
| [include/GridSlot.h](include/GridSlot.h) | `GridSlot` class — one slot in the grid: column letter, row number, computed label, and an `std::optional<Product>`. |
| [src/GridSlot.cpp](src/GridSlot.cpp) | `GridSlot` implementation — constructor and `label()` builder. |
| [include/Product.h](include/Product.h) | `Product` class — name, price, and nested `Product::Category` enum (`DRINK`, `SNACK`) with `toString` helper. |
| [src/Product.cpp](src/Product.cpp) | `Product` implementation. |
| [include/Utils.h](include/Utils.h) | Cross-platform console helpers — terminal width, centred output, screen clear. |
| [src/Utils.cpp](src/Utils.cpp) | `Utils` implementation — Windows (`<windows.h>`) and POSIX (`<sys/ioctl.h>`) backends. |
| [tests/](tests/) | Unit tests. |
| `build/` | CMake build artifacts (generated, not tracked). |

---

## Domain Model

```
VendingMachine
├── machine_label : std::string
├── columns, rows : int
└── grid : std::map<std::string, GridSlot>     // keyed by slot label, e.g. "A1"
        │
        └── GridSlot
            ├── column_label : char            // 'A', 'B', ...
            ├── row_label    : int             // 1, 2, ...
            └── product      : std::optional<Product>
                                │
                                └── Product
                                    ├── label    : std::string
                                    ├── price    : double
                                    └── category : Product::Category {DRINK, SNACK}
```

Slot labels are **unique by construction** — `std::map` enforces it at the type level. Empty slots are represented by `std::optional<Product>` having no value.

---

## Building and Running

The project uses **CMake** (≥ 3.10) with C++17. To configure, build, and run:

```bash
cmake -S . -B build
cmake --build build
./build/vending_machine
```

To rebuild after changes, re-run `cmake --build build`. Strict warnings are enabled (`-Wall -Wextra -Wpedantic` on GCC/Clang, `/W4` on MSVC).

---

## Assignment Brief

Your task is to create a **Vending Machine** program using the C++ programming language.

The Vending Machine must include the following minimum features:

* A menu of drinks and snacks presented via the console. The number and range of items is up to you.
* A set of codes that the user can input to select a particular drink or snack.
* A way of capturing the user's inputted code.
* A way of managing money — the user should be able to input any amount and have the correct change returned.
* A message that tells the user that a particular drink or snack has been dispensed.
* A message that tells the user how much change they have received.
* Comments in the code to explain key operations.

Higher marks are available for additional advanced features such as:

* Categorising menu items to improve the user experience (e.g. *Chocolate*, *Hot Drinks*).
* Allowing users to buy additional items in the same session.
* Appropriate error checking to validate inputs and ensure the user has enough credit.
* An intelligence system for suggesting purchases (e.g. suggesting biscuits after a coffee).
* A stock system so the machine may run out of products.

To achieve marks in the higher boundaries, the implementation should make use of functions and object-oriented programming.

---

## Deliverables

### The Application

The C++ source code (under `src/` and `include/`), the `CMakeLists.txt` build configuration, and any supplementary assets required to run the vending machine. Submitted as a project saved to this folder and pushed to GitHub before the deadline.

### Development Document

A 1,000–1,500 word document accompanying the code, containing:

* **Specification** *(≈100 words)* — what the program does, the feature list, and a link to the GitHub repository.
* **System Flowchart** *(≈50 words)* — visual depiction of the program's logical flow with a short explanation.
* **Technical Description & Walkthrough** *(500–800 words)* — a 5–8 minute video walkthrough showing the program running and a technical breakdown of the key features. (Approx. 100 words/min counts toward the word total.)
* **Critical Reflection** *(≈250 words)* — what works well, what could be improved, and what skills are needed to make those improvements.
* **Appendix** *(not counted)* — a copy of the source code.
