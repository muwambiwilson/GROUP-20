
#include "evaluation.hpp"
#include <vector>
#include <unordered_set>

std::size_t cluster_count(const std::vector<std::size_t>& labels) {
    std::unordered_set<std::size_t> unique(labels.begin(), labels.end());
    return unique.size();
}
