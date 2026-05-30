#pragma once
#include <type_traits>

// ===================================================
//  bitwise wrapper 
// ===================================================

template<typename T = u32>
class bit {
    static_assert(std::is_integral_v<T>, "bit<T> requires an integral type");

public:
    T value;

    // constructors
    constexpr bit() noexcept : value(0) {}
    constexpr bit(T v) noexcept : value(v) {}

    constexpr bit& operator=(T v) noexcept {
        value = v;
        return *this;
    }

    explicit constexpr operator T() const noexcept {
        return value;
    }

    // bitwise ops (bit vs bit)
    constexpr bit operator|(const bit& rhs) const noexcept { return bit(value | rhs.value); }
    constexpr bit operator&(const bit& rhs) const noexcept { return bit(value & rhs.value); }
    constexpr bit operator^(const bit& rhs) const noexcept { return bit(value ^ rhs.value); }
    constexpr bit operator~() const noexcept { return bit(static_cast<T>(~value)); }

    constexpr bit& operator|=(const bit& rhs) noexcept { value |= rhs.value; return *this; }
    constexpr bit& operator&=(const bit& rhs) noexcept { value &= rhs.value; return *this; }
    constexpr bit& operator^=(const bit& rhs) noexcept { value ^= rhs.value; return *this; }

    // bitwise ops (bit vs raw)
    constexpr bit operator|(T rhs) const noexcept { return bit(value | rhs); }
    constexpr bit operator&(T rhs) const noexcept { return bit(value & rhs); }
    constexpr bit operator^(T rhs) const noexcept { return bit(value ^ rhs); }

    constexpr bit& operator|=(T rhs) noexcept { value |= rhs; return *this; }
    constexpr bit& operator&=(T rhs) noexcept { value &= rhs; return *this; }
    constexpr bit& operator^=(T rhs) noexcept { value ^= rhs; return *this; }

    // shifting
    constexpr bit operator<<(int shift) const noexcept { return bit(value << shift); }
    constexpr bit operator>>(int shift) const noexcept { return bit(value >> shift); }

    constexpr bit& operator<<=(int shift) noexcept { value <<= shift; return *this; }
    constexpr bit& operator>>=(int shift) noexcept { value >>= shift; return *this; }

    // bit helpers (single bit)
    constexpr bool test(int pos) const noexcept {
        return (value >> pos) & static_cast<T>(1);
    }

    constexpr void set(int pos, bool state = true) noexcept {
        const T mask = static_cast<T>(1) << pos;
        if (state)
            value |= mask;
        else
            value &= ~mask;
    }

    constexpr void toggle(int pos) noexcept {
        value ^= (static_cast<T>(1) << pos);
    }

    // bit helpers (mask-based)
    constexpr bool has(bit mask) const noexcept {
        return (value & mask.value) == mask.value;
    }

    constexpr bool any() const noexcept {
        return value != 0;
    }

    constexpr bool none() const noexcept {
        return value == 0;
    }

    constexpr bool all(T mask) const noexcept {
        return (value & mask) == mask;
    }

    constexpr bool all(bit mask) const noexcept {
        return (value & mask.value) == mask.value;
    }

    // utilities
    constexpr void clear() noexcept {
        value = 0;
    }
};
