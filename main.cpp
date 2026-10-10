#include <iostream>
#include "dataset.hpp"
#include "affinity_propagation.hpp"
#include "evaluation.hpp"

int main(){
    std::cout <<"---Affinity Propagation Clustering---"<<std::endl;
    Dataset data;
    data.values={
        {1.0,2.0},
        {1.2,1.8},
        {0.8,2.1},
        {8.0,8.0},
        {8.2,8.1},
        {7.9,7.8},
    };
    APConfig config;
    config.damping=0.7;
    config.preference=-3.0;
    config.max_iterations=500;
    config.convergence_iterations=15;

    APResult result = run_affinity_propagation(data,config);
    std::cout<<"\n --- Execution Output ---"<<std::endl;
    std::cout<<"Converged:"<<(result.converged?"Yes":"No")<<std::endl;
    std::cout<<"Total Iterations:"<<result.iterations<<std::endl;
    std::cout<<"Number of Clusters Identified:"<<cluster_count(result.labels)<<std::endl;

    return 0;
} 
