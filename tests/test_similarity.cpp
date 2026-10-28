#include "affinity_propagation/similarity.hpp"
#include "test_helpers.hpp"

int main() {
    Dataset d({{0.0, 0.0}, {3.0, 4.0}});
    Matrix s = SimilarityCalculator::negative_squared_euclidean(d);

    CHECK_NEAR(s[0][1], -25.0, 1e-12);   // -(3^2 + 4^2)
    CHECK_NEAR(s[0][1], s[1][0], 1e-12); // symmetric

    SimilarityCalculator::initialize_preferences(s, -7.0);
    CHECK_NEAR(s[0][0], -7.0, 1e-12);    // custom preference on diagonal

    // No preference given -> median of off-diagonal values (-25 here)
    SimilarityCalculator::initialize_preferences(s, std::nullopt);
    CHECK_NEAR(s[1][1], -25.0, 1e-12);

    return TEST_RESULT();
}
