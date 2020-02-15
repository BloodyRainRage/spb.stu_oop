// lab3_2.cpp 
// by BadDragon on 15.02.2020 in educational purpose
/*task:
*2.	Разработайте программу, которая
*a.Заполняет list < int> 15 случайными значениями от 1 до 20, список может 
 содержать от 0 до 20 значений(обязательно проверить на длине списка 0, 1. 2, 3, 4, 5, 7, 14)
*b.Выводит содержимое списка в следующем порядке : первый элемент, последний элемент, второй 
 элемент, предпоследний элемент, тритий элемент и т.д.
*
*Например если список содержит :
*1 2 3 4 5 6 7 8
*то вывод будет иметь вид
*1 8 2 7 3 6 4 5
*/

#include <time.h>
#include <iostream>
#include "Solution.h"
#include <conio.h>


int main()
{
    srand(time(NULL));
    Solution* sol = new Solution(13);
    sol->append(14);
    sol->regularPrint();
    std::cout << std::endl << sol->length() << std::endl;  
    sol->regularPrint();

    sol->print();
    _getch();
}
