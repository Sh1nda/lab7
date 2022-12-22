#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <locale.h>
#include <queue>
using namespace std;


void NewGraphNeOr(int** G, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				G[i][j] = 0;
			}
			if (i < j) {
				if (rand() % 100 > 50) {
					G[i][j] = rand() % 15;
				}
				else {
					G[i][j] = 0;
				}
				G[j][i] = G[i][j];
			}
		}
	}
}


void PrintGraph(int** G, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d ", G[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void BFSD(int s, int** G, int* dist, int n) {
	queue <int> q;
	q.push(s);
	dist[s] = 0;

	while (!q.empty()) {
		s = q.front();
		q.pop();
		printf("%d ", s);

		for (int i = 0; i < n; i++) {
			if ((G[s][i] > 0) && (dist[i] == 1000)) {
				q.push(i);
				dist[i] = dist[s] + G[s][i];
			}
		}
	}
	printf("\n");
}



int main() {
	int** G;	// указатель на указатель на строку элементов
	int* dist;
	int i, j, n;

	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	printf("Введите размер графа: ");
	scanf("%d", &n);
	printf("\n");

	G = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		G[i] = (int*)malloc(n * sizeof(int));
	}
	dist = (int*)malloc(n * sizeof(int));

	printf("Неориентированный взвешенный граф \n");
	NewGraphNeOr(G, n);
	PrintGraph(G, n);
	
	for (j = 0; j < n; j++) {

		for (i = 0; i < n; i++) {
			dist[i] = 1000;
		}

		printf("от вершины %d: ", j);
		BFSD(j, G, dist, n);

		for (i = 0; i < n; i++) {
			if (dist[i] != 1000)
				printf("%d\t", dist[i]);
			else
				printf("нет прохода\t");
		}
		printf("\n\n");
	}

	for (i = 0; i < n; i++) {
		free(G[i]);
	}
	free(G);
	free(dist);

	getchar();
	getchar();
}