#include <iostream>
#include <cassert>

int toggle_bit(int n, unsigned pos) { return n ^ (1 << pos); }
int set_bit(int n, unsigned pos) { return n | (1 << pos); }
int clear_bit(int n, unsigned pos) { return n & ~(1 << pos); }
bool is_bit_set(int n, unsigned pos) { return (n >> pos) & 1; }

int set_multiple_bits(int n, int mask) { return n | mask; }
int clear_multiple_bits(int n, int mask) { return n & ~mask; }
int toggle_multiple_bits(int n, int mask) { return n ^ mask; }

int main()
{
    // It(toggle_a_single_bit)
    assert(toggle_bit(5, 0u) == (4) && ("Incorrect output for toggle_bit(5, 0u) [must toggle on bit #0]:"));
    assert(toggle_bit(5, 1u) == (7) && ("Incorrect output for toggle_bit(5, 1u) [must toggle off bit #1]:"));

    // It(set_a_single_bit)
    assert(set_bit(5, 1u) == (7) && ("Incorrect output for set_bit(5, 1u) [must turn on bit]:"));
    assert(set_bit(5, 2u) == (5) && ("Incorrect output for set_bit(5, 2u) [bit already on, so no change needed]:"));

    // It(clear_a_single_bit)
    assert(clear_bit(7, 1u) == (5) && ("Incorrect output for clear_bit(7, 1u) [must toggle off bit]:"));
    assert(clear_bit(9, 1u) == (9) && ("Incorrect output for clear_bit(9, 1u) [bit already off, so no change needed]:"));

    // It(check_whether_a_bit_is_set)
    assert(is_bit_set(5, 0u) == (true) && ("Incorrect output for is_bit_set(5, 0u):"));
    assert(is_bit_set(5, 1u) == (false) && ("Incorrect output for is_bit_set(5, 1u):"));

    // It(set_multiple_bits_by_masking)
    assert(set_multiple_bits(40, 26u) == (58) && ("Incorrect output for set_multiple_bits(40, 26u):"));

    // It(clear_multiple_bits_by_masking)
    assert(clear_multiple_bits(101, 52u) == (65) && ("Incorrect output for clear_multiple_bits(101, 52u):"));

    // It(toggle_multiple_bits_by_masking)
    assert(toggle_multiple_bits(101, 52u) == (81) && ("Incorrect output for toggle_multiple_bits(101, 52u):"));

    return 0;
}