#include "affinity_propagation.hpp"
#include "evaluation.hpp"
#include "test_helpers.hpp"
#include <stdexcept>

int main() {
    // Two obvious groups: points 0-2 and points 3-5
    Dataset data({{1.0, 2.0}, {1.2, 1.8}, {0.8, 2.1},
                  {8.0, 8.0}, {8.2, 8.1}, {7.9, 7.8}});

    APConfig config;
    config.damping = 0.7;
    config.preference = -3.0;
    APResult r = AffinityPropagation(config).run(data);

    CHECK(r.converged);
    CHECK(ClusterEvaluator::cluster_count(r.labels) == 2);
    CHECK(r.labels[0] == r.labels[1] && r.labels[1] == r.labels[2]);
    CHECK(r.labels[3] == r.labels[4] && r.labels[4] == r.labels[5]);
    CHECK(r.labels[0] != r.labels[3]);

    // Every exemplar must be labelled with itself
    for (std::size_t k : r.exemplars) CHECK(r.labels[k] == k);

    // Invalid input
    CHECK_THROWS(AffinityPropagation(config).run(Dataset(Matrix{})), std::runtime_error);

    return TEST_RESULT();
}
