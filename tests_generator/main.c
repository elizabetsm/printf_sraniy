//
// Created by Cody Seabass on 8/3/20.
//
#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("%0+184hdAAA\n", 1960560852);
	ft_printf("%0+184hdAAA\n", 1960560852);
}