#include <stdio.h>
#include <string.h>

// Definición de la estructura Cliente
struct Cliente {
    char nombre[100];
    float consumoPromedio;
    float kmPorGalones;
    float costoCombustible;
    float costomantenimiento;
    float costoruedas;
};

int main() {
    // Declaración
    struct Cliente cliente;

    // Datos
    printf("Datos del Cliente:\n");
    printf("Nombre del cliente: ");
    fgets(cliente.nombre, sizeof(cliente.nombre), stdin);
    printf("Consumo promedio (8-16): ");
    scanf("%f", &cliente.consumoPromedio);
    printf("Kilometros por galon: ");
    scanf("%f", &cliente.kmPorGalones);
    printf("Costo de combustible por galon: ");
    scanf("%f", &cliente.costoCombustible);
    printf("Costo de mantenimiento: ");
    scanf("%f", &cliente.costomantenimiento);
    printf("Costo de las ruedas: ");
    scanf("%f", &cliente.costoruedas);

    cliente.nombre[strcspn(cliente.nombre, "\n")] = '\0';

    // Imprimir la tabla
    printf("\nTabla de Costos:\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");
    printf("|  Km  | Nombre                 | Consumo prom. | Km x galon    | Costo combustible | Gastos varios  | Pago por galon | Costo   |\n");
    printf("|------|------------------------|---------------|---------------|-------------------|----------------|----------------|---------|\n");

    float consumo;
    for (float km = 8; km <= 16; km++) {
        consumo = cliente.consumoPromedio * km;
        printf("| %4.0f | %-22s | %13.2f | %13.2f | %17.2f | %14.2f | %14.2f | %7.2f |\n",
               km, cliente.nombre, cliente.consumoPromedio, cliente.kmPorGalones, cliente.costoCombustible,
               cliente.costomantenimiento, cliente.kmPorGalones * cliente.costoCombustible,
               consumo * cliente.costomantenimiento);
    }

    printf("---------------------------------------------------------------------------------------------------------------------------\n");

    return 0;
}
