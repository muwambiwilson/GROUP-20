
#include "affinity_propagation.hpp"
#include "similarity.hpp"
#include <limits>
#include <algorithm>
AffinityPropagation::AffinityPropagation(APConfig config) : config_(config) {}
std::vector<std::size_t> AffinityPropagation::find_exemplars(const Matrix& a, const Matrix& r) {
    const std::size_t n = a.size();
    std::vector<std::size_t> ex;
    for (std::size_t k = 0; k < n; ++k) {
        if (a[k][k] + r[k][k] > 0.0)
            ex.push_back(k);
    }
    return ex;
}
bool AffinityPropagation::same_vector(const std::vector<std::size_t>& v1, const std::vector<std::size_t>& v2) {
    return v1 == v2;
}
APResult AffinityPropagation::run(const Dataset& data) {
    Dataset std_data = data.standardize();
    std::size_t n = std_data.rows();
    APResult result;
    result.similarity = SimilarityCalculator::negative_squared_euclidean(std_data);
    SimilarityCalculator::initialize_preferences(result.similarity, config_.preference);

    result.responsibilities = Matrix(n, std::vector<double>(n, 0.0));
    result.availabilities = Matrix(n, std::vector<double>(n, 0.0));

    std::vector<std::size_t> previous_exemplars;
    std::size_t stable = 0;
    for (std::size_t iter = 0; iter < config_.max_iterations; ++iter) {
        result.iterations = iter + 1;
        // Responsibility Update
        for (std::size_t i = 0; i < n; ++i) {
            double largest = -std::numeric_limits<double>::infinity();
            double second = -std::numeric_limits<double>::infinity();
            std::size_t argmax = 0;
            for (std::size_t k = 0; k < n; ++k) {
                const double val = result.availabilities[i][k] + result.similarity[i][k];
                if (val > largest) {
                    second = largest;
                    largest = val;
                    argmax = k;
                } else if (val > second) {
                    second = val;
                }
            }
            for (std::size_t k = 0; k < n; ++k) {
                const double max_other = (k == argmax) ? second : largest;
                const double raw = result.similarity[i][k] - max_other;
                result.responsibilities[i][k] = config_.damping * result.responsibilities[i][k] + (1.0 - config_.damping) * raw;
            }
        }
        // Availability Update
        Matrix new_a = result.availabilities;
        for (std::size_t k = 0; k < n; ++k) {
            double positive_sum = 0.0;
            for (std::size_t i = 0; i < n; ++i) {
                if (i != k) positive_sum += std::max(0.0, result.responsibilities[i][k]);
            }
            for (std::size_t i = 0; i < n; ++i) {
                if (i == k) {
                    const double raw = positive_sum;
                    new_a[k][k] = config_.damping * result.availabilities[k][k] + (1.0 - config_.damping) * raw;
                } else {
                    const double raw = std::min(0.0, result.responsibilities[k][k] + positive_sum - std::max(0.0, result.responsibilities[i][k]));
                    new_a[i][k] = config_.damping * result.availabilities[i][k] + (1.0 - config_.damping) * raw;
                }
            }
        }
        result.availabilities = new_a;
        // Convergence Detection
        const auto exemplars = find_exemplars(result.availabilities, result.responsibilities);
        if (same_vector(exemplars, previous_exemplars)) {
            ++stable;
        } else {
            stable = 0;
        }
        previous_exemplars = exemplars;

        if (stable >= config_.convergence_iterations) {
            result.exemplars = exemplars;
            result.converged = true;
            break;
        }
    }
    if (result.exemplars.empty()) {
        result.exemplars = find_exemplars(result.availabilities, result.responsibilities);
    }
    // Cluster Assignment
    result.labels.resize(n);
    if (!result.exemplars.empty()) {
        for (std::size_t i = 0; i < n; ++i) {
            std::size_t best = result.exemplars.front();
            double best_score = result.similarity[i][best];
            for (std::size_t k : result.exemplars) {
                const double score = result.similarity[i][k];
                if (score > best_score) {
                    best_score = score;
                    best = k;
                }
            }
            result.labels[i] = best;
        }
    }
    return result;
}
