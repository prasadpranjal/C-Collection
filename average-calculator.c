/* C-Collection
 * Finding the average of the desired number of positive integers
    Copyright (C) 2025  Pranjal Prasad

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses
 */
#include <stdio.h>

int main() {
    int n;
    float sum = 0.0, num, average;

    // Input: total number of values
    printf("Enter the quantity of numbers: ");
    scanf("%d", &n);

    // Check if the input is valid
    if (n <= 0) {
        printf("Please enter a valid positive number for the quantity.\n");
        return 1;
    }

    // Input numbers and calculate their sum
    for (int i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%f", &num);
        sum += num;
    }

    // Calculate the average
    average = sum / n;

    // Output the result
    printf("The average of the given numbers is: %.2f\n", average);

    return 0;
}
