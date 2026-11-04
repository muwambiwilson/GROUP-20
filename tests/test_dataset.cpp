#include "dataset.hpp"
#include "test_helpers.hpp"
#include <stdexcept>

int main() {
    // Normal case: dimensions
    Dataset d({{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}});
    CHECK(d.rows() == 3);
    CHECK(d.cols() == 2);

    // Standardization: each column has mean 0
    Dataset s = d.standardize();
    double mean0 = 0.0;
    for (const auto& row : s.get_values()) mean0 += row[0];
    CHECK_NEAR(mean0 / 3.0, 0.0, 1e-12);

    // Edge case: constant column becomes all zeros (no divide by zero)
    Dataset c({{1.0, 5.0}, {2.0, 5.0}, {3.0, 5.0}});
    CHECK_NEAR(c.standardize().get_values()[0][1], 0.0, 1e-12);

    // Invalid input
    CHECK_THROWS(Dataset(Matrix{}).validate(), std::runtime_error);
    CHECK_THROWS(Dataset({{1.0, 2.0}, {3.0}}).validate(), std::runtime_error);

    return TEST_RESULT();
}

