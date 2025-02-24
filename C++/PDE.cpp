#include <iostream>
#include <vector>
#include <cmath>

const int GRID_SIZE = 50;
const double DELTA_T = 0.01;
const double DIFFUSION_COEFF = 0.1;
const double INITIAL_PRESSURE = 1013.0;//(psi)
const double INITIAL_AQI = 50.0;

struct Cell {
    double pressure;
    double aqi;
};

void initializeGrid(std::vector<std::vector<Cell>>& grid) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j].pressure = INITIAL_PRESSURE;
            grid[i][j].aqi = INITIAL_AQI;
        }
    }
}

void updateGrid(std::vector<std::vector<Cell>>& grid) {
    std::vector<std::vector<Cell>> newGrid = grid;

    for (int i = 1; i < GRID_SIZE - 1; ++i) {
        for (int j = 1; j < GRID_SIZE - 1; ++j) {
            // Simple pressure update based on neighboring cells
            double pressureChange = 0.25 * (
                grid[i + 1][j].pressure + grid[i - 1][j].pressure +
                grid[i][j + 1].pressure + grid[i][j - 1].pressure -
                4 * grid[i][j].pressure
            );

            // AQI update using diffusion
            double diffusion = DIFFUSION_COEFF * (
                grid[i + 1][j].aqi + grid[i - 1][j].aqi +
                grid[i][j + 1].aqi + grid[i][j - 1].aqi -
                4 * grid[i][j].aqi
            );

            double sourceTerm = exp(-0.01 * grid[i][j].pressure); // Pressure-AQI coupling

            newGrid[i][j].pressure += DELTA_T * pressureChange;
            newGrid[i][j].aqi += DELTA_T * (diffusion + sourceTerm);
        }
    }

    grid = newGrid;
}

void printGrid(const std::vector<std::vector<Cell>>& grid) {
    for (int i = 0; i < GRID_SIZE; i += 5) {
        for (int j = 0; j < GRID_SIZE; j += 5) {
            std::cout << "P:" << grid[i][j].pressure << " AQI:" << grid[i][j].aqi << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}

int main() {
    std::vector<std::vector<Cell>> grid(GRID_SIZE, std::vector<Cell>(GRID_SIZE));
    initializeGrid(grid);

    for (int t = 0; t < 100; ++t) {
        updateGrid(grid);
        printGrid(grid);
    }

    return 0;
}

