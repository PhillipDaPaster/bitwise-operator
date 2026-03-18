#pragma once

// ===================================================
//  bitwise wrapper 
// ===================================================

template<typename T = u32>
class bit {
public:
    T value;

    FORCEINLINE bit() noexcept : value(0) {}
    FORCEINLINE bit(T v) noexcept : value(v) {}

    FORCEINLINE bit& operator=(T v) noexcept {
        value = v;
        return *this;
    }

    FORCEINLINE operator T() const noexcept { return value; }

    // bitwise ops
    FORCEINLINE bit operator|(const bit& rhs) const noexcept { return bit(value | rhs.value); }
    FORCEINLINE bit operator&(const bit& rhs) const noexcept { return bit(value & rhs.value); }
    FORCEINLINE bit operator^(const bit& rhs) const noexcept { return bit(value ^ rhs.value); }
    FORCEINLINE bit operator~() const noexcept { return bit(~value); }

    FORCEINLINE bit& operator|=(const bit& rhs) noexcept { value |= rhs.value; return *this; }
    FORCEINLINE bit& operator&=(const bit& rhs) noexcept { value &= rhs.value; return *this; }
    FORCEINLINE bit& operator^=(const bit& rhs) noexcept { value ^= rhs.value; return *this; }

    // shifting
    FORCEINLINE bit operator<<(int shift) const noexcept { return bit(value << shift); }
    FORCEINLINE bit operator>>(int shift) const noexcept { return bit(value >> shift); }

    FORCEINLINE bit& operator<<=(int shift) noexcept { value <<= shift; return *this; }
    FORCEINLINE bit& operator>>=(int shift) noexcept { value >>= shift; return *this; }

    FORCEINLINE bool test(int pos) const noexcept {
        return (value >> pos) & (T)1;
    }

    FORCEINLINE void set(int pos, bool state = true) noexcept {
        T mask = (T)1 << pos;
        if (state)
            value |= mask;
        else
            value &= ~mask;
    }

    FORCEINLINE void toggle(int pos) noexcept {
        value ^= (T)1 << pos;
    }

    FORCEINLINE void clear() noexcept {
        value = 0;
    }

    FORCEINLINE bool any() const noexcept { return value != 0; }
    FORCEINLINE bool none() const noexcept { return value == 0; }

    FORCEINLINE bool all(T mask) const noexcept {
        return (value & mask) == mask;
    }
};
