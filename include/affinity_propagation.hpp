#ifndef AFFINITY_PROPAGATION_HPP
#define AFFINITY_PROPAGATION_HPP

#include "dataset.hpp"
#include <optional>

struct APConfig {
double damping = 0.5;
std::size_t max_iterations = 500;
std::size_t convergence_iterations = 15;
std::optional<double> preference;
};

struct APResult{
std::vector<std::size_t> exemplars;
std::vector<std::size_t> labels;
Matrix similarity;
Matrix responsibilities;
Matrix availabities;
std::size_t iterations = 0;
bool converged = false;
};
class AffinityPropagation {
private:
    APConfig config_;

    static std::vector<std::size_t> find_exemplars(const Matrix& a, const Matrix& r);
    static bool same_vector(const std::vector<std::size_t>& v1, const std::vector<std::size_t>& v2);

public:
    explicit AffinityPropagation(APConfig config);
    APResult run(const Dataset& data);
};

#endif

