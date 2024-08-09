#include <stdio.h>
#include <stdlib.h>
int main()
{
	int matriz[35][7], i, j, totalSemana;
	int somaLin, somaCol, qtdmenosProd, qtdmaisProd;
	int diamenosProd, diamaisProd, vacamaisProd, qtdvacamaisProd;
	
	printf ("FAZENDA CAPAXO BAXO INC.\n========================\n");
	
	// leitura da matriz e cálculo do total produzido na semana
	for (j = 0; j < 7; j++)
	{
		for (i = 0; i < 35; i++)
		{
			printf ("DIA %d / VACA %d: ", j+1, i+1);
			scanf ("%d", &matriz[i][j]);
			totalSemana = totalSemana + matriz[i][j];
		}
		printf ("\n");
	}
	system ("cls");
	printf ("FAZENDA CAPAXO BAXO INC.\n========================\n");
	
	// impressão da matriz
	printf ("As linhas representam as vacas, e as colunas, os dias da semana (valores em litros)\n\n");
	for (i = 0; i < 35; i++)
	{
		for (j = 0; j < 7; j++)
		{
			printf ("%d ", matriz[i][j]);
		}
		printf ("\n");
	}
	printf ("\nRELATORIO SEMANAL\n================");
	
	// soma das colunas e cálculo dos dias em que a fazenda menos produziu e mais produziu
	for (j = 0; j < 7; j++)
	{
		somaCol = 0;
		for (i = 0; i < 35; i++)
		{
			somaCol = somaCol + matriz[i][j];
		}
		printf ("\nProducao do dia %d: %d litros, com media de %d litros/vaca", j+1, somaCol, somaCol/35);
		if ((j == 0)&&(i == 0))
		{
			qtdmenosProd = somaCol;
			diamenosProd = j+1;
			qtdmaisProd = somaCol;
			diamaisProd = j+1;
		}
		else
		{
			if (somaCol < qtdmenosProd)
			{
				qtdmenosProd = somaCol;
				diamenosProd = j+1;
			}
			if (somaCol > qtdmaisProd)
			{
				qtdmaisProd = somaCol;
				diamaisProd = j+1;
			}
		}
	}
	printf ("\n\nMenor producao: dia %d, com %d litros", diamenosProd, qtdmenosProd);
	printf ("\nMaior producao: dia %d, com %d litros\n", diamaisProd, qtdmaisProd);
	printf ("\nTotal produzido na semana: %d litros\n", totalSemana);
	
	// soma das linhas, cálculo da quantidade produzida por cada vaca e o número da vaca que mais produziu
	for (i = 0; i < 35; i++)
	{
		somaLin = 0;
		for (j = 0; j < 7; j++)
		{
			somaLin = somaLin + matriz[i][j];	
		}
		printf ("\nProducao da vaca %d: %d litros, com media de %d litros/dia", i+1, somaLin, somaLin/7);
		if (i == 0)
		{
			qtdvacamaisProd = somaLin;
			vacamaisProd = i+1;
		}
		else
		{
			if (somaLin > qtdvacamaisProd)
			{
				qtdvacamaisProd = somaLin;
				vacamaisProd = i+1;
			}
		}
	}
	printf ("\n\nVaca mais eficiente: no %d, com %d litros", vacamaisProd, qtdvacamaisProd);
	
	return 0;
}
