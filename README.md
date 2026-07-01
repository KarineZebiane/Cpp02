# CPP Module 02 — Ad-hoc Polymorphism, Operator Overloading & Orthodox Canonical Form

42 Beirut project implementing a fixed-point number class (`Fixed`) in C++98,
progressively fleshed out across three exercises.

## Overview

Fixed-point numbers store a fractional value in an integer, reserving a fixed number
of bits for the fractional part. This project builds a `Fixed` class from the ground
up: first establishing the Orthodox Canonical Form, then adding conversions to/from
`int` and `float`, and finally overloading comparison, arithmetic, increment/decrement,
and stream insertion operators.

## Build

Each exercise has its own `Makefile`:

```bash
cd ex00   # or ex01, ex02
make
./Fixed
```

Standard rules apply: `make`, `make clean`, `make fclean`, `make re`.
Compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

## Exercises

### ex00 — Orthodox Canonical Form

Introduces `Fixed` with the four canonical member functions expected of any C++ class:

- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor

The fixed-point value is stored internally as an `int`, with `8` bits reserved for
the fractional part (`static const int fb = 8;`). Also provides:

- `int getRawBits(void) const` — returns the raw internal integer value
- `void setRawBits(int const raw)` — sets the raw internal integer value

Every member function prints a message identifying which one was called, to make
the canonical-form behavior visible when running `main.cpp`.

### ex01 — Fixed-Point Number

Extends `Fixed` with real value handling:

- `Fixed(const int i)` — constructs from an int, shifting into fixed-point representation
- `Fixed(const float f)` — constructs from a float, using `roundf` for conversion
- `float toFloat(void) const` — converts back to a floating-point value
- `int toInt(void) const` — converts back to an integer value
- `std::ostream& operator<<(std::ostream&, const Fixed&)` — prints the float value

At this point `Fixed` behaves like a usable numeric type that can be constructed,
converted, and printed.

### ex02 — Ad-Hoc Polymorphism / Operator Overloading

Completes the class with the full canonical operator set:

**Comparison:** `>`, `<`, `>=`, `<=`, `==`, `!=`

**Arithmetic:** `+`, `-`, `*`, `/`

**Increment / decrement:** `++a` / `a++`, `--a` / `a--` (both prefix and postfix,
distinguished by the `int` dummy parameter on the postfix versions)

**Min / max (static, both const and non-const overloads):**

```cpp
static const Fixed& min(const Fixed& f1, const Fixed& f2);
static Fixed&        min(Fixed& f1, Fixed& f2);
static const Fixed& max(const Fixed& f1, const Fixed& f2);
static Fixed&        max(Fixed& f1, Fixed& f2);
```

`main.cpp` exercises all of the above: increment/decrement chains, arithmetic between
two `Fixed`s, every comparison operator, and both `min`/`max` overloads.

> Note: division by zero is undefined behavior here — the subject explicitly allows
> the program to crash in that case.

## Design notes

- The fractional precision is `8` bits (`1 << 8 = 256`), fixed as a private static
  member of the class.
- Float construction rounds rather than truncates, via `roundf(f * (1 << fp))`.
- `toInt`/raw-bit shifts rely on `>>`/`<<` on `int`, matching the C++98 constraints
  of the subject (no `<cstdint>`/fixed-width types required).
- All arithmetic operators return by value (a new `Fixed`), keeping the class
  immutable-friendly aside from the mutating increment/decrement operators.

## Files

```
ex00/  Makefile  main.cpp  Fixed.hpp  Fixed.cpp
ex01/  Makefile  main.cpp  Fixed.hpp  Fixed.cpp
ex02/  Makefile  main.cpp  Fixed.hpp  Fixed.cpp
```
