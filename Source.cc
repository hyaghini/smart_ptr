/*!
 * **************************************************
 * @file Source.cc
 * @brief Testing shared pointer in the main function.
 *
 * The shared_ptr class is used to define and test some
 * pointers inside the main function.
 *
 * @sa SmartPtrTemplate.h
 * @sa SmartPtrTemplate.cc
 *
 * @section  LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * https://www.gnu.org/copyleft/gpl.html
 * 
 * @author Hamed Yaghini (hamed84.yaghini@gmail.com)
 * @date 03/20/2019
 * 
 * ****************************************************
 */



#include "SmartPtrTemplate.h"


int main()
{
//    double *int1 = new double;
//    *int1 = 1;

    {
        using namespace new_ptr;
        shared_ptr<double> p1 = make_shared<double> (9.6);
        shared_ptr<double> p2 = p1;
    }

    {
        using namespace std;
        shared_ptr<double> p1 = make_shared<double> (9.6);
        shared_ptr<double> p2 = p1;
    }



    return 0;
}
