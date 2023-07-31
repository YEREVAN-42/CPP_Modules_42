/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:21:12 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/28 20:43:19 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

// #define MAX_VAL 750
// int main()
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }



int main()
{
    Array<int> a;
    
    Array<int> arr(5);

    for (std::size_t i = 0; i < arr.size(); ++i) {
        arr[i] = i;
    }

    for (std::size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;

    a = arr;

    for (std::size_t i = 0; i < arr.size(); ++i) {
        std::cout << a[i] << "  ";
    }
    std::cout << std::endl;

    const Array<int> ca(arr);

    for (std::size_t i = 0; i < arr.size(); ++i) {
        std::cout << ca[i] << "  ";
    }
    std::cout << std::endl;


    try {
        std::cout << ca[-2] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
