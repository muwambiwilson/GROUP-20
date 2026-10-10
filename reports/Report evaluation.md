Overview and importance of evaluation.hpp

The evaluation.hpp header declares functions for evaluating Affinity Propagation results, including determining the number of identified clusters.


 
It uses header guards and includes <vector> and <cstddef>.
The main declaration is:
std::size_t cluster_count(const std::vector<std::size_t>& labels);
This function returns the number of unique cluster labels.


Implemented in src/evaluation.cpp with std::unordered_set, it removes duplicate labels and counts the remaining entries. Its average time complexity is O(N).

Integration with the Project
main.cpp can call this function to display the cluster count, keeping evaluation separate from the clustering process.




