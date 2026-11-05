#ifndef TEST_HELPERS_HPP
#define TEST_HELPERS_HPP

#include <cmath>
#include <iostream>

// Tiny test helper (no external dependencies).
inline int g_failures = 0;

#define CHECK(cond)                                                          \
    do {                                                                     \
        if (!(cond)) {                                                       \
            std::cerr << "FAILED: " #cond " (" << __FILE__ << ":" << __LINE__ \
                      << ")\n";                                              \
            ++g_failures;                                                    \
        }                                                                    \
    } while (0)

#define CHECK_NEAR(a, b, eps) CHECK(std::fabs((a) - (b)) < (eps))

// Passes if `expr` throws exceptions of type `ex`.
#define CHECK_THROWS(expr, ex)                                               \
    do {                                                                     \
        bool thrown = false;                                                 \
        try { expr; } catch (const ex&) { thrown = true; }                   \
        CHECK(thrown);                                                       \
    } while (0)

#define TEST_RESULT() \
    (g_failures == 0 ? (std::cout << "All tests passed\n", 0) : 1)

#endif
