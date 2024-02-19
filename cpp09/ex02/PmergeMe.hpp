/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:20:08 by codespace         #+#    #+#             */
/*   Updated: 2024/02/19 16:34:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <deque>
#include <climits>

int isInt(const std::string& literal);
int countOcurs(const std::string literal, const char toFind);
std::vector<unsigned int> convertToVector(char **av, int ac);
std::deque<unsigned int> convertToDeque(char **av, int ac);
template <typename T>
void insertionSort(T &cont)
{
    for (unsigned int step = 0; step < cont.size(); step++)
    {
        unsigned int key = cont[step];
        int j = step - 1;
        while (j >= 0 && key < cont[j])
        {
            cont[j + 1] = cont[j];
            j--;
        }
        cont[j + 1] = key;
    }
}

template <typename T>
void	merge(T &cont, int left, int mid, int right)
{  
    T temp(right - left + 1);
    int i = left, j = mid+1, k = 0;
    while (i <= mid && j <= right) 
    {
        if (cont[i] <= cont[j])
            temp[k++] = cont[i++];
        else
            temp[k++] = cont[j++];
    }
    while (i <= mid)
        temp[k++] = cont[i++];
    while (j <= right)
        temp[k++] = cont[j++];
    for (int p = 0; p < k; p++)
    cont[left+p] = temp[p];
}

template <typename T>
void	merge_sort(T &cont, int beg, int end)
{
    int mid;

    if ((end - beg) > 5)  
    {
        mid = (beg+end)/2;  
        merge_sort(cont, beg, mid);  
        merge_sort(cont, mid+1, end);  
        merge(cont, beg, mid, end);  
    }
    else
        insertionSort(cont);
}

template <typename T>
void printContent(T &cont)
{
    for (typename T::iterator it = cont.begin(); it != cont.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}