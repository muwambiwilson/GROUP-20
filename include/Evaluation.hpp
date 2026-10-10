include/evaluation.hpp 
  #ifndef EVALUATION_HPP 
  #define EVALUATION_HPP 

  #include <vector>
  #include<cstddef>

  class ClusterEvaluator {
  public:
static std::size_t cluster_count(const std::vector<std::size_t>& labels);
};

#endif

