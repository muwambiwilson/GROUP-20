
#ifndef SIMILARITY_HPP
#define SIMILARITY_HPP

#include "dataset.hpp"
#include <optional>

class SimilarityCalculator{
    private:
    static double median_off_diagonal(const Matrix& similarity);

    public:
    static Matrix negative_squared_euclidean(const Dataset& data);
    static void initialize_preferences(Matrix& similarity, const
    std::optional<double>& preference);

};

#endif
