#include "similarity.hpp"
#include <algorithm>

Matrix SimilarityCalculator::negative_squared_euclidean(const
    Dataset& data){
        std::size_t n = data.rows();
        std::size_t d = data.cols();
        const auto& values = data.get_values();
        Matrix s(n, std::vector<double>(n, 0.0));

        for (std::size_t i = 0;i < n;++i){
              for (std::size_t k = i; k < n; ++k) {
            double dist2 = 0.0;
            for (std::size_t j = 0; j < d; ++j) {
                const double diff = values[i][j] - values[k][j];
                dist2 += diff * diff;
            }
            const double value = -dist2;
            s[i][k] = value;
            s[k][i] = value;
        }
    }
    return s;
}

double SimilarityCalculator::median_off_diagonal(const Matrix& similarity) {
    std::vector<double> off_diag;
    std::size_t n = similarity.size();
    for (std::size_t i = 0; i < n; ++i) {
        for (std::size_t j = 0; j < n; ++j) {
            if (i != j) off_diag.push_back(similarity[i][j]);
        }
    }
    if (off_diag.empty()) return 0.0;
    std::sort(off_diag.begin(), off_diag.end());
    std::size_t mid = off_diag.size() / 2;
    if (off_diag.size() % 2 == 0) {
        return (off_diag[mid - 1] + off_diag[mid]) / 2.0;
    }
    return off_diag[mid];
}

void SimilarityCalculator::initialize_preferences(Matrix& similarity, const std::optional<double>& preference) {
    std::size_t n = similarity.size();
    const double p = preference.has_value() ? *preference : median_off_diagonal(similarity);
    for (std::size_t k = 0; k < n; ++k) {
        similarity[k][k] = p;
    }
}


    
