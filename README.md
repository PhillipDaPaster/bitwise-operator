# bit<T> - Lightweight Bitwise Wrapper

A small, header-only C++ utility that wraps integral types and provides a clean, type-safe interface for bitwise operations, masking, and bit manipulation.

C++17 or newer

---

## Features

- Fully `constexpr` friendly
- Strongly typed bitwise operations
- Works with any integral type (`u32`, `int`, `uint64_t`, etc.)
- Bit manipulation helpers (test, set, toggle)
- Mask-based queries (`has`, `all`, `any`, `none`)
- Header-only and dependency-free (except `<type_traits>`)

---

## Usage

Basic Example
```cpp
#include "bit.hpp"

bit<u32> flags;

flags.set(1);
flags.set(3);

if (flags.test(3)) {
    // bit 3 is set
}

flags.toggle(1);

flags.clear();
```

Bitwise Operations
```cpp
bit<u32> a(0b0011);
bit<u32> b(0b0101);

auto c = a | b;   // OR
auto d = a & b;   // AND
auto e = a ^ b;   // XOR
auto f = ~a;      // NOT
```

Raw Value Operations
```cpp
bit<u32> a(0b0011);

a |= 0b1000;
a &= 0b0111;
a ^= 0b0101;
```

Shift Operations
```cpp
bit<u32> a(1);

a <<= 3;  // 0b1000
a >>= 1;  // 0b0100
```
## Bit Helpers

Single Bit
```cpp
bit<u32> flags(0);

flags.set(2);        // set bit 2
flags.toggle(2);     // flip bit 2

bool isSet = flags.test(2);
```

Mask-Based
```cpp
bit<u32> flags(0b1111);
bit<u32> mask(0b0110);

if (flags.has(mask)) {
    // all bits in mask are set
}

if (flags.any()) {
    // at least one bit set
}

if (flags.none()) {
    // no bits set
}

if (flags.all(0b1111)) {
    // exact match
}
```

# Design Notes
- bit<T> is a lightweight wrapper around an integral type.
- Designed for readability and safer bitwise operations.
- Implicit conversion is restricted; use static_cast<T>(bit) when needed.
