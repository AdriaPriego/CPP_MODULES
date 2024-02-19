/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:15:34 by codespace         #+#    #+#             */
/*   Updated: 2024/02/19 16:36:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

int main(int ac, char **av)
{
    if (ac < 3)
    {
        std::cout << "Bad arguments." << std::endl;
        return (1);
    }
    else
    {
        std::vector<unsigned int> vec;
        std::deque<unsigned int> deq;
        try
        {
            vec = convertToVector(av, ac);
            std::cout << "Before: ";
            printContent(vec);
                        
            std::clock_t initVec = std::clock();
            merge_sort(vec, 0, vec.size());
            std::clock_t finVec = std::clock();

            std::cout << "After: ";
            printContent(vec);
            
            deq = convertToDeque(av, ac);
            std::clock_t initDeq = std::clock();
            merge_sort(deq, 0, deq.size());
            std::clock_t finDeq = std::clock();
            
            std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : ";
            std::cout << (static_cast< double >( finVec - initVec ) / CLOCKS_PER_SEC) * 1000000 << "us" << std::endl;
            std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : ";
            std::cout << (static_cast< double >( finDeq - initDeq ) / CLOCKS_PER_SEC) * 1000000 << "us" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }
    return (0);
}