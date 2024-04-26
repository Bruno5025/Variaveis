#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float X;
    float Y;
} Ponto;

float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    return 0.5 * abs((A.X*(B.Y - C.Y) + B.X*(C.Y - A.Y) + C.X*(A.Y - B.Y)));
}

float AreaPoligono(Ponto *vertices, int numVertices) {
    float area = 0.0;
    int i;

    for (i = 1; i < numVertices - 1; i++) {
        area += AreaTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }

    return area;
}

int main() {
    FILE *arquivo;
    int numVertices, i;
    Ponto *vertices;

    arquivo = fopen("vertices.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fscanf(arquivo, "%d", &numVertices);

    vertices = (Ponto*)malloc(numVertices * sizeof(Ponto));
    if (vertices == NULL) {
        printf("Erro de alocação de memória.\n");
        fclose(arquivo);
        return 1;
    }

    for (i = 0; i < numVertices; i++) {
        fscanf(arquivo, "%f %f", &(vertices[i].X), &(vertices[i].Y));
    }

    fclose(arquivo);

    float area = AreaPoligono(vertices, numVertices);

    printf("A área do polígono é %.2f\n", area);

    free(vertices);

    return 0;
}
