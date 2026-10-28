#include "affinity_propagation.hpp"
#include "dataset.hpp"
#include "evaluation.hpp"

#include <iostream>

int main() {
    Dataset data({
        {1.0, 1.0}, {1.2, 0.9}, {0.8, 1.1}, {1.1, 1.3},
        {8.0, 8.0}, {8.2, 7.9}, {7.8, 8.1}, {8.1, 8.3}
    });

    APConfig config;
    config.damping = 0.7;
    config.max_iterations = 500;
    config.convergence_iterations = 15;
    config.preference = -3.0;

    AffinityPropagation model(config);
    const auto result = model.run(data);

    std::cout << "Converged: " << std::boolalpha << result.converged << "\n";
    std::cout << "Iterations: " << result.iterations << "\n";
    std::cout << "Exemplars: ";
    for (auto e : result.exemplars) std::cout << e << ' ';
    std::cout << "\nClusters: "
              << ClusterEvaluator::cluster_count(result.labels) << "\n";

    std::cout << "Labels: ";
    for (auto label : result.labels) std::cout << label << ' ';
    std::cout << "\n";

    return 0;
}
