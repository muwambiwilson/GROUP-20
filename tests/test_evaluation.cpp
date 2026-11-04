#include "evaluation.hpp"
#include "test_helpers.hpp"
#include <vector>

int main() {
    // Normal case: multiple distinct cluster labels
    std::vector<std::size_t> labels1 = {0, 0, 1, 2, 1, 2};
    CHECK(ClusterEvaluator::cluster_count(labels1) == 3);

    // Edge case: all points belong to a single cluster
    std::vector<std::size_t> labels2 = {4, 4, 4, 4};
    CHECK(ClusterEvaluator::cluster_count(labels2) == 1);

    // Edge case: every point is its own cluster
    std::vector<std::size_t> labels3 = {0, 1, 2, 3};
    CHECK(ClusterEvaluator::cluster_count(labels3) == 4);

    // Edge case: empty labels vector
    std::vector<std::size_t> labels_empty = {};
    CHECK(ClusterEvaluator::cluster_count(labels_empty) == 0);

    return TEST_RESULT();
}
